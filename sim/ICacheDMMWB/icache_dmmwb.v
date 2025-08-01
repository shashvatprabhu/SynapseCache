`timescale 1ns/1ps
`default_nettype none

module icache_dmmwb #(
    parameter WORDSPERBLOCK = 4               
)(
    input wire clk,
    input wire reset,
    input wire [31:0] ifetch,        
    input wire [31:0] instraddress,   
    input wire iready,         

    output reg [31:0] instruction,   
    output reg hit,
    output reg miss,
    output reg [31:0] fetchaddr      
);

    localparam CACHESIZE = 1024;                 
    localparam BLOCKSIZE = WORDSPERBLOCK * 4;   
    localparam NUMOFSETS = 256;                 
    localparam SETBITS = 8;                  
    localparam BLOCKOFFSETBITS = 2;                    
    localparam OFFSETBITS = 2 + BLOCKOFFSETBITS;  
    localparam TAGBITS = 32 - SETBITS - OFFSETBITS;

   
    reg [31:0] dataarray [0:NUMOFSETS-1][0:WORDSPERBLOCK-1]; 
    reg [TAGBITS-1:0] tagarray [0:NUMOFSETS-1];             
    reg valid [0:NUMOFSETS-1];                             

   
    wire [TAGBITS-1:0] tag = instraddress[31:32-TAGBITS];
    wire [SETBITS-1:0] index = instraddress[32-TAGBITS-1 -: SETBITS];
    wire [BLOCKOFFSETBITS-1:0] word_offset = instraddress[OFFSETBITS-1:2];

  
    reg miss_pending;
    reg [BLOCKOFFSETBITS:0] fetch_count;      
    reg [31:0] miss_address;                   
    reg [SETBITS-1:0] miss_index;
    reg [TAGBITS-1:0] miss_tag;

    integer i;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
          
            for (i = 0; i < NUMOFSETS; i = i + 1) begin
                valid[i] <= 0;
                tagarray[i] <= 0;
                for (int j = 0; j < WORDSPERBLOCK; j = j + 1) begin
                    dataarray[i][j] <= 0;
                end
            end
            instruction <= 32'b0;
            hit <= 0;
            miss <= 0;
            fetchaddr <= 32'b0;
            miss_pending <= 0;
            fetch_count <= 0;
            miss_address <= 32'b0;
        end else begin
            if (miss_pending) begin
             
                hit  <= 0;
                miss <= 1;

                if (iready) begin
                    dataarray[miss_index][fetch_count] <= ifetch;
                    fetch_count <= fetch_count + 1;
                    fetchaddr <= fetchaddr + 4;

                    if (fetch_count == WORDSPERBLOCK - 1) begin
                     
                        tagarray[miss_index] <= miss_tag;
                        valid[miss_index]    <= 1;

                        instruction <= ifetch;
                        hit <= 1;
                        miss <= 0;
                        miss_pending <= 0;
                    end
                end

            end else if (valid[index] && tagarray[index] == tag) begin
              
                instruction <= dataarray[index][word_offset];
                hit <= 1;
                miss <= 0;
                fetchaddr <= 32'b0;

            end else begin
              
                hit <= 0;
                miss = 1;
                fetchaddr <= {instraddress[31:OFFSETBITS], {OFFSETBITS{1'b0}}};  
                miss_address <= instraddress;
                miss_index <= index;
                miss_tag <= tag;
                fetch_count <= 0;
                miss_pending <= 1;
            end
        end
    end

endmodule
