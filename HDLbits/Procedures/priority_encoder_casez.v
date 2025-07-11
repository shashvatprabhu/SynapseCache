// Build a priority encoder for 8-bit inputs. Given an 8-bit vector, the output should report the first (least significant) bit in the vector that is 1. Report zero if the input vector has no bits that are high. For example, the input 8'b10010000 should output 3'd4, because bit[4] is first bit that is high. 

module top_module (
    input [7:0] in,
    output reg [2:0] pos );
    always @(*) begin
        casez(in)
        8'bzzzzzzz1 : pos = 8'd0;
        8'bzzzzzz10 : pos = 8'd1;
        8'bzzzzz100 : pos = 8'd2;
        8'bzzzz1000 : pos = 8'd3;
        8'bzzz10000 : pos = 8'd4;
        8'bzz100000 : pos = 8'd5;
        8'bz1000000 : pos = 8'd6;
        8'b10000000 : pos = 8'd7;
        default : pos = 8'd0;
    endcase
    end
endmodule