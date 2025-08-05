module cache_storage #(
    parameter WORD_WIDTH       = 32,
    parameter INDEX_BITS       = 4,
    parameter TAG_BITS         = 24,
    parameter ASSOCIATIVITY    = 2
)(
    input clk,
    input reset,

    input                       read,
    input                       write,
    input [31:0]                address,
    input [WORD_WIDTH-1:0]      write_data,
    input [TAG_BITS-1:0]        write_tag,
    input [$clog2(ASSOCIATIVITY)-1:0] way_select,
    input                       write_valid,

    output reg [WORD_WIDTH-1:0] read_data,
    output reg                  hit
);

    localparam NUM_SETS = (1 << INDEX_BITS);

    reg                        valid_bits   [NUM_SETS-1:0][ASSOCIATIVITY-1:0];
    reg [TAG_BITS-1:0]         tag_array    [NUM_SETS-1:0][ASSOCIATIVITY-1:0];
    reg [WORD_WIDTH-1:0]       data_array   [NUM_SETS-1:0][ASSOCIATIVITY-1:0];

    wire [INDEX_BITS-1:0] index = address[INDEX_BITS + 0 - 1: 0];
    wire [TAG_BITS-1:0] tag     = address[31 : 32 - TAG_BITS];

    integer i;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            for (i = 0; i < NUM_SETS; i = i + 1) begin : RESET_LOOP
                integer j;
                for (j = 0; j < ASSOCIATIVITY; j = j + 1) begin
                    valid_bits[i][j] <= 0;
                    tag_array[i][j]  <= 0;
                    data_array[i][j] <= 0;
                end
            end
            read_data <= 0;
            hit       <= 0;
        end else begin
            if (read) begin
                hit <= 0;
                for (i = 0; i < ASSOCIATIVITY; i = i + 1) begin
                    if (valid_bits[index][i] && tag_array[index][i] == tag) begin
                        hit       <= 1;
                        read_data <= data_array[index][i];
                    end
                end
                if (!hit) begin
                    read_data <= 32'hx;
                end
            end

            if (write) begin
                data_array[index][way_select] <= write_data;
                tag_array[index][way_select]  <= write_tag;
                valid_bits[index][way_select] <= write_valid;
            end
        end
    end

endmodule
