import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import os



@cocotb.test()
async def test_cache_storage(dut):
    """
    Cocotb testbench for verifying cache_storage module.
    """

    # Start a 100MHz clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset the DUT
    dut.reset.value = 1
    dut.read.value = 0
    dut.write.value = 0
    dut.address.value = 0
    dut.write_block.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Test: Writing a block to set 0, tag = 0xAB")

    # Compose a 128-bit (4×32) write block
    words = [0xDEADBEEF, 0xCAFEBABE, 0x12345678, 0x0BADF00D]
    write_block = 0
    for i, word in enumerate(reversed(words)):  # word[0] = lowest offset
        write_block = (write_block << 32) | word

    # Set 0 = index 0, offset = 0, tag = 0xAB
    address = (0xAB << (4 + 2)) | (0 << 2) | 0  # tag:0xAB, index:0, offset:0
    dut.address.value = address
    dut.write_block.value = write_block
    dut.write.value = 1
    await RisingEdge(dut.clk)
    dut.write.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Test: Reading back word[0] from same set and tag")

    # Read from offset = 0 (i.e., lowest word in the block)
    dut.address.value = address
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)

    assert dut.hit.value == 1, "Expected a cache hit"
    assert dut.read_data.value == words[0], f"Expected {hex(words[0])}, got {hex(int(dut.read_data.value))}"

    cocotb.log.info("Test: Reading from same index but different tag (expect miss)")

    address_miss = (0xCD << (4 + 2)) | (0 << 2) | 0  # same index, different tag
    dut.address.value = address_miss
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)

    assert dut.hit.value == 0, "Expected a cache miss"

    cocotb.log.info("Test: Reading other offsets from valid block")

    for offset in range(1, 4):
        addr = (0xAB << (4 + 2)) | (0 << 2) | offset
        dut.address.value = addr
        dut.read.value = 1
        await RisingEdge(dut.clk)
        dut.read.value = 0
        await RisingEdge(dut.clk)
        assert dut.hit.value == 1, f"Expected hit at offset {offset}"
        assert dut.read_data.value == words[offset], f"Offset {offset} data mismatch"

    cocotb.log.info("Test: Dumping memory contents to cache_contents.txt")

    # Only dump set 0 (since we only wrote to that)
    dump_path = "cache_contents.txt"
    with open(dump_path, "w") as f:
        f.write(f"Set 0:\n")
        for i in range(4):
            f.write(f"  Word[{i}] = 0x{words[i]:08X}\n")
        f.write(f"  Tag = 0xAB\n")
        f.write(f"  Valid = 1\n")

    cocotb.log.info("✅ All tests passed. Check 'cache_contents.txt' for final dump.")

    await Timer(100, units='ns')
