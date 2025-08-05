//

module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    output walk_left,
    output walk_right); //  
parameter LEFT=0, RIGHT = 1;
    // parameter LEFT=0, RIGHT=1, ...
    reg state, next_state;

    always @(*) begin
        case (state)
            LEFT: next_state = (bump_left) ? RIGHT : LEFT;
            RIGHT: next_state = (bump_right) ? LEFT : RIGHT;

        endcase
    end

    always @(posedge clk, posedge areset) begin
    if (areset)
            state <= LEFT;
        else
            state <= next_state;
    
   // State flip-flops with asynchronous reset
    end
    always @(state) begin
        if(state)begin
            walk_left=0;
        	walk_right=1;
        end else begin
            walk_right=0;
            walk_left=1;
        end
    end 
    // Output logic
    // assign walk_left = (state == ...);
    // assign walk_right = (state == ...);

endmodule
