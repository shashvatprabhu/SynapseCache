`timescale 1ns/1ps
`default_nettype none

module icache_controller #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter INDEX_WIDTH = 5,
    parameter BLOCK_WORDS = 4,
    parameter OFFSET_WIDTH = $clog2(BLOCK_WORDS),
    parameter TAG_WIDTH = ADDR_WIDTH - INDEX_WIDTH - OFFSET_WIDTH
)(
    input  wire                     clk,
    input  wire                     reset,

    // CPU interface
    input  wire                     CPU_READ,
    input  wire [ADDR_WIDTH-1:0]    CPU_ADDRESS,
    output reg  [DATA_WIDTH-1:0]    CPU_INSTR,
    output reg                      CPU_BUSYWAIT,

    // Memory interface
    input  wire                     MEM_BUSYWAIT,
    output reg                      MEM_READ_REQ,
    output reg  [ADDR_WIDTH-1:0]    MEM_ADDRESS,
    input  wire [DATA_WIDTH-1:0]    MEM_READDATA,
    input  wire                     MEM_READDATA_VALID,

    // Cache storage interface
    input  wire                     HIT,
    input  wire [DATA_WIDTH-1:0]    CACHE_READDATA,
    output reg                      COMPARE_EN,
    output reg                      WRITE_ENABLE,
    output reg  [ADDR_WIDTH-1:0]    CACHE_ADDRESS,
    output reg  [DATA_WIDTH-1:0]    CACHE_WRITEDATA,
    output reg  [TAG_WIDTH-1:0]     CACHE_WRITETAG,
    output reg                      CACHE_WRITEVALID
);

    // FSM states
    localparam IDLE       = 3'b000;
    localparam CHECK_HIT  = 3'b001;
    localparam MISS       = 3'b010;
    localparam WAIT_WORD  = 3'b011;
    localparam FILL_DONE  = 3'b100;

    reg [2:0] state, next_state;

    // Block fetch offset
    reg [OFFSET_WIDTH-1:0] fetch_offset;
    reg [TAG_WIDTH-1:0]    req_tag;
    reg [INDEX_WIDTH-1:0]  req_index;
    reg [OFFSET_WIDTH-1:0] req_offset;

    // Split incoming address
    wire [TAG_WIDTH-1:0]    cpu_tag    = CPU_ADDRESS[ADDR_WIDTH-1 -: TAG_WIDTH];
    wire [INDEX_WIDTH-1:0]  cpu_index  = CPU_ADDRESS[OFFSET_WIDTH +: INDEX_WIDTH];
    wire [OFFSET_WIDTH-1:0] cpu_offset = CPU_ADDRESS[OFFSET_WIDTH-1:0];

    // FSM sequential
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            fetch_offset <= 0;
            CPU_BUSYWAIT <= 0;
        end else begin
            state <= next_state;
        end
    end

    // FSM combinational
    always @(*) begin
        // defaults
        next_state      = state;
        CPU_BUSYWAIT    = 0;
        COMPARE_EN      = 0;
        WRITE_ENABLE    = 0;
        MEM_READ_REQ    = 0;
        CACHE_WRITEVALID= 0;
        CACHE_WRITETAG  = req_tag;
        CACHE_ADDRESS   = {req_index, fetch_offset};
        CACHE_WRITEDATA = MEM_READDATA;
        MEM_ADDRESS     = {req_tag, req_index, fetch_offset};
        CPU_INSTR       = CACHE_READDATA;

        case (state)
            IDLE: begin
                if (CPU_READ) begin
                    req_tag    = cpu_tag;
                    req_index  = cpu_index;
                    req_offset = cpu_offset;
                    COMPARE_EN = 1;
                    CPU_BUSYWAIT = 1;
                    next_state = CHECK_HIT;
                end
            end

            CHECK_HIT: begin
                CPU_BUSYWAIT = 1;
                if (HIT) begin
                    CPU_INSTR = CACHE_READDATA;
                    next_state = IDLE;
                end else begin
                    fetch_offset = 0;
                    MEM_ADDRESS = {cpu_tag, cpu_index, {OFFSET_WIDTH{1'b0}}};
                    MEM_READ_REQ = 1;
                    CPU_BUSYWAIT = 1;
                    next_state = MISS;
                end
            end

            MISS: begin
                CPU_BUSYWAIT = 1;
                MEM_READ_REQ = 1;
                if (!MEM_BUSYWAIT) begin
                    next_state = WAIT_WORD;
                end
            end

            WAIT_WORD: begin
                CPU_BUSYWAIT = 1;
                if (MEM_READDATA_VALID) begin
                    // write word into cache
                    WRITE_ENABLE = 1;
                    CACHE_WRITEVALID = 1;
                    CACHE_WRITETAG = req_tag;
                    CACHE_ADDRESS = {req_index, fetch_offset};
                    CACHE_WRITEDATA = MEM_READDATA;

                    if (fetch_offset == BLOCK_WORDS-1) begin
                        next_state = FILL_DONE;
                    end else begin
                        fetch_offset = fetch_offset + 1;
                        MEM_ADDRESS = {req_tag, req_index, fetch_offset + 1'b1};
                        MEM_READ_REQ = 1;
                        next_state = MISS; // request next word
                    end
                end
            end

            FILL_DONE: begin
                CPU_BUSYWAIT = 0;
                next_state = IDLE;
            end
        endcase
    end

endmodule
