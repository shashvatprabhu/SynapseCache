// Build a circuit that has one 3-bit input, then outputs the same vector, and also splits it into three separate 1-bit outputs. Connect output o0 to the input vector's position 0, o1 to position 1, etc. 

module top_module ( 
    input wire [2:0] vec,
    output wire [2:0] outv,
    output wire o2,
    output wire o1,
    output wire o0  );
    assign outv[2:0] = vec[2:0];
    assign o0 = vec[0];
    assign o1 = vec[1];
    assign o2 = vec[2];
endmodule