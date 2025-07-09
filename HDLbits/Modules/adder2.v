// you are given a module add16 that performs a 16-bit addition. You must instantiate two of them to create a 32-bit adder. One add16 module computes the lower 16 bits of the addition result, while the second add16 module computes the upper 16 bits of the result. Your 32-bit adder does not need to handle carry-in (assume 0) or carry-out (ignored). 

module top_module (
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
);//
 wire q,w,z;
    wire [15:0] a1,a2,b1,b2;
    wire [15:0] s1,s2;
	assign q = 1'b0;
    assign {a2,a1} = {a};
    assign {b2,b1} = {b};
    add16 m1(a1,b1,q,s1,w);
    add16 m2(a2,b2,w,s2,z);
    assign sum = {s2,s1};

endmodule

module add1 ( input a, input b, input cin,   output sum, output cout );
assign sum = a + b +cin;
    assign cout = (((b==1)&&(a==1))||((b==1)&&(cin==1))||((cin==1)&&(a==1)))?1'b1:    
    1'b0;
endmodule