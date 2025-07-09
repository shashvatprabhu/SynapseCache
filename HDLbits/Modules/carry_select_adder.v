// you are provided with the same module add16 as the previous exercise, which adds two 16-bit numbers with carry-in and produces a carry-out and 16-bit sum. You must instantiate three of these to build the carry-select adder, using your own 16-bit 2-to-1 multiplexer.

module top_module(
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);
 wire q,w,z,y,p;
    wire [15:0] a1,a2,b1,b2;
    wire [15:0] s1,s2,s21,s22;
	assign q = 1'b0;
    assign p = 1'b1;
    assign {a2,a1} = {a};
    assign {b2,b1} = {b};
    add16 m1(a1,b1,q,s1,w);
    add16 m2(a2,b2,p,s21,z);
    add16 m3(a2,b2,q,s22,y);
    assign s2 = (w == 1'b0) ? s22   :
        s21;
    assign sum = {s2,s1};
endmodule
