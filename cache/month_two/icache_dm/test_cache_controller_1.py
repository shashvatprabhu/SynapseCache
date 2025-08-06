import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_cache_controller(dut):
    """
    Testbench for cache_controller module. This testbench simulates:
    - Cache miss and memory read
    - Cache fill
    - Cache hit on subsequent access
    """

    # Start clock
    clock = Clock(dut.clk, 10, units="ns")  # 100MHz
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.CPU_READ.value = 0
    await Timer(20, units='ns')
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # ---- Step 1: Simulate cache miss ----
    test_address = 0xABCD0040  # Any address
    expected_data = 0x12345678

    dut.CPU_READ.value = 1
    dut.CPU_ADDRESS.value = test_address
    dut.HIT.value = 0
    dut.VALID.value = 0
    dut.CACHE_READDATA.value = 0

    await RisingEdge(dut.clk)
    cocotb.log.info(f"Step 1: Simulate cache miss and memory read | CPU_BUSYWAIT={int(dut.CPU_BUSYWAIT.value)}")

    # ---- Step 2: Respond with memory data ----
    await RisingEdge(dut.clk)
    cocotb.log.info(f"Step 2: Updating cache...")

    # Simulate memory responding with data
    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = expected_data
    dut.MEM_READDATA_VALID.value = 1  # optional if unused

    await RisingEdge(dut.clk)

    # FSM goes to UPDATE_CACHE → WAIT_READ

    # ---- Step 3: Simulate cache hit ----
    await RisingEdge(dut.clk)  # FSM in WAIT_READ
    dut.HIT.value = 1
    dut.VALID.value = 1
    dut.CACHE_READDATA.value = expected_data  # what the cache would now hold

    await RisingEdge(dut.clk)  # back to IDLE

    cocotb.log.info(f"Step 3: Simulate cache hit | CPU_BUSYWAIT={int(dut.CPU_BUSYWAIT.value)} INSTR={int(dut.CPU_INSTR.value):08X}")

    assert int(dut.CPU_INSTR.value) == expected_data, "❌ Cache hit did not return correct instruction"
    cocotb.log.info("✅ Test passed: Cache hit returned correct instruction.")
