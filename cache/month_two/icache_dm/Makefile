TOPLEVEL_LANG = verilog
VERILOG_SOURCES = cache_controller.v 
TOPLEVEL = cache_controller
MODULE = test_cache_controller
SIM = verilator
export VERILATOR_TRACE=1
export COCOTB_LOG_LEVEL=INFO
export COCOTB_RESULTS_FILE=cocotb_results.xml

include $(shell cocotb-config --makefiles)/Makefile.sim