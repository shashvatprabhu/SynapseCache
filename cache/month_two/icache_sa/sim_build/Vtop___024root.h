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
    VL_IN8(read,0,0);
    VL_IN8(write,0,0);
    VL_IN8(way_select,0,0);
    VL_IN8(write_valid,0,0);
    VL_OUT8(hit,0,0);
    CData/*0:0*/ cache_storage__DOT__clk;
    CData/*0:0*/ cache_storage__DOT__reset;
    CData/*0:0*/ cache_storage__DOT__read;
    CData/*0:0*/ cache_storage__DOT__write;
    CData/*0:0*/ cache_storage__DOT__way_select;
    CData/*0:0*/ cache_storage__DOT__write_valid;
    CData/*0:0*/ cache_storage__DOT__hit;
    CData/*3:0*/ cache_storage__DOT__index;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(address,31,0);
    VL_IN(write_data,31,0);
    VL_IN(write_tag,23,0);
    VL_OUT(read_data,31,0);
    IData/*31:0*/ cache_storage__DOT__address;
    IData/*31:0*/ cache_storage__DOT__write_data;
    IData/*23:0*/ cache_storage__DOT__write_tag;
    IData/*31:0*/ cache_storage__DOT__read_data;
    IData/*23:0*/ cache_storage__DOT__tag;
    IData/*31:0*/ cache_storage__DOT__i;
    IData/*31:0*/ cache_storage__DOT__RESET_LOOP__DOT__j;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 16> cache_storage__DOT__valid_bits;
    VlUnpacked<VlUnpacked<IData/*23:0*/, 2>, 16> cache_storage__DOT__tag_array;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 16> cache_storage__DOT__data_array;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr IData/*31:0*/ cache_storage__DOT__WORD_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ cache_storage__DOT__INDEX_BITS = 4U;
    static constexpr IData/*31:0*/ cache_storage__DOT__TAG_BITS = 0x00000018U;
    static constexpr IData/*31:0*/ cache_storage__DOT__ASSOCIATIVITY = 2U;
    static constexpr IData/*31:0*/ cache_storage__DOT__NUM_SETS = 0x00000010U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
