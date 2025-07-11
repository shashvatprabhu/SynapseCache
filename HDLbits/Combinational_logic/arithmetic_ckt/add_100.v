//

module top_module( 
    input [99:0] a, b,
    input cin,
    output cout,
    output [99:0] sum );

    wire [100:0] result;
    assign result = a + b + cin;
    assign sum = result[99:0];
    assign cout = result[100];

endmodule