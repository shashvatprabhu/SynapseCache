// Note the Verilog-1995 module declaration syntax here:
module top_module(clk, reset, in, out);
    input clk;
    input reset;    // Synchronous reset to state B
    input in;
    output out;//  
    reg out;

    // Fill in state name declarations
    parameter B = 0,A = 1;
    reg present_state, next_state;

    always @(posedge clk) begin
        if (reset) begin  
            present_state <= B;
        end else begin
            present_state <= next_state;
        end
    end
            
    always @(*) begin
           case (present_state)
                B : if(in) next_state = B;
                    else next_state = A;
                A : if(in) next_state = A;
                    else next_state = B;
                default : next_state = B;
            endcase
    end

    always @(*) begin
            case (present_state)
                B : out = 1;
                A : out = 0;
            endcase
    end

endmodule