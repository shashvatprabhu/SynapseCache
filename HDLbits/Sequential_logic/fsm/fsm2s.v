//

module top_module(
    input clk,
    input reset,    // Synchronous reset to OFF
    input j,
    input k,
    output out); //  

    parameter OFF=0, ON=1; 
    reg state, next_state;

    always @(*) begin
        // State transition logic
        case (state)
            OFF: next_state = (j & ~k) ? ON : OFF;
            ON:  next_state = (~j & k) ? OFF : ON;
            // j=1, k=1 → toggle (handled in next_state update below)
        endcase

        // Optional: combine both conditions:
        if (j & k)
            next_state = ~state;
    end

    always @(posedge clk) begin
        // State flip-flops with synchronous reset
        if (reset)
            state <= OFF;
        else
            state <= next_state;
    end

    // Output logic
    // assign out = (state == ...);
	    assign out = state;
endmodule