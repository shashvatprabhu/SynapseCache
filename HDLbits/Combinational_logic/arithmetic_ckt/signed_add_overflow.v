
module top_module (
    input [7:0] a,
    input [7:0] b,
    output [7:0] s,
    output overflow
); //
assign s = a + b;
    // assign s = ...
assign overflow = (~a[7] & ~b[7] & s[7]) | (a[7] & b[7] & ~s[7]);


    // assign overflow = ...

endmodule

// You're doing a comparison on the unsigned result of a + b. But a, b, and a + b are 8-bit wires, which in Verilog are unsigned by default unless explicitly treated as signed.