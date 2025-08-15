import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random

# Cache parameters
CACHE_BLOCK_SIZE = 1  # word/block
NUM_SETS = 4
ASSOCIATIVITY = 2
MEM_LATENCY = 10  # cycles to respond from memory

def extract_set_and_tag(addr):
    offset_bits = 0  # 1 word/block
    set_bits = NUM_SETS.bit_length() - 1
    set_index = (addr >> offset_bits) & ((1 << set_bits) - 1)
    tag = addr >> (offset_bits + set_bits)
    return set_index, tag

@cocotb.test()
async def test_cache_fsm(dut):
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    hits = 0
    misses = 0
    memory = {}  # simulated main memory

    accessed = []

    for i in range(20):
        addr = random.randint(0, 15)
        if i < 10:
            addr = addr & 0b1110  # increase chance of same set
        accessed.append(addr)
        print(f"\nAccess {i+1}: Requesting address 0x{addr:02x}")

        # Drive request
        dut.addr.value = addr
        dut.req.value = 1
        await RisingEdge(dut.clk)
        dut.req.value = 0

        # Wait for memory request
        while dut.mem_req.value == 0:
            await RisingEdge(dut.clk)

        miss_addr = dut.mem_addr.value.integer
        print(f"MISS detected for 0x{addr:02x}, requesting mem at 0x{miss_addr:02x}")
        misses += 1

        # Simulate memory delay and provide response
        for _ in range(MEM_LATENCY):
            dut.mem_ready.value = 0
            await RisingEdge(dut.clk)
        mem_data = (addr << 2) | 0xBEEF  # Dummy word
        memory[miss_addr] = mem_data
        dut.mem_data_in.value = mem_data
        dut.mem_ready.value = 1
        await RisingEdge(dut.clk)
        dut.mem_ready.value = 0

        # Wait for cache to finish update
        for _ in range(3):
            await RisingEdge(dut.clk)

    # Now verify pre-hit
    print("\nTesting a known pre-hit:")
    repeat_addr = accessed[5]
    dut.addr.value = repeat_addr
    dut.req.value = 1
    await RisingEdge(dut.clk)
    dut.req.value = 0

    await RisingEdge(dut.clk)
    if dut.hit.value:
        hits += 1
        print("✅ Pre-test hit confirmed")
    else:
        print("❌ Expected hit but got miss")

    hit_rate = hits / (hits + misses)
    print(f"\nFinal Hit Rate: {hit_rate*100:.2f}% ({hits} hits, {misses} misses)")
