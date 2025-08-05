//

module top_module (
    input clk,
    input resetn,   // synchronous reset
    input in,
    output out);
wire w1,w2,w3;
    dff_r d1(clk, resetn, in, w1);
    dff_r d2(clk, resetn, w1, w2);
    dff_r d3(clk, resetn, w2, w3);
    dff_r d4(clk, resetn, w3, out);    
endmodule

module dff_r (
    input clk,
    input resetn,
    input d,
    output q);
    
    always @(posedge clk) begin
        if(~resetn)
            q<=1'b0;
        else
            q<=d;
    
    
    end
endmodule