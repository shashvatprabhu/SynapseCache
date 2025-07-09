module top_module( 
    input [399:0] a, b,
    input cin,
    output cout,
    output [399:0] sum );
    
    wire [99:0] c;

    genvar i;
    generate
        for (i = 0; i < 100; i = i + 1) begin : bcd_adders
            if (i == 0) begin
                bcd_fadd adder (a[3:0], b[3:0], cin, c[0], sum[3:0]);
            end 
            else begin
                bcd_fadd adder ( a[4*i + 3 : 4*i],  b[4*i + 3 : 4*i], c[i - 1], c[i], sum[4*i + 3 : 4*i] );
            end
        end
    endgenerate

    assign cout = c[99]; 

endmodule