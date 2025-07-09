module top_module ( 
   input clk, 
   input [7:0] d, 
   input [1:0] sel, 
   output [7:0] q 
);
   
   wire [7:0] i1;
   wire [7:0] i2;
   wire [7:0] i3;
   
   my_dff8 inst1 (clk, d, i1);
   my_dff8 inst2 (clk, i1, i2);
   my_dff8 inst3 (clk, i2, i3);
   
    always @(*)
        
           case (sel)
               2'b00 : q = d;
               2'b01 : q = i1;
               2'b10 : q = i2;
               2'b11 : q = i3;
           endcase 
   
endmodule