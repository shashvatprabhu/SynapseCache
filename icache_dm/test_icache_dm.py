"""
Professional Test Bench for Direct-Mapped Instruction Cache
Target: icache module (Direct-mapped, single-word block)
Framework: cocotb
Author: Cache Verification Team
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
from cocotb.result import TestFailure
import random
import math

class CacheMetrics:
    """Professional metrics collection and analysis class"""
    
    def __init__(self, cache_size=1024):
        self.cache_size = cache_size
        self.reset_metrics()
    
    def reset_metrics(self):
        self.total_requests = 0
        self.total_hits = 0
        self.total_misses = 0
        self.compulsory_misses = 0
        self.conflict_misses = 0
        self.capacity_misses = 0
        self.evictions = 0
        self.memory_requests = 0
        self.accessed_addresses = set()
        self.cache_state = {}  # Track what's in cache
        self.access_history = []
        
    def record_access(self, address, hit, miss, evict, mem_req):
        self.total_requests += 1
        self.access_history.append({'addr': address, 'hit': hit, 'miss': miss})
        
        if hit:
            self.total_hits += 1
        
        if miss:
            self.total_misses += 1
            self._classify_miss(address)
            
        if evict:
            self.evictions += 1
            
        if mem_req:
            self.memory_requests += 1
    
    def _classify_miss(self, address):
        """Classify miss type for direct-mapped cache"""
        cache_index = (address >> 2) % self.cache_size
        
        if address not in self.accessed_addresses:
            # First access to this address - compulsory miss
            self.compulsory_misses += 1
            self.accessed_addresses.add(address)
        elif cache_index in self.cache_state:
            # Cache line occupied by different address - conflict miss
            self.conflict_misses += 1
        else:
            # Should not happen in direct-mapped, but count as capacity
            self.capacity_misses += 1
        
        # Update cache state (simplified model)
        self.cache_state[cache_index] = address
    
    def get_hit_rate(self):
        return (self.total_hits / self.total_requests * 100) if self.total_requests > 0 else 0
    
    def get_miss_rate(self):
        return (self.total_misses / self.total_requests * 100) if self.total_requests > 0 else 0
    
    def get_memory_traffic_ratio(self):
        return (self.memory_requests / self.total_requests) if self.total_requests > 0 else 0
    
    def generate_report(self, test_name):
        """Generate professional test report"""
        report = f"\n{'='*60}\n"
        report += f"CACHE PERFORMANCE REPORT - {test_name.upper()}\n"
        report += f"{'='*60}\n"
        report += f"Total Requests:      {self.total_requests:8d}\n"
        report += f"Cache Hits:          {self.total_hits:8d}\n"
        report += f"Cache Misses:        {self.total_misses:8d}\n"
        report += f"Hit Rate:            {self.get_hit_rate():8.2f}%\n"
        report += f"Miss Rate:           {self.get_miss_rate():8.2f}%\n"
        report += f"{'='*60}\n"
        report += f"MISS CLASSIFICATION:\n"
        report += f"Compulsory Misses:   {self.compulsory_misses:8d}\n"
        report += f"Conflict Misses:     {self.conflict_misses:8d}\n"
        report += f"Capacity Misses:     {self.capacity_misses:8d}\n"
        report += f"{'='*60}\n"
        report += f"MEMORY TRAFFIC ANALYSIS:\n"
        report += f"Memory Requests:     {self.memory_requests:8d}\n"
        report += f"Traffic Ratio:       {self.get_memory_traffic_ratio():8.2f}\n"
        report += f"Cache Evictions:     {self.evictions:8d}\n"
        report += f"{'='*60}\n"
        return report

class CacheTestBench:
    """Professional test bench controller"""
    
    def __init__(self, dut):
        self.dut = dut
        self.metrics = CacheMetrics()
        self.mem_latency = 10  # Memory access latency in cycles
        
    async def reset_cache(self):
        """Reset cache and initialize signals"""
        self.dut.rst_n.value = 0
        self.dut.cpu_req.value = 0
        self.dut.cpu_addr.value = 0
        self.dut.mem_data.value = 0
        self.dut.mem_ready.value = 0
        
        await RisingEdge(self.dut.clk)
        await RisingEdge(self.dut.clk)
        
        self.dut.rst_n.value = 1
        await RisingEdge(self.dut.clk)
        
        self.metrics.reset_metrics()
    
    async def memory_model(self):
        """Simple memory model with configurable latency"""
        mem_delay_counter = 0
        
        while True:
            await RisingEdge(self.dut.clk)
            
            if self.dut.mem_req.value == 1 and mem_delay_counter == 0:
                mem_delay_counter = self.mem_latency
                self.dut.mem_ready.value = 0
                # Generate deterministic data based on address
                addr = int(self.dut.mem_addr.value)
                self.dut.mem_data.value = (addr & 0xFFFFFFFF) ^ 0xDEADBEEF
            
            if mem_delay_counter > 0:
                mem_delay_counter -= 1
                if mem_delay_counter == 0:
                    self.dut.mem_ready.value = 1
            else:
                self.dut.mem_ready.value = 0
    
    async def single_access(self, address):
        """Perform single cache access and collect metrics"""
        self.dut.cpu_req.value = 1
        self.dut.cpu_addr.value = address
        
        # Wait for response
        cycles = 0
        while True:
            await RisingEdge(self.dut.clk)
            cycles += 1
            
            hit = int(self.dut.cache_hit.value)
            miss = int(self.dut.cache_miss.value)
            evict = int(self.dut.cache_evict.value)
            mem_req = int(self.dut.mem_req.value)
            
            if hit or miss:
                self.metrics.record_access(address, hit, miss, evict, mem_req)
                break
                
            if cycles > 100:  # Timeout protection
                raise TestFailure("Access timeout")
        
        self.dut.cpu_req.value = 0
        await RisingEdge(self.dut.clk)
        return cycles

@cocotb.test()
async def test_basic_functionality(dut):
    """Test 1: Basic Functionality and Cold Start Behavior"""
    
    # Initialize
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Basic Functionality Test")
    
    # Test cold start - first access should always miss
    test_addresses = [0x1000, 0x1004, 0x2000, 0x3000]
    
    for addr in test_addresses:
        await tb.single_access(addr)
    
    # Test immediate re-access - should hit
    for addr in test_addresses:
        await tb.single_access(addr)
    
    report = tb.metrics.generate_report("Basic Functionality")
    dut._log.info(report)
    
    # Verify basic expectations
    assert tb.metrics.total_requests == 8, f"Expected 8 requests, got {tb.metrics.total_requests}"
    assert tb.metrics.compulsory_misses == 4, f"Expected 4 compulsory misses, got {tb.metrics.compulsory_misses}"

@cocotb.test()
async def test_sequential_access_pattern(dut):
    """Test 2: Sequential Access Pattern Analysis"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Sequential Access Pattern Test")
    
    # Sequential access pattern
    base_addr = 0x1000
    num_accesses = 64
    
    for i in range(num_accesses):
        addr = base_addr + (i * 4)
        await tb.single_access(addr)
    
    report = tb.metrics.generate_report("Sequential Access Pattern")
    dut._log.info(report)

