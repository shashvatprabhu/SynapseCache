//

module top_module(
    input clk,
    input areset,    // Asynchronous reset to state B
    input in,
    output out);//  

    parameter A=0, B=1; 
    reg state, next_state;
wire q;
    always @(*) begin    // This is a combinational always block
        // State transition logic
        case({in,out})
            2'b11: q = B;
            2'b10: q = A;
            2'b01: q = A;
            2'b00: q = B;
        endcase
    end

    always @(posedge clk, posedge areset) begin    // This is a sequential always block
        // State flip-flops with asynchronous reset
        if(areset)
            out<=B;
        else 
            out<=q;
    end

    // Output logic
    // assign out = (state == ...);

endmodule
