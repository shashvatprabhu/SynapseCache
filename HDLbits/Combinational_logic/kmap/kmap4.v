//
module top_module(
    input a,
    input b,
    input c,
    input d,
    output out  ); 
    wire p,q,r,s,t,u,v,w;
    and a1(p,~a,b,~c,~d);
    and a2(q,a,~b,~c,~d);
    and a3(r,~a,~b,~c,d);
    and a4(s,a,b,~c,d);
    and a5(t,~a,b,c,d);
    and a6(u,a,~b,c,d);
    and a7(v,~a,~b,c,~d);
    and a8(w,a,b,c,~d);
    or o1(out,p,q,r,s,t,u,v,w);
endmodule
