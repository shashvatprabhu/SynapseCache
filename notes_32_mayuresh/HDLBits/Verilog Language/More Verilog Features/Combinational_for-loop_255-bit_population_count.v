module top_module( 
    input [254:0] in,
    output [7:0] out );

    always @(*) begin
        out = 0;
        for(int i = 0; i<255; i++) begin
            case(in[i])
                  1'b1 : out++;
                  1'b0 : out = out;
            endcase       
        end             
    end 
    
endmodule