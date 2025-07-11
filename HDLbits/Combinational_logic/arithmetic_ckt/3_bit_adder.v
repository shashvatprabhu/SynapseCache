// is there a way to use loops, gervar, generate

module top_module( 
    input [2:0] a, b,
    input cin,
    output [2:0] cout,
    output [2:0] sum );

    wire c1, c2;

    fadd u0 (
        .a(a[0]),
        .b(b[0]),
        .cin(cin),
        .sum(sum[0]),
        .cout(cout[0])
    );

    fadd u1 (
        .a(a[1]),
        .b(b[1]),
        .cin(cout[0]),
        .sum(sum[1]),
        .cout(cout[1])
    );

    fadd u2 (
        .a(a[2]),
        .b(b[2]),
        .cin(cout[1]),
        .sum(sum[2]),
        .cout(cout[2])
    );

endmodule

module fadd( 
    input a, b, cin,
    output cout, sum );
    
    wire ab_xor, ab_and, xor_and;

    xor x1(ab_xor, a, b);
    and a1(ab_and, a, b);
    and a2(xor_and, ab_xor, cin);
    xor x2(sum, ab_xor, cin);
    or o1(cout, ab_and, xor_and);

endmodule