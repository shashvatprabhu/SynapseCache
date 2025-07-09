module top_module (
    input clk,
    input x,
    output z
); 
    
    reg [2:0] Q;
    assign z = ~|Q;

    always @(posedge clk) begin
        Q[0] <= Q[0] ^ x;        
        Q[1] <= x & ~Q[1];      
        Q[2] <= x | ~Q[2];       
    end
   
endmodule