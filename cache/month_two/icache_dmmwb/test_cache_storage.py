import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_cache_storage(dut):
    """
    Cocotb testbench for verifying classic Verilog cache_storage module with burst block support.
    """

    # Create a 100MHz clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset
    dut.reset.value = 1
    dut.read.value = 0
    dut.write.value = 0
    dut.address.value = 0
    dut.write_block.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    # Prepare a 128-bit write block (4 words, 32-bit each)
    words = [0xDEADBEEF, 0xCAFEBABE, 0x12345678, 0x0BADF00D]
    write_block = 0
    for word in reversed(words):  # MSB = word[3], LSB = word[0]
        write_block = (write_block << 32) | word

    cocotb.log.info("Test: Writing burst block with tag=0xAB to index=0")

    # Address: tag = 0xAB, index = 0, offset = 0
    address = (0xAB << 6) | (0 << 2) | 0
    dut.address.value = address
    dut.write_block.value = write_block
    dut.write.value = 1
    await RisingEdge(dut.clk)
    dut.write.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Test: Reading back all 4 words from same block")

    for offset in range(4):
        addr = (0xAB << 6) | (0 << 2) | offset
        dut.address.value = addr
        dut.read.value = 1
        await RisingEdge(dut.clk)
        dut.read.value = 0
        await RisingEdge(dut.clk)

        assert dut.hit.value == 1, f"Expected hit at offset {offset}"
        assert dut.read_data.value == words[offset], f"Data mismatch at offset {offset}"

    cocotb.log.info("Test: Reading from same index but different tag – expect miss")

    addr_miss = (0xCD << 6) | (0 << 2) | 0
    dut.address.value = addr_miss
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)

    assert dut.hit.value == 0, "Expected miss for different tag"

    cocotb.log.info("✅ All cache_storage tests passed.")
    await Timer(50, units="ns")
