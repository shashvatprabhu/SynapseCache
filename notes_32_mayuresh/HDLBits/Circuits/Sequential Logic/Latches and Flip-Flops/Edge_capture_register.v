module top_module (
    input clk,
    input reset,
    input [31:0] in,
    output [31:0] out
);
    
    reg [31:0] in2;
    
    always @(posedge clk) begin
        in2 <= in;
        if(reset) begin
            out <= 32'b0;
        end
        else begin
            out <= (in2 & ~in) | out;
        end
    end
    
endmodule