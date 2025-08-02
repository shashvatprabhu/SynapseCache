`default_nettype none

module icache_fifo #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,              // width of instruction
    parameter WORD_SIZE = 4,                // in bytes
    parameter BLOCK_SIZE = 1,               // words per block
    parameter DEG_ASSOCIATIVITY = 1,        // 1 = direct-mapped
    parameter CAPACITY = 256,               // total words in cache
    parameter NUM_SETS = CAPACITY / (BLOCK_SIZE * DEG_ASSOCIATIVITY),
    parameter BYTE_OFFSET = $clog2(WORD_SIZE),
    parameter BLOCK_OFFSET = (BLOCK_SIZE > 1) ? $clog2(BLOCK_SIZE) : 1,
    parameter SET_BITS = $clog2(NUM_SETS),
    parameter TAG_WIDTH = ADDR_WIDTH - SET_BITS - BLOCK_OFFSET - BYTE_OFFSET
) (
    input wire clk,
    input wire rst,
    input wire [ADDR_WIDTH-1:0] instr_addr,
    output reg [DATA_WIDTH-1:0] instr,

    output reg hit,
    output reg miss,
    output reg [ADDR_WIDTH-1:0] mem_addr,
    output reg mem_req,
    input wire [DATA_WIDTH-1:0] mem_instr,
    input wire mem_instr_valid
);

    reg [TAG_WIDTH-1:0] tag_bits [NUM_SETS-1:0][DEG_ASSOCIATIVITY-1:0];
    reg valid_bits [NUM_SETS-1:0][DEG_ASSOCIATIVITY-1:0];
    reg [DATA_WIDTH-1:0] data_bits [NUM_SETS-1:0][BLOCK_SIZE-1:0][DEG_ASSOCIATIVITY-1:0];

    wire [TAG_WIDTH-1:0] tag = instr_addr[ADDR_WIDTH-1 -: TAG_WIDTH];
    wire [SET_BITS-1:0]  set = instr_addr[BLOCK_OFFSET + BYTE_OFFSET +: SET_BITS];
    wire [BLOCK_OFFSET-1:0] block_offset = (BLOCK_SIZE == 1) ? {BLOCK_OFFSET{1'b0}} :
                                           instr_addr[BYTE_OFFSET +: BLOCK_OFFSET];

    integer i, j, k;
    reg hit_found;
    reg [$clog2(DEG_ASSOCIATIVITY)-1:0] matched_way;
    reg [$clog2(DEG_ASSOCIATIVITY)-1:0] fifo_ptr [NUM_SETS-1:0];

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            for (i = 0; i < NUM_SETS; i = i + 1) begin
                fifo_ptr[i] <= 0;
                for (j = 0; j < DEG_ASSOCIATIVITY; j = j + 1) begin
                    valid_bits[i][j] <= 0;
                    tag_bits[i][j]   <= 0;
                    for (k = 0; k < BLOCK_SIZE; k = k + 1) begin
                        data_bits[i][k][j] <= 0;
                    end
                end
            end
            instr     <= 32'h0;
            mem_addr  <= 32'h0;
            mem_req   <= 0;
            hit_found <= 0;
            hit       <= 0;
            miss      <= 0;
        end else begin
            hit_found = 0;
            matched_way = 0;

            // Tag match check
            for (i = 0; i < DEG_ASSOCIATIVITY; i = i + 1) begin
                if (valid_bits[set][i] && tag_bits[set][i] == tag) begin
                    hit_found = 1;
                    matched_way = i;
                end
            end

            if (hit_found) begin
                instr <= data_bits[set][block_offset][matched_way];
                hit   <= 1;
                miss  <= 0;
                mem_req <= 0;
            end else begin
                hit   <= 0;
                miss  <= 1;

                // Only issue memory request once
                if (!mem_req) begin
                    mem_addr <= {instr_addr[ADDR_WIDTH-1:BYTE_OFFSET + BLOCK_OFFSET],
                                 {(BYTE_OFFSET + BLOCK_OFFSET){1'b0}}};
                    mem_req <= 1;
                end

                if (mem_instr_valid) begin
                    data_bits[set][block_offset][fifo_ptr[set]] <= mem_instr;
                    tag_bits[set][fifo_ptr[set]]                <= tag;
                    valid_bits[set][fifo_ptr[set]]              <= 1;

                    instr <= mem_instr;
                    hit   <= 1;
                    miss  <= 0;
                    mem_req <= 0;

                    // Wrap-around FIFO pointer
                    fifo_ptr[set] <= (fifo_ptr[set] == DEG_ASSOCIATIVITY - 1) ? 0 : fifo_ptr[set] + 1;

                    
                end
            end
        end
    end

endmodule
