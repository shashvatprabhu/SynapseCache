import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def test_cache_storage(dut):
    """
    Cocotb testbench for verifying single-word cache_storage module.
    """

    # Start a 100MHz clock
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    # Reset DUT
    dut.reset.value = 1
    dut.read.value = 0
    dut.write.value = 0
    dut.address.value = 0
    dut.write_block.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Test: Write to index 0, tag 0xAB, data 0xDEADBEEF")

    # Address: tag=0xAB, index=0
    address = (0xAB << 4) | 0x0  # assuming INDEX_BITS=4
    data = 0xDEADBEEF

    dut.address.value = address
    dut.write_block.value = data
    dut.write.value = 1
    await RisingEdge(dut.clk)
    dut.write.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("Test: Read back same address (expect hit)")

    dut.address.value = address
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)

    assert dut.hit.value == 1, "Expected cache hit"
    assert dut.read_data.value == data, f"Expected {hex(data)}, got {hex(int(dut.read_data.value))}"

    cocotb.log.info("Test: Read same index with different tag (expect miss)")

    address_miss = (0xCD << 4) | 0x0
    dut.address.value = address_miss
    dut.read.value = 1
    await RisingEdge(dut.clk)
    dut.read.value = 0
    await RisingEdge(dut.clk)

    assert dut.hit.value == 0, "Expected cache miss"

    cocotb.log.info("✅ All tests passed for single-word cache.")
