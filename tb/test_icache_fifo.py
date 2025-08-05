import cocotb
from cocotb.triggers import RisingEdge, Timer
from cocotb.clock import Clock
import random

# Common parameters
ADDR_WIDTH = 32
DATA_WIDTH = 32
WORD_SIZE = 4
NUM_WORDS = 1024
NUM_ACCESSES = 50

# Simulated memory
memory = [0x10000000 + i for i in range(NUM_WORDS)]

async def reset_dut(dut):
    """Reset the DUT"""
    dut.rst.value = 1
    dut.instr_addr.value = 0
    dut.mem_instr.value = 0
    dut.mem_instr_valid.value = 0
    await Timer(20, units="ns")
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

async def test_config(dut):
    """Test the cache with parameters from DUT"""
    block_size = dut.BLOCK_SIZE.value.integer
    deg_associativity = dut.DEG_ASSOCIATIVITY.value.integer
    capacity = dut.CAPACITY.value.integer
    num_sets = capacity // (block_size * deg_associativity)
    byte_offset = 2  # log2(WORD_SIZE)
    block_offset = 0 if block_size == 1 else int.bit_length(block_size - 1)
    set_bits = int.bit_length(num_sets - 1) if num_sets > 1 else 1

    dut._log.info(f"\nTesting DEG_ASSOCIATIVITY={deg_associativity}, BLOCK_SIZE={block_size}, NUM_SETS={num_sets}")

    total_accesses = 0
    total_hits = 0
    total_misses = 0

    # Directed test: Sequential addresses
    dut._log.info("Running directed test: Sequential addresses")
    base_addr = random.randrange(0, NUM_WORDS * WORD_SIZE) & ~(WORD_SIZE - 1)
    for i in range(block_size * 2):
        addr = (base_addr + i * WORD_SIZE) & ~(WORD_SIZE - 1)
        dut.instr_addr.value = addr
        await RisingEdge(dut.clk)

        if dut.mem_req.value == 1:
            for w in range(block_size):
                await RisingEdge(dut.clk)
                mem_addr = dut.mem_addr.value + (w * WORD_SIZE)
                instr_data = memory[mem_addr >> 2] if mem_addr >> 2 < NUM_WORDS else 0xDEADBEEF
                dut.mem_instr.value = instr_data
                dut.mem_instr_valid.value = 1
                await RisingEdge(dut.clk)
                dut.mem_instr_valid.value = 0
            for _ in range(block_size + 2):
                await RisingEdge(dut.clk)
                if dut.mem_req.value == 0:
                    break
            else:
                dut._log.error(f"Timeout waiting for mem_req to deassert at addr 0x{addr:08x}")
                assert False, "Test failed due to timeout"

        await RisingEdge(dut.clk)
        total_accesses += 1
        if dut.hit.value == 1:
            total_hits += 1
            expected_instr = memory[addr >> 2]
            assert dut.instr.value == expected_instr, (
                f"Incorrect instruction at addr 0x{addr:08x}, "
                f"expected 0x{expected_instr:08x}, got 0x{dut.instr.value:08x}"
            )
            assert dut.stall.value == 0, f"Stall should be 0 on hit at addr 0x{addr:08x}"
        elif dut.miss.value == 1:
            total_misses += 1
            assert dut.stall.value == 1, f"Stall should be 1 on miss at addr 0x{addr:08x}"
            assert dut.state.value != 0, f"Expected non-IDLE state during miss at addr 0x{addr:08x}"

        dut._log.info(
            f"[Time {cocotb.utils.get_sim_time('ns'):.0f} ns] "
            f"Addr = 0x{addr:08x} | HIT = {dut.hit.value} | MISS = {dut.miss.value} | "
            f"INSTR = 0x{dut.instr.value:08x} | State = {dut.state.value} | Stall = {dut.stall.value}"
        )

    # Random test
    dut._log.info("Running random address test")
    for i in range(NUM_ACCESSES):
        addr = random.randrange(0, NUM_WORDS * WORD_SIZE) & ~(WORD_SIZE - 1)
        dut.instr_addr.value = addr
        await RisingEdge(dut.clk)

        if dut.mem_req.value == 1:
            for w in range(block_size):
                await RisingEdge(dut.clk)
                mem_addr = dut.mem_addr.value + (w * WORD_SIZE)
                instr_data = memory[mem_addr >> 2] if mem_addr >> 2 < NUM_WORDS else 0xDEADBEEF
                dut.mem_instr.value = instr_data
                dut.mem_instr_valid.value = 1
                await RisingEdge(dut.clk)
                dut.mem_instr_valid.value = 0
            for _ in range(block_size + 2):
                await RisingEdge(dut.clk)
                if dut.mem_req.value == 0:
                    break
            else:
                dut._log.error(f"Timeout waiting for mem_req to deassert at addr 0x{addr:08x}")
                assert False, "Test failed due to timeout"

        await RisingEdge(dut.clk)
        total_accesses += 1
        if dut.hit.value == 1:
            total_hits += 1
            expected_instr = memory[addr >> 2]
            assert dut.instr.value == expected_instr, (
                f"Incorrect instruction at addr 0x{addr:08x}, "
                f"expected 0x{expected_instr:08x}, got 0x{dut.instr.value:08x}"
            )
            assert dut.stall.value == 0, f"Stall should be 0 on hit at addr 0x{addr:08x}"
        elif dut.miss.value == 1:
            total_misses += 1
            assert dut.stall.value == 1, f"Stall should be 1 on miss at addr 0x{addr:08x}"
            assert dut.state.value != 0, f"Expected non-IDLE state during miss at addr 0x{addr:08x}"

        dut._log.info(
            f"[Time {cocotb.utils.get_sim_time('ns'):.0f} ns] "
            f"Addr = 0x{addr:08x} | HIT = {dut.hit.value} | MISS = {dut.miss.value} | "
            f"INSTR = 0x{dut.instr.value:08x} | State = {dut.state.value} | Stall = {dut.stall.value}"
        )

    # Directed test: Associativity test
    if deg_associativity > 1:
        dut._log.info("Running directed test: Associativity test")
        set_addr = random.randrange(0, num_sets) << (byte_offset + block_offset)
        for i in range(deg_associativity + 1):
            addr = (set_addr + (i << (byte_offset + block_offset))) & ~(WORD_SIZE - 1)
            dut.instr_addr.value = addr
            await RisingEdge(dut.clk)

            if dut.mem_req.value == 1:
                for w in range(block_size):
                    await RisingEdge(dut.clk)
                    mem_addr = dut.mem_addr.value + (w * WORD_SIZE)
                    instr_data = memory[mem_addr >> 2] if mem_addr >> 2 < NUM_WORDS else 0xDEADBEEF
                    dut.mem_instr.value = instr_data
                    dut.mem_instr_valid.value = 1
                    await RisingEdge(dut.clk)
                    dut.mem_instr_valid.value = 0
                for _ in range(block_size + 2):
                    await RisingEdge(dut.clk)
                    if dut.mem_req.value == 0:
                        break
                else:
                    dut._log.error(f"Timeout waiting for mem_req to deassert at addr 0x{addr:08x}")
                    assert False, "Test failed due to timeout"

            await RisingEdge(dut.clk)
            total_accesses += 1
            if dut.hit.value == 1:
                total_hits += 1
                expected_instr = memory[addr >> 2]
                assert dut.instr.value == expected_instr, (
                    f"Incorrect instruction at addr 0x{addr:08x}, "
                    f"expected 0x{expected_instr:08x}, got 0x{dut.instr.value:08x}"
                )
            elif dut.miss.value == 1:
                total_misses += 1
                assert dut.stall.value == 1, f"Stall should be 1 on miss at addr 0x{addr:08x}"
                assert dut.state.value != 0, f"Expected non-IDLE state during miss at addr 0x{addr:08x}"

            dut._log.info(
                f"[Time {cocotb.utils.get_sim_time('ns'):.0f} ns] "
                f"Addr = 0x{addr:08x} | HIT = {dut.hit.value} | MISS = {dut.miss.value} | "
                f"INSTR = 0x{dut.instr.value:08x} | State = {dut.state.value} | Stall = {dut.stall.value}"
            )

    # Performance report
    hit_rate = 100.0 * total_hits / total_accesses if total_accesses > 0 else 0
    miss_rate = 100.0 * total_misses / total_accesses if total_accesses > 0 else 0
    dut._log.info(f"\n=== CACHE PERFORMANCE REPORT (DEG_ASSOCIATIVITY={deg_associativity}, BLOCK_SIZE={block_size}) ===")
    dut._log.info(f"Total Accesses : {total_accesses}")
    dut._log.info(f"Total Hits     : {total_hits}")
    dut._log.info(f"Total Misses   : {total_misses}")
    dut._log.info(f"Hit Rate       : {hit_rate:.2f}%")
    dut._log.info(f"Miss Rate      : {miss_rate:.2f}%")
    dut._log.info("==================================")

@cocotb.test()
async def test_icache_fifo(dut):
    """Test the icache_fifo module with parameters defined in DUT"""
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    await reset_dut(dut)
    await test_config(dut)