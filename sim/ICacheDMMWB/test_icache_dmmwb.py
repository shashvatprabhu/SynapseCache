import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random


@cocotb.test()
async def icache_test(dut):
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())

    dut.reset.value = 1
    dut.iready.value = 0
    dut.ifetch.value = 0
    dut.instraddress.value = 0

    await Timer(20, units='ns')
    await RisingEdge(dut.clk)
    dut.reset.value = 0
    await RisingEdge(dut.clk)

    testaddresses = [
        0x00000000,  # Miss
        0x00000004,  # Hit
        0x0000000C,  # Hit
        0x00000010,  # Miss (new set)
        0x00000014,  # Hit
        0x00000000,  # Hit
        0x00000100,  # Miss (new set)
        0x00000104,  # Hit
        0x00000200,  # Miss (new set)
        0x00000010   # Hit
    ]

    hitcount = 0
    misscount = 0
    accesses = 0

    for i, addr in enumerate(testaddresses):
        dut.instraddress.value = addr
        accesses += 1

        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)

        if dut.hit.value:
            hitcount += 1
            cocotb.log.info(f"[{i}] HIT at address 0x{addr:08X}, instruction = 0x{int(dut.instruction.value):08X}")
        else:
            misscount += 1
            fetch_addr = int(dut.fetchaddr.value)
            cocotb.log.info(f"[{i}] MISS at address 0x{addr:08X}, fetching block at 0x{fetch_addr:08X}")

            for j in range(4):
                dut.ifetch.value = int(f"0xAA{i:02X}{j:02X}00", 16)
                dut.iready.value = 1
                await RisingEdge(dut.clk)
                dut.iready.value = 0
                await RisingEdge(dut.clk)

            cocotb.log.info(f"[{i}] Block fetch complete.")

        await RisingEdge(dut.clk)

    hit_rate = (hitcount / accesses) * 100.0
    miss_rate = 100.0 - hit_rate
    cocotb.log.info(f"Total Accesses : {accesses}")
    cocotb.log.info(f"Total Hits : {hitcount}")
    cocotb.log.info(f"Total Misses : {misscount}")
    cocotb.log.info(f"Hit Rate : {hit_rate:.2f}%")
    cocotb.log.info(f"Miss Rate : {miss_rate:.2f}%")
