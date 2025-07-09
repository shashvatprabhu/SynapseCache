module top_module (
    input clk,
    input [7:0] in,
    output [7:0] anyedge
);
    
    reg [7:0] in2;
    
    always @(posedge clk) begin
        
        in2 <= in;
        anyedge = (in & ~in2) | (~in & in2);
        
    end

endmodule