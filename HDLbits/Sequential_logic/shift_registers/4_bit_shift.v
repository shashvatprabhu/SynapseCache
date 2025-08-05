// what is the difference bw

// q[3] <= 1'b0;
// q[2] <= q[3];
// q[1] <= q[2]; 
// q[0] <= q[1]; 

// q <= {1'b0, q[3:1]};

module top_module (
    input clk,
    input areset,       // asynchronous active-high reset
    input load,         // synchronous load
    input ena,          // shift enable
    input [3:0] data,   // input data for loading
    output reg [3:0] q  // shift register output
);

    always @(posedge clk or posedge areset) begin
        if (areset)
            q <= 4'b0000;                 // asynchronous reset
        else if (load)
            q <= data;                   // synchronous load (has priority)
        else if (ena)
q <= {1'b0, q[3:1]};

    end

endmodule
