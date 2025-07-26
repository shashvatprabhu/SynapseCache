`timescale 1ns/1ps
`default_nettype none

module icache_dm_tb;

    reg clk;
    reg reset;
    reg [31:0] ifetch; 
    reg [31:0] instraddress;
    reg iready; 
    wire [31:0] instruction; 
    wire hit;
    wire miss;
    wire [31:0] fetchaddr;

    integer i;
    integer hitcount = 0;
    integer misscount = 0;
    integer accesses = 0;

    reg [31:0] testaddresses [0:6];

    icache_dm i1 (
        .clk(clk),
        .reset(reset),
        .ifetch(ifetch), 
        .instraddress(instraddress),
        .iready(iready), 
        .instruction(instruction), 
        .hit(hit),
        .miss(miss),
        .fetchaddr(fetchaddr)
    );

    initial begin
    $dumpfile("icache_dm_tb.vcd");
    $dumpvars(0, icache_dm_tb);
end

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end 

    initial begin
      testaddresses[0] = 32'h00000008; // Should be a Compulsory Miss
      testaddresses[1] = 32'h00000008; //  SJhould be a Hit
      testaddresses[2] = 32'h00000009; // Should be a Miss due to conflict
      testaddresses[3] = 32'h00000009; // Should be a Hit
      testaddresses[4] = 32'h0000000C; // Should be a Compulsory Miss
      testaddresses[5] = 32'h0000000E; // Should be a Miss due to conflict
      testaddresses[6] = 32'h0000000E; // Should be a Hit

        reset = 1;
        ifetch = 32'h00000000;
        iready = 0;
        instraddress = 32'h00000000;

        #10 reset = 0;

        for (i = 0; i < 7; i = i + 1) begin
            instraddress = testaddresses[i];
            ifetch = 32'h10000000 + i;
            iready = 0;
            accesses = accesses + 1;

            $display("Address: 0x%08X",instraddress);

            @(posedge clk);
            @(posedge clk);

            if (hit) begin
                hitcount = hitcount + 1;
                $display("Hit");
            end else begin
                misscount = misscount + 1;
                $display("Miss");
              $display("Fetched Address = 0x%08X", fetchaddr);

                @(posedge clk);
                iready = 1;
                @(posedge clk);
                iready = 0;
                @(posedge clk);
              $display("Instruction added");
            end
        end

        $display("Total Accesses :  %0d", accesses);
        $display("Total Hits     :  %0d", hitcount);
        $display("Total Misses   :  %0d", misscount);
        $display("Hit Rate       :  %0.2f%%", (hitcount * 100.0) / accesses);
        $display("Miss Rate      :  %0.2f%%", (misscount * 100.0) / accesses);

        $finish;
    end

endmodule