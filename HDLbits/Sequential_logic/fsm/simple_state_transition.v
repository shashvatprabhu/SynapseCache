//

module top_module(
    input in,
    input [1:0] state,
    output reg [1:0] next_state,
    output reg out
); 
    parameter A = 2'b00, B = 2'b01, C = 2'b10, D = 2'b11;

    // State transition logic
    always @(*) begin
        case (state)
            A: next_state = in ? B : A;
            B: next_state = in ? B : C;
            C: next_state = in ? D : A;
            D: next_state = in ? B : C;
            default: next_state = A;
        endcase
    end

    // Moore output logic (depends only on state)
    always @(*) begin
        case (state)
            D: out = 1;
            default: out = 0;
        endcase
    end
endmodule

// module top_module(
//     input in,
//     input [1:0] state,
//     output [1:0] next_state,
//     output out); //

//     parameter A=0, B=1, C=2, D=3;
//     always @(*) begin
//         case (state)
//             A: next_state = (in) ? B : A;
//             B: next_state = (in) ? B : C;
//             C: next_state = (in) ? D : A;
//             D: next_state = (in) ? B : C;            
            
//         endcase
//         if((state==D))
//             out=1;
//         else out=0;
            
//     end
//     // State transition logic: next_state = f(state, in)

//     // Output logic:  out = f(state) for a Moore state machine

// endmodule