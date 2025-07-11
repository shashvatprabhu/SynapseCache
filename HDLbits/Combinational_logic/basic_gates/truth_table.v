//

module top_module( 
    input x3,
    input x2,
    input x1,  // three inputs
    output f   // one output
);
wire w,z;
assign w = ~x3 & x2;
assign z = x3 & x1;
assign f = w | z;
endmodule