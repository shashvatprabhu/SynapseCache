module top_module( 
    input [2:0] in,
    output [1:0] out );

    always @(*) begin
        out = 0;
        for(int i = 0; i<3; i++) begin
            case(in[i])
                1'b1 : out++;
                1'b0 : out = out;
            endcase
        end
    end

//assign out[0] = (~in[2] & ~in[1] & in[0]) | (~in[2] & in[1] & ~in[0]) | (in[2] & ~in[1] & ~in[0]) | (in[2] & in[1] & in[0]);
//assign out[1] = (in[1] & in[0]) | (in[2] & in[0]) | (in[2] & in[1]);


endmodule