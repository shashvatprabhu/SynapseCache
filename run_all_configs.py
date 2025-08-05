import os
import re

# Configurations to test
configs = [
    {"DEG_ASSOCIATIVITY": 1, "BLOCK_SIZE": 1},
    {"DEG_ASSOCIATIVITY": 2, "BLOCK_SIZE": 1},
    {"DEG_ASSOCIATIVITY": 1, "BLOCK_SIZE": 4},
    {"DEG_ASSOCIATIVITY": 2, "BLOCK_SIZE": 4}
]

# Path to Verilog file
verilog_file = "rtl/icache_fifo.v"

for config in configs:
    print(f"\n>>> Running DEG_ASSOCIATIVITY={config['DEG_ASSOCIATIVITY']}, BLOCK_SIZE={config['BLOCK_SIZE']}...")
    
    # Read and modify Verilog file
    with open(verilog_file, "r") as f:
        content = f.read()
    
    # Update parameters
    content = re.sub(
        r"parameter\s+BLOCK_SIZE\s*=\s*\d+",
        f"parameter BLOCK_SIZE = {config['BLOCK_SIZE']}",
        content
    )
    content = re.sub(
        r"parameter\s+DEG_ASSOCIATIVITY\s*=\s*\d+",
        f"parameter DEG_ASSOCIATIVITY = {config['DEG_ASSOCIATIVITY']}",
        content
    )
    
    # Write modified Verilog file
    with open(verilog_file, "w") as f:
        f.write(content)
    
    # Run simulation
    os.system("make sim")