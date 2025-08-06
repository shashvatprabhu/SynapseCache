// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(CPU_READ,0,0);
    VL_OUT8(CPU_BUSYWAIT,0,0);
    VL_IN8(MEM_BUSYWAIT,0,0);
    VL_OUT8(MEM_READ_REQ,0,0);
    VL_IN8(MEM_READDATA_VALID,0,0);
    VL_IN8(HIT,0,0);
    VL_IN8(VALID,0,0);
    VL_OUT8(COMPARE_EN,0,0);
    VL_OUT8(WRITE_ENABLE,0,0);
    VL_OUT8(CACHE_WRITEVALID,0,0);
    CData/*0:0*/ cache_controller__DOT__clk;
    CData/*0:0*/ cache_controller__DOT__reset;
    CData/*0:0*/ cache_controller__DOT__CPU_READ;
    CData/*0:0*/ cache_controller__DOT__CPU_BUSYWAIT;
    CData/*0:0*/ cache_controller__DOT__MEM_BUSYWAIT;
    CData/*0:0*/ cache_controller__DOT__MEM_READ_REQ;
    CData/*0:0*/ cache_controller__DOT__MEM_READDATA_VALID;
    CData/*0:0*/ cache_controller__DOT__HIT;
    CData/*0:0*/ cache_controller__DOT__VALID;
    CData/*0:0*/ cache_controller__DOT__COMPARE_EN;
    CData/*0:0*/ cache_controller__DOT__WRITE_ENABLE;
    CData/*0:0*/ cache_controller__DOT__CACHE_WRITEVALID;
    CData/*1:0*/ cache_controller__DOT__state;
    CData/*1:0*/ cache_controller__DOT__next_state;
    CData/*4:0*/ cache_controller__DOT__index;
    CData/*1:0*/ cache_controller__DOT__offset;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(CPU_ADDRESS,31,0);
    VL_OUT(CPU_INSTR,31,0);
    VL_OUT(MEM_ADDRESS,31,0);
    VL_IN(MEM_READDATA,31,0);
    VL_IN(CACHE_READDATA,31,0);
    VL_IN(STORED_TAG,24,0);
    VL_OUT(CACHE_ADDRESS,31,0);
    VL_OUT(CACHE_WRITEDATA,31,0);
    VL_OUT(CACHE_WRITETAG,24,0);
    IData/*31:0*/ cache_controller__DOT__CPU_ADDRESS;
    IData/*31:0*/ cache_controller__DOT__CPU_INSTR;
    IData/*31:0*/ cache_controller__DOT__MEM_ADDRESS;
    IData/*31:0*/ cache_controller__DOT__MEM_READDATA;
    IData/*31:0*/ cache_controller__DOT__CACHE_READDATA;
    IData/*24:0*/ cache_controller__DOT__STORED_TAG;
    IData/*31:0*/ cache_controller__DOT__CACHE_ADDRESS;
    IData/*31:0*/ cache_controller__DOT__CACHE_WRITEDATA;
    IData/*24:0*/ cache_controller__DOT__CACHE_WRITETAG;
    IData/*31:0*/ cache_controller__DOT__saved_address;
    IData/*24:0*/ cache_controller__DOT__tag;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*1:0*/ cache_controller__DOT__IDLE = 0U;
    static constexpr CData/*1:0*/ cache_controller__DOT__READ_MEM = 1U;
    static constexpr CData/*1:0*/ cache_controller__DOT__UPDATE_CACHE = 2U;
    static constexpr CData/*1:0*/ cache_controller__DOT__WAIT_READ = 3U;
    static constexpr IData/*31:0*/ cache_controller__DOT__ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ cache_controller__DOT__DATA_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ cache_controller__DOT__BLOCK_SIZE = 4U;
    static constexpr IData/*31:0*/ cache_controller__DOT__INDEX_WIDTH = 5U;
    static constexpr IData/*31:0*/ cache_controller__DOT__TAG_WIDTH = 0x00000019U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
