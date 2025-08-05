import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random

@cocotb.test()
async def test_cache_storage(dut):
    """
    Cocotb testbench for set-associative cache_storage module.
    """

    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.read.value = 0
    dut.write.value = 0
    dut.address.value = 0
    dut.write_block.value = 0
    dut.way_select.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    words = [0xDEADBEEF]
    way = 0
    index = 0
    tag = 0x1A

    # Encode address: tag = 0x1A, index = 0, offset = 0
    address = (tag << 2) | (index << 0)
    dut.address.value = address
    dut.write_block.value = words[0]
    dut.way_select.value = way
    dut.write.value = 1
    await RisingEdge(dut.clk)
    dut.write.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Test: Read from matching tag in same way (expect hit)")
    dut.address.value = address
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)
    assert dut.hit.value == 1, "Expected cache hit"
    assert dut.read_data.value == words[0], f"Expected {hex(words[0])}, got {hex(int(dut.read_data.value))}"

    cocotb.log.info("Test: Read with tag mismatch (expect miss)")
    bad_address = ((tag + 1) << 2) | (index << 0)
    dut.address.value = bad_address
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)
    assert dut.hit.value == 0, "Expected cache miss"

    cocotb.log.info("Test: Write to other way and verify isolation")
    way = 1
    tag = 0x2B
    new_word = 0xBEEFDEAD
    address = (tag << 2) | (index << 0)
    dut.address.value = address
    dut.write_block.value = new_word
    dut.way_select.value = way
    dut.write.value = 1
    await RisingEdge(dut.clk)
    dut.write.value = 0
    await RisingEdge(dut.clk)

    dut.address.value = address
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)
    assert dut.hit.value == 1, "Expected hit on second way"
    assert dut.read_data.value == new_word, f"Way-1 data mismatch"

    cocotb.log.info("Test: Read from first way again")
    old_address = (0x1A << 2) | (index << 0)
    dut.address.value = old_address
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)
    assert dut.hit.value == 1, "Expected hit on original way"
    assert dut.read_data.value == 0xDEADBEEF, "Original data mismatch"

    cocotb.log.info("✅ All tests passed.")
    with open("cache_contents.txt", "w") as f:
        f.write("Way 0:\n  Tag = 0x1A\n  Data = 0xDEADBEEF\n")
        f.write("Way 1:\n  Tag = 0x2B\n  Data = 0xBEEFDEAD\n")
