#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vicache_fifo_tb.h"  // ✅ Correct header name

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vicache_fifo_tb* top = new Vicache_fifo_tb;
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace(tfp, 99);
    tfp->open("wave.vcd");

    int time = 0;
    while (!Verilated::gotFinish() && time < 500) {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(time);
        time++;
    }

    tfp->close();
    delete top;
    return 0;
}
