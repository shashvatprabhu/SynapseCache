//

module top_module( 
    input a, b, cin,
    output cout, sum );
wire z,y,x;
    xor x1(z,a,b);
    and a1(y,a,b);
    and a2(x,z,cin);
    xor x2(sum,z,cin);
    or o1(cout,y,x);
endmodule
