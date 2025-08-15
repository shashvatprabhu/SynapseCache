`timescale 1ns/1ps

module cache_storage #(
    parameter WORD_WIDTH  = 32,    // Width of each instruction
    parameter INDEX_BITS  = 4,     // Number of bits used for index (e.g., 2^4 = 16 sets)
    parameter TAG_BITS    = 24     // Remaining bits in address after index
)(
    input                        clk,
    input                        reset,

    // Interface with Controller
    input                        read,         // Read request from controller
    input                        write,        // Write enable from controller
    input       [31:0]           address,      // Full CPU address
    input       [WORD_WIDTH-1:0] write_block,  // One instruction (1 word only)
    output reg  [WORD_WIDTH-1:0] read_data,    // One word back to CPU
    output reg                   hit           // Cache hit flag
);

    localparam NUM_BLOCKS = (1 << INDEX_BITS);

    // Cache arrays
    reg                        valid_bits[NUM_BLOCKS-1:0];
    reg [TAG_BITS-1:0]         tag_array [NUM_BLOCKS-1:0];
    reg [WORD_WIDTH-1:0]       data_array[NUM_BLOCKS-1:0];

    // Address decoding
    wire [INDEX_BITS-1:0] index;
    wire [TAG_BITS-1:0]   tag;

    assign index = address[INDEX_BITS - 1:0];
    assign tag   = address[31:32 - TAG_BITS];

    integer i;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            for (i = 0; i < NUM_BLOCKS; i = i + 1) begin
                valid_bits[i] <= 0;
                tag_array[i]  <= 0;
                data_array[i] <= 0;
            end
            read_data <= 0;
            hit       <= 0;
        end else begin
            if (read) begin
                if (valid_bits[index] && (tag_array[index] == tag)) begin
                    hit       <= 1;
                    read_data <= data_array[index];
                end else begin
                    hit       <= 0;
                    read_data <= 32'hx;
                end
            end

            if (write) begin
                valid_bits[index] <= 1;
                tag_array[index]  <= tag;
                data_array[index] <= write_block;
            end
        end
    end

endmodule
