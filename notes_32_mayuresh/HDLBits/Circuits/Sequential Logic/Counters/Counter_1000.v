module top_module (
    input clk,
    input reset,
    output OneHertz,
    output [2:0] c_enable
);

    wire [3:0] bcd0, bcd1, bcd2;
    wire reset_all;
    
    assign reset_all = reset | (bcd0 == 4'd9 && bcd1 == 4'd9 && bcd2 == 4'd9);assign c_enable[0] = 1'b1;                          
    assign c_enable[1] = (bcd0 == 4'd9);                
    assign c_enable[2] = (bcd0 == 4'd9 && bcd1 == 4'd9);
    assign OneHertz = (bcd0 == 4'd9 && bcd1 == 4'd9 && bcd2 == 4'd9);

    bcdcount counter0 ( clk, reset_all, c_enable[0], bcd0);
    bcdcount counter1 ( clk, reset_all, c_enable[1], bcd1);
    bcdcount counter2 ( clk, reset_all, c_enable[2], bcd2);
    
endmodule