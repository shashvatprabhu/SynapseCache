`timescale 1ns/1ps

module icache_fifo_tb;

  // === PARAMETERS ===
  parameter ADDR_WIDTH = 32;
  parameter DATA_WIDTH = 32;
  parameter WORD_SIZE = 4;
  parameter BLOCK_SIZE = 1;
  parameter DEG_ASSOCIATIVITY = 1;
  parameter CAPACITY = 256;
  parameter NUM_WORDS = 1024;             // memory size
  parameter NUM_ACCESSES = 2000;          // number of test inputs

  // === INPUTS AND OUTPUTS ===
  reg clk, rst;
  reg [ADDR_WIDTH-1:0] instr_addr;
  reg [DATA_WIDTH-1:0] mem_instr;
  reg mem_instr_valid;

  wire [DATA_WIDTH-1:0] instr;
  wire hit, miss;
  wire [ADDR_WIDTH-1:0] mem_addr;
  wire mem_req;

  // === CACHE INSTANCE ===
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
    .mem_instr(mem_instr),
    .mem_instr_valid(mem_instr_valid),
    .mem_req(mem_req)
  );

  // === CLOCK GENERATION ===
  always #5 clk = ~clk;

  // === MEMORY SIMULATION ===
  reg [DATA_WIDTH-1:0] memory [0:NUM_WORDS-1];

  // === STATISTICS ===
  integer total_accesses = 0;
  integer total_hits = 0;
  integer total_misses = 0;

  // === RANDOM ACCESS LOOP ===
  integer i;
  reg [ADDR_WIDTH-1:0] rand_addr;

  initial begin
    // Initialization
    clk = 0;
    rst = 1;
    instr_addr = 0;
    mem_instr = 0;
    mem_instr_valid = 0;

    // Fill memory with dummy values
    for (i = 0; i < NUM_WORDS; i = i + 1)
      memory[i] = 32'h10000000 + i;

    #20;
    rst = 0;

    for (i = 0; i < NUM_ACCESSES; i = i + 1) begin
      // Random word-aligned address
      rand_addr = {$random} % (NUM_WORDS * WORD_SIZE);
      rand_addr = rand_addr & ~(WORD_SIZE - 1);
      instr_addr = rand_addr;

      #10;

      // Provide memory response if requested
      if (mem_req) begin
        mem_instr = memory[mem_addr >> 2];
        mem_instr_valid = 1;
        #10 mem_instr_valid = 0;
      end

      // Wait for hit/miss to register
      #10;
    end

    // Final delay and report
    #20;
    $display("\n=== CACHE PERFORMANCE REPORT ===");
    $display("Total Accesses : %0d", total_accesses);
    $display("Total Hits     : %0d", total_hits);
    $display("Total Misses   : %0d", total_misses);
    if (total_accesses > 0) begin
      $display("Hit Rate       : %0.2f%%", 100.0 * total_hits / total_accesses);
      $display("Miss Rate      : %0.2f%%", 100.0 * total_misses / total_accesses);
    end
    $display("==================================");
    $finish;
  end

  // === TRACK STATS ===
  always @(posedge clk) begin
    if (!rst) begin
      if (hit || miss) begin
        total_accesses = total_accesses + 1;
        if (hit)
          total_hits = total_hits + 1;
        else
          total_misses = total_misses + 1;

        $display("[%0t ns] Addr = 0x%08h | HIT = %b | MISS = %b | INSTR = 0x%08h",
                 $time, instr_addr, hit, miss, instr);
      end
    end
  end

endmodule
