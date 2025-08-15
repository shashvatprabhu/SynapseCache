`timescale 1ns/1ps
`default_nettype none

module icache_storage #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter INDEX_WIDTH = 5,
    parameter TAG_WIDTH = ADDR_WIDTH - INDEX_WIDTH
)(
    input  wire                     clk,
    input  wire                     reset,

    // Read / compare interface
    input  wire                     COMPARE_EN,
    input  wire [ADDR_WIDTH-1:0]    ADDRESS,
    output wire                     HIT,
    output wire [DATA_WIDTH-1:0]    READDATA,
    output wire [TAG_WIDTH-1:0]     STORED_TAG,
    output wire                     VALID,

    // Write interface
    input  wire                     WRITE_ENABLE,
    input  wire [ADDR_WIDTH-1:0]    WRITE_ADDRESS,
    input  wire [DATA_WIDTH-1:0]    WRITEDATA,
    input  wire [TAG_WIDTH-1:0]     WRITETAG,
    input  wire                     WRITEVALID
);

    // Internal storage
    reg [DATA_WIDTH-1:0]  data_array [0:(1<<INDEX_WIDTH)-1];
    reg [TAG_WIDTH-1:0]   tag_array  [0:(1<<INDEX_WIDTH)-1];
    reg                   valid_array[0:(1<<INDEX_WIDTH)-1];

    // Address split
    wire [INDEX_WIDTH-1:0] read_index  = ADDRESS[INDEX_WIDTH-1:0];
    wire [TAG_WIDTH-1:0]   read_tag    = ADDRESS[ADDR_WIDTH-1:INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] write_index = WRITE_ADDRESS[INDEX_WIDTH-1:0];

    // Read path
    assign READDATA   = data_array[read_index];
    assign STORED_TAG = tag_array[read_index];
    assign VALID      = valid_array[read_index];
    assign HIT        = COMPARE_EN && VALID && (STORED_TAG == read_tag);

    // Write path
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            integer i;
            for (i = 0; i < (1<<INDEX_WIDTH); i = i + 1) begin
                data_array[i]  <= {DATA_WIDTH{1'b0}};
                tag_array[i]   <= {TAG_WIDTH{1'b0}};
                valid_array[i] <= 1'b0;
            end
        end else if (WRITE_ENABLE) begin
            data_array[write_index]  <= WRITEDATA;
            tag_array[write_index]   <= WRITETAG;
            valid_array[write_index] <= WRITEVALID;
        end
    end

endmodule
