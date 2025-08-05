//

module top_module(
    input clk,
    input areset,    // Asynchronous reset to OFF (state = 0)
    input j,
    input k,
    output out
);  
    parameter OFF=0, ON=1;
    reg state, next_state;

    // State transition logic (combinational)
    always @(*) begin
        case (state)
            OFF: next_state = (j & ~k) ? ON : OFF;
            ON:  next_state = (~j & k) ? OFF : ON;
            // j=1, k=1 → toggle (handled in next_state update below)
        endcase

        // Optional: combine both conditions:
        if (j & k)
            next_state = ~state;
    end

    // State register with asynchronous reset
    always @(posedge clk or posedge areset) begin
        if (areset)
            state <= OFF;
        else
            state <= next_state;
    end

    // Output logic (Moore output)
    assign out = state;

endmodule
