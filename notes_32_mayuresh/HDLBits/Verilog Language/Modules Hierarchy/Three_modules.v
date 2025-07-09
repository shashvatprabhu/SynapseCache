module top_module ( input clk, input d, output q );
   
   wire i1;
   wire i2;
   
   my_dff inst1 (clk, d, i1);
   my_dff inst2 (clk, i1, i2);
   my_dff inst3 (clk, i2, q);

endmodule