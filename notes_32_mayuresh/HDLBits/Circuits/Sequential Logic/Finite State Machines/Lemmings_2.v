module top_module(
    input clk,
    input areset,    // Freshly brainwashed Lemmings walk left.
    input bump_left,
    input bump_right,
    input ground,
    output walk_left,
    output walk_right,
    output aaah );
     
     parameter LEFT = 2'b00, RIGHT = 2'b01, LEFTFALL = 2'b10, RIGHTFALL = 2'b11;
     reg [1:0] state, next_state;

    always @(*) begin
        case(state)
            LEFT : if(!ground) next_state = LEFTFALL;
            else begin if (bump_left) next_state = RIGHT;
                else next_state = LEFT; end
            RIGHT : if(!ground) next_state = RIGHTFALL;
            else begin if (bump_right) next_state = LEFT;
                else next_state = RIGHT; end
            LEFTFALL : if(!ground) next_state = LEFTFALL;
                           else next_state = LEFT;
            RIGHTFALL : if(!ground) next_state = RIGHTFALL;
                              else next_state = RIGHT;
        endcase
    end

    always @(posedge clk, posedge areset) begin
        if(areset) begin
            state <= LEFT;
        end
        else begin
            state <= next_state;
        end
    end

    assign walk_left = (state == LEFT);
    assign walk_right = (state == RIGHT);
    assign aaah = (state == LEFTFALL | state == RIGHTFALL);

endmodule