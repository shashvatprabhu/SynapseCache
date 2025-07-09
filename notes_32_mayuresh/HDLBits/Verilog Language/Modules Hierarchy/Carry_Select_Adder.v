module top_module(
   input [31:0] a,
   input [31:0] b,
   output [31:0] sum
);
    
   wire cout1;
   wire cout2;
   wire cout20, cout21;
   wire [15:0] s1;
   wire [15:0] s2;
   
   add16 inst1 (a[15:0], b[15:0], 1'b0, sum[15:0], cout1);
   add16 inst2 (a[31:16], b[31:16], 0, s1[15:0], cout20);
   add16 inst3 (a[31:16], b[31:16], 1, s2[15:0], cout21);
   
    always @(*)
        
        case(cout1)
            
            1'b0 :  sum[31:16] = s1[15:0];
            1'b1 :  sum[31:16] = s2[15:0];
            
        endcase
    
endmodule