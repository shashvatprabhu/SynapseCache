`timescale 1ns/1ps

module icache_dm #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter CACHE_SIZE = 1024 
)(
    input  wire                    clk,
    input  wire                    rst_n,
    
    // CPU Interface
    input  wire                    cpu_req, 
    input  wire [ADDR_WIDTH-1:0]   cpu_addr,      
    output reg  [DATA_WIDTH-1:0]   cpu_data,     
    output reg                     cpu_valid,  
    output reg                     cpu_stall, 
    
    // Memory Interface
    output reg                     mem_req,  
    output reg [ADDR_WIDTH-1:0]    mem_addr,  
    input  wire [DATA_WIDTH-1:0]   mem_data, 
    input  wire                    mem_ready,
    
    // Cache Statistics
    output reg                     cache_hit,
    output reg                     cache_miss,
    output reg                     cache_evict
);

    // parameters
    localparam INDEX_BITS  = $clog2(CACHE_SIZE);
    localparam OFFSET_BITS = 2;
    localparam TAG_BITS    = ADDR_WIDTH - INDEX_BITS - OFFSET_BITS;
    
    // Cache storage arrays
    reg [TAG_BITS-1:0]    tag_array    [0:CACHE_SIZE-1];
    reg [DATA_WIDTH-1:0]  data_array   [0:CACHE_SIZE-1];
    reg                   valid_array  [0:CACHE_SIZE-1];
    
    // saved request information
    reg [TAG_BITS-1:0]    saved_tag;
    reg [INDEX_BITS-1:0]  saved_index;
    reg [ADDR_WIDTH-1:0]  saved_addr;
    
    // buffer register
    reg [DATA_WIDTH-1:0]  fetched_data_reg;
    
    // Combinational address parsing
    wire [TAG_BITS-1:0]   req_tag   = cpu_addr[ADDR_WIDTH-1 : INDEX_BITS + OFFSET_BITS];
    wire [INDEX_BITS-1:0] req_index = cpu_addr[INDEX_BITS + OFFSET_BITS - 1 : OFFSET_BITS];
    
    // Combinational hit detection
    wire                  hit = valid_array[req_index] && (tag_array[req_index] == req_tag);
    
    // FSM States
    localparam [1:0] IDLE     = 2'd0;
    localparam [1:0] FETCH    = 2'd1;
    localparam [1:0] ALLOCATE = 2'd2;
    
    reg [1:0] state, next_state;
    
    integer i;
    
    //  Synchronous Block for State, Registers, and Memory
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state       <= IDLE;
            saved_tag   <= {TAG_BITS{1'b0}};
            saved_index <= {INDEX_BITS{1'b0}};
            saved_addr  <= {ADDR_WIDTH{1'b0}};
            fetched_data_reg <= {DATA_WIDTH{1'b0}};
            
            for (i = 0; i < CACHE_SIZE; i = i + 1) begin
                tag_array[i]   <= {TAG_BITS{1'b0}};
                data_array[i]  <= {DATA_WIDTH{1'b0}};
                valid_array[i] <= 1'b0;
            end
        end else begin
            state <= next_state;
            
            // Latch request info on miss
            if (state == IDLE && next_state == FETCH) begin
                saved_tag   <= req_tag;
                saved_index <= req_index;
                saved_addr  <= cpu_addr;
            end
            
            // Capture data from memory
            if (state == FETCH && mem_ready) begin
                fetched_data_reg <= mem_data;
            end
            
            // Update cache arrays on allocate
            if (state == ALLOCATE) begin
                tag_array[saved_index]   <= saved_tag;
                data_array[saved_index]  <= fetched_data_reg;
                valid_array[saved_index] <= 1'b1;
            end
        end
    end
    

    //  Combinational Block for Next State Logic
    always @(*) begin
        next_state = state; // Default to staying in the current state
        
        case (state)
            IDLE: begin
                if (cpu_req && !hit) begin
                    next_state = FETCH;
                end
            end
            
            FETCH: begin
                if (mem_ready) begin
                    next_state = ALLOCATE;
                end
            end
            
            ALLOCATE: begin
                next_state = IDLE;
            end
            
            default: begin
                next_state = IDLE;
            end
        endcase
    end
    
    //  Combinational Block for Outputs (Memory & Stall)
    always @(*) begin
        mem_req   = 1'b0;
        mem_addr  = {ADDR_WIDTH{1'b0}};
        cpu_stall = 1'b0;

        case (state)
            IDLE: begin
                if (cpu_req && !hit) begin
                    cpu_stall = 1'b1;
                end
            end
            FETCH: begin
                mem_addr = {saved_addr[ADDR_WIDTH-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                if (!mem_ready) begin
                    mem_req = 1'b1;
                end
                cpu_stall = 1'b1;
            end
            ALLOCATE: begin
                cpu_stall = 1'b1;
            end
            default: begin
                cpu_stall = 1'b0;
            end
        endcase
    end

    //  Synchronous Block for Registered Outputs (CPU)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cpu_data    <= {DATA_WIDTH{1'b0}};
            cpu_valid   <= 1'b0;
            cache_hit   <= 1'b0;
            cache_miss  <= 1'b0;
            cache_evict <= 1'b0;
        end else begin
            cache_hit   <= 1'b0;
            cache_miss  <= 1'b0;
            cache_evict <= 1'b0;
            
            if (cpu_req && hit) begin
                cpu_data  <= data_array[req_index];
                cpu_valid <= 1'b1;
                cache_hit <= 1'b1;
            end else if (state == ALLOCATE) begin
                cpu_data  <= fetched_data_reg;
                cpu_valid <= 1'b1;
                cache_miss <= 1'b1;
                if (valid_array[saved_index]) begin
                    cache_evict <= 1'b1;
                end
            end else begin
                cpu_valid <= 1'b0;
            end
        end
    end
endmodule
