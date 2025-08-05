`timescale 1ns/1ps

module cache_storage #(
    parameter BLOCK_SIZE       = 4,     // Number of words per block
    parameter WORD_WIDTH       = 32,    // Width of each instruction
    parameter INDEX_BITS       = 4,     // Number of sets = 2^INDEX_BITS
    parameter TAG_BITS         = 24     // Remaining bits in address
)(
    input clk,
    input reset,

    // Interface with Controller
    input                       read,              // Read request
    input                       write,             // Write request
    input [31:0]                address,           // Full CPU address
    input [WORD_WIDTH*BLOCK_SIZE-1:0] write_block, // Burst block from memory (e.g., 128-bit)
    output reg [WORD_WIDTH-1:0] read_data,         // One word returned to CPU
    output reg                  hit                // Cache hit flag
);

    // Derived parameters
    localparam OFFSET_BITS = (BLOCK_SIZE == 1) ? 0 : $clog2(BLOCK_SIZE);
    localparam NUM_BLOCKS  = (1 << INDEX_BITS);

    // Internal memory arrays
    reg                        valid_bits   [NUM_BLOCKS-1:0];
    reg [TAG_BITS-1:0]         tag_array    [NUM_BLOCKS-1:0];
    reg [WORD_WIDTH-1:0]       data_array   [NUM_BLOCKS-1:0][BLOCK_SIZE-1:0];

    // Address decoding
    wire [OFFSET_BITS-1:0] offset;
    wire [INDEX_BITS-1:0]  index;
    wire [TAG_BITS-1:0]    tag;

    assign offset = (OFFSET_BITS == 0) ? 0 : address[OFFSET_BITS-1:0];
    assign index  = address[OFFSET_BITS + INDEX_BITS - 1 : OFFSET_BITS];
    assign tag    = address[31 : 32 - TAG_BITS];

    integer i;
    integer bit_offset;
    reg [WORD_WIDTH-1:0] extracted_word;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            for (i = 0; i < NUM_BLOCKS; i = i + 1) begin
                valid_bits[i] <= 0;
                tag_array[i]  <= 0;
                for (integer j = 0; j < BLOCK_SIZE; j = j + 1)
                    data_array[i][j] <= 0;
            end
            read_data <= 0;
            hit       <= 0;

        end else begin
            // Read logic
            if (read) begin
                if (valid_bits[index] && tag_array[index] == tag) begin
                    hit       <= 1;
                    read_data <= data_array[index][offset];
                end else begin
                    hit       <= 0;
                    read_data <= 32'hx;
                end
            end

            // Write logic
            if (write) begin
                valid_bits[index] <= 1;
                tag_array[index]  <= tag;
                for (i = 0; i < BLOCK_SIZE; i = i + 1) begin
                    bit_offset = i * WORD_WIDTH;
                    extracted_word = write_block[bit_offset + WORD_WIDTH - 1 : bit_offset];
                    data_array[index][i] <= extracted_word;
                end
            end
        end
    end

endmodule
