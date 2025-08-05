// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.reset));
    bufp->chgBit(oldp+2,(vlSelfRef.read));
    bufp->chgBit(oldp+3,(vlSelfRef.write));
    bufp->chgIData(oldp+4,(vlSelfRef.address),32);
    bufp->chgIData(oldp+5,(vlSelfRef.write_data),32);
    bufp->chgIData(oldp+6,(vlSelfRef.write_tag),24);
    bufp->chgBit(oldp+7,(vlSelfRef.way_select));
    bufp->chgBit(oldp+8,(vlSelfRef.write_valid));
    bufp->chgIData(oldp+9,(vlSelfRef.read_data),32);
    bufp->chgBit(oldp+10,(vlSelfRef.hit));
    bufp->chgBit(oldp+11,(vlSelfRef.cache_storage__DOT__clk));
    bufp->chgBit(oldp+12,(vlSelfRef.cache_storage__DOT__reset));
    bufp->chgBit(oldp+13,(vlSelfRef.cache_storage__DOT__read));
    bufp->chgBit(oldp+14,(vlSelfRef.cache_storage__DOT__write));
    bufp->chgIData(oldp+15,(vlSelfRef.cache_storage__DOT__address),32);
    bufp->chgIData(oldp+16,(vlSelfRef.cache_storage__DOT__write_data),32);
    bufp->chgIData(oldp+17,(vlSelfRef.cache_storage__DOT__write_tag),24);
    bufp->chgBit(oldp+18,(vlSelfRef.cache_storage__DOT__way_select));
    bufp->chgBit(oldp+19,(vlSelfRef.cache_storage__DOT__write_valid));
    bufp->chgIData(oldp+20,(vlSelfRef.cache_storage__DOT__read_data),32);
    bufp->chgBit(oldp+21,(vlSelfRef.cache_storage__DOT__hit));
    bufp->chgBit(oldp+22,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0U][0U]));
    bufp->chgBit(oldp+23,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0U][1U]));
    bufp->chgBit(oldp+24,(vlSelfRef.cache_storage__DOT__valid_bits
                          [1U][0U]));
    bufp->chgBit(oldp+25,(vlSelfRef.cache_storage__DOT__valid_bits
                          [1U][1U]));
    bufp->chgBit(oldp+26,(vlSelfRef.cache_storage__DOT__valid_bits
                          [2U][0U]));
    bufp->chgBit(oldp+27,(vlSelfRef.cache_storage__DOT__valid_bits
                          [2U][1U]));
    bufp->chgBit(oldp+28,(vlSelfRef.cache_storage__DOT__valid_bits
                          [3U][0U]));
    bufp->chgBit(oldp+29,(vlSelfRef.cache_storage__DOT__valid_bits
                          [3U][1U]));
    bufp->chgBit(oldp+30,(vlSelfRef.cache_storage__DOT__valid_bits
                          [4U][0U]));
    bufp->chgBit(oldp+31,(vlSelfRef.cache_storage__DOT__valid_bits
                          [4U][1U]));
    bufp->chgBit(oldp+32,(vlSelfRef.cache_storage__DOT__valid_bits
                          [5U][0U]));
    bufp->chgBit(oldp+33,(vlSelfRef.cache_storage__DOT__valid_bits
                          [5U][1U]));
    bufp->chgBit(oldp+34,(vlSelfRef.cache_storage__DOT__valid_bits
                          [6U][0U]));
    bufp->chgBit(oldp+35,(vlSelfRef.cache_storage__DOT__valid_bits
                          [6U][1U]));
    bufp->chgBit(oldp+36,(vlSelfRef.cache_storage__DOT__valid_bits
                          [7U][0U]));
    bufp->chgBit(oldp+37,(vlSelfRef.cache_storage__DOT__valid_bits
                          [7U][1U]));
    bufp->chgBit(oldp+38,(vlSelfRef.cache_storage__DOT__valid_bits
                          [8U][0U]));
    bufp->chgBit(oldp+39,(vlSelfRef.cache_storage__DOT__valid_bits
                          [8U][1U]));
    bufp->chgBit(oldp+40,(vlSelfRef.cache_storage__DOT__valid_bits
                          [9U][0U]));
    bufp->chgBit(oldp+41,(vlSelfRef.cache_storage__DOT__valid_bits
                          [9U][1U]));
    bufp->chgBit(oldp+42,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xaU][0U]));
    bufp->chgBit(oldp+43,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xaU][1U]));
    bufp->chgBit(oldp+44,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xbU][0U]));
    bufp->chgBit(oldp+45,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xbU][1U]));
    bufp->chgBit(oldp+46,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xcU][0U]));
    bufp->chgBit(oldp+47,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xcU][1U]));
    bufp->chgBit(oldp+48,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xdU][0U]));
    bufp->chgBit(oldp+49,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xdU][1U]));
    bufp->chgBit(oldp+50,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xeU][0U]));
    bufp->chgBit(oldp+51,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xeU][1U]));
    bufp->chgBit(oldp+52,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xfU][0U]));
    bufp->chgBit(oldp+53,(vlSelfRef.cache_storage__DOT__valid_bits
                          [0xfU][1U]));
    bufp->chgIData(oldp+54,(vlSelfRef.cache_storage__DOT__tag_array
                            [0U][0U]),24);
    bufp->chgIData(oldp+55,(vlSelfRef.cache_storage__DOT__tag_array
                            [0U][1U]),24);
    bufp->chgIData(oldp+56,(vlSelfRef.cache_storage__DOT__tag_array
                            [1U][0U]),24);
    bufp->chgIData(oldp+57,(vlSelfRef.cache_storage__DOT__tag_array
                            [1U][1U]),24);
    bufp->chgIData(oldp+58,(vlSelfRef.cache_storage__DOT__tag_array
                            [2U][0U]),24);
    bufp->chgIData(oldp+59,(vlSelfRef.cache_storage__DOT__tag_array
                            [2U][1U]),24);
    bufp->chgIData(oldp+60,(vlSelfRef.cache_storage__DOT__tag_array
                            [3U][0U]),24);
    bufp->chgIData(oldp+61,(vlSelfRef.cache_storage__DOT__tag_array
                            [3U][1U]),24);
    bufp->chgIData(oldp+62,(vlSelfRef.cache_storage__DOT__tag_array
                            [4U][0U]),24);
    bufp->chgIData(oldp+63,(vlSelfRef.cache_storage__DOT__tag_array
                            [4U][1U]),24);
    bufp->chgIData(oldp+64,(vlSelfRef.cache_storage__DOT__tag_array
                            [5U][0U]),24);
    bufp->chgIData(oldp+65,(vlSelfRef.cache_storage__DOT__tag_array
                            [5U][1U]),24);
    bufp->chgIData(oldp+66,(vlSelfRef.cache_storage__DOT__tag_array
                            [6U][0U]),24);
    bufp->chgIData(oldp+67,(vlSelfRef.cache_storage__DOT__tag_array
                            [6U][1U]),24);
    bufp->chgIData(oldp+68,(vlSelfRef.cache_storage__DOT__tag_array
                            [7U][0U]),24);
    bufp->chgIData(oldp+69,(vlSelfRef.cache_storage__DOT__tag_array
                            [7U][1U]),24);
    bufp->chgIData(oldp+70,(vlSelfRef.cache_storage__DOT__tag_array
                            [8U][0U]),24);
    bufp->chgIData(oldp+71,(vlSelfRef.cache_storage__DOT__tag_array
                            [8U][1U]),24);
    bufp->chgIData(oldp+72,(vlSelfRef.cache_storage__DOT__tag_array
                            [9U][0U]),24);
    bufp->chgIData(oldp+73,(vlSelfRef.cache_storage__DOT__tag_array
                            [9U][1U]),24);
    bufp->chgIData(oldp+74,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xaU][0U]),24);
    bufp->chgIData(oldp+75,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xaU][1U]),24);
    bufp->chgIData(oldp+76,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xbU][0U]),24);
    bufp->chgIData(oldp+77,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xbU][1U]),24);
    bufp->chgIData(oldp+78,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xcU][0U]),24);
    bufp->chgIData(oldp+79,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xcU][1U]),24);
    bufp->chgIData(oldp+80,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xdU][0U]),24);
    bufp->chgIData(oldp+81,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xdU][1U]),24);
    bufp->chgIData(oldp+82,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xeU][0U]),24);
    bufp->chgIData(oldp+83,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xeU][1U]),24);
    bufp->chgIData(oldp+84,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xfU][0U]),24);
    bufp->chgIData(oldp+85,(vlSelfRef.cache_storage__DOT__tag_array
                            [0xfU][1U]),24);
    bufp->chgIData(oldp+86,(vlSelfRef.cache_storage__DOT__data_array
                            [0U][0U]),32);
    bufp->chgIData(oldp+87,(vlSelfRef.cache_storage__DOT__data_array
                            [0U][1U]),32);
    bufp->chgIData(oldp+88,(vlSelfRef.cache_storage__DOT__data_array
                            [1U][0U]),32);
    bufp->chgIData(oldp+89,(vlSelfRef.cache_storage__DOT__data_array
                            [1U][1U]),32);
    bufp->chgIData(oldp+90,(vlSelfRef.cache_storage__DOT__data_array
                            [2U][0U]),32);
    bufp->chgIData(oldp+91,(vlSelfRef.cache_storage__DOT__data_array
                            [2U][1U]),32);
    bufp->chgIData(oldp+92,(vlSelfRef.cache_storage__DOT__data_array
                            [3U][0U]),32);
    bufp->chgIData(oldp+93,(vlSelfRef.cache_storage__DOT__data_array
                            [3U][1U]),32);
    bufp->chgIData(oldp+94,(vlSelfRef.cache_storage__DOT__data_array
                            [4U][0U]),32);
    bufp->chgIData(oldp+95,(vlSelfRef.cache_storage__DOT__data_array
                            [4U][1U]),32);
    bufp->chgIData(oldp+96,(vlSelfRef.cache_storage__DOT__data_array
                            [5U][0U]),32);
    bufp->chgIData(oldp+97,(vlSelfRef.cache_storage__DOT__data_array
                            [5U][1U]),32);
    bufp->chgIData(oldp+98,(vlSelfRef.cache_storage__DOT__data_array
                            [6U][0U]),32);
    bufp->chgIData(oldp+99,(vlSelfRef.cache_storage__DOT__data_array
                            [6U][1U]),32);
    bufp->chgIData(oldp+100,(vlSelfRef.cache_storage__DOT__data_array
                             [7U][0U]),32);
    bufp->chgIData(oldp+101,(vlSelfRef.cache_storage__DOT__data_array
                             [7U][1U]),32);
    bufp->chgIData(oldp+102,(vlSelfRef.cache_storage__DOT__data_array
                             [8U][0U]),32);
    bufp->chgIData(oldp+103,(vlSelfRef.cache_storage__DOT__data_array
                             [8U][1U]),32);
    bufp->chgIData(oldp+104,(vlSelfRef.cache_storage__DOT__data_array
                             [9U][0U]),32);
    bufp->chgIData(oldp+105,(vlSelfRef.cache_storage__DOT__data_array
                             [9U][1U]),32);
    bufp->chgIData(oldp+106,(vlSelfRef.cache_storage__DOT__data_array
                             [0xaU][0U]),32);
    bufp->chgIData(oldp+107,(vlSelfRef.cache_storage__DOT__data_array
                             [0xaU][1U]),32);
    bufp->chgIData(oldp+108,(vlSelfRef.cache_storage__DOT__data_array
                             [0xbU][0U]),32);
    bufp->chgIData(oldp+109,(vlSelfRef.cache_storage__DOT__data_array
                             [0xbU][1U]),32);
    bufp->chgIData(oldp+110,(vlSelfRef.cache_storage__DOT__data_array
                             [0xcU][0U]),32);
    bufp->chgIData(oldp+111,(vlSelfRef.cache_storage__DOT__data_array
                             [0xcU][1U]),32);
    bufp->chgIData(oldp+112,(vlSelfRef.cache_storage__DOT__data_array
                             [0xdU][0U]),32);
    bufp->chgIData(oldp+113,(vlSelfRef.cache_storage__DOT__data_array
                             [0xdU][1U]),32);
    bufp->chgIData(oldp+114,(vlSelfRef.cache_storage__DOT__data_array
                             [0xeU][0U]),32);
    bufp->chgIData(oldp+115,(vlSelfRef.cache_storage__DOT__data_array
                             [0xeU][1U]),32);
    bufp->chgIData(oldp+116,(vlSelfRef.cache_storage__DOT__data_array
                             [0xfU][0U]),32);
    bufp->chgIData(oldp+117,(vlSelfRef.cache_storage__DOT__data_array
                             [0xfU][1U]),32);
    bufp->chgCData(oldp+118,(vlSelfRef.cache_storage__DOT__index),4);
    bufp->chgIData(oldp+119,(vlSelfRef.cache_storage__DOT__tag),24);
    bufp->chgIData(oldp+120,(vlSelfRef.cache_storage__DOT__i),32);
    bufp->chgIData(oldp+121,(vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
