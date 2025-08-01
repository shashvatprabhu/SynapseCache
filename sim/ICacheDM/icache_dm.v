`timescale 1ns/1ps
`default_nettype none

module icache_dm (
    input wire clk,
    input wire reset,
    input wire [31:0] ifetch,      
    input wire [31:0] instraddress, 
    input wire iready,     
    output reg  [31:0] instruction,  
    output reg  hit,
    output reg miss,
    output reg  [31:0] fetchaddr 
);

    localparam CACHESIZE  = 1024;
    localparam NUMOFSETS  = 256;
    localparam SETBITS    = 8;
    localparam OFFSETBITS = 2;
    localparam TAGBITS    = 22;
  
    reg [TAGBITS-1:0] tagarray [0:NUMOFSETS-1];
    reg [31:0] dataarray [0:NUMOFSETS-1];
    reg  valid [0:NUMOFSETS-1];
    wire [TAGBITS-1:0] tag   = instraddress[31:(32-TAGBITS)];
    wire [SETBITS-1:0] index = instraddress[(32-TAGBITS-1):OFFSETBITS];
  
    reg miss_pending;
    reg [31:0] miss_address;

    integer i;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            for (i = 0; i < NUMOFSETS; i = i + 1) begin
                tagarray[i] <= 0;
                dataarray[i] <= 0;
                valid[i] <= 0;
            end
            instruction <= 32'b0;
            hit <= 0;
            miss <= 0;
            fetchaddr <= 32'b0;
            miss_pending <= 0;
            miss_address <= 32'b0;
        end else begin
            if (miss_pending) begin
                hit <= 0;
                miss <= 1;
                if (iready) begin
                         dataarray[index] <= ifetch;
                    tagarray[index] <= tag;
                    valid[index] <= 1;

                    instruction <= ifetch;
                    hit <= 1;
                    miss <= 0;
                    miss_pending <= 0;
                end
            end 
          else if (valid[index] && tagarray[index] == tag) begin
                instruction <= dataarray[index];
                hit <= 1;
                miss <= 0;
                fetchaddr <= 32'b0;
            end 
          else begin
                hit <= 0;
                miss <= 1;
                fetchaddr <= {instraddress[31:2], 2'b00};
                miss_pending <= 1;
                miss_address <= instraddress;
            end
        end
    end

endmodule
