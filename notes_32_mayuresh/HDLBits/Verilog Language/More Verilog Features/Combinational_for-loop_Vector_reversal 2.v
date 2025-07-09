module top_module( 
    input [99:0] in,
    output [99:0] out
);
    
    always @(*)
        
        for(int i = 0; i<100; i++) begin //$bits() could also be used
            out[99-i] = in[i];
        end

endmodule