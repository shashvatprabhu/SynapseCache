module top_module(
    input clk,
    input [7:0] in,
    input reset,    // Synchronous reset
    output [23:0] out_bytes,
    output done); //

    // FSM from fsm_ps2
    
    parameter B1 = 2'b00, B2 = 2'b01, B3 = 2'b10, D = 2'b11;
    
    reg [1:0] state, next_state; 
    reg [23:0] message;
  
    // State transition logic (combinational)
      
    always @(*) begin
        
        case(state) 
           B1 : if(in[3]) next_state = B2;
            else next_state = B1;
           B2 : next_state = B3;
           B3 : next_state = D;
            D : if(in[3]) next_state = B2;
                else next_state = B1;
            default : next_state = B1;
        endcase
        
    end
           
    // State flip-flops (sequential)
    
    always @(posedge clk) begin
        
        if(reset) begin
            state <= B1;
        end
        else begin
            state <= next_state;
        end
        
    end
 
    // Output logic
    
    assign done = (state == D);

    // New: Datapath to store incoming bytes.
    
    always @(posedge clk) begin
        
        if(reset) begin
            message <= 0;
        end
        else begin
            message <= {message[15:8], message[7:0], in[7:0]};
        end
    
    end
    
    assign out_bytes = (state == D) ? message : 0;
        
endmodule