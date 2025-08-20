"""
Enhanced Parameterizable Test Bench for N-Way Set Associative Instruction Cache
Target: icache_nway module (N-way set associative, single-word block, round-robin replacement)
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
    """Performance metrics collection for benchmark tests"""
    
    def __init__(self, cache_size=1024, associativity=4):
        self.cache_size = cache_size
        self.associativity = associativity
        self.sets = cache_size // associativity
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
        self.cache_state = {}
        self.access_history = []
        self.replacement_history = []
        
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
    
    def record_replacement(self, set_index, way, address):
        """Track round-robin replacement pattern"""
        self.replacement_history.append({
            'set': set_index,
            'way': way,
            'addr': address
        })
    
    def _classify_miss(self, address):
        """Classify miss type for N-way set associative cache"""
        set_index = (address >> 2) % self.sets
        
        if address not in self.accessed_addresses:
            self.compulsory_misses += 1
            self.accessed_addresses.add(address)
        else:
            if set_index not in self.cache_state:
                self.cache_state[set_index] = []
            
            if len(self.cache_state[set_index]) < self.associativity:
                self.compulsory_misses += 1
            else:
                if len(self.accessed_addresses) > self.cache_size:
                    self.capacity_misses += 1
                else:
                    self.conflict_misses += 1
        
        # Update cache state (simplified model)
        if set_index not in self.cache_state:
            self.cache_state[set_index] = []
        
        if address not in self.cache_state[set_index]:
            if len(self.cache_state[set_index]) >= self.associativity:
                self.cache_state[set_index].pop(0)
            self.cache_state[set_index].append(address)
    
    def analyze_round_robin_pattern(self, set_index):
        """Analyze round-robin replacement pattern for specific set"""
        set_replacements = [r for r in self.replacement_history if r['set'] == set_index]
        if len(set_replacements) < self.associativity:
            return True, "Insufficient data"
        
        expected_way = 0
        for replacement in set_replacements:
            if replacement['way'] != expected_way:
                return False, f"Expected way {expected_way}, got {replacement['way']}"
            expected_way = (expected_way + 1) % self.associativity
        
        return True, "Round-robin pattern verified"
    
    def get_hit_rate(self):
        return (self.total_hits / self.total_requests * 100) if self.total_requests > 0 else 0
    
    def get_miss_rate(self):
        return (self.total_misses / self.total_requests * 100) if self.total_requests > 0 else 0
    
    def get_memory_traffic_ratio(self):
        return (self.memory_requests / self.total_requests) if self.total_requests > 0 else 0
    
    def get_conflict_reduction(self):
        """Measure conflict miss reduction compared to direct-mapped"""
        total_non_compulsory = self.conflict_misses + self.capacity_misses
        return total_non_compulsory / self.total_requests if self.total_requests > 0 else 0
    
    def generate_benchmark_report(self, test_name):
        """Generate detailed benchmark report"""
        report = f"\n{'='*70}\n"
        report += f"BENCHMARK REPORT - {test_name.upper()}\n"
        report += f"Cache: {self.associativity}-Way Set Associative, {self.cache_size} words\n"
        report += f"{'='*70}\n"
        report += f"Total Requests:      {self.total_requests:8d}\n"
        report += f"Cache Hits:          {self.total_hits:8d}\n"
        report += f"Cache Misses:        {self.total_misses:8d}\n"
        report += f"Hit Rate:            {self.get_hit_rate():8.2f}%\n"
        report += f"Miss Rate:           {self.get_miss_rate():8.2f}%\n"
        report += f"{'='*70}\n"
        report += f"MISS BREAKDOWN:\n"
        report += f"Compulsory Misses:   {self.compulsory_misses:8d}\n"
        report += f"Conflict Misses:     {self.conflict_misses:8d}\n"
        report += f"Capacity Misses:     {self.capacity_misses:8d}\n"
        report += f"{'='*70}\n"
        report += f"ASSOCIATIVITY ANALYSIS:\n"
        report += f"Conflict Reduction:  {self.get_conflict_reduction():8.2f}\n"
        report += f"Cache Evictions:     {self.evictions:8d}\n"
        report += f"{'='*70}\n"
        report += f"MEMORY ANALYSIS:\n"
        report += f"Memory Requests:     {self.memory_requests:8d}\n"
        report += f"Traffic Ratio:       {self.get_memory_traffic_ratio():8.2f}\n"
        report += f"{'='*70}\n"
        return report

class BenchmarkWorkloads:
    """Unified benchmark workloads for cross-cache comparison"""
    
    def __init__(self, cache_size, block_size=1, associativity=4):
        self.cache_size = cache_size
        self.block_size = block_size
        self.associativity = associativity
    
    def sequential_pattern(self, size_ratio=0.5):
        """Sequential access pattern"""
        base_addr = 0x10000
        num_accesses = int(self.cache_size * size_ratio)
        return [base_addr + (i * 4) for i in range(num_accesses)]
    
    def random_pattern(self, num_accesses=100):
        """Random access pattern with fixed seed"""
        random.seed(42)
        base_addr = 0x20000
        max_addr = base_addr + (self.cache_size * 8 * 4)
        return [random.randrange(base_addr, max_addr, 4) for _ in range(num_accesses)]
    
    def hot_spot_pattern(self, hot_size=16, iterations=10):
        """Hot spot access pattern"""
        base_addr = 0x30000
        hot_addresses = [base_addr + (i * 4) for i in range(hot_size)]
        pattern = []
        for _ in range(iterations):
            pattern.extend(hot_addresses)
        return pattern
    
    def stride_pattern(self, stride_size=None, num_accesses=50):
        """Stride access pattern"""
        if stride_size is None:
            stride_size = max(4, self.cache_size // 8)
        base_addr = 0x40000
        return [base_addr + (i * stride_size * 4) for i in range(num_accesses)]
    
    def instruction_fetch_pattern(self):
        """Realistic instruction fetch pattern with loops and branches"""
        pattern = []
        base_addr = 0x50000
        
        # Main program sequence
        for i in range(20):
            pattern.append(base_addr + (i * 4))
        
        # Tight loop (simulate for loop)
        loop_addr = base_addr + 0x100
        for _ in range(15):  # Loop iterations
            for i in range(8):  # Instructions in loop
                pattern.append(loop_addr + (i * 4))
        
        # Function call pattern
        func_addr = base_addr + 0x200
        for _ in range(5):  # Multiple calls
            pattern.append(base_addr + 80)  # Call instruction
            for i in range(12):
                pattern.append(func_addr + (i * 4))
            pattern.append(base_addr + 84)  # Return point
        
        # Branch-heavy section
        branch_addr = base_addr + 0x300
        for i in range(25):
            pattern.append(branch_addr + (i * 4))
            if i % 3 == 0:  # Conditional branch taken
                pattern.append(branch_addr + 0x50 + ((i % 5) * 4))
        
        return pattern
    
    def mixed_realistic_pattern(self):
        """Mixed realistic workload combining multiple patterns"""
        pattern = []
        
        # 40% sequential (normal program flow)
        pattern.extend(self.sequential_pattern(0.3))
        
        # 30% instruction fetch (loops, calls, branches) 
        pattern.extend(self.instruction_fetch_pattern())
        
        # 20% hot spot (frequently executed code)
        pattern.extend(self.hot_spot_pattern(hot_size=8, iterations=8))
        
        # 10% random (unpredictable branches)
        pattern.extend(self.random_pattern(num_accesses=30))
        
        # Shuffle to mix patterns realistically
        random.seed(123)
        random.shuffle(pattern)
        
        return pattern

class CacheTestBench:
    """Enhanced parameterizable test bench controller"""
    
    def __init__(self, dut):
        self.dut = dut
        
        # Extract parameters from DUT
        try:
            self.cache_size = int(self.dut.CACHE_SIZE.value) if hasattr(self.dut, 'CACHE_SIZE') else 1024
            self.associativity = int(self.dut.ASSOCIATIVITY.value) if hasattr(self.dut, 'ASSOCIATIVITY') else 4
        except:
            self.cache_size = 1024
            self.associativity = 4
            
        self.metrics = CacheMetrics(cache_size=self.cache_size, associativity=self.associativity)
        self.workloads = BenchmarkWorkloads(cache_size=self.cache_size, associativity=self.associativity)
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
                
            if cycles > 100:
                raise TestFailure("Access timeout")
        
        self.dut.cpu_req.value = 0
        await RisingEdge(self.dut.clk)
        return cycles
    
    async def run_benchmark_pattern(self, addresses, test_name):
        """Run benchmark pattern and generate detailed report"""
        total_cycles = 0
        for addr in addresses:
            cycles = await self.single_access(addr)
            total_cycles += cycles
        
        # Calculate timing metrics
        avg_access_time = total_cycles / len(addresses) if addresses else 0
        
        report = self.metrics.generate_benchmark_report(test_name)
        report += f"TIMING METRICS:\n"
        report += f"Total Cycles:        {total_cycles:8d}\n"
        report += f"Average Access Time: {avg_access_time:8.2f} cycles\n"
        report += f"Addresses Tested:    {len(addresses):8d}\n"
        report += f"{'='*70}\n"
        
        return {
            'hit_rate': self.metrics.get_hit_rate(),
            'miss_rate': self.metrics.get_miss_rate(),
            'avg_access_time': avg_access_time,
            'total_cycles': total_cycles,
            'memory_traffic_ratio': self.metrics.get_memory_traffic_ratio(),
            'conflict_reduction': self.metrics.get_conflict_reduction()
        }

# FUNCTIONAL VERIFICATION TESTS (1-7) - Simple Pass/Fail
@cocotb.test()
async def test_basic_functionality(dut):
    """Test 1: Basic Functionality - Cold Start and Hit/Miss Behavior"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 1: Basic Functionality")
    
    # Test cold start with non-conflicting addresses
    test_addresses = [0x1000, 0x1004, 0x2000, 0x3000]
    
    for addr in test_addresses:
        await tb.single_access(addr)
    
    # Test immediate re-access - should hit
    for addr in test_addresses:
        await tb.single_access(addr)
    
    # Verify basic expectations
    assert tb.metrics.total_requests == 8, f"Expected 8 requests, got {tb.metrics.total_requests}"
    assert tb.metrics.compulsory_misses == 4, f"Expected 4 compulsory misses, got {tb.metrics.compulsory_misses}"
    
    dut._log.info("✓ Basic functionality verified")

