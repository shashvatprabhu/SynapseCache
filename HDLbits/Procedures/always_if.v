// Build a 2-to-1 mux that chooses between a and b. Choose b if both sel_b1 and sel_b2 are true. Otherwise, choose a. Do the same twice, once using assign statements and once using a procedural if statement. 

module top_module(
    input a,
    input b,
    input sel_b1,
    input sel_b2,
    output wire out_assign,
    output reg out_always   ); 
    assign out_assign = ({sel_b1,sel_b2} == 2'b11) ? b :
                   a ;
    always @(*)
        if ({sel_b1,sel_b2} == 2'b11) begin
            out_always = b;
        end
    else begin
        out_always = a;
    end
            

endmodule