module top_module (
    input clk,
    input resetn,   // synchronous reset
    input in,
    output out);
    
    wire d1, d2, d3;
    
    always @(posedge clk) begin
        
        if(!resetn) begin
            out <= 0;
            d1 <= 0;
            d2 <= 0;
            d3 <= 0;
        end
        else begin
            d1 <= in;
            d2 <= d1;
            d3 <= d2;
            out <= d3;
        end
    end

endmodule