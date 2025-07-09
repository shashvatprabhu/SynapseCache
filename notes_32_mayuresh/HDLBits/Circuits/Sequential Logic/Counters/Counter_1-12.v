module top_module (
    input clk,
    input reset,
    input enable,
    output [3:0] Q,
    output c_enable,
    output c_load,
    output [3:0] c_d
);
   
    always @(*) begin
        if (reset) begin
            c_load = 1'b1;
            c_enable = 1'b0;
            c_d= 4'd1;
        end else if (enable && Q == 12) begin
            c_load = 1'b1;
            c_enable = 1'b0;
            c_d = 4'd1;
        end else if (enable) begin
            c_load = 1'b0;
            c_enable = 1'b1;
            c_d = 4'd7;  
        end else begin
            c_load= 1'b0;
            c_enable = 1'b0;
            c_d = 4'd7;  
        end
    end
    
    count4 the_counter (clk, c_enable, c_load, c_d , Q);
    
endmodule