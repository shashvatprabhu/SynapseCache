module top_module( 
    input a, b, sel,
    output out ); 

    
    assign out = (sel & b) | (~sel & a);
    
    // assign out = sel ? b : a;
    
    /*always @(*)
        case(sel)
            1'b0 : out = a;
            1'b1 : out = b;
        endcase */
    
endmodule