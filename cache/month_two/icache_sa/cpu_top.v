module cpu_top (
    input clk,
    input reset,
    input        cpu_read,
    input [31:0] cpu_addr,
    output [31:0] cpu_instr,
    output       cpu_busywait,

    // Memory interface
    input        mem_busywait,
    input [31:0] mem_readdata,
    output       mem_read_req,
    output [31:0] mem_address
);

    // Interconnect signals
    wire [31:0] cache_data;
    wire        hit, valid;

    wire        compare_en, write_en;
    wire [31:0] cache_addr, write_data;
    wire [23:0] write_tag;
    wire        write_valid;

    cache_controller u_ctrl (
        .clk(clk), .reset(reset),
        .CPU_READ(cpu_read),
        .CPU_ADDRESS(cpu_addr),
        .CPU_INSTR(cpu_instr),
        .CPU_BUSYWAIT(cpu_busywait),

        .MEM_BUSYWAIT(mem_busywait),
        .MEM_READDATA(mem_readdata),
        .MEM_READ_REQ(mem_read_req),
        .MEM_ADDRESS(mem_address),
        .MEM_READDATA_VALID(1'b1), // optional for now

        .HIT(hit),
        .VALID(valid),
        .CACHE_READDATA(cache_data),
        .STORED_TAG(), // optional
        .COMPARE_EN(compare_en),
        .WRITE_ENABLE(write_en),
        .CACHE_ADDRESS(cache_addr),
        .CACHE_WRITEDATA(write_data),
        .CACHE_WRITETAG(write_tag),
        .CACHE_WRITEVALID(write_valid)
    );

    cache_storage u_storage (
        .clk(clk), .reset(reset),
        .read(compare_en),
        .write(write_en),
        .address(cache_addr),
        .write_block(write_data),
        .read_data(cache_data),
        .hit(hit)
    );

endmodule
