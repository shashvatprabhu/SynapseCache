//

module top_module (
    input [3:0] SW,
    input [3:0] KEY,
    output [3:0] LEDR
); 
    wire w1,w2,w3,w4;
    MUXDFF m1(.clk(KEY[0]),.w(KEY[3]),.R(SW[3]),.E(KEY[1]),.L(KEY[2]),.Q(w1));
    MUXDFF m2(.clk(KEY[0]),.w(w1),.R(SW[2]),.E(KEY[1]),.L(KEY[2]),.Q(w2));
    MUXDFF m3(.clk(KEY[0]),.w(w2),.R(SW[1]),.E(KEY[1]),.L(KEY[2]),.Q(w3));
    MUXDFF m4(.clk(KEY[0]),.w(w3),.R(SW[0]),.E(KEY[1]),.L(KEY[2]),.Q(w4));
    assign LEDR = {w1,w2,w3,w4};

endmodule


module MUXDFF (
    input clk,
    input w,
    input R,
    input E,
    input L,
    output reg Q
);
    wire d1;
    wire d2;
    assign d1 = E ? w : Q;
    assign d2 = L ? R : d1;
    always @(posedge clk) begin
        Q <= d2;
    end

endmodule