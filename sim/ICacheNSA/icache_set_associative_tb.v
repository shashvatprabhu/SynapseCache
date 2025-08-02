`timescale 1ns/1ps
`default_nettype none

module icache_set_associative_tb;

    localparam CACHESIZE = 1024;     
    localparam BLOCKSIZE = 4;      
    localparam ASSOCIATIVITY = 2;    

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

    icache_set_associative #(
        .CACHESIZE(CACHESIZE),
        .BLOCKSIZE(BLOCKSIZE),
        .ASSOCIATIVITY(ASSOCIATIVITY)
    ) i1 (
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


    function [31:0] mem_read(input [31:0] addr);
        mem_read = {8'hAA, addr[23:0]};
    endfunction

    initial begin
        $dumpfile("icache_set_associative_tb.vcd");
        $dumpvars(0, icache_set_associative_tb);
    end

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
     
        testaddresses[0] = 32'h00000010; // should be a compulsory miss
        testaddresses[1] = 32'hAA000010; // should be a compulsory miss as same set different tag different way
        testaddresses[2] = 32'h00000010; // should be a compulsory hit
        testaddresses[3] = 32'hAA000010; // should be a compulsory hit
        testaddresses[4] = 32'hBB000010; // should be a miss as set full
        testaddresses[5] = 32'hBB000010; // should now be a hit
        testaddresses[6] = 32'h00000010; // should be a miss because evicted as it was oldest instr by FIFO

        reset = 1;
        iready = 0;
        ifetch = 0;
        instraddress = 0;

        #20 reset = 0;
        #10;

        for (i = 0; i < 7; i = i + 1) begin
            instraddress = testaddresses[i];
            accesses = accesses + 1;
            $display("---------------------------------------------------");
            $display("Access %0d: Address = 0x%08X", accesses, instraddress);

            @(posedge clk); // allow hit/miss to update
            @(posedge clk); // allow cache to go into miss_pending if needed

            if (hit) begin
                hitcount = hitcount + 1;
                $display("Hit! Instruction = 0x%08X", instruction);
            end else begin
                misscount = misscount + 1;
                $display("Miss. Fetching from memory @ 0x%08X", fetchaddr);

                // wait one more clock to allow cache to go into miss_pending state
                @(posedge clk);
                ifetch = mem_read(fetchaddr);
                iready = 1;

                @(posedge clk);
                iready = 0;

                @(posedge clk);
                $display("Memory returned: 0x%08X", ifetch);
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