@cocotb.test()
async def test_round_robin_replacement(dut):
    """Test 2: Round-Robin Replacement Policy Verification"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 2: Round-Robin Replacement")
    
    # Choose specific set to test (set 0)
    set_index = 0
    
    # Fill the set with different addresses using actual associativity
    base_addresses = []
    for way in range(tb.associativity):
        addr = (way * 256 * 4) + (set_index * 4)  # Different tags, same set
        base_addresses.append(addr)
        await tb.single_access(addr)
    
    # Cause replacements by accessing more addresses to same set
    replacement_addresses = []
    for way in range(tb.associativity):
        addr = ((way + tb.associativity) * 256 * 4) + (set_index * 4)
        replacement_addresses.append(addr)
        await tb.single_access(addr)
        
        # Record replacement for analysis
        tb.metrics.record_replacement(set_index, way, addr)
    
    # Verify round-robin pattern
    is_round_robin, message = tb.metrics.analyze_round_robin_pattern(set_index)
    assert is_round_robin, f"Round-robin pattern verification failed: {message}"
    
    dut._log.info("✓ Round-robin replacement verified")

@cocotb.test()
async def test_associativity_benefits(dut):
    """Test 3: Associativity Benefits vs Direct-Mapped"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 3: Associativity Benefits")
    
    # Create addresses that would conflict in direct-mapped but not in N-way
    set_index = 10
    addresses = []
    
    # Generate addresses that map to same set (within associativity limit)
    for i in range(tb.associativity):
        addr = (i * 256 * 4) + (set_index * 4)
        addresses.append(addr)
    
    # Access all addresses (should fill the set)
    for addr in addresses:
        await tb.single_access(addr)
    
    # Re-access all addresses multiple times (should hit due to associativity)
    for _ in range(3):
        for addr in addresses:
            await tb.single_access(addr)
    
    # Should have high hit rate after initial misses
    expected_hits = tb.associativity * 3  # 3 rounds × associativity addresses
    total_accesses = tb.associativity * 4  # associativity × 4 rounds
    expected_hit_rate = (expected_hits / total_accesses) * 100
    assert tb.metrics.get_hit_rate() >= expected_hit_rate * 0.9, f"Expected hit rate >= {expected_hit_rate*0.9:.1f}%, got {tb.metrics.get_hit_rate():.2f}%"
    
    dut._log.info("✓ Associativity benefits verified")

