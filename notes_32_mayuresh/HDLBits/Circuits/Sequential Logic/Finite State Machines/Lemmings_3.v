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
    
     parameter LEFT = 3'b000, RIGHT = 3'b001, LEFTFALL = 3'b010, RIGHTFALL = 3'b11, DIGLEFT = 3'b100, DIGRIGHT = 3'b101;
    reg [2:0] state, next_state;

    always @(*) begin
        case(state)
            LEFT : begin if(!ground) next_state = LEFTFALL;
            else begin if(dig) next_state = DIGLEFT;
                else begin if (bump_left) next_state = RIGHT;
                    else next_state = LEFT; end end end
            RIGHT : begin if(!ground) next_state = RIGHTFALL;
            else begin if (dig) next_state = DIGRIGHT;
                else begin if (bump_right) next_state = LEFT;
                    else next_state = RIGHT; end end end
            LEFTFALL : if(!ground) next_state = LEFTFALL;
                           else next_state = LEFT;
            RIGHTFALL : if(!ground) next_state = RIGHTFALL;
                              else next_state = RIGHT;
            DIGLEFT : if(ground) next_state = DIGLEFT;
                      else next_state = LEFTFALL;
            DIGRIGHT : if(ground) next_state = DIGRIGHT;
                      else next_state = RIGHTFALL;
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
    assign digging = (state == DIGLEFT | state == DIGRIGHT);

endmodule