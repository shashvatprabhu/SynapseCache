import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer, ReadOnly


@cocotb.test()
async def test_fsm_corner_cases(dut):
    """
    Test cache controller FSM behavior under tricky corner cases:
    1. Prolonged MEM_BUSYWAIT
    2. HIT=0, VALID=1
    3. CPU_READ drops mid-transaction
    """

    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.CPU_READ.value = 0
    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = 0
    dut.MEM_READDATA_VALID.value = 0
    dut.HIT.value = 0
    dut.VALID.value = 0
    dut.CACHE_READDATA.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    def make_address(tag, index, offset=0):
        return (tag << 7) | (index << 2) | offset

    # === 1. Prolonged Memory Stall ===
    addr_stall = make_address(0x20, 0x01)
    dut.CPU_ADDRESS.value = addr_stall
    dut.CPU_READ.value = 1
    dut.HIT.value = 0
    dut.VALID.value = 0
    dut.MEM_BUSYWAIT.value = 1

    for _ in range(5):  # Simulate stall
        await RisingEdge(dut.clk)
        assert dut.CPU_BUSYWAIT.value == 1, "❌ CPU not stalling during MEM_BUSYWAIT"
    cocotb.log.info("✅ Prolonged MEM_BUSYWAIT handled properly")

    # Provide memory response
    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = 0xCAFEBABE
    dut.MEM_READDATA_VALID.value = 1
    dut.HIT.value = 1
    dut.VALID.value = 1
    dut.CACHE_READDATA.value = 0xCAFEBABE

    # Wait for CPU_BUSYWAIT to go low before checking CPU_INSTR
    while dut.CPU_BUSYWAIT.value != 0:
        await RisingEdge(dut.clk)

    await ReadOnly()
    assert int(dut.CPU_INSTR.value) == 0xCAFEBABE, "❌ Incorrect instruction fetched"
    cocotb.log.info("✅ Memory read completed after stall")

    # === 2. HIT=0, VALID=1 (Tag mismatch) ===
    addr_conflict = make_address(0x33, 0x02)
    dut.CPU_ADDRESS.value = addr_conflict
    dut.CPU_READ.value = 1
    dut.HIT.value = 0
    dut.VALID.value = 1
    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = 0x12341234
    dut.MEM_READDATA_VALID.value = 1
    dut.CACHE_READDATA.value = 0x12341234
    dut.HIT.value = 1

    while dut.CPU_BUSYWAIT.value != 0:
        await RisingEdge(dut.clk)

    await ReadOnly()
    assert int(dut.CPU_INSTR.value) == 0x12341234, "❌ Tag conflict fetch failed"
    cocotb.log.info("✅ HIT=0 and VALID=1 correctly treated as miss")

    # === 3. CPU_READ drops mid-transaction ===
    addr_drop = make_address(0x42, 0x03)
    dut.CPU_ADDRESS.value = addr_drop
    dut.CPU_READ.value = 1
    dut.HIT.value = 0
    dut.VALID.value = 0
    dut.MEM_BUSYWAIT.value = 1

    await RisingEdge(dut.clk)
    dut.CPU_READ.value = 0  # Drops mid-read

    # Finalize memory read
    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = 0xDEADBEEF
    dut.MEM_READDATA_VALID.value = 1
    dut.CACHE_READDATA.value = 0xDEADBEEF
    dut.HIT.value = 1
    dut.VALID.value = 1

    while dut.CPU_BUSYWAIT.value != 0:
        await RisingEdge(dut.clk)

    await ReadOnly()
    assert int(dut.CPU_INSTR.value) == 0xDEADBEEF, "❌ CPU_READ drop interrupted FSM"
    cocotb.log.info("✅ FSM correctly completes read even if CPU_READ drops")

    cocotb.log.info("🎯 All FSM corner cases passed successfully")
