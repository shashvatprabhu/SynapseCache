module top_module (
    input clk,
    input [7:0] in,
    output [7:0] pedge
);
    reg [7:0] in2;
    
    always @(posedge clk) begin
        
        pedge <= ~in2 & in;
        in2 <= in;
        
    end
   
endmodule