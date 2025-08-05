//

module top_module(
    input clk,
    input reset,
    input ena,
    output reg pm,
    output reg [7:0] hh,
    output reg [7:0] mm,
    output reg [7:0] ss
);

// Internal BCD digit access
wire [3:0] ss0 = ss[3:0];    // seconds units
wire [3:0] ss1 = ss[7:4];    // seconds tens
wire [3:0] mm0 = mm[3:0];    // minutes units
wire [3:0] mm1 = mm[7:4];    // minutes tens
wire [3:0] hh0 = hh[3:0];    // hours units
wire [3:0] hh1 = hh[7:4];    // hours tens

always @(posedge clk) begin
    if (reset) begin
        ss <= 8'h00;    // 00
        mm <= 8'h00;    // 00
        hh <= 8'h12;    // 12
        pm <= 1'b0;     // AM
    end else if (ena) begin
        // Seconds
        if (ss0 == 4'd9) begin
            ss[3:0] <= 4'd0;
            if (ss1 == 4'd5) begin
                ss[7:4] <= 4'd0;

                // Minutes
                if (mm0 == 4'd9) begin
                    mm[3:0] <= 4'd0;
                    if (mm1 == 4'd5) begin
                        mm[7:4] <= 4'd0;

                        // Hours
                        if (hh == 8'h11) begin
                            hh <= 8'h12;
                            pm <= ~pm;
                        end else if (hh == 8'h12) begin
                            hh <= 8'h01;
                        end else if (hh0 == 4'd9) begin
                            hh[3:0] <= 4'd0;
                            hh[7:4] <= hh1 + 4'd1;
                        end else begin
                            hh[3:0] <= hh0 + 4'd1;
                        end

                    end else begin
                        mm[7:4] <= mm1 + 4'd1;
                    end
                end else begin
                    mm[3:0] <= mm0 + 4'd1;
                end

            end else begin
                ss[7:4] <= ss1 + 4'd1;
            end
        end else begin
            ss[3:0] <= ss0 + 4'd1;
        end
    end
end

endmodule
