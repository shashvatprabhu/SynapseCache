module top_module(
    input clk,
    input in,
    input areset,
    output out); //
    
    parameter A = 0, B = 1, C = 2, D = 3;
    reg [1:0] state, next_state;
    
    // State transition logic
    always @(*) begin
        case(state)
            A : if(in) next_state = B;
                else next_state = A;
            B : if(in) next_state = B;
                else next_state = C;
            C : if(in) next_state = D;
                else next_state = A;
            D : if(in) next_state = B;
                else next_state = C;
        endcase
    end

    // State flip-flops with asynchronous reset
    always @(posedge clk, posedge areset) begin
        if(areset) begin
            state <= A;
        end else begin
            state <= next_state;
        end
    end

    // Output logic
    assign out = (state == D);

endmodule