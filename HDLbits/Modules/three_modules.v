// You are given a module my_dff with two inputs and one output (that implements a D flip-flop). Instantiate three of them, then chain them together to make a shift register of length 3. The clk port needs to be connected to all instances. 

module top_module ( input clk, input d, output q );
wire q1,q2;
    my_dff d1(.clk(clk),.d(d),.q(q1));
    my_dff d2(.clk(clk),.d(q1),.q(q2));
    my_dff d3(.clk(clk),.d(q2),.q(q));
endmodule   