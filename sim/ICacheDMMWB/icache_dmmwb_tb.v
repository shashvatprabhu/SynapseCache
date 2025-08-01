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

 
    icache_dmmwb #(.CACHESIZE(1024),.WORDSPERBLOCK(4)) i1 (
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

    integer i;
    integer hitcount = 0;
    integer misscount = 0;
    integer accesses = 0;

    reg [31:0] testaddresses [0:9]; 
 
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        $dumpfile("icache_dm_tb.vcd");
        $dumpvars(0, icache_dm_tb);
    end

    initial begin

        testaddresses[0] = 32'h00000000; // Should be a Compulsory Miss
        testaddresses[1] = 32'h00000004; // Should be a Hit as in block
        testaddresses[2] = 32'h0000000C; // Should be a Hit as in block
        testaddresses[3] = 32'h00000010; // Should be a Compulsory Miss as new set 
        testaddresses[4] = 32'h00000014; // Should be a Hit as in block
        testaddresses[5] = 32'h00000000; // Should be a Hit
        testaddresses[6] = 32'h00000100; // Should be a Compulsory Miss as new set 
        testaddresses[7] = 32'h00000104; // Should be a Hit as in the block
        testaddresses[8] = 32'h00000200; // Should be a Compulsory Miss as new set
        testaddresses[9] = 32'h00000010; // Should be a Hit

        reset = 1;
        iready = 0;
        ifetch = 32'h0;
        instraddress = 32'h0;
        #20 reset = 0;

        @(posedge clk);

        for (i = 0; i < 10; i = i + 1) begin
            instraddress = testaddresses[i];
            accesses = accesses + 1;

            $display("Access %0d: Addr = 0x%08X", i, instraddress);

            @(posedge clk); 
            @(posedge clk); 

            if (hit) begin
                hitcount = hitcount + 1;
                $display("HIT. Instruction = 0x%08X", instruction);
            end else begin
                misscount = misscount + 1;
                $display("MISS. Fetching block at address 0x%08X", fetchaddr);

      
                for (int j = 0; j < 4; j = j + 1) begin
           
                    ifetch = {8'hAA, i[7:0], j[7:0], 8'h00};
                    iready = 1;
                    @(posedge clk);
                    iready = 0;
                    @(posedge clk);
                end

                $display("Block fetch complete.");
            end

            @(posedge clk);
        end

        $display("Total Accesses : %0d", accesses);
        $display("Total Hits : %0d", hitcount);
        $display("Total Misses : %0d", misscount);
        $display("Hit Rate : %0.2f%%", (hitcount * 100.0) / accesses);
        $display("Miss Rate : %0.2f%%", (misscount * 100.0) / accesses);

        $finish;
    end

endmodule