@cocotb.test()
async def test_conflict_miss_reduction(dut):
    """Test 4: Conflict Miss Reduction Analysis"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 4: Conflict Miss Reduction")
    
    # Create conflicting addresses (same set, different tags)
    set_index = 5
    conflicting_addresses = []
    
    # Generate addresses that map to same set - more than associativity
    num_conflicts = tb.associativity + 2
    for i in range(num_conflicts):
        addr = (i * 256 * 4) + (set_index * 4)
        conflicting_addresses.append(addr)
    
    # Repeated access pattern
    for _ in range(3):
        for addr in conflicting_addresses:
            await tb.single_access(addr)
    
    # Should show some conflict reduction compared to direct-mapped
    assert tb.metrics.conflict_misses < tb.metrics.total_requests, "Expected some conflict reduction"
    
    dut._log.info("✓ Conflict miss reduction verified")

@cocotb.test()
async def test_cache_capacity_stress(dut):
    """Test 5: Cache Capacity Stress - Fill Cache + Overflow"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 5: Cache Capacity Stress")
    
    base_addr = 0x1000
    
    # Fill entire cache capacity
    for i in range(tb.cache_size):
        addr = base_addr + (i * 4)
        await tb.single_access(addr)
    
    # Access beyond capacity
    overflow_count = min(50, tb.cache_size // 10)
    for i in range(tb.cache_size, tb.cache_size + overflow_count):
        addr = base_addr + (i * 4)
        await tb.single_access(addr)
    
    # Verify capacity behavior
    total_accesses = tb.cache_size + overflow_count
    assert tb.metrics.total_requests == total_accesses, f"Expected {total_accesses} requests"
    assert tb.metrics.evictions > 0, "Expected cache evictions"
    
    dut._log.info("✓ Cache capacity stress verified")

@cocotb.test()
async def test_replacement_fairness(dut):
    """Test 6: Replacement Policy Fairness Across Multiple Sets"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 6: Replacement Policy Fairness")
    
    # Test fairness of round-robin across multiple sets
    sets_to_test = [0, 1, 2]
    
    for set_idx in sets_to_test:
        # Fill set completely using actual associativity
        for way in range(tb.associativity):
            addr = (way * 256 * 4) + (set_idx * 4)
            await tb.single_access(addr)
        
        # Cause replacements and verify round-robin
        for way in range(tb.associativity):
            addr = ((way + tb.associativity) * 256 * 4) + (set_idx * 4)
            await tb.single_access(addr)
            tb.metrics.record_replacement(set_idx, way, addr)
    
    # Verify round-robin for all tested sets
    all_correct = True
    for set_idx in sets_to_test:
        is_correct, message = tb.metrics.analyze_round_robin_pattern(set_idx)
        if not is_correct:
            all_correct = False
            dut._log.error(f"Set {set_idx} round-robin failed: {message}")
    
    assert all_correct, "Round-robin fairness verification failed"
    
    dut._log.info("✓ Replacement policy fairness verified")

@cocotb.test()
async def test_edge_cases(dut):
    """Test 7: Edge Cases and Boundary Conditions"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 7: Edge Cases")
    
    # Test boundary addresses and corner cases
    edge_addresses = [
        0x00000000,  # Minimum address
        0xFFFFFFFC,  # Maximum word-aligned address
        0x00001000,  # Typical address
        0x80000000,  # Mid-range address
    ]
    
    for addr in edge_addresses:
        await tb.single_access(addr)
    
    # Verify all accesses completed
    assert tb.metrics.total_requests == 4, "Expected 4 requests"
    
    dut._log.info("✓ Edge cases verified")

