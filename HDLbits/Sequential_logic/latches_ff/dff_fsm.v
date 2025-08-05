//

module top_module (
    input clk,
    input x,
    output z
); 
    wire q1, q2, q3;
    wire w1, w2, w3;

    // Combinational logic
    assign w1 = x ^ q1;
    assign w2 = x & ~q2;
    assign w3 = x | ~q3;

    // Flip-flops
    dff d1 (.clk(clk), .d(w1), .q(q1));
    dff d2 (.clk(clk), .d(w2), .q(q2));
    dff d3 (.clk(clk), .d(w3), .q(q3));

    // Output logic
    assign z = ~(q1 | q2 | q3);

endmodule

module dff (
    input clk,  
    input d,
    output reg q
);
    always @(posedge clk)
        q <= d;
endmodule
