//

module top_module( 
    input [15:0] a, b, c, d, e, f, g, h, i,
    input [3:0] sel,
    output [15:0] out );
    assign out = (sel==4'b0000)?a:
        (sel==4'b0001)?b:
        (sel==4'b0010)?c:
        (sel==4'b0011)?d:
        (sel==4'b0100)?e:
        (sel==4'b0101)?f:
        (sel==4'b0110)?g:
        (sel==4'b0111)?h:
        (sel==4'b1000)?i:
    {16{1'b1}};
// or 16'hFFFF;
endmodule
