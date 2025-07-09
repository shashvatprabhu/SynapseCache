module top_module (
    input [7:0] a, b, c, d,
    output [7:0] min);

    wire [7:0] res1;
    wire [7:0] res2;
    assign res1 = a<b ? a : b;
    assign res2 = c<d ? c : d;
    assign min = res1<res2 ? res1 : res2;

endmodule