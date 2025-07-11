// Build a 4-bit priority encoder. For this problem, if none of the input bits are high (i.e., input is zero), output zero. Note that a 4-bit number has 16 possible combinations.


module top_module (
    input [3:0] in,
    output reg [1:0] pos  );
    always @(in) begin
        casex(in)
            4'b1000 : begin
                pos = 2'd3; 
            end
            4'bx100 : begin
                pos = 2'd2; 
            end
            4'bxx10 : begin
                pos = 2'd1; 
            end
            4'bxxx1 : begin
                pos = 2'd0; 
            end
            default : pos = 2'd0;
        endcase
    end
endmodule