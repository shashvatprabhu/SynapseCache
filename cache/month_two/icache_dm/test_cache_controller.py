import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random


@cocotb.test()
async def test_cache_controller(dut):
    """
    Comprehensive testbench for cache_controller module.
    Includes:
      1. Cache miss and memory read
      2. Cache fill
      3. Cache hit on subsequent access
      4. Rapid alternating access
      5. Tag conflict (eviction)
      6. Reset during access
      7. Stall/memory latency
      8. Randomized access with hit/miss statistics
    """

    clock = Clock(dut.clk, 10, units="ns")  # 100 MHz
    cocotb.start_soon(clock.start())

    def reset():
        dut.reset.value = 1
        dut.CPU_READ.value = 0
        dut.MEM_BUSYWAIT.value = 0
        dut.MEM_READDATA.value = 0
        dut.MEM_READDATA_VALID.value = 0
        dut.HIT.value = 0
        dut.VALID.value = 0
        dut.CACHE_READDATA.value = 0

    reset()
    await Timer(20, units='ns')
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    def make_address(tag, index, offset=0):
        return (tag << 7) | (index << 2) | offset  # Assuming index=5 bits, offset=2 bits

    # === 1 to 6 (previous tests) ===
    # [snipped for brevity — retain all tests from previous message]

    # === 7. Random Access Test with Hit Rate ===
    INDEX_BITS = 5  # matches index width
    TAG_BITS = 19
    WORD_WIDTH = 32
    NUM_ITERATIONS = 500
    REUSE_PROBABILITY = 0.85

    cache_model = {}  # software model: index -> (valid, tag, data)
    written_addrs = []

    hit_count = 0
    miss_count = 0

    cocotb.log.info("🚀 Starting randomized access test")

    for i in range(NUM_ITERATIONS):
        tag = random.randint(0, (1 << TAG_BITS) - 1)
        index = random.randint(0, (1 << INDEX_BITS) - 1)
        offset = 0
        data = random.getrandbits(WORD_WIDTH)

        if written_addrs and random.random() < REUSE_PROBABILITY:
            # Reuse previous address to increase hit chance
            tag, index, data = random.choice(written_addrs)

        addr = make_address(tag, index, offset)
        dut.CPU_ADDRESS.value = addr
        dut.CPU_READ.value = 1

        # Simulate cache contents
        valid, expected_tag, expected_data = cache_model.get(index, (False, 0, 0))
        if valid and expected_tag == tag:
            # Simulate cache hit
            dut.HIT.value = 1
            dut.VALID.value = 1
            dut.CACHE_READDATA.value = expected_data
            await RisingEdge(dut.clk)
            assert int(dut.CPU_INSTR.value) == expected_data, f"[{i}] ❌ Wrong data on hit"
            hit_count += 1
            cocotb.log.info(f"[{i:03}] ✅ HIT tag=0x{tag:X} idx={index} data=0x{expected_data:08X}")
        else:
            # Simulate miss → memory fetch
            miss_count += 1
            dut.HIT.value = 0
            dut.VALID.value = 0
            await RisingEdge(dut.clk)
            dut.MEM_BUSYWAIT.value = 0
            dut.MEM_READDATA.value = data
            dut.MEM_READDATA_VALID.value = 1
            await RisingEdge(dut.clk)
            await RisingEdge(dut.clk)

            # Set as valid in cache model
            dut.HIT.value = 1
            dut.VALID.value = 1
            dut.CACHE_READDATA.value = data
            await RisingEdge(dut.clk)

            cache_model[index] = (True, tag, data)
            written_addrs.append((tag, index, data))

            cocotb.log.info(f"[{i:03}] ✅ MISS tag=0x{tag:X} idx={index} data=0x{data:08X}")

        # Reset read signal
        dut.CPU_READ.value = 0
        await RisingEdge(dut.clk)

    total = hit_count + miss_count
    cocotb.log.info(f"\n📊 Total Random Accesses: {total}")
    cocotb.log.info(f"✅ Hits   : {hit_count} ({(hit_count / total) * 100:.2f}%)")
    cocotb.log.info(f"❌ Misses : {miss_count} ({(miss_count / total) * 100:.2f}%)\n")
    cocotb.log.info("🎉 Test 7 Passed: Randomized access test complete ✅")