@cocotb.test()
async def test_hot_spot_access(dut):
    """Test 3: Hot Spot Access Pattern"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Hot Spot Access Test")
    
    # Create hot spot - repeatedly access small set of addresses
    hot_addresses = [0x1000, 0x1004, 0x1008, 0x100C]
    
    # Access hot spot multiple times
    for _ in range(10):
        for addr in hot_addresses:
            await tb.single_access(addr)
    
    report = tb.metrics.generate_report("Hot Spot Access")
    dut._log.info(report)

@cocotb.test()
async def test_conflict_miss_pattern(dut):
    """Test 4: Conflict Miss Analysis"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Conflict Miss Test")
    
    # Create addresses that map to same cache line (conflict)
    cache_size = 1024
    base_addr1 = 0x1000
    base_addr2 = base_addr1 + (cache_size * 4)  # Same index, different tag
    
    # Alternating access to conflicting addresses
    for i in range(20):
        await tb.single_access(base_addr1)
        await tb.single_access(base_addr2)
    
    report = tb.metrics.generate_report("Conflict Miss Pattern")
    dut._log.info(report)

@cocotb.test()
async def test_cache_capacity_stress(dut):
    """Test 5: Cache Capacity and Stress Test"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Cache Capacity Stress Test")
    
    # Access more addresses than cache can hold
    cache_size = 1024
    base_addr = 0x1000
    
    # Fill entire cache
    for i in range(cache_size):
        addr = base_addr + (i * 4)
        await tb.single_access(addr)
    
    # Access beyond cache capacity (should cause evictions)
    for i in range(cache_size, cache_size + 100):
        addr = base_addr + (i * 4)
        await tb.single_access(addr)
    
    report = tb.metrics.generate_report("Cache Capacity Stress")
    dut._log.info(report)

@cocotb.test()
async def test_replacement_and_eviction(dut):
    """Test 6: Replacement and Eviction Analysis"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Replacement and Eviction Test")
    
    # Fill specific cache lines then cause replacements
    test_index = 100
    addr1 = (test_index << 2) + 0x1000
    addr2 = (test_index << 2) + 0x1000 + (1024 * 4)  # Same index
    
    # Initial access
    await tb.single_access(addr1)
    
    # Access different address with same index (causes eviction)
    await tb.single_access(addr2)
    
    # Re-access first address (should miss due to eviction)
    await tb.single_access(addr1)
    
    report = tb.metrics.generate_report("Replacement and Eviction")
    dut._log.info(report)

