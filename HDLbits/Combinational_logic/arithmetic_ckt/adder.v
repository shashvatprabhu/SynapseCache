// ideal solution

// module top_module (
// 	input [3:0] x,
// 	input [3:0] y,
// 	output [4:0] sum
// );

// 	// This circuit is a 4-bit ripple-carry adder with carry-out.
// 	assign sum = x+y;	// Verilog addition automatically produces the carry-out bit.

// 	// Verilog quirk: Even though the value of (x+y) includes the carry-out, (x+y) is still considered to be a 4-bit number (The max width of the two operands).
// 	// This is correct:
// 	// assign sum = (x+y);
// 	// But this is incorrect:
// 	// assign sum = {x+y};	// Concatenation operator: This discards the carry-out
// endmodule

module top_module (
    input [3:0] x,
    input [3:0] y, 
    output [4:0] sum);
    wire cin;
    wire [3:0] cout;
    fadd u0 (
        .a(x[0]),
        .b(y[0]),
        .cin(cin),
        .sum(sum[0]),
        .cout(cout[0])
    );

    fadd u1 (
        .a(x[1]),
        .b(y[1]),
        .cin(cout[0]),
        .sum(sum[1]),
        .cout(cout[1])
    );

    fadd u2 (
        .a(x[2]),
        .b(y[2]),
        .cin(cout[1]),
        .sum(sum[2]),
        .cout(cout[2])
    );
    
    fadd u3 (
        .a(x[3]),
        .b(y[3]),
        .cin(cout[2]),
        .sum(sum[3]),
        .cout(sum[4])
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

