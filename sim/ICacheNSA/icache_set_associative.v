`timescale 1ns / 1ps
`default_nettype none

module icache_set_associative #(
    parameter CACHESIZE = 1024,     
    parameter BLOCKSIZE = 4,       
    parameter ASSOCIATIVITY = 2        
)(
    input  wire clk,
    input  wire reset,
    input  wire [31:0]  ifetch,         
    input  wire [31:0]  instraddress,
    input wire iready,  
    output reg [31:0] instruction,  
    output reg hit,
    output reg miss,
    output reg  [31:0] fetchaddr       
);

    localparam NUMBLOCKS = CACHESIZE / BLOCKSIZE;
    localparam NUMSETS = NUMBLOCKS / ASSOCIATIVITY;
    localparam OFFSETBITS = $clog2(BLOCKSIZE);    
    localparam SETBITS = $clog2(NUMSETS);
    localparam TAGBITS = 32 - SETBITS - OFFSETBITS;
    localparam WAYBITS = $clog2(ASSOCIATIVITY);

    wire [TAGBITS-1:0] tag = instraddress[31:(32-TAGBITS)];
    wire [SETBITS-1:0] index = instraddress[(32-TAGBITS-1):OFFSETBITS];

    wire [TAGBITS-1:0] miss_tag = miss_address[31:(32-TAGBITS)];
    wire [SETBITS-1:0] miss_index = miss_address[(32-TAGBITS-1):OFFSETBITS];

    reg [TAGBITS-1:0] tagarray [0:NUMSETS-1][0:ASSOCIATIVITY-1];
    reg [31:0] dataarray [0:NUMSETS-1][0:ASSOCIATIVITY-1];
    reg validarray [0:NUMSETS-1][0:ASSOCIATIVITY-1];
    reg [WAYBITS-1:0] fifo_ptr [0:NUMSETS-1];

    reg [31:0] miss_address;
    reg miss_pending;

    integer i, w;
    reg [WAYBITS-1:0] hit_way;
    reg hit_found;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
        
            for (i = 0; i < NUMSETS; i = i + 1) begin
                fifo_ptr[i] <= 0;
                for (w = 0; w < ASSOCIATIVITY; w = w + 1) begin
                    tagarray[i][w] <= 0;
                    dataarray[i][w] <= 0;
                    validarray[i][w] <= 0;
                end
            end
            instruction <= 32'b0;
            hit <= 0;
            miss <= 0;
            fetchaddr <= 32'b0;
            miss_pending <= 0;
            miss_address <= 32'b0;
        end else begin
            hit  <= 0;
            miss <= 0;

            if (miss_pending) begin
            
                if (iready) begin
            
                    dataarray[miss_index][fifo_ptr[miss_index]] <= ifetch;
                    tagarray[miss_index][fifo_ptr[miss_index]]  <= miss_tag;
                    validarray[miss_index][fifo_ptr[miss_index]] <= 1;

                    fifo_ptr[miss_index] <= (fifo_ptr[miss_index] + 1) % ASSOCIATIVITY;

                    instruction <= ifetch;
                    hit <= 1;
                    miss <= 0;
                    fetchaddr <= 0;
                    miss_pending <= 0;
                end
            end else begin
   
                hit_found = 0;
                hit_way   = 0;

                for (w = 0; w < ASSOCIATIVITY; w = w + 1) begin
                    if (validarray[index][w] && tagarray[index][w] == tag) begin
                        hit_found = 1;
                        hit_way = w;
                    end
                end

                if (hit_found) begin
                    instruction <= dataarray[index][hit_way];
                    hit <= 1;
                    miss <= 0;
                    fetchaddr <= 0;
                end else begin
           
                    miss_address <= instraddress; 
                    fetchaddr <= {instraddress[31:2], 2'b00};
                    miss <= 1;
                    hit  <= 0;
                    miss_pending <= 1;
                end
            end
        end
    end

endmodule
