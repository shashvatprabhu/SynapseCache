//

module top_module (
    input clk,
    input reset, 
    output [3:1] ena,
    output [15:0] q
);

    wire [3:0] q0, q1, q2, q3;


    assign ena[1] = (q0 == 4'd9);                     
    assign ena[2] = (q1 == 4'd9) && (q0 == 4'd9);     
    assign ena[3] = (q2 == 4'd9) && (q1 == 4'd9) && (q0 == 4'd9); 

   
    bcdcount u0(clk, reset, 1'b1,   q0);  
    bcdcount u1(clk, reset, ena[1], q1);   
    bcdcount u2(clk, reset, ena[2], q2);  
    bcdcount u3(clk, reset, ena[3], q3);  

    assign q = {q3, q2, q1, q0}; 

endmodule

module bcdcount (
    input clk,
    input reset,
    input enable,
    output reg [3:0] Q
);

    always @(posedge clk) begin
        if (reset)
            Q <= 4'd0;
        else if (enable) begin
            if (Q == 4'd9)
                Q <= 4'd0;
            else
                Q <= Q + 1'b1;
        end
    end

endmodule

