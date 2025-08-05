//

module top_module (
    input clk,
    input reset,
    input [31:0] in,
    output reg [31:0] out
);

    reg [31:0] prev_in;

    always @(posedge clk) begin
        if (reset)
            out <= 32'b0;                            // Reset takes priority
        else
            out <= out | (prev_in & ~in);            // Set on 1->0 transition

        prev_in <= in;                               // Update previous input
    end

endmodule
