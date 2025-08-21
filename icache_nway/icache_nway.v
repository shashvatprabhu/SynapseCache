`timescale 1ns/1ps

// N-Way Set Associative Instruction Cache with Round-Robin Replacement

module icache_nway #(
    parameter ADDR_WIDTH    = 32,
    parameter DATA_WIDTH    = 32,
    parameter CACHE_SIZE    = 1024,
    parameter ASSOCIATIVITY = 1
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
    output reg  [ADDR_WIDTH-1:0]   mem_addr,
    input  wire [DATA_WIDTH-1:0]   mem_data,
    input  wire                    mem_ready,
    
    // Cache Statistics (single-cycle pulses)
    output reg                     cache_hit,
    output reg                     cache_miss,
    output reg                     cache_evict
);


    // Parameters
    localparam SETS        = CACHE_SIZE / ASSOCIATIVITY;
    localparam SET_BITS    = $clog2(SETS);
    localparam OFFSET_BITS = 2;  // 4-byte words
    localparam TAG_BITS    = ADDR_WIDTH - SET_BITS - OFFSET_BITS;
    localparam WAY_BITS    = (ASSOCIATIVITY > 1) ? $clog2(ASSOCIATIVITY) : 1;
    
    
    // Cache Storage Arrays
    reg [TAG_BITS-1:0]   tag_array   [0:SETS-1][0:ASSOCIATIVITY-1];
    reg [DATA_WIDTH-1:0] data_array  [0:SETS-1][0:ASSOCIATIVITY-1];
    reg                  valid_array [0:SETS-1][0:ASSOCIATIVITY-1];
    
    // Round-robin replacement tracking
    reg [WAY_BITS-1:0]   fifo_counter [0:SETS-1];
    
    // saved request information
    reg [TAG_BITS-1:0]   saved_tag;
    reg [SET_BITS-1:0]   saved_set;
    reg [ADDR_WIDTH-1:0] saved_addr;
    reg [WAY_BITS-1:0]   saved_way;
    reg                  saved_will_evict;
    
    // Register to safely hold memory data
    reg [DATA_WIDTH-1:0] fetched_data_reg;
    
    // Combinational Address Parsing
    wire [TAG_BITS-1:0]  req_tag = cpu_addr[ADDR_WIDTH-1 : SET_BITS+OFFSET_BITS];
    wire [SET_BITS-1:0]  req_set = cpu_addr[SET_BITS+OFFSET_BITS-1 : OFFSET_BITS];
    
    // Combinational Hit Detection
    reg hit;
    reg [WAY_BITS-1:0] hit_way_num;
    integer hit_i;
    
    always @(*) begin
        hit = 0;
        hit_way_num = 0;
        
        // Check all ways for hit
        for (hit_i = 0; hit_i < ASSOCIATIVITY; hit_i = hit_i + 1) begin
            if (valid_array[req_set][hit_i] && (tag_array[req_set][hit_i] == req_tag)) begin
                hit = 1;
                hit_way_num = hit_i[WAY_BITS-1:0];
            end
        end
    end
    
    // Combinational Round-Robin Replacement Logic
    reg [WAY_BITS-1:0] replace_way;
    reg                found_invalid;
    integer repl_i;
    
    always @(*) begin
        found_invalid = 0;
        replace_way = 0;
        
        // First, look for an invalid way
        for (repl_i = 0; repl_i < ASSOCIATIVITY; repl_i = repl_i + 1) begin
            if (!valid_array[req_set][repl_i] && !found_invalid) begin
                replace_way = repl_i[WAY_BITS-1:0];
                found_invalid = 1;
            end
        end
        
        // If no invalid way found, use round-robin pointer
        if (!found_invalid) begin
            replace_way = fifo_counter[req_set];
        end
    end
    
    // FSM States
    localparam [1:0] IDLE     = 2'd0;
    localparam [1:0] FETCH    = 2'd1;
    localparam [1:0] ALLOCATE = 2'd2;
    
    reg [1:0] state, next_state;
    
    integer i, j;
    
    // BLOCK 1: Synchronous State & Register Updates
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            saved_tag <= 0;
            saved_set <= 0;
            saved_addr <= 0;
            saved_way <= 0;
            saved_will_evict <= 0;
            fetched_data_reg <= 0;
            
            // Initialize cache arrays
            for (i = 0; i < SETS; i = i + 1) begin
                fifo_counter[i] <= 0;
                for (j = 0; j < ASSOCIATIVITY; j = j + 1) begin
                    tag_array[i][j] <= 0;
                    data_array[i][j] <= 0;
                    valid_array[i][j] <= 0;
                end
            end
        end else begin
            state <= next_state;
            
            // save request info on miss
            if (state == IDLE && next_state == FETCH) begin
                saved_tag <= req_tag;
                saved_set <= req_set;
                saved_addr <= {cpu_addr[ADDR_WIDTH-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
                saved_way <= replace_way;
                saved_will_evict <= valid_array[req_set][replace_way];
            end
            
            // Capture data from memory
            if (state == FETCH && mem_ready) begin
                fetched_data_reg <= mem_data;
            end
            
            // Update cache arrays on allocate
            if (state == ALLOCATE) begin
                tag_array[saved_set][saved_way] <= saved_tag;
                data_array[saved_set][saved_way] <= fetched_data_reg;
                valid_array[saved_set][saved_way] <= 1;
                
                // Update round-robin pointer
                if (ASSOCIATIVITY > 1) begin
                    if (fifo_counter[saved_set] == WAY_BITS'(ASSOCIATIVITY - 1)) begin
                        fifo_counter[saved_set] <= 0;
                    end else begin
                        fifo_counter[saved_set] <= fifo_counter[saved_set] + 1;
                    end
                end
            end
        end
    end
    
    // BLOCK 2: Combinational Next State Logic
    always @(*) begin
        next_state = state; // Default to staying in current state
        
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
    
    // BLOCK 3: Combinational Memory Interface & Stall Logic
    always @(*) begin
        mem_req = 0;
        mem_addr = 0;
        cpu_stall = 0;
        
        case (state)
            IDLE: begin
                if (cpu_req && !hit) begin
                    cpu_stall = 1;
                end
            end
            
            FETCH: begin
                mem_addr = saved_addr;
                if (!mem_ready) begin
                    mem_req = 1;
                end
                cpu_stall = 1;
            end
            
            ALLOCATE: begin
                cpu_stall = 1;
            end
            
            default: begin
                cpu_stall = 0;
            end
        endcase
    end
    
    // BLOCK 4: Synchronous CPU Output Generation (following your style)
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cpu_data    <= 0;
            cpu_valid   <= 0;
            cache_hit   <= 0;
            cache_miss  <= 0;
            cache_evict <= 0;
        end else begin
            // clear status signals
            cache_hit   <= 0;
            cache_miss  <= 0;
            cache_evict <= 0;
            
            // Handle hit (immediate response)
            if (cpu_req && hit && state == IDLE) begin
                cpu_data  <= data_array[req_set][hit_way_num];
                cpu_valid <= 1;
                cache_hit <= 1;
            end else if (state == ALLOCATE) begin
                // Handle miss completion
                cpu_data  <= fetched_data_reg;
                cpu_valid <= 1;
                cache_miss <= 1;
                cache_evict <= saved_will_evict;
            end else begin
                cpu_valid <= 0;
            end
        end
    end

endmodule