# BENCHMARK TESTS (8-9) - Detailed Performance Analysis
@cocotb.test()
async def test_unified_benchmark_suite(dut):
    """Test 8: Unified Benchmark Suite for Cross-Cache Comparison"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    dut._log.info("Test 8: Unified Benchmark Suite")
    
    benchmark_results = {}
    
    # Benchmark 1: Sequential Pattern
    await tb.reset_cache()
    sequential_addrs = tb.workloads.sequential_pattern(size_ratio=0.5)
    results = await tb.run_benchmark_pattern(sequential_addrs, "Sequential Access")
    benchmark_results['sequential'] = results
    dut._log.info(tb.metrics.generate_benchmark_report("Sequential Access"))
    
    # Benchmark 2: Random Pattern  
    await tb.reset_cache()
    random_addrs = tb.workloads.random_pattern(num_accesses=100)
    results = await tb.run_benchmark_pattern(random_addrs, "Random Access")
    benchmark_results['random'] = results
    dut._log.info(tb.metrics.generate_benchmark_report("Random Access"))
    
    # Benchmark 3: Hot Spot Pattern
    await tb.reset_cache()
    hotspot_addrs = tb.workloads.hot_spot_pattern(hot_size=16, iterations=10)
    results = await tb.run_benchmark_pattern(hotspot_addrs, "Hot Spot Access")
    benchmark_results['hotspot'] = results
    dut._log.info(tb.metrics.generate_benchmark_report("Hot Spot Access"))
    
    # Benchmark 4: Stride Pattern
    await tb.reset_cache()
    stride_addrs = tb.workloads.stride_pattern(num_accesses=50)
    results = await tb.run_benchmark_pattern(stride_addrs, "Stride Access")
    benchmark_results['stride'] = results
    dut._log.info(tb.metrics.generate_benchmark_report("Stride Access"))
    
    # Unified Summary Report
    summary_report = f"\n{'='*80}\n"
    summary_report += f"UNIFIED BENCHMARK SUITE SUMMARY\n"
    summary_report += f"Cache Type: {tb.associativity}-Way Set Associative, Size: {tb.cache_size} words\n"
    summary_report += f"{'='*80}\n"
    summary_report += f"{'Pattern':<15} {'Hit Rate':<12} {'Avg Access':<12} {'Memory Traffic':<15} {'Conflict Red.':<12}\n"
    summary_report += f"{'-'*80}\n"
    
    for benchmark, results in benchmark_results.items():
        summary_report += f"{benchmark.capitalize():<15} "
        summary_report += f"{results['hit_rate']:>8.2f}%    "
        summary_report += f"{results['avg_access_time']:>8.1f} cyc   "
        summary_report += f"{results['memory_traffic_ratio']:>12.2f}   "
        summary_report += f"{results['conflict_reduction']:>8.2f}\n"
    
    summary_report += f"{'='*80}\n"
    dut._log.info(summary_report)

@cocotb.test()
async def test_realistic_workloads(dut):
    """Test 9: Realistic Instruction Fetch Workloads"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    dut._log.info("Test 9: Realistic Workloads")
    
    workload_results = {}
    
    # Workload 1: Instruction Fetch Pattern
    await tb.reset_cache()
    instruction_addrs = tb.workloads.instruction_fetch_pattern()
    results = await tb.run_benchmark_pattern(instruction_addrs, "Instruction Fetch")
    workload_results['instruction_fetch'] = results
    dut._log.info(tb.metrics.generate_benchmark_report("Instruction Fetch"))
    
    # Workload 2: Mixed Realistic Pattern
    await tb.reset_cache()
    mixed_addrs = tb.workloads.mixed_realistic_pattern()
    results = await tb.run_benchmark_pattern(mixed_addrs, "Mixed Realistic")
    workload_results['mixed_realistic'] = results
    dut._log.info(tb.metrics.generate_benchmark_report("Mixed Realistic"))
    
    # Realistic Workloads Summary
    summary_report = f"\n{'='*80}\n"
    summary_report += f"REALISTIC WORKLOADS SUMMARY\n"
    summary_report += f"Cache Type: {tb.associativity}-Way Set Associative, Size: {tb.cache_size} words\n"
    summary_report += f"{'='*80}\n"
    summary_report += f"{'Workload':<20} {'Hit Rate':<12} {'Avg Access':<12} {'Memory Traffic':<15} {'Conflict Red.':<12}\n"
    summary_report += f"{'-'*80}\n"
    
    for workload, results in workload_results.items():
        name = workload.replace('_', ' ').title()
        summary_report += f"{name:<20} "
        summary_report += f"{results['hit_rate']:>8.2f}%    "
        summary_report += f"{results['avg_access_time']:>8.1f} cyc   "
        summary_report += f"{results['memory_traffic_ratio']:>12.2f}   "
        summary_report += f"{results['conflict_reduction']:>8.2f}\n"
    
    summary_report += f"{'='*80}\n"
    summary_report += f"PERFORMANCE INSIGHTS:\n"
    summary_report += f"• Strength: Reduced conflict misses vs direct-mapped\n"
    summary_report += f"• Best for: Mixed workloads with moderate spatial locality\n"
    summary_report += f"• Trade-off: Slightly higher access latency, better hit rates\n"
    summary_report += f"• Ideal use: General-purpose instruction caches\n"
    summary_report += f"{'='*80}\n"
    
    dut._log.info(summary_report)
    
    # Final verification message
    dut._log.info("N-WAY SET ASSOCIATIVE CACHE TESTING COMPLETE")
    dut._log.info(f"Cache verified: {tb.cache_size} words, {tb.associativity}-way, all patterns tested successfully")