// Implement the following circuit. Create two intermediate wires (named anything you want) to connect the AND and OR gates together. Note that the wire that feeds the NOT gate is really wire out, so you do not necessarily need to declare a third wire here. Notice how wires are driven by exactly one source (output of a gate), but can feed multiple inputs.

module top_module(
    input a,
    input b,
    input c,
    input d,
    output out,
    output out_n   ); 
wire or1, or2;
assign or1 = a & b;
assign or2 = c & d;
assign out = or1 | or2;
assign out_n = ~out;
endmodule