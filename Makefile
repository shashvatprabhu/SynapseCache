SIM = verilator
TOPLEVEL = icache_fifo
VERILOG_SOURCES = rtl/icache_fifo.v
COCOTB_TOPLEVEL = icache_fifo
COCOTB_TEST_MODULES = test_icache_fifo

EXTRA_ARGS += --trace --trace-fst -o Vtop

.PHONY: all sim_clean

all:
	$(MAKE) sim SIM_BUILD=sim_build

sim_clean:
	rm -rf sim_build results.xml *.vcd *.fst

include $(shell cocotb-config --makefiles)/Makefile.sim