// You are given a module my_dff8 with two inputs and one output (that implements a set of 8 D flip-flops). Instantiate three of them, then chain them together to make a 8-bit wide shift register of length 3. In addition, create a 4-to-1 multiplexer (not provided) that chooses what to output depending on sel[1:0]: The value at the input d, after the first, after the second, or after the third D flip-flop.

module top_module ( 
    input clk, 
    input [7:0] d, 
    input [1:0] sel, 
    output [7:0] q 
);
    wire [7:0] q1, q2,q3;
    my_dff8 m1(.clk(clk),.d(d),.q(q1));
    my_dff8 m2(.clk(clk),.d(q1),.q(q2));
    my_dff8 m3(.clk(clk),.d(q2),.q(q3));
    assign q =  (sel==2'b00)?d:
        		(sel==2'b01)?q1:
        (sel == 2'b10)?q2:
    q3;
endmodule