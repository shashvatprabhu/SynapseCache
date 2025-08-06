`timescale 1ns/1ps

module cache_controller #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter BLOCK_SIZE = 4,
    parameter INDEX_WIDTH = 5,
    parameter TAG_WIDTH = ADDR_WIDTH - INDEX_WIDTH - $clog2(BLOCK_SIZE)
)(
    input clk,
    input reset,

    // CPU interface
    input                       CPU_READ,
    input [ADDR_WIDTH-1:0]      CPU_ADDRESS,
    output reg [DATA_WIDTH-1:0] CPU_INSTR,
    output reg                  CPU_BUSYWAIT,

    // Memory interface
    input                       MEM_BUSYWAIT,
    output reg                  MEM_READ_REQ,
    output reg [ADDR_WIDTH-1:0] MEM_ADDRESS,
    input [DATA_WIDTH-1:0]      MEM_READDATA,
    input                       MEM_READDATA_VALID,

    // Cache storage interface
    input                       HIT,
    input [DATA_WIDTH-1:0]      CACHE_READDATA,
    input [TAG_WIDTH-1:0]       STORED_TAG,
    input                       VALID,

    output reg                  COMPARE_EN,
    output reg                  WRITE_ENABLE,
    output reg [ADDR_WIDTH-1:0] CACHE_ADDRESS,
    output reg [DATA_WIDTH-1:0] CACHE_WRITEDATA,
    output reg [TAG_WIDTH-1:0]  CACHE_WRITETAG,
    output reg                  CACHE_WRITEVALID
);

    // FSM states
    reg [1:0] state, next_state;
    parameter IDLE = 2'b00, READ_MEM = 2'b01, UPDATE_CACHE = 2'b10, WAIT_READ = 2'b11;

    // Internal registers
    reg [ADDR_WIDTH-1:0] saved_address;
    reg [TAG_WIDTH-1:0]  tag;
    reg [INDEX_WIDTH-1:0] index;
    reg [$clog2(BLOCK_SIZE)-1:0] offset;

    // Address split
    always @(*) begin
        offset = CPU_ADDRESS[$clog2(BLOCK_SIZE)-1:0];
        index  = CPU_ADDRESS[$clog2(BLOCK_SIZE)+INDEX_WIDTH-1:$clog2(BLOCK_SIZE)];
        tag    = CPU_ADDRESS[ADDR_WIDTH-1:$clog2(BLOCK_SIZE)+INDEX_WIDTH];
    end

    // FSM sequential logic
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            saved_address <= 0;
            
        end else begin
            state <= next_state;

            // Save address after memory request is accepted
            if (state == READ_MEM && !MEM_BUSYWAIT)
                saved_address <= CPU_ADDRESS;
        end
    end

    // FSM next state logic
    always @(*) begin
        case (state)
            IDLE: begin
                if (CPU_READ && (!HIT || !VALID))
                    next_state = READ_MEM;
                else
                    next_state = IDLE;
            end

            READ_MEM: begin
                if (!MEM_BUSYWAIT)
                    next_state = UPDATE_CACHE;
                else
                    next_state = READ_MEM;
            end

            UPDATE_CACHE: begin
                next_state = WAIT_READ;
            end

            WAIT_READ: begin
                next_state = IDLE;
            end

            default: next_state = IDLE;
        endcase
    end

    // FSM output logic
    always @(*) begin
        // Default outputs
        CPU_BUSYWAIT     = 0;
        CPU_INSTR        = 32'hxxxxxxxx;
        MEM_READ_REQ     = 0;
        MEM_ADDRESS      = 0;
        COMPARE_EN       = 0;
        WRITE_ENABLE     = 0;
        CACHE_ADDRESS    = 0;
        CACHE_WRITEDATA  = 0;
        CACHE_WRITETAG   = 0;
        CACHE_WRITEVALID = 0;

        case (state)
            IDLE: begin
                COMPARE_EN = 1;
                if (CPU_READ) begin
                    CPU_BUSYWAIT = 1;
                    CACHE_ADDRESS = CPU_ADDRESS;
                    if (HIT && VALID) begin
                        CPU_INSTR = CACHE_READDATA;
                        CPU_BUSYWAIT = 0;
                    end
                end
            end

            READ_MEM: begin
                CPU_BUSYWAIT = 1;
                MEM_READ_REQ = 1;
                MEM_ADDRESS = {tag, index, {($clog2(BLOCK_SIZE)){1'b0}}}; // aligned
            end

            UPDATE_CACHE: begin
                CPU_BUSYWAIT     = 1;
                WRITE_ENABLE     = 1;
                CACHE_ADDRESS    = saved_address;
                CACHE_WRITEDATA  = MEM_READDATA;
                CACHE_WRITETAG   = tag;
                CACHE_WRITEVALID = 1;
            end

            WAIT_READ: begin
                CPU_BUSYWAIT = 1;
                CACHE_ADDRESS = saved_address;
                CPU_INSTR = CACHE_READDATA;
            end
        endcase
    end

endmodule
