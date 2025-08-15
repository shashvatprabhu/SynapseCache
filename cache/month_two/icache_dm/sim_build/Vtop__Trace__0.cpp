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
    bufp->chgBit(oldp+2,(vlSelfRef.CPU_READ));
    bufp->chgIData(oldp+3,(vlSelfRef.CPU_ADDRESS),32);
    bufp->chgIData(oldp+4,(vlSelfRef.CPU_INSTR),32);
    bufp->chgBit(oldp+5,(vlSelfRef.CPU_BUSYWAIT));
    bufp->chgBit(oldp+6,(vlSelfRef.MEM_BUSYWAIT));
    bufp->chgBit(oldp+7,(vlSelfRef.MEM_READ_REQ));
    bufp->chgIData(oldp+8,(vlSelfRef.MEM_ADDRESS),32);
    bufp->chgIData(oldp+9,(vlSelfRef.MEM_READDATA),32);
    bufp->chgBit(oldp+10,(vlSelfRef.MEM_READDATA_VALID));
    bufp->chgBit(oldp+11,(vlSelfRef.HIT));
    bufp->chgIData(oldp+12,(vlSelfRef.CACHE_READDATA),32);
    bufp->chgIData(oldp+13,(vlSelfRef.STORED_TAG),24);
    bufp->chgBit(oldp+14,(vlSelfRef.VALID));
    bufp->chgBit(oldp+15,(vlSelfRef.COMPARE_EN));
    bufp->chgBit(oldp+16,(vlSelfRef.WRITE_ENABLE));
    bufp->chgIData(oldp+17,(vlSelfRef.CACHE_ADDRESS),32);
    bufp->chgIData(oldp+18,(vlSelfRef.CACHE_WRITEDATA),32);
    bufp->chgIData(oldp+19,(vlSelfRef.CACHE_WRITETAG),24);
    bufp->chgBit(oldp+20,(vlSelfRef.CACHE_WRITEVALID));
    bufp->chgBit(oldp+21,(vlSelfRef.cache_controller__DOT__clk));
    bufp->chgBit(oldp+22,(vlSelfRef.cache_controller__DOT__reset));
    bufp->chgBit(oldp+23,(vlSelfRef.cache_controller__DOT__CPU_READ));
    bufp->chgIData(oldp+24,(vlSelfRef.cache_controller__DOT__CPU_ADDRESS),32);
    bufp->chgIData(oldp+25,(vlSelfRef.cache_controller__DOT__CPU_INSTR),32);
    bufp->chgBit(oldp+26,(vlSelfRef.cache_controller__DOT__CPU_BUSYWAIT));
    bufp->chgBit(oldp+27,(vlSelfRef.cache_controller__DOT__MEM_BUSYWAIT));
    bufp->chgBit(oldp+28,(vlSelfRef.cache_controller__DOT__MEM_READ_REQ));
    bufp->chgIData(oldp+29,(vlSelfRef.cache_controller__DOT__MEM_ADDRESS),32);
    bufp->chgIData(oldp+30,(vlSelfRef.cache_controller__DOT__MEM_READDATA),32);
    bufp->chgBit(oldp+31,(vlSelfRef.cache_controller__DOT__MEM_READDATA_VALID));
    bufp->chgBit(oldp+32,(vlSelfRef.cache_controller__DOT__HIT));
    bufp->chgIData(oldp+33,(vlSelfRef.cache_controller__DOT__CACHE_READDATA),32);
    bufp->chgIData(oldp+34,(vlSelfRef.cache_controller__DOT__STORED_TAG),24);
    bufp->chgBit(oldp+35,(vlSelfRef.cache_controller__DOT__VALID));
    bufp->chgBit(oldp+36,(vlSelfRef.cache_controller__DOT__COMPARE_EN));
    bufp->chgBit(oldp+37,(vlSelfRef.cache_controller__DOT__WRITE_ENABLE));
    bufp->chgIData(oldp+38,(vlSelfRef.cache_controller__DOT__CACHE_ADDRESS),32);
    bufp->chgIData(oldp+39,(vlSelfRef.cache_controller__DOT__CACHE_WRITEDATA),32);
    bufp->chgIData(oldp+40,(vlSelfRef.cache_controller__DOT__CACHE_WRITETAG),24);
    bufp->chgBit(oldp+41,(vlSelfRef.cache_controller__DOT__CACHE_WRITEVALID));
    bufp->chgCData(oldp+42,(vlSelfRef.cache_controller__DOT__state),2);
    bufp->chgCData(oldp+43,(vlSelfRef.cache_controller__DOT__next_state),2);
    bufp->chgIData(oldp+44,(vlSelfRef.cache_controller__DOT__saved_address),32);
    bufp->chgIData(oldp+45,(vlSelfRef.cache_controller__DOT__tag),24);
    bufp->chgCData(oldp+46,(vlSelfRef.cache_controller__DOT__index),5);
    bufp->chgCData(oldp+47,(vlSelfRef.cache_controller__DOT__offset),3);
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