@cocotb.test()
async def test_random_access_pattern(dut):
    """Test 7: Random Access Pattern"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Random Access Pattern Test")
    
    # Generate deterministic random pattern
    random.seed(42)
    num_accesses = 100
    
    for _ in range(num_accesses):
        addr = random.randint(0x1000, 0x10000) & 0xFFFFFFFC  # Word-aligned
        await tb.single_access(addr)
    
    report = tb.metrics.generate_report("Random Access Pattern")
    dut._log.info(report)

@cocotb.test()
async def test_performance_characterization(dut):
    """Test 8: Comprehensive Performance Analysis"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Performance Characterization Test")
    
    # Mixed workload: sequential + hot spot + random
    total_cycles = 0
    
    # Sequential phase
    for i in range(50):
        addr = 0x2000 + (i * 4)
        cycles = await tb.single_access(addr)
        total_cycles += cycles
    
    # Hot spot phase
    hot_addresses = [0x1000, 0x1004, 0x1008]
    for _ in range(20):
        for addr in hot_addresses:
            cycles = await tb.single_access(addr)
            total_cycles += cycles
    
    # Calculate average access time
    avg_access_time = total_cycles / tb.metrics.total_requests if tb.metrics.total_requests > 0 else 0
    
    report = tb.metrics.generate_report("Performance Characterization")
    report += f"TIMING ANALYSIS:\n"
    report += f"Total Cycles:        {total_cycles:8d}\n"
    report += f"Average Access Time: {avg_access_time:8.2f} cycles\n"
    report += f"{'='*60}\n"
    
    dut._log.info(report)

@cocotb.test()
async def test_final_summary(dut):
    """Test 9: Final Summary and Edge Cases"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Starting Final Summary Test")
    
    # Edge case: Address boundary testing
    edge_addresses = [
        0x00000000,  # Minimum address
        0xFFFFFFFC,  # Maximum word-aligned address
        0x00001000,  # Typical address
        0x80000000,  # Mid-range address
    ]
    
    for addr in edge_addresses:
        await tb.single_access(addr)
    
    report = tb.metrics.generate_report("Edge Cases and Final Summary")
    dut._log.info(report)
    
    # Final verification
    dut._log.info("DIRECT-MAPPED CACHE VERIFICATION COMPLETE")
    dut._log.info("All test patterns executed successfully")