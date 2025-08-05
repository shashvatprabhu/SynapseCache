//

module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    input dig,
    output walk_left,
    output walk_right,
    output aaah,
    output digging ); 
    parameter LEFT=3'b000,RIGHT=3'b001,FALL_LEFT=3'b010,FALL_RIGHT=2'b011,DIG_LEFT=3'b100,DIG_RIGHT=3'b101;
    reg [2:0] state, next_state;
 always @(*) begin
        case (state)
            LEFT: begin
                if (!ground)
                    next_state = FALL_LEFT;
                else if (ground&&dig)
                    next_state = DIG_LEFT;
                else if (bump_left)
                    next_state = RIGHT;
                else
                    next_state = LEFT;
            end

            RIGHT: begin
                if (!ground)
                    next_state = FALL_RIGHT;
                else if (ground&&dig)
                    next_state = DIG_RIGHT;
                else if (bump_right)
                    next_state = LEFT;
                else
                    next_state = RIGHT;
            end

            FALL_LEFT: begin
                if (ground)
                    next_state = LEFT;
                else
                    next_state = FALL_LEFT;
            end

            FALL_RIGHT: begin
                if (ground)
                    next_state = RIGHT;
                else
                    next_state = FALL_RIGHT;
            end
            DIG_RIGHT: begin
                if (ground)
                    next_state=DIG_RIGHT;
                else 
                    next_state=FALL_RIGHT;
                end
            DIG_LEFT: begin
                if (ground)
                    next_state=DIG_LEFT;
                else 
                    next_state=FALL_LEFT;
            end
       
            default: next_state = LEFT;
        endcase
    end
    always @(posedge clk, posedge areset) begin
    if (areset)
            state <= LEFT;
        else
            state <= next_state;
    end
    always @(*) begin
        walk_left = 0;
        walk_right = 0;
        aaah = 0;
        digging = 0;
        case (state)
            LEFT: begin
                walk_left = 1;
            end
            RIGHT: begin
                walk_right = 1;
            end
            FALL_LEFT, FALL_RIGHT: begin
                aaah = 1;
            end
            DIG_LEFT,DIG_RIGHT: begin
            	digging = 1;
            end
        endcase
    end
endmodule
