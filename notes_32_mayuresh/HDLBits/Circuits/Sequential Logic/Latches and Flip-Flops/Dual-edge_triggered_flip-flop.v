module top_module (
    input clk,
    input d,
    output q
);
    
  reg q1, q2;
    
    assign q = q1^q2;
    
    always @ (posedge clk)
        begin
            q1 <= d ^ q2;
        end
    
    always @ (negedge clk)
        begin
           q2 <= d ^ q1; 
        end

reg p, n;
	
	/* A positive-edge triggered flip-flop
    always @(posedge clk)
         p <= d ^ n;
        
    A negative-edge triggered flip-flop
    always @(negedge clk)
        n <= d ^ p;
    
     Why does this work? 
     After posedge clk, p changes to d^n. Thus q = (p^n) = (d^n^n) = d.
     After negedge clk, n changes to d^p. Thus q = (p^n) = (p^d^p) = d.
     At each (positive or negative) clock edge, p and n FFs alternately
     load a value that will cancel out the other and cause the new value of d to remain.
      assign q = p ^ n;
    
    
	Can't synthesize this.
	always @(posedge clk, negedge clk) begin
		q <= d;
	end */

endmodule