//

module top_module (
    input clk,
    input in, 
    output out);
wire x;
    always@(posedge clk)begin
        out <= in^out;
    end
endmodule
