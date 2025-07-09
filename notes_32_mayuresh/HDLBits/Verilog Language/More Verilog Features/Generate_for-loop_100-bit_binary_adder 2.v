module full_adder (
    input  wire a,
    input  wire b,
    input  wire cin,
    output wire sum,
    output wire cout
);
    assign sum  = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);
endmodule

module top_module( 
    input [99:0] a, b,
    input cin,
    output [99:0] cout,
    output [99:0] sum );
     
  wire [99:0] c;

    full_adder fa0 ( a[0], b[0], cin, sum[0], c[0] );

    assign cout[0] = c[0];
    
    genvar i;
    generate
        for (i = 1; i < 99; i = i + 1) begin : fa_loop
            full_adder fa ( a[i], b[i], c[i-1], sum[i], c[i] );
            assign cout[i] = c[i];
        end
    endgenerate
    
    full_adder fa99 ( a[99], b[99], c[98], sum[99], cout[99]);
    
endmodule