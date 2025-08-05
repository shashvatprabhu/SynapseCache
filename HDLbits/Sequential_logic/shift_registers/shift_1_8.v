// very repetitive

// can be improved using case statement


// always @(posedge clk) begin
//         if (load)
//             q <= data;
//         else if (ena) begin
//             case (amount)
//                 2'b00: q <= q << 1;
//                 2'b01: q <= q << 8;
//                 2'b10: q <= {q[63], q[63:1]};           // arithmetic right shift by 1
//                 2'b11: q <= {{8{q[63]}}, q[63:8]};       // arithmetic right shift by 8
//             endcase
//         end
//     end

module top_module(
    input clk,
    input load,
    input ena,
    input [1:0] amount,
    input [63:0] data,
    output reg [63:0] q); 
always @(posedge clk) begin
	if (load)
        q <= data;
    else if (ena&(q[63]==1)) begin
        if(amount==2'b00) begin     
            q <= {q[62:0],1'b0};
        end
        if(amount==2'b01) begin     
            q <= {q[55:0],8'h00};
        end
        if(amount==2'b10) begin     
            q <= {1'b1, q[63:1]};
        end
        if(amount==2'b11) begin                 
            q <= {8'hFF, q[63:8]};
        end
    end
    else if (ena&(q[63]==0)) begin
        if(amount==2'b00) begin     
            q <= {q[62:0],1'b0};
        end
        if(amount==2'b01) begin     
            q <= {q[55:0],8'h00};
        end
        if(amount==2'b10) begin
            q <= {1'b0, q[63:1]};

        end
        if(amount==2'b11) begin     

            q <= {8'h00, q[63:8]};
        end
    end
end
endmodule
