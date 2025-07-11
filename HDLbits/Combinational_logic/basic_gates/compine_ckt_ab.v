//

module top_module (input x, input y, output z);
wire w,t,p,q;
    circuit_1 x1(x,y,w);
    mod_xnor x2(x,y,t);
    and a1(p,w,t);
    or a2(q,w,t);
    xor a3(z,p,q);
endmodule
    
module mod_xnor ( input x, input y, output z );
    xnor x1(z,x,y);
endmodule
    
    
module circuit_1 (input x, input y, output z);
    assign z = (x^y)&x;
endmodule