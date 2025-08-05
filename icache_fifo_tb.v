`timescale 1ns/1ps
`default_nettype none

module icache_fifo_tb;

    parameter ADDR_WIDTH = 32;
    parameter DATA_WIDTH = 32;
    parameter WORD_SIZE = 4;
    parameter BLOCK_SIZE = 1;
    parameter DEG_ASSOCIATIVITY = 1;
    parameter CAPACITY = 256;
    parameter NUM_WORDS = 1024;
    parameter NUM_ACCESSES = 500;

    reg clk, rst;
    reg [ADDR_WIDTH-1:0] instr_addr;
    reg [DATA_WIDTH-1:0] mem_instr;
    reg mem_instr_valid;
    wire [DATA_WIDTH-1:0] instr;
    wire hit, miss;
    wire [ADDR_WIDTH-1:0] mem_addr;
    wire mem_req;

    icache_fifo #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .WORD_SIZE(WORD_SIZE),
        .BLOCK_SIZE(BLOCK_SIZE),
        .DEG_ASSOCIATIVITY(DEG_ASSOCIATIVITY),
        .CAPACITY(CAPACITY)
    ) uut (
        .clk(clk),
        .rst(rst),
        .instr_addr(instr_addr),
        .instr(instr),
        .hit(hit),
        .miss(miss),
        .mem_addr(mem_addr),
        .mem_req(mem_req),
        .mem_instr(mem_instr),
        .mem_instr_valid(mem_instr_valid)
    );

    reg [DATA_WIDTH-1:0] memory [0:NUM_WORDS-1];
    integer total_hits = 0;
    integer total_misses = 0;
    integer total_accesses = 0;
    reg [ADDR_WIDTH-1:0] last_addr;

    integer cycle = 0;
    integer i = 0;
    reg [7:0] state = 0;
    integer j;

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        for (j = 0; j < NUM_WORDS; j = j + 1)
            memory[j] = 32'hA000_0000 + j;

        $display("Starting simulation...");
    end

    always @(posedge clk) begin
        cycle <= cycle + 1;

        case (state)
            0: begin
                rst <= 1;
                instr_addr <= 0;
                mem_instr <= 0;
                mem_instr_valid <= 0;
                state <= 1;
            end

            1: begin
                if (cycle >= 10) begin
                    rst <= 0;
                    state <= 2;
                end
            end

            2: begin
                if (i < NUM_ACCESSES) begin
                    instr_addr <= ({$random} % (NUM_WORDS * WORD_SIZE)) & ~(WORD_SIZE - 1);
                    last_addr <= instr_addr;
                    state <= 3;
                end else begin
                    state <= 10;
                end
            end

            3: begin
                if (mem_req) begin
                    mem_instr <= memory[mem_addr >> 2];
                    mem_instr_valid <= 1;
                    state <= 4;
                end else begin
                    state <= 5;
                end
            end

            4: begin
                mem_instr_valid <= 0;
                state <= 5;
            end

            5: begin
                if (hit || miss) begin
                    total_accesses <= total_accesses + 1;
                    if (hit) total_hits <= total_hits + 1;
                    else total_misses <= total_misses + 1;

                    $display("[%0t ns] Addr = 0x%08h | HIT = %b | MISS = %b | INSTR = 0x%08h",
                             $time, instr_addr, hit, miss, instr);

                    i <= i + 1;
                    state <= 2;
                end
            end

            10: begin
                $display("\n=== CACHE PERFORMANCE ===");
                $display("Total Accesses : %0d", total_accesses);
                $display("Total Hits     : %0d", total_hits);
                $display("Total Misses   : %0d", total_misses);
                $display("Hit Rate       : %0.2f%%", 100.0 * total_hits / total_accesses);
                $display("Miss Rate      : %0.2f%%", 100.0 * total_misses / total_accesses);
                $display("==================================");
                $finish;
            end
        endcase
    end

endmodule
