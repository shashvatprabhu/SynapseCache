`timescale 1ns/1ps
`default_nettype none

module icache_controller #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter INDEX_WIDTH = 5,
    parameter TAG_WIDTH   = ADDR_WIDTH - INDEX_WIDTH
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

    // Cache storage interface (1-word lines, direct-mapped)
    input  wire                     HIT,
    input  wire [DATA_WIDTH-1:0]    CACHE_READDATA,
    input  wire [TAG_WIDTH-1:0]     STORED_TAG,
    input  wire                     VALID,

    output reg                      COMPARE_EN,
    output reg                      WRITE_ENABLE,
    output reg  [ADDR_WIDTH-1:0]    CACHE_ADDRESS,
    output reg  [DATA_WIDTH-1:0]    CACHE_WRITEDATA,
    output reg  [TAG_WIDTH-1:0]     CACHE_WRITETAG,
    output reg                      CACHE_WRITEVALID
);

    // FSM states
    localparam S_LOOKUP     = 2'b00; // compare tags / serve hit
    localparam S_REQ_MEM    = 2'b01; // assert read req, wait for accept (BUSYWAIT=0)
    localparam S_WAIT_VALID = 2'b10; // wait for MEM_READDATA_VALID
    localparam S_UPDATE     = 2'b11; // write line and return to CPU

    reg [1:0] state, next_state;

    // Latches
    reg [ADDR_WIDTH-1:0] saved_address;
    wire [TAG_WIDTH-1:0] saved_tag = saved_address[ADDR_WIDTH-1:INDEX_WIDTH];

    // For convenience (single-word lines: index is low INDEX_WIDTH bits)
    wire [INDEX_WIDTH-1:0] addr_index = CPU_ADDRESS[INDEX_WIDTH-1:0];
    wire [TAG_WIDTH-1:0]   addr_tag   = CPU_ADDRESS[ADDR_WIDTH-1:INDEX_WIDTH];

    // Sequential state/latches
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state         <= S_LOOKUP;
            saved_address <= {ADDR_WIDTH{1'b0}};
        end else begin
            state <= next_state;

            // Latch the miss address when we kick off a memory request
            if (state == S_LOOKUP && CPU_READ && !(HIT && VALID)) begin
                saved_address <= CPU_ADDRESS;
            end
        end
    end

    // Next-state logic
    always @(*) begin
        case (state)
            S_LOOKUP: begin
                // If CPU is reading and miss (or invalid), go fetch
                if (CPU_READ && !(HIT && VALID))
                    next_state = S_REQ_MEM;
                else
                    next_state = S_LOOKUP;
            end

            S_REQ_MEM: begin
                // Keep requesting until memory accepts (BUSYWAIT deasserts)
                if (!MEM_BUSYWAIT)
                    next_state = S_WAIT_VALID;
                else
                    next_state = S_REQ_MEM;
            end

            S_WAIT_VALID: begin
                // Wait until memory actually presents valid data
                if (MEM_READDATA_VALID)
                    next_state = S_UPDATE;
                else
                    next_state = S_WAIT_VALID;
            end

            S_UPDATE: begin
                // Write cache & finish this transaction
                next_state = S_LOOKUP;
            end

            default: next_state = S_LOOKUP;
        endcase
    end

    // Output / control logic
    always @(*) begin
        // Defaults
        CPU_BUSYWAIT     = 1'b0;
        CPU_INSTR        = {DATA_WIDTH{1'b0}};
        MEM_READ_REQ     = 1'b0;
        MEM_ADDRESS      = {ADDR_WIDTH{1'b0}};
        COMPARE_EN       = 1'b0;
        WRITE_ENABLE     = 1'b0;
        CACHE_ADDRESS    = {ADDR_WIDTH{1'b0}};
        CACHE_WRITEDATA  = {DATA_WIDTH{1'b0}};
        CACHE_WRITETAG   = {TAG_WIDTH{1'b0}};
        CACHE_WRITEVALID = 1'b0;

        if (reset) begin
            // keep defaults
        end else begin
            case (state)
                // Tag compare / serve hits immediately
                S_LOOKUP: begin
                    COMPARE_EN = 1'b1;
                    if (CPU_READ) begin
                        CACHE_ADDRESS = CPU_ADDRESS;
                        if (HIT && VALID) begin
                            // Hit: serve instruction, no stall
                            CPU_INSTR    = CACHE_READDATA;
                            CPU_BUSYWAIT = 1'b0;
                        end else begin
                            // Miss: stall CPU while we fetch
                            CPU_BUSYWAIT = 1'b1;
                        end
                    end
                end

                // Issue read request; keep BUSYWAIT high until accepted
                S_REQ_MEM: begin
                    CPU_BUSYWAIT = 1'b1;
                    MEM_READ_REQ = 1'b1;
                    MEM_ADDRESS  = saved_address; // single-word line, no alignment needed
                end

                // Wait for data-valid; still stalled
                S_WAIT_VALID: begin
                    CPU_BUSYWAIT = 1'b1;
                end

                // Update cache and provide data to CPU immediately
                S_UPDATE: begin
                    CPU_BUSYWAIT     = 1'b0;              // data is ready this cycle
                    WRITE_ENABLE     = 1'b1;
                    CACHE_ADDRESS    = saved_address;
                    CACHE_WRITEDATA  = MEM_READDATA;
                    CACHE_WRITETAG   = saved_tag;
                    CACHE_WRITEVALID = 1'b1;

                    // You can return MEM_READDATA directly; no need to re-read cache
                    CPU_INSTR        = MEM_READDATA;
                end
            endcase
        end
    end

endmodule
