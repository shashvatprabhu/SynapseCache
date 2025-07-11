//

module top_module( 
    input a, b,
    output cout, sum );
    xor(sum,a,b);
    and(cout,a,b);
endmodule
