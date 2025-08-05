//

module top_module(clk, reset, in, out);
    input clk;
    input reset;    // Synchronous reset to state B
    input in;
    output out;//  
    reg out;

    // Fill in state name declarations

    reg present_state, next_state;
	parameter A=0,B=1;
    always @(posedge clk) begin
        if (reset) begin  
            // Fill in reset logic
            present_state<=B;
            out<=B;
        end else begin
            case (present_state)
                A: next_state= in ? A:B;
                B: next_state= in ? B:A;
                // Fill in state transition logic
            endcase

            // State flip-flops
            present_state = next_state;   

            case (present_state)
                // Fill in output logic
                A: out<=A;
                B: out<=B;
            endcase
        end
    end

endmodule