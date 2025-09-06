# SynapseCache : RISC-V Cache Verification Suite

SynapseCache is a comprehensive verification and performance analysis suite for three RISC-V instruction cache implementations: Direct-Mapped, N-Way Set Associative, and N-Way Set Associative with Multi-Word Blocks. Written in Verilog and tested using Python with the Cocotb framework, this project verifies functionality, analyzes performance, and compares design trade-offs for each cache architecture.

## Cache Architecture

### Cache Implementations

1. **Direct-Mapped Cache** (`icache.v`):
   - **Mapping**: One-to-one address-to-cache-line mapping
   - **Capacity**: 1024 words (4KB)
   - **Block Size**: Single word (32 bits)
   - **Replacement**: Implicit (direct mapping)
   - **Features**:
     - Simple and fast single-cycle access
     - Cost-effective but susceptible to conflict misses
   - **Interface**:
     ```systemverilog
     module icache #(
         parameter ADDR_WIDTH = 32,
         parameter DATA_WIDTH = 32,
         parameter CACHE_SIZE = 1024 
     )(
         input  wire clk, rst_n,
         input  wire cpu_req,
         input  wire [ADDR_WIDTH-1:0] cpu_addr,
         output reg  [DATA_WIDTH-1:0] cpu_data,
         output reg  cpu_valid, cpu_stall,
         output reg  mem_req,
         output reg  [ADDR_WIDTH-1:0] mem_addr,
         input  wire [DATA_WIDTH-1:0] mem_data,
         input  wire mem_ready,
         output reg  cache_hit, cache_miss, cache_evict
     );
     ```

2. **N-Way Set Associative Cache** (`icache_nway.v`):
   - **Mapping**: 4-way set associative
   - **Capacity**: 1024 words (4KB), 256 sets × 4 ways
   - **Block Size**: Single word (32 bits)
   - **Replacement**: Round-robin policy
   - **Features**:
     - Reduces conflict misses compared to direct-mapped
     - Moderate complexity with balanced performance
   - **Interface**:
     ```systemverilog
     module icache_nway #(
         parameter ADDR_WIDTH    = 32,
         parameter DATA_WIDTH    = 32,
         parameter CACHE_SIZE    = 1024,
         parameter ASSOCIATIVITY = 4
     )(
         // Standard cache interface with associativity logic
     );
     ```

3. **N-Way Multi-Word Block Cache** (`icache_nway_multiword.v`):
   - **Mapping**: 4-way set associative with multi-word blocks
   - **Capacity**: 1024 words (4KB), 64 sets × 4 ways × 4 words/block
   - **Block Size**: 4 words (128 bits)
   - **Memory Interface**: Burst transfer protocol
   - **Replacement**: Round-robin policy at block level
   - **Features**:
     - Exploits spatial locality for improved performance
     - Efficient memory bandwidth usage with burst transfers
   - **Interface**:
     ```systemverilog
     module icache_nway_multiword #(
         parameter ADDR_WIDTH    = 32,
         parameter DATA_WIDTH    = 32,
         parameter CACHE_SIZE    = 1024,
         parameter ASSOCIATIVITY = 4,
         parameter BLOCK_SIZE    = 4
     )(
         // Enhanced interface with burst support
         output reg [BLOCK_SIZE-1:0] mem_burst_len,
         input  wire mem_valid, mem_last
     );
     ```

### Cache Test Suites

Each cache implementation is rigorously tested to verify functionality and analyze performance under various workloads:

1. **Direct-Mapped Cache Tests**:
   - **Basic Functionality**: Verifies cold start, hit/miss logic, data integrity (50% hit rate)
   - **Sequential Access**: Tests consecutive addresses (~0% hit rate, no spatial locality)
   - **Hot Spot Access**: Evaluates temporal locality (90% hit rate)
   - **Conflict Miss**: Demonstrates cache thrashing (~0% hit rate)
   - **Capacity Stress**: Tests behavior beyond capacity (~0% hit rate)
   - **Replacement/Eviction**: Validates eviction behavior
   - **Random Access**: Simulates unpredictable patterns (<20% hit rate)
   - **Performance Characterization**: Measures mixed workload performance
   - **Edge Cases**: Tests boundary addresses (e.g., 0x00000000, 0xFFFFFFFC)

2. **N-Way Set Associative Cache Tests**:
   - **Basic Functionality**: Verifies associative lookup (50% hit rate)
   - **Round-Robin Replacement**: Ensures fair replacement policy
   - **Associativity Benefits**: Shows reduced conflict misses
   - **Hot Spot Access**: Tests multiple hot spots (93.33% hit rate)
   - **Conflict Miss Reduction**: Quantifies associativity improvements
   - **Sequential Access**: Shows limitations without spatial locality (~0% hit rate)
   - **Capacity Stress**: Tests replacement under pressure
   - **Random Access**: Evaluates unpredictable patterns
   - **Performance Characterization**: Comprehensive performance analysis
   - **Replacement Fairness**: Verifies round-robin across sets
   - **Final Verification**: Validates all N-way features

3. **N-Way Multi-Word Block Cache Tests**:
   - **Basic Functionality**: Verifies block-based operation and burst interface
   - **Spatial Locality**: Demonstrates multi-word block benefits (>60% hit rate)
   - **Round-Robin Replacement**: Validates block-level replacement
   - **Sequential Access**: Shows significant improvement (>50% hit rate)
   - **Hot Spot Access**: Tests combined locality (>85% hit rate)
   - **Bandwidth Efficiency**: Measures memory utilization (>0.5 efficiency)
   - **Conflict Miss Reduction**: Shows block-level conflict benefits
   - **Capacity Stress**: Tests block-level capacity management
   - **Random Access**: Evaluates performance with potential spatial locality
   - **Performance Characterization**: Comprehensive performance analysis
   - **Final Verification**: Validates all multi-word features

### Performance Summary

| Cache Type          | Best Hit Rate | Worst Hit Rate | Avg Access Time | Best Use Case                     |
|---------------------|---------------|----------------|-----------------|-----------------------------------|
| Direct-Mapped       | 90.00%        | 0.00%          | 7.78 cycles     | Cost-sensitive, predictable loads |
| N-Way Single        | 93.33%        | 0.00%          | 6.98 cycles     | General-purpose, balanced         |
| N-Way Multi-Word    | **96.88%**    | 3.75%          | **3.09 cycles** | High-performance, spatial locality |

- **Sequential Access**:
  - Direct-Mapped: 0% hit rate
  - N-Way Single: 0% hit rate
  - N-Way Multi-Word: **75% hit rate**
- **Hot Spot Access**:
  - Direct-Mapped: 90% hit rate
  - N-Way Single: 93.33% hit rate
  - N-Way Multi-Word: **96.88% hit rate**
- **Conflict Pattern**:
  - Direct-Mapped: 0% hit rate
  - N-Way Single: 0% hit rate
  - N-Way Multi-Word: **50% hit rate**
- **Bandwidth Efficiency**:
  - Direct-Mapped: 0.10–1.00 traffic ratio
  - N-Way Single: 0.07–1.00 traffic ratio
  - N-Way Multi-Word: **0.03–1.00 traffic ratio, up to 8.0× efficiency**

## Running the Verification Suite

To run the cache verification suite, you need the following tools installed:
- [Icarus Verilog](https://steveicarus.github.io/iverilog/usage/installation.html)
- [Cocotb](https://cocotb.readthedocs.io/en/stable/)
- [Python 3.7+](https://www.python.org/downloads/) with pip


### Setup Instructions

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/shashvatprabhu/SynapseCache
   cd SynapseCache
   ```

2. **Install Dependencies**:
   ```bash
   pip install cocotb matplotlib
   ```

3. **Install Icarus Verilog**:
   ```bash
   # Ubuntu/Debian
   sudo apt-get install iverilog
   # MacOS
   brew install icarus-verilog
   # Windows (WSL recommended)
   sudo apt-get install iverilog
   ```

4. **Verify Installation**:
   ```bash
   iverilog -V
   python -c "import cocotb; print('cocotb installed successfully')"
   ```

### Running Tests

1. **Run All Tests**:
      ```bash
    cd tests
    python3 -m venv .venv
    source .venv/bin/activate
    pip install -r requirements.txt
   ```

2. **Run Individual Cache Tests**:
   - **Direct-Mapped Cache**:
    ```bash
     python test_icache_dm.py
     ```
   - **N-Way Set Associative Cache**:
    ```bash
     python test_icache_nway.py
     ```
   - **N-Way Multi-Word Block Cache**:
    ```bash
     python test_icache_nwaymw.py
     ```



## Documentation

- **[Direct Mapped Cache Design](docs/dm_cache_design.md)**: Architecture overview, interface specifications, and implementation details for single-word direct-mapped cache
- **[N-Way Set Associative Cache Design](docs/nway_cache_design.md)**: Comprehensive design documentation for configurable N-way set associative cache with round-robin replacement
- **[N-Way Set Associative Multi-Word Cache Design](docs/nwaymw_cache_design.md)**: Advanced cache design with multi-word blocks, burst transfers, and spatial locality optimization
- **[Comprehensive Cache Test Suite Documentation](docs/cache_test_suite.md)**: Detailed explanation of all test cases across three cache implementations with performance analysis and comparison

## Contributors

- [Shashvat Prabhu](https://github.com/shashvatprabhu)

## Acknowledgements and Resources

- [SRA VJTI](https://sravjti.in/)
- [RISC-V Foundation](https://riscv.org/)
- [Cocotb Documentation](https://cocotb.readthedocs.io/en/stable/)

