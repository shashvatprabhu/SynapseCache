//

module top_module (
    input [7:0] a, b, c, d,
    output [7:0] min);//
    assign min = ((b>a)&(c>a)&(d>a)) ? a:
        ((c>b)&(a>b)&(d>b)) ? b:
        ((d>c)&(a>c)&(b>c)) ? c :
        d;
endmodule