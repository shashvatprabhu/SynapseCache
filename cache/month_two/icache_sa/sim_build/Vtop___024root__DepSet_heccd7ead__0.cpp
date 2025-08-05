// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cache_storage__DOT__clk = vlSelfRef.clk;
    vlSelfRef.cache_storage__DOT__reset = vlSelfRef.reset;
    vlSelfRef.cache_storage__DOT__read = vlSelfRef.read;
    vlSelfRef.cache_storage__DOT__write = vlSelfRef.write;
    vlSelfRef.cache_storage__DOT__address = vlSelfRef.address;
    vlSelfRef.cache_storage__DOT__write_data = vlSelfRef.write_data;
    vlSelfRef.cache_storage__DOT__write_tag = vlSelfRef.write_tag;
    vlSelfRef.cache_storage__DOT__way_select = vlSelfRef.way_select;
    vlSelfRef.cache_storage__DOT__write_valid = vlSelfRef.write_valid;
    vlSelfRef.cache_storage__DOT__index = (0xfU & vlSelfRef.address);
    vlSelfRef.cache_storage__DOT__tag = (vlSelfRef.address 
                                         >> 8U);
    vlSelfRef.read_data = vlSelfRef.cache_storage__DOT__read_data;
    vlSelfRef.hit = vlSelfRef.cache_storage__DOT__hit;
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__cache_storage__DOT__hit;
    __Vdly__cache_storage__DOT__hit = 0;
    CData/*0:0*/ __VdlySet__cache_storage__DOT__valid_bits__v0;
    __VdlySet__cache_storage__DOT__valid_bits__v0 = 0;
    CData/*0:0*/ __VdlyVal__cache_storage__DOT__valid_bits__v32;
    __VdlyVal__cache_storage__DOT__valid_bits__v32 = 0;
    CData/*0:0*/ __VdlyDim0__cache_storage__DOT__valid_bits__v32;
    __VdlyDim0__cache_storage__DOT__valid_bits__v32 = 0;
    CData/*3:0*/ __VdlyDim1__cache_storage__DOT__valid_bits__v32;
    __VdlyDim1__cache_storage__DOT__valid_bits__v32 = 0;
    CData/*0:0*/ __VdlySet__cache_storage__DOT__valid_bits__v32;
    __VdlySet__cache_storage__DOT__valid_bits__v32 = 0;
    CData/*0:0*/ __VdlySet__cache_storage__DOT__tag_array__v0;
    __VdlySet__cache_storage__DOT__tag_array__v0 = 0;
    IData/*23:0*/ __VdlyVal__cache_storage__DOT__tag_array__v32;
    __VdlyVal__cache_storage__DOT__tag_array__v32 = 0;
    CData/*0:0*/ __VdlyDim0__cache_storage__DOT__tag_array__v32;
    __VdlyDim0__cache_storage__DOT__tag_array__v32 = 0;
    CData/*3:0*/ __VdlyDim1__cache_storage__DOT__tag_array__v32;
    __VdlyDim1__cache_storage__DOT__tag_array__v32 = 0;
    CData/*0:0*/ __VdlySet__cache_storage__DOT__tag_array__v32;
    __VdlySet__cache_storage__DOT__tag_array__v32 = 0;
    CData/*0:0*/ __VdlySet__cache_storage__DOT__data_array__v0;
    __VdlySet__cache_storage__DOT__data_array__v0 = 0;
    IData/*31:0*/ __VdlyVal__cache_storage__DOT__data_array__v32;
    __VdlyVal__cache_storage__DOT__data_array__v32 = 0;
    CData/*0:0*/ __VdlyDim0__cache_storage__DOT__data_array__v32;
    __VdlyDim0__cache_storage__DOT__data_array__v32 = 0;
    CData/*3:0*/ __VdlyDim1__cache_storage__DOT__data_array__v32;
    __VdlyDim1__cache_storage__DOT__data_array__v32 = 0;
    CData/*0:0*/ __VdlySet__cache_storage__DOT__data_array__v32;
    __VdlySet__cache_storage__DOT__data_array__v32 = 0;
    // Body
    __VdlySet__cache_storage__DOT__valid_bits__v0 = 0U;
    __VdlySet__cache_storage__DOT__valid_bits__v32 = 0U;
    __VdlySet__cache_storage__DOT__tag_array__v0 = 0U;
    __VdlySet__cache_storage__DOT__tag_array__v32 = 0U;
    __VdlySet__cache_storage__DOT__data_array__v0 = 0U;
    __VdlySet__cache_storage__DOT__data_array__v32 = 0U;
    __Vdly__cache_storage__DOT__hit = vlSelfRef.cache_storage__DOT__hit;
    if (vlSelfRef.reset) {
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 1U;
        vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j = 2U;
        vlSelfRef.cache_storage__DOT__i = 1U;
        vlSelfRef.cache_storage__DOT__i = 2U;
        vlSelfRef.cache_storage__DOT__i = 3U;
        vlSelfRef.cache_storage__DOT__i = 4U;
        vlSelfRef.cache_storage__DOT__i = 5U;
        vlSelfRef.cache_storage__DOT__i = 6U;
        vlSelfRef.cache_storage__DOT__i = 7U;
        vlSelfRef.cache_storage__DOT__i = 8U;
        vlSelfRef.cache_storage__DOT__i = 9U;
        vlSelfRef.cache_storage__DOT__i = 0xaU;
        vlSelfRef.cache_storage__DOT__i = 0xbU;
        vlSelfRef.cache_storage__DOT__i = 0xcU;
        vlSelfRef.cache_storage__DOT__i = 0xdU;
        vlSelfRef.cache_storage__DOT__i = 0xeU;
        vlSelfRef.cache_storage__DOT__i = 0xfU;
        vlSelfRef.cache_storage__DOT__i = 0x10U;
        __VdlySet__cache_storage__DOT__valid_bits__v0 = 1U;
        __VdlySet__cache_storage__DOT__tag_array__v0 = 1U;
        __VdlySet__cache_storage__DOT__data_array__v0 = 1U;
        vlSelfRef.cache_storage__DOT__read_data = 0U;
        __Vdly__cache_storage__DOT__hit = 0U;
    } else {
        if (vlSelfRef.read) {
            vlSelfRef.cache_storage__DOT__i = 1U;
            vlSelfRef.cache_storage__DOT__i = 2U;
            __Vdly__cache_storage__DOT__hit = 0U;
            if ((vlSelfRef.cache_storage__DOT__valid_bits
                 [vlSelfRef.cache_storage__DOT__index]
                 [0U] & (vlSelfRef.cache_storage__DOT__tag_array
                         [vlSelfRef.cache_storage__DOT__index]
                         [0U] == vlSelfRef.cache_storage__DOT__tag))) {
                __Vdly__cache_storage__DOT__hit = 1U;
                vlSelfRef.cache_storage__DOT__read_data 
                    = vlSelfRef.cache_storage__DOT__data_array
                    [vlSelfRef.cache_storage__DOT__index]
                    [0U];
            }
            if ((vlSelfRef.cache_storage__DOT__valid_bits
                 [vlSelfRef.cache_storage__DOT__index]
                 [1U] & (vlSelfRef.cache_storage__DOT__tag_array
                         [vlSelfRef.cache_storage__DOT__index]
                         [1U] == vlSelfRef.cache_storage__DOT__tag))) {
                __Vdly__cache_storage__DOT__hit = 1U;
                vlSelfRef.cache_storage__DOT__read_data 
                    = vlSelfRef.cache_storage__DOT__data_array
                    [vlSelfRef.cache_storage__DOT__index]
                    [1U];
            }
            if ((1U & (~ (IData)(vlSelfRef.cache_storage__DOT__hit)))) {
                vlSelfRef.cache_storage__DOT__read_data = 0U;
            }
        }
        if (vlSelfRef.write) {
            __VdlyVal__cache_storage__DOT__valid_bits__v32 
                = vlSelfRef.write_valid;
            __VdlyDim0__cache_storage__DOT__valid_bits__v32 
                = vlSelfRef.way_select;
            __VdlyDim1__cache_storage__DOT__valid_bits__v32 
                = vlSelfRef.cache_storage__DOT__index;
            __VdlySet__cache_storage__DOT__valid_bits__v32 = 1U;
            __VdlyVal__cache_storage__DOT__tag_array__v32 
                = vlSelfRef.write_tag;
            __VdlyDim0__cache_storage__DOT__tag_array__v32 
                = vlSelfRef.way_select;
            __VdlyDim1__cache_storage__DOT__tag_array__v32 
                = vlSelfRef.cache_storage__DOT__index;
            __VdlySet__cache_storage__DOT__tag_array__v32 = 1U;
            __VdlyVal__cache_storage__DOT__data_array__v32 
                = vlSelfRef.write_data;
            __VdlyDim0__cache_storage__DOT__data_array__v32 
                = vlSelfRef.way_select;
            __VdlyDim1__cache_storage__DOT__data_array__v32 
                = vlSelfRef.cache_storage__DOT__index;
            __VdlySet__cache_storage__DOT__data_array__v32 = 1U;
        }
    }
    vlSelfRef.cache_storage__DOT__hit = __Vdly__cache_storage__DOT__hit;
    if (__VdlySet__cache_storage__DOT__valid_bits__v0) {
        vlSelfRef.cache_storage__DOT__valid_bits[0U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[1U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[1U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[2U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[2U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[3U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[3U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[4U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[4U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[5U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[5U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[6U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[6U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[7U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[7U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[8U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[8U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[9U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[9U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xaU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xaU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xbU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xbU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xcU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xcU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xdU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xdU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xeU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xeU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xfU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__valid_bits[0xfU][1U] = 0U;
    }
    if (__VdlySet__cache_storage__DOT__valid_bits__v32) {
        vlSelfRef.cache_storage__DOT__valid_bits[__VdlyDim1__cache_storage__DOT__valid_bits__v32][__VdlyDim0__cache_storage__DOT__valid_bits__v32] 
            = __VdlyVal__cache_storage__DOT__valid_bits__v32;
    }
    if (__VdlySet__cache_storage__DOT__tag_array__v0) {
        vlSelfRef.cache_storage__DOT__tag_array[0U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[1U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[1U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[2U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[2U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[3U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[3U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[4U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[4U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[5U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[5U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[6U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[6U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[7U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[7U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[8U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[8U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[9U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[9U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xaU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xaU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xbU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xbU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xcU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xcU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xdU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xdU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xeU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xeU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xfU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__tag_array[0xfU][1U] = 0U;
    }
    if (__VdlySet__cache_storage__DOT__tag_array__v32) {
        vlSelfRef.cache_storage__DOT__tag_array[__VdlyDim1__cache_storage__DOT__tag_array__v32][__VdlyDim0__cache_storage__DOT__tag_array__v32] 
            = __VdlyVal__cache_storage__DOT__tag_array__v32;
    }
    if (__VdlySet__cache_storage__DOT__data_array__v0) {
        vlSelfRef.cache_storage__DOT__data_array[0U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[1U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[1U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[2U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[2U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[3U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[3U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[4U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[4U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[5U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[5U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[6U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[6U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[7U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[7U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[8U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[8U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[9U][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[9U][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xaU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xaU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xbU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xbU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xcU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xcU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xdU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xdU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xeU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xeU][1U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xfU][0U] = 0U;
        vlSelfRef.cache_storage__DOT__data_array[0xfU][1U] = 0U;
    }
    if (__VdlySet__cache_storage__DOT__data_array__v32) {
        vlSelfRef.cache_storage__DOT__data_array[__VdlyDim1__cache_storage__DOT__data_array__v32][__VdlyDim0__cache_storage__DOT__data_array__v32] 
            = __VdlyVal__cache_storage__DOT__data_array__v32;
    }
    vlSelfRef.read_data = vlSelfRef.cache_storage__DOT__read_data;
    vlSelfRef.hit = vlSelfRef.cache_storage__DOT__hit;
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("cache_storage.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("cache_storage.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("cache_storage.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY(((vlSelfRef.read & 0xfeU)))) {
        Verilated::overWidthError("read");}
    if (VL_UNLIKELY(((vlSelfRef.write & 0xfeU)))) {
        Verilated::overWidthError("write");}
    if (VL_UNLIKELY(((vlSelfRef.write_tag & 0xff000000U)))) {
        Verilated::overWidthError("write_tag");}
    if (VL_UNLIKELY(((vlSelfRef.way_select & 0xfeU)))) {
        Verilated::overWidthError("way_select");}
    if (VL_UNLIKELY(((vlSelfRef.write_valid & 0xfeU)))) {
        Verilated::overWidthError("write_valid");}
}
#endif  // VL_DEBUG
