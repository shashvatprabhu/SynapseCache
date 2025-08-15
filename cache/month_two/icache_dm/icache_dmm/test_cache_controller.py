import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_icache_controller(dut):
    """
    Updated testbench for the *new* icache_controller module.
    """

    clock = Clock(dut.clk, 10, units="ns")  # 100 MHz
    cocotb.start_soon(clock.start())

    async def reset():
        dut.reset.value = 1
        dut.CPU_READ.value = 0
        dut.CPU_ADDRESS.value = 0
        dut.MEM_BUSYWAIT.value = 0
        dut.MEM_READDATA.value = 0
        dut.MEM_READDATA_VALID.value = 0
        await Timer(20, units='ns')
        dut.reset.value = 0
        await RisingEdge(dut.clk)

    def make_address(tag, index, offset=0):
        # Assuming: offset=2 bits, index=5 bits, tag = rest
        return (tag << 7) | (index << 2) | offset

    await reset()

    # === 1. Cache Miss and Memory Read ===
    miss_addr = make_address(0x55, 0x02)
    expected_data = 0x12345678

    dut.CPU_ADDRESS.value = miss_addr
    dut.CPU_READ.value = 1

    await RisingEdge(dut.clk)
    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = expected_data
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    assert int(dut.CPU_INSTR.value) == expected_data, "❌ Test 1 Failed"
    cocotb.log.info("✅ Test 1 Passed")

    # === 2. Rapid Alternating Access ===
    alt_addr1 = make_address(0x66, 0x03)
    alt_addr2 = make_address(0x77, 0x03)

    dut.CPU_ADDRESS.value = alt_addr1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA.value = 0xAAAA5555
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    dut.CPU_ADDRESS.value = alt_addr2
    await RisingEdge(dut.clk)
    dut.MEM_READDATA.value = 0xBBBB6666
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    assert int(dut.CPU_INSTR.value) == 0xBBBB6666, "❌ Test 2 Failed"
    cocotb.log.info("✅ Test 2 Passed")

    # === 3. Eviction ===
    evict_addr1 = make_address(0x10, 0x04)
    evict_addr2 = make_address(0x20, 0x04)

    dut.CPU_ADDRESS.value = evict_addr1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA.value = 0xAAAA1111
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    dut.CPU_ADDRESS.value = evict_addr2
    await RisingEdge(dut.clk)
    dut.MEM_READDATA.value = 0xBBBB2222
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    assert int(dut.CPU_INSTR.value) == 0xBBBB2222, "❌ Test 3 Failed"
    cocotb.log.info("✅ Test 3 Passed")

    # === 4. Reset During Access ===
    mid_addr = make_address(0x33, 0x07)
    dut.CPU_ADDRESS.value = mid_addr
    dut.CPU_READ.value = 1
    await RisingEdge(dut.clk)

    dut.reset.value = 1
    dut.CPU_READ.value = 0
    await RisingEdge(dut.clk)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    assert dut.CPU_BUSYWAIT.value == 0, "❌ Test 4 Failed"
    cocotb.log.info("✅ Test 4 Passed")

    # === 5. Back-to-Back Misses ===
    addr1 = make_address(0x40, 0x10)
    addr2 = make_address(0x41, 0x11)

    dut.CPU_ADDRESS.value = addr1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA.value = 0x10001000
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    dut.CPU_ADDRESS.value = addr2
    await RisingEdge(dut.clk)
    dut.MEM_READDATA.value = 0x20002000
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    assert int(dut.CPU_INSTR.value) == 0x20002000, "❌ Test 5 Failed"
    cocotb.log.info("✅ Test 5 Passed")

    # === 6. Stall Handling ===
    stall_addr = make_address(0x12, 0x05)
    dut.CPU_ADDRESS.value = stall_addr

    dut.MEM_BUSYWAIT.value = 1
    for _ in range(4):
        await RisingEdge(dut.clk)
        assert dut.CPU_BUSYWAIT.value == 1, "❌ Test 6 Failed"

    dut.MEM_BUSYWAIT.value = 0
    dut.MEM_READDATA.value = 0xDEADBEEF
    dut.MEM_READDATA_VALID.value = 1
    await RisingEdge(dut.clk)
    dut.MEM_READDATA_VALID.value = 0
    await RisingEdge(dut.clk)

    assert int(dut.CPU_INSTR.value) == 0xDEADBEEF, "❌ Test 6 Failed"
    cocotb.log.info("✅ Test 6 Passed")

    cocotb.log.info("🎉 All cache controller tests passed ✅")
