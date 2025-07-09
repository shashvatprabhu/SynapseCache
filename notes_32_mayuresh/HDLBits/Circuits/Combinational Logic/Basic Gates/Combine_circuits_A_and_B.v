module A (input a, input b, output c);
    assign c = (a^b) & a;
endmodule

module B (input a, input b, output c);
    assign c = ~(a^b);
    
endmodule

module top_module (input x, input y, output z);

  wire i1, i2, i3,i4;
    
    A IA1 (x, y, i1);
    B IB1 (x, y, i2);
    A IA2 (x, y, i3);
    B IB2 (x, y, i4);
    
    assign z = (i1|i2) ^ (i3&i4); 
       
endmodule