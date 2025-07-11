// module top_module( 
//     input [1023:0] in,
//     input [7:0] sel,
//     output [3:0] out );
//     integer i,j;
//     always @(*) begin
//         for(i=0;i<1024;i=i+4)begin
//             for(j=0;j<256;j=j+1)
//                 if(sel==j) begin
//                     out = {in[i+3],in[i+2],in[i+1],in[i]};
//                 end
//         end
//     end
// endmodule

// inefficient

module top_module( 
    input [1023:0] in,
    input [7:0] sel,
    output [3:0] out );
assign out = in[ (sel*4) +: 4 ];
endmodule

// [ (sel*4) +: 4 ] means sel*4 and the next 4 bits