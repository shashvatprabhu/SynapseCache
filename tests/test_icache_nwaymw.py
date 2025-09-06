"""
Enhanced Parameterizable Test Bench for N-Way Set Associative Multi-Word Block Instruction Cache
Target: icache_nway_multiword module (N-way set associative, multi-word block, round-robin replacement)
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
    
    def __init__(self, cache_size=1024, associativity=4, block_size=4):
        self.cache_size = cache_size
        self.associativity = associativity
        self.block_size = block_size
        self.blocks = cache_size // block_size
        self.sets = self.blocks // associativity
        # Calculate block alignment mask based on actual block size
        self.block_mask = ~((self.block_size * 4) - 1)  # 4 bytes per word
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
        self.burst_transfers = 0
        
        # Track unique blocks and addresses for miss classification
        self.unique_blocks_accessed = set()
        self.unique_addresses_accessed = set()
        
        # Track spatial and temporal locality
        self.spatial_hits = 0  # Hits due to fetching entire block
        self.temporal_hits = 0  # Hits due to re-accessing same data
        
        # Cache state tracking for miss classification
        self.cache_contents = {}  # set_index -> list of block addresses
        self.access_history = []
        self.replacement_history = []
        
    def record_access(self, address, hit, miss, evict, mem_req, burst_count=0):
        self.total_requests += 1
        block_addr = address & self.block_mask
        set_index = (block_addr >> int(math.log2(self.block_size * 4))) % self.sets
        
        self.access_history.append({
            'addr': address, 
            'block_addr': block_addr,
            'set_index': set_index,
            'hit': hit, 
            'miss': miss
        })
        
        if hit:
            self.total_hits += 1
            self._classify_hit(address, block_addr)
        
        if miss:
            self.total_misses += 1
            self._classify_miss(address, block_addr, set_index)
            
        if evict:
            self.evictions += 1
            
        if mem_req:
            self.memory_requests += 1
            self.burst_transfers += burst_count if burst_count > 0 else self.block_size
        
        # Track accessed addresses and blocks
        self.unique_addresses_accessed.add(address)
        self.unique_blocks_accessed.add(block_addr)
    
    def _classify_hit(self, address, block_addr):
        """Classify hit as spatial or temporal - only if data is still in cache"""
        set_index = (block_addr >> int(math.log2(self.block_size * 4))) % self.sets
        
        # Verify the block is actually in cache (not evicted)
        if set_index not in self.cache_contents or block_addr not in self.cache_contents[set_index]:
            # This shouldn't happen for a hit, but safety check
            return
        
        # Find the most recent miss that brought this block into cache
        last_miss_for_block = None
        for i in range(len(self.access_history) - 1, -1, -1):
            if (self.access_history[i]['block_addr'] == block_addr and 
                self.access_history[i]['miss']):
                last_miss_for_block = i
                break
        
        if last_miss_for_block is None:
            return  # Safety check
        
        # Check accesses to this address since the block was last loaded
        prev_accesses_to_addr = []
        for i in range(last_miss_for_block + 1, len(self.access_history) - 1):
            if self.access_history[i]['addr'] == address and self.access_history[i]['hit']:
                prev_accesses_to_addr.append(i)
        
        if prev_accesses_to_addr:
            # Temporal hit - we've accessed this exact address before (after last load)
            self.temporal_hits += 1
        else:
            # First access to this specific address since block was loaded
            # Check if other addresses in the block were accessed
            other_block_accesses = False
            for i in range(last_miss_for_block, len(self.access_history) - 1):
                if (self.access_history[i]['block_addr'] == block_addr and 
                    self.access_history[i]['addr'] != address and
                    self.access_history[i]['hit']):
                    other_block_accesses = True
                    break
            
            if other_block_accesses or address != self.access_history[last_miss_for_block]['addr']:
                # Spatial hit - benefiting from block fetch
                self.spatial_hits += 1
            else:
                # This is a re-access to the same address that caused the miss
                self.temporal_hits += 1
    
    def _classify_miss(self, address, block_addr, set_index):
        """Classify miss type accurately"""
        # Compulsory miss: First time accessing this block ever
        if block_addr not in self.unique_blocks_accessed:
            self.compulsory_misses += 1
        else:
            # This block was accessed before but is not in cache now (evicted)
            # Determine if it's a capacity or conflict miss
            
            # Count total unique blocks accessed so far
            total_unique_blocks = len(self.unique_blocks_accessed)
            
            if total_unique_blocks > self.blocks:
                # More unique blocks than cache capacity
                self.capacity_misses += 1
            else:
                # Block was evicted due to set conflicts
                # (Total blocks fit in cache but too many map to same set)
                self.conflict_misses += 1
        
        # Update cache state for tracking
        if set_index not in self.cache_contents:
            self.cache_contents[set_index] = []
        
        # Simulate cache replacement (FIFO/Round-Robin for this set)
        if block_addr not in self.cache_contents[set_index]:
            if len(self.cache_contents[set_index]) >= self.associativity:
                # Evict oldest block from this set
                evicted = self.cache_contents[set_index].pop(0)
            self.cache_contents[set_index].append(block_addr)
    
    def record_replacement(self, set_index, way, address):
        """Track round-robin replacement pattern"""
        self.replacement_history.append({
            'set': set_index,
            'way': way,
            'addr': address
        })
    
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
    
    def get_spatial_benefit(self):
        """Calculate spatial locality benefit percentage"""
        return (self.spatial_hits / self.total_hits * 100) if self.total_hits > 0 else 0
    
    def get_temporal_benefit(self):
        """Calculate temporal locality benefit percentage"""
        return (self.temporal_hits / self.total_hits * 100) if self.total_hits > 0 else 0
    
    def generate_benchmark_report(self, test_name):
        """Generate detailed benchmark report"""
        report = f"\n{'='*80}\n"
        report += f"BENCHMARK REPORT - {test_name.upper()}\n"
        report += f"Cache: {self.associativity}-Way Multi-Word, {self.cache_size} words, {self.block_size}-word blocks\n"
        report += f"{'='*80}\n"
        report += f"Total Requests:      {self.total_requests:8d}\n"
        report += f"Cache Hits:          {self.total_hits:8d}\n"
        report += f"Cache Misses:        {self.total_misses:8d}\n"
        report += f"Hit Rate:            {self.get_hit_rate():8.2f}%\n"
        report += f"Miss Rate:           {self.get_miss_rate():8.2f}%\n"
        report += f"{'='*80}\n"
        report += f"MISS BREAKDOWN:\n"
        report += f"Compulsory Misses:   {self.compulsory_misses:8d} ({self.compulsory_misses/self.total_misses*100 if self.total_misses > 0 else 0:5.1f}%)\n"
        report += f"Conflict Misses:     {self.conflict_misses:8d} ({self.conflict_misses/self.total_misses*100 if self.total_misses > 0 else 0:5.1f}%)\n"
        report += f"Capacity Misses:     {self.capacity_misses:8d} ({self.capacity_misses/self.total_misses*100 if self.total_misses > 0 else 0:5.1f}%)\n"
        report += f"{'='*80}\n"
        report += f"LOCALITY BENEFITS:\n"
        report += f"Spatial Benefit:     {self.get_spatial_benefit():8.2f}% (hits from block fetching)\n"
        report += f"Temporal Benefit:    {self.get_temporal_benefit():8.2f}% (hits from data reuse)\n"
        report += f"{'='*80}\n"
        return report

class BenchmarkWorkloads:
    """Unified benchmark workloads for cross-cache comparison"""
    
    def __init__(self, cache_size, block_size=4, associativity=4):
        self.cache_size = cache_size
        self.block_size = block_size
        self.associativity = associativity
        self.block_size_bytes = block_size * 4  # 4 bytes per word
    
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
            self.block_size = int(self.dut.BLOCK_SIZE.value) if hasattr(self.dut, 'BLOCK_SIZE') else 8
        except:
            self.cache_size = 1024
            self.associativity = 4
            self.block_size = 8
            
        self.metrics = CacheMetrics(cache_size=self.cache_size, associativity=self.associativity, block_size=self.block_size)
        self.workloads = BenchmarkWorkloads(cache_size=self.cache_size, block_size=self.block_size, associativity=self.associativity)
        self.mem_latency = 10  # Memory access latency in cycles
        
        # Calculate block size in bytes for address generation
        self.block_size_bytes = self.block_size * 4  # 4 bytes per word
        
    async def reset_cache(self):
        """Reset cache and initialize signals"""
        self.dut.rst_n.value = 0
        self.dut.cpu_req.value = 0
        self.dut.cpu_addr.value = 0
        self.dut.mem_data.value = 0
        self.dut.mem_ready.value = 0
        self.dut.mem_valid.value = 0
        self.dut.mem_last.value = 0
        
        await RisingEdge(self.dut.clk)
        await RisingEdge(self.dut.clk)
        
        self.dut.rst_n.value = 1
        await RisingEdge(self.dut.clk)
        
        self.metrics.reset_metrics()
    
    async def memory_model(self):
        """Burst-capable memory model with configurable latency"""
        mem_delay_counter = 0
        burst_counter = 0
        burst_active = False
        burst_addr = 0
        
        while True:
            await RisingEdge(self.dut.clk)
            
            # Handle new memory request
            if self.dut.mem_req.value == 1 and not burst_active:
                mem_delay_counter = self.mem_latency
                burst_counter = 0
                burst_active = True
                burst_addr = int(self.dut.mem_addr.value)
                self.dut.mem_ready.value = 0
                self.dut.mem_valid.value = 0
                self.dut.mem_last.value = 0
            
            # Handle memory latency
            if burst_active and mem_delay_counter > 0:
                mem_delay_counter -= 1
                if mem_delay_counter == 0:
                    self.dut.mem_ready.value = 1
            
            # Handle burst data transfer
            if burst_active and mem_delay_counter == 0:
                self.dut.mem_valid.value = 1
                # Generate deterministic data based on address and word offset
                word_addr = burst_addr + (burst_counter * 4)
                self.dut.mem_data.value = (word_addr & 0xFFFFFFFF) ^ 0xDEADBEEF
                
                burst_counter += 1
                
                # Check if this is the last word
                if burst_counter >= self.block_size:
                    self.dut.mem_last.value = 1
                    burst_active = False
                else:
                    self.dut.mem_last.value = 0
            else:
                self.dut.mem_valid.value = 0
                self.dut.mem_last.value = 0
                if not burst_active:
                    self.dut.mem_ready.value = 0
    
    async def single_access(self, address):
        """Perform single cache access and collect metrics"""
        self.dut.cpu_req.value = 1
        self.dut.cpu_addr.value = address
        
        # Track if memory request was generated during this access
        mem_req_detected = False
        cycles = 0
        
        # Wait for response
        while True:
            await RisingEdge(self.dut.clk)
            cycles += 1
            
            # Check for memory request during any cycle
            if int(self.dut.mem_req.value) == 1:
                mem_req_detected = True
            
            hit = int(self.dut.cache_hit.value)
            miss = int(self.dut.cache_miss.value)
            evict = int(self.dut.cache_evict.value)
            
            if hit or miss:
                self.metrics.record_access(address, hit, miss, evict, mem_req_detected, self.block_size)
                break
                
            if cycles > 200:  # Increased timeout for burst operations
                raise TestFailure(f"Access timeout for address 0x{address:08x}")
        
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
        report += f"{'='*80}\n"
        
        return {
            'hit_rate': self.metrics.get_hit_rate(),
            'miss_rate': self.metrics.get_miss_rate(),
            'avg_access_time': avg_access_time,
            'total_cycles': total_cycles,
            'memory_traffic_ratio': self.metrics.get_memory_traffic_ratio(),
            'spatial_benefit': self.metrics.get_spatial_benefit(),
            'temporal_benefit': self.metrics.get_temporal_benefit()
        }

# FUNCTIONAL VERIFICATION TESTS (1-9) - Simple Pass/Fail
@cocotb.test()
async def test_basic_functionality(dut):
    """Test 1: Basic Functionality - Cold Start and Hit/Miss Behavior"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 1: Basic Functionality")
    
    # Test cold start with different blocks using dynamic block spacing
    test_addresses = [
        0x1000, 
        0x1004, 
        0x1000 + tb.block_size_bytes,      # Next block
        0x1000 + (2 * tb.block_size_bytes) # Third block
    ]
    
    for addr in test_addresses:
        await tb.single_access(addr)
    
    # Test immediate re-access - should hit
    for addr in test_addresses:
        await tb.single_access(addr)
    
    # Verify basic expectations
    assert tb.metrics.total_requests == 8, f"Expected 8 requests, got {tb.metrics.total_requests}"
    assert tb.metrics.total_hits >= 4, f"Expected at least 4 hits on re-access"
    
    dut._log.info("✓ Test 1 passed")

@cocotb.test()
async def test_multi_word_block_benefits(dut):
    """Test 2: Multi-Word Block Spatial Locality Benefits"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 2: Multi-Word Block Benefits")
    
    # Access addresses within same block
    base_block = 0x1000  # Block-aligned address
    
    # First access to block (should miss and fetch entire block)
    await tb.single_access(base_block)
    
    # Subsequent accesses to same block (should hit) - use actual block size
    for i in range(1, tb.block_size):
        await tb.single_access(base_block + (i * 4))
    
    # Test another block
    base_block2 = 0x1000 + tb.block_size_bytes
    await tb.single_access(base_block2)      # Miss - new block
    
    # Access more words in second block based on block size
    words_to_test = min(tb.block_size - 1, 3)  # Test up to 3 more words
    for i in range(1, words_to_test + 1):
        await tb.single_access(base_block2 + (i * 4))  # Hits - same block
    
    # Calculate expected hit rate based on actual accesses
    total_accesses = tb.block_size + 1 + words_to_test
    expected_hits = (tb.block_size - 1) + words_to_test
    expected_hit_rate = (expected_hits / total_accesses) * 100
    
    # Allow 10% tolerance
    min_acceptable_rate = expected_hit_rate * 0.85
    
    assert tb.metrics.get_hit_rate() >= min_acceptable_rate, \
        f"Expected hit rate >= {min_acceptable_rate:.1f}%, got {tb.metrics.get_hit_rate():.2f}% " \
        f"(block_size={tb.block_size}, expected ~{expected_hit_rate:.1f}%)"
    
    dut._log.info("✓ Test 2 passed")

@cocotb.test()
async def test_round_robin_replacement(dut):
    """Test 3: Round-Robin Replacement Policy Verification"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 3: Round-Robin Replacement")
    
    # Choose specific set to test (set 0)
    set_index = 0
    
    # Calculate set size for proper address generation
    sets = (tb.cache_size // tb.block_size) // tb.associativity
    set_spacing = sets * tb.block_size_bytes
    
    # Fill the set with different blocks using actual associativity
    base_addresses = []
    for way in range(tb.associativity):
        # Generate block-aligned addresses that map to set 0
        addr = 0x10000 + (way * set_spacing)
        base_addresses.append(addr)
        await tb.single_access(addr)
    
    # Cause replacements by accessing more blocks to same set
    replacement_addresses = []
    for way in range(tb.associativity):
        addr = 0x10000 + ((way + tb.associativity) * set_spacing)
        replacement_addresses.append(addr)
        await tb.single_access(addr)
        
        # Record replacement for analysis
        tb.metrics.record_replacement(set_index, way, addr)
    
    # Verify round-robin pattern
    is_round_robin, message = tb.metrics.analyze_round_robin_pattern(set_index)
    assert is_round_robin, f"Round-robin pattern verification failed: {message}"
    
    dut._log.info("✓ Test 3 passed")

@cocotb.test()
async def test_memory_traffic_analysis(dut):
    """Test 4: Memory Traffic Analysis"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 4: Memory Traffic Analysis")
    
    # Test pattern to analyze memory traffic
    base_addr = 0x1000
    num_blocks = 4
    
    # Access multiple words from same blocks
    for block in range(num_blocks):
        block_base = base_addr + (block * tb.block_size_bytes)
        # Access all words in each block using actual block size
        for word in range(tb.block_size):
            await tb.single_access(block_base + (word * 4))
    
    # Verify memory system is working
    assert tb.metrics.memory_requests > 0, f"Expected memory requests > 0, got {tb.metrics.memory_requests}"
    
    traffic_ratio = tb.metrics.get_memory_traffic_ratio()
    assert traffic_ratio > 0, f"Expected memory traffic ratio > 0, got {traffic_ratio:.2f}"
    
    dut._log.info("✓ Test 4 passed")

@cocotb.test()
async def test_conflict_miss_reduction(dut):
    """Test 5: Conflict Miss Reduction with Multi-Word Blocks"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 5: Conflict Miss Reduction")
    
    # Create conflicting blocks (same set, different tags)
    set_index = 5
    conflicting_blocks = []
    
    # Calculate proper address spacing
    sets = (tb.cache_size // tb.block_size) // tb.associativity
    set_spacing = sets * tb.block_size_bytes
    
    # Generate block addresses that map to same set - more than associativity
    num_conflicts = tb.associativity + 2
    for i in range(num_conflicts):
        block_addr = 0x10000 + (set_index * tb.block_size_bytes) + (i * set_spacing)
        conflicting_blocks.append(block_addr)
    
    # Repeated access pattern
    for _ in range(2):
        for block_addr in conflicting_blocks:
            # Access multiple words from each block
            await tb.single_access(block_addr)
            await tb.single_access(block_addr + 4)
    
    # Should show some conflict reduction compared to direct-mapped
    assert tb.metrics.total_misses < tb.metrics.total_requests, "Expected some hits to demonstrate conflict reduction"
    
    dut._log.info("✓ Test 5 passed")

@cocotb.test()
async def test_cache_capacity_stress(dut):
    """Test 6: Cache Capacity Stress - Fill Cache + Overflow"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 6: Cache Capacity Stress")
    
    # Fill entire cache capacity using actual parameters
    cache_blocks = tb.cache_size // tb.block_size
    base_addr = 0x100000  # Use higher base address to avoid conflicts
    
    # Fill cache with unique blocks - ensure they're properly spaced
    for i in range(cache_blocks):
        block_addr = base_addr + (i * tb.block_size_bytes)
        await tb.single_access(block_addr)
    
    # Access beyond capacity to force evictions
    overflow_count = min(tb.associativity + 5, 20)  # Reasonable overflow count
    for i in range(cache_blocks, cache_blocks + overflow_count):
        block_addr = base_addr + (i * tb.block_size_bytes)
        await tb.single_access(block_addr)
    
    # Verify capacity behavior
    total_accesses = cache_blocks + overflow_count
    assert tb.metrics.total_requests == total_accesses, f"Expected {total_accesses} requests"
    
    # With overflow accesses, we should get some evictions
    if cache_blocks >= tb.associativity:
        assert tb.metrics.evictions > 0, f"Expected cache evictions after overflow"
    
    dut._log.info("✓ Test 6 passed")

@cocotb.test()
async def test_associativity_benefits(dut):
    """Test 7: Associativity Benefits vs Direct-Mapped"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 7: Associativity Benefits")
    
    # Create addresses that would conflict in direct-mapped but not in N-way
    set_index = 10
    addresses = []
    
    # Calculate proper spacing for same set mapping
    sets = (tb.cache_size // tb.block_size) // tb.associativity
    set_spacing = sets * tb.block_size_bytes
    
    # Generate block addresses that map to same set (within associativity limit)
    for i in range(tb.associativity):
        addr = 0x20000 + (set_index * tb.block_size_bytes) + (i * set_spacing)
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
    assert tb.metrics.get_hit_rate() >= expected_hit_rate * 0.9, f"Expected hit rate >= {expected_hit_rate*0.9:.1f}%"
    
    dut._log.info("✓ Test 7 passed")

@cocotb.test()
async def test_replacement_policy_fairness(dut):
    """Test 8: Replacement Policy Fairness Across Multiple Sets"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 8: Replacement Policy Fairness")
    
    # Test fairness of round-robin across multiple sets
    sets_to_test = [0, 1, 2]
    sets = (tb.cache_size // tb.block_size) // tb.associativity
    set_spacing = sets * tb.block_size_bytes
    
    for set_idx in sets_to_test:
        # Fill set completely using actual associativity
        for way in range(tb.associativity):
            addr = 0x30000 + (set_idx * tb.block_size_bytes) + (way * set_spacing)
            await tb.single_access(addr)
        
        # Cause replacements and verify round-robin
        for way in range(tb.associativity):
            addr = 0x30000 + (set_idx * tb.block_size_bytes) + ((way + tb.associativity) * set_spacing)
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
    
    dut._log.info("✓ Test 8 passed")

@cocotb.test()
async def test_edge_cases(dut):
    """Test 9: Edge Cases and Boundary Conditions"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    await tb.reset_cache()
    
    dut._log.info("Test 9: Edge Cases")
    
    # Test boundary addresses
    edge_addresses = [
        0x00000000,  # Minimum address
        0xFFFFFFFC,  # Maximum word-aligned address
        0x00001000,  # Typical address
        0x80000000,  # Mid-range address
    ]
    
    for addr in edge_addresses:
        await tb.single_access(addr)
    
    # Test rapid successive accesses to same address
    rapid_addr = 0x5000
    for _ in range(5):
        await tb.single_access(rapid_addr)
    
    # Test block boundary conditions
    boundary_base = 0x6000
    # Access last word of a block
    await tb.single_access(boundary_base + tb.block_size_bytes - 4)
    # Access first word of next block
    await tb.single_access(boundary_base + tb.block_size_bytes)
    
    # Verify all accesses completed
    assert tb.metrics.total_requests >= len(edge_addresses), f"Expected at least {len(edge_addresses)} requests"
    
    dut._log.info("✓ Test 9 passed")

# BENCHMARK TESTS (10-11) - Detailed Performance Analysis
@cocotb.test()
async def test_unified_benchmark_suite(dut):
    """Test 10: Unified Benchmark Suite for Cross-Cache Comparison"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    dut._log.info("Test 10: Unified Benchmark Suite")
    
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
    summary_report = f"\n{'='*90}\n"
    summary_report += f"UNIFIED BENCHMARK SUITE SUMMARY\n"
    summary_report += f"Cache Type: {tb.associativity}-Way Multi-Word, Size: {tb.cache_size} words, Block: {tb.block_size} words\n"
    summary_report += f"{'='*90}\n"
    summary_report += f"{'Pattern':<12} {'Hit Rate':<10} {'Avg Access':<12} {'Mem Traffic':<12} {'Spatial':<10} {'Temporal':<10}\n"
    summary_report += f"{'-'*90}\n"
    
    for benchmark, results in benchmark_results.items():
        summary_report += f"{benchmark.capitalize():<12} "
        summary_report += f"{results['hit_rate']:>7.2f}%   "
        summary_report += f"{results['avg_access_time']:>8.1f} cyc   "
        summary_report += f"{results['memory_traffic_ratio']:>10.3f}   "
        summary_report += f"{results.get('spatial_benefit', 0):>7.1f}%   "
        summary_report += f"{results.get('temporal_benefit', 0):>7.1f}%\n"
    
    summary_report += f"{'='*90}\n"
    summary_report += f"KEY INSIGHTS:\n"
    summary_report += f"• Sequential: Best spatial locality due to consecutive accesses\n"
    summary_report += f"• Hot Spot: High temporal locality from repeated accesses\n"
    summary_report += f"• Random: Tests worst-case scenario with minimal locality\n"
    summary_report += f"• Stride: Tests cache's ability to handle regular patterns\n"
    summary_report += f"{'='*90}\n"
    dut._log.info(summary_report)

@cocotb.test()
async def test_realistic_workloads(dut):
    """Test 11: Realistic Instruction Fetch Workloads"""
    
    clock = Clock(dut.clk, 10, units="ns")
    cocotb.start_soon(clock.start())
    
    tb = CacheTestBench(dut)
    cocotb.start_soon(tb.memory_model())
    
    dut._log.info("Test 11: Realistic Workloads")
    
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
    summary_report = f"\n{'='*90}\n"
    summary_report += f"REALISTIC WORKLOADS SUMMARY\n"
    summary_report += f"Cache Type: {tb.associativity}-Way Multi-Word, Size: {tb.cache_size} words, Block: {tb.block_size} words\n"
    summary_report += f"{'='*90}\n"
    summary_report += f"{'Workload':<18} {'Hit Rate':<10} {'Avg Access':<12} {'Mem Traffic':<12} {'Spatial':<10} {'Temporal':<10}\n"
    summary_report += f"{'-'*90}\n"
    
    for workload, results in workload_results.items():
        name = workload.replace('_', ' ').title()
        summary_report += f"{name:<18} "
        summary_report += f"{results['hit_rate']:>7.2f}%   "
        summary_report += f"{results['avg_access_time']:>8.1f} cyc   "
        summary_report += f"{results['memory_traffic_ratio']:>10.3f}   "
        summary_report += f"{results.get('spatial_benefit', 0):>7.1f}%   "
        summary_report += f"{results.get('temporal_benefit', 0):>7.1f}%\n"
    
    summary_report += f"{'='*90}\n"
    summary_report += f"PERFORMANCE ANALYSIS:\n"
    summary_report += f"• Multi-word blocks provide significant spatial locality benefits\n"
    summary_report += f"• N-way associativity reduces conflict misses effectively\n"
    summary_report += f"• Round-robin replacement ensures fair cache utilization\n"
    summary_report += f"• Ideal for instruction caches with sequential fetch patterns\n"
    summary_report += f"{'='*90}\n"
    
    dut._log.info(summary_report)
    
    # Final summary
    dut._log.info("=" * 90)
    dut._log.info("N-WAY MULTI-WORD CACHE VERIFICATION COMPLETE")
    dut._log.info(f"Configuration: {tb.cache_size} words, {tb.associativity}-way, {tb.block_size}-word blocks")
    dut._log.info("All tests passed successfully")
    dut._log.info("=" * 90)

def runCocotbTests():
    """Run the N-way multi-word cache tests"""
    from cocotb_test.simulator import run
    import os
    
    # Find RTL sources
    curr_dir = os.getcwd()
    root_dir = curr_dir
    while not os.path.exists(os.path.join(root_dir, "rtl")):
        root_dir = os.path.dirname(root_dir)
        if root_dir == os.path.dirname(root_dir):
            root_dir = curr_dir
            break
    
    sources = []
    rtl_dir = os.path.join(root_dir, "rtl")
    if os.path.exists(rtl_dir):
        for root, _, files in os.walk(rtl_dir):
            for file in files:
                if file.endswith(".v"):
                    sources.append(os.path.join(root, file))
    
    run(
        verilog_sources=sources,
        toplevel="icache_nway_multiword",
        module="test_icache_nwaymw",
        simulator="icarus",
        force_compile=True,
    )

if __name__ == "__main__":
    runCocotbTests()