import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


@cocotb.test()
async def icache_dm_test(dut):
    """Testbench for icache_dm"""

    clock = Clock(dut.clk, 10, units="ns")
    cocotb.fork(clock.start())

    dut.reset.value = 1
    dut.ifetch.value = 0
    dut.instraddress.value = 0
    dut.iready.value = 0

    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    dut.reset.value = 0
    await RisingEdge(dut.clk)

    testaddresses = [
        0x00000008,  # Compulsory Miss
        0x00000008,  # Hit
        0x00000009,  # Hit
        0x0000000B,  # Hit
        0x0000000C,  # Compulsory Miss
        0x0000000E,  # Hit
        0x0000000E,  # Hit
    ]

    hitcount = 0
    misscount = 0
    accesses = 0

    for i, addr in enumerate(testaddresses):
        dut.instraddress.value = addr
        dut.ifetch.value = 0x10000000 + i
        dut.iready.value = 0
        accesses += 1

        cocotb.log.info(f"Address: 0x{addr:08X}")

        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)

        if dut.hit.value == 1:
            hitcount += 1
            cocotb.log.info("Hit")
        else:
            misscount += 1
            cocotb.log.info("Miss")
            cocotb.log.info(f"Fetched Address = 0x{int(dut.fetchaddr.value):08X}")

            await RisingEdge(dut.clk)
            dut.iready.value = 1
            await RisingEdge(dut.clk)
            dut.iready.value = 0
            await RisingEdge(dut.clk)

            cocotb.log.info("Instruction added")

    cocotb.log.info(f"Total Accesses :  {accesses}")
    cocotb.log.info(f"Total Hits     :  {hitcount}")
    cocotb.log.info(f"Total Misses   :  {misscount}")

    hit_rate = (hitcount * 100.0) / accesses if accesses > 0 else 0.0
    miss_rate = (misscount * 100.0) / accesses if accesses > 0 else 0.0

    cocotb.log.info(f"Hit Rate       :  {hit_rate:.2f}%")
    cocotb.log.info(f"Miss Rate      :  {miss_rate:.2f}%")
