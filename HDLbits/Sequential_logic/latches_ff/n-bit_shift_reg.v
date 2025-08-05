//

module top_module (
    input clk,
    input w, R, E, L,
    output reg Q       // Q must be reg to be assigned in always block
);

    wire d1;  // output of first mux
    wire d2;  // output of second mux (input to flip-flop)

    // First mux: select between Q and w
    assign d1 = E ? w : Q;

    // Second mux: select between d1 and R
    assign d2 = L ? R : d1;

    // D Flip-Flop
    always @(posedge clk) begin
        Q <= d2;
    end

endmodule