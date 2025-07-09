// Use a 32-bit wide XOR gate to invert the b input whenever sub is 1

module top_module(
    input [31:0] a,
    input [31:0] b,
    input sub,
    output [31:0] sum
);
wire q,w,z;
    wire [15:0] a1,a2,b1,b2;
    wire [15:0] s1,s2;
    assign {a2,a1} = {a};
    assign {b2,b1} = {b^{32{sub}}};
    add16 m1(a1,b1,sub,s1,w);
    add16 m2(a2,b2,w,s2,z);
    assign sum = {s2,s1};
endmodule