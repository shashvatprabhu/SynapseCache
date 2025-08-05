// is there a latch in this code?

module top_module (
    input clk,
    input resetn,
    input [1:0] byteena,
    input [15:0] d,
    output [15:0] q
);

    always @(posedge (clk)) begin
        if(~resetn) begin
        q <= 16'h0000;
        end
        else if(resetn&byteena[1]&byteena[0])begin
        q <= d;
        end
        else if(resetn&~byteena[1]&byteena[0])begin
            q[7:0] <= d[7:0];
        end
        else if(resetn&byteena[1]&~byteena[0]) begin
            q[15:8] <= d[15:8];
        end
    end
        
endmodule