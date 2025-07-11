//

module top_module( 
    input [3:0] in,
    output reg [2:0] out_both,
    output reg [3:1] out_any,
    output reg [3:0] out_different );

    integer i;

    always @(*) begin
        for (i = 0; i < 3; i = i + 1) begin
            out_both[i] = in[i] & in[i+1];
        end
        for (i = 0; i < 3; i = i + 1) begin
            out_any[i+1] = in[i] | in[i+1];
        end
        out_different[3] = in[0] ^ in[3];
        for (i = 0; i < 3; i = i + 1) begin
            out_different[i] = in[i] ^ in[i+1];
        end
    end

endmodule