//

module top_module (
    input clk,
    input j,
    input k,
    output Q); 
    always @(posedge clk) begin
        if(j&k)
            Q<=~Q;
        else if (~j&~k)
            Q<=Q;
        else if (~j&k)
            Q<=1'b0;
        else if (j&~k)
            Q<=1'b1;
    
    
    end
endmodule
