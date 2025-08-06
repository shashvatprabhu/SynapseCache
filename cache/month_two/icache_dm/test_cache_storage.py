import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random


@cocotb.test()
async def test_cache_storage_stress_with_reuse(dut):
    """
    Stress test with increased hit probability by reusing past write addresses.
    """

    INDEX_BITS = 8
    TAG_BITS = 20
    WORD_WIDTH = 32
    NUM_ITERATIONS = 1000
    REUSE_PROBABILITY = 0.9  # 60% chance to reuse a past write

    def make_address(tag, index):
        return (tag << INDEX_BITS) | index

    # Reference model
    cache_model = {}
    written_addresses = []  # (tag, index, data)

    # Init
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.read.value = 0
    dut.write.value = 0
    dut.address.value = 0
    dut.write_block.value = 0
    await Timer(20, units="ns")
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    cocotb.log.info("🚀 Starting stress test with reuse")

    hit_count = 0
    miss_count = 0

    for i in range(NUM_ITERATIONS):
        is_write = random.choice([True, False])

        if is_write or not written_addresses or random.random() > REUSE_PROBABILITY:
            # Generate a fresh random tag/index
            tag = random.randint(0, (1 << TAG_BITS) - 1)
            index = random.randint(0, (1 << INDEX_BITS) - 1)
            data = random.getrandbits(WORD_WIDTH)
        else:
            # Reuse previous write address (to increase hit chance)
            tag, index, data = random.choice(written_addresses)

        address = make_address(tag, index)
        dut.address.value = address

        if is_write:
            # Perform write
            dut.write.value = 1
            dut.write_block.value = data
            await RisingEdge(dut.clk)
            dut.write.value = 0
            await RisingEdge(dut.clk)

            cache_model[index] = (True, tag, data)
            written_addresses.append((tag, index, data))

            cocotb.log.info(f"[{i:03}] WRITE tag=0x{tag:X}, idx={index:02}, data=0x{data:08X}")

        else:
            # Perform read
            dut.read.value = 1
            await RisingEdge(dut.clk)
            dut.read.value = 0
            await RisingEdge(dut.clk)

            valid, expected_tag, expected_data = cache_model.get(index, (False, 0, 0))
            if valid and expected_tag == tag:
                assert dut.hit.value == 1, f"[{i:03}] ❌ Expected hit, got miss"
                assert dut.read_data.value == expected_data, (
                    f"[{i:03}] ❌ Data mismatch! Expected 0x{expected_data:08X}, got {hex(int(dut.read_data.value))}"
                )
                hit_count += 1
                cocotb.log.info(f"[{i:03}] READ ✅ HIT tag=0x{tag:X}, idx={index:02}, data=0x{expected_data:08X}")
            else:
                assert dut.hit.value == 0, f"[{i:03}] ❌ Expected miss, got hit"
                miss_count += 1
                cocotb.log.info(f"[{i:03}] READ ✅ MISS tag=0x{tag:X}, idx={index:02}")

    total = hit_count + miss_count
    cocotb.log.info(f"\n📊 Total Accesses: {total}")
    cocotb.log.info(f"✅ Hits : {hit_count} ({(hit_count / total) * 100:.2f}%)")
    cocotb.log.info(f"❌ Misses : {miss_count} ({(miss_count / total) * 100:.2f}%)\n")

    cocotb.log.info("🎉 Stress test with reuse completed ✅")
