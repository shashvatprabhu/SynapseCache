//

module top_module (
    input in1,
    input in2,
    input in3,
    output out);
wire w;
    xnor xn1(w,in1,in2);
    xor x1(out,w,in3);
endmodule