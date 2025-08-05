// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vicache_fifo_tb__Syms.h"


void Vicache_fifo_tb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vicache_fifo_tb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+1,(vlTOPp->icache_fifo_tb__DOT__mem_instr_valid));
            tracep->chgIData(oldp+2,(vlTOPp->icache_fifo_tb__DOT__total_hits),32);
            tracep->chgIData(oldp+3,(vlTOPp->icache_fifo_tb__DOT__total_misses),32);
            tracep->chgIData(oldp+4,(vlTOPp->icache_fifo_tb__DOT__total_accesses),32);
            tracep->chgIData(oldp+5,(vlTOPp->icache_fifo_tb__DOT__last_addr),32);
            tracep->chgIData(oldp+6,(vlTOPp->icache_fifo_tb__DOT__cycle),32);
            tracep->chgIData(oldp+7,(vlTOPp->icache_fifo_tb__DOT__i),32);
            tracep->chgCData(oldp+8,(vlTOPp->icache_fifo_tb__DOT__state),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+9,(vlTOPp->icache_fifo_tb__DOT__instr),32);
            tracep->chgIData(oldp+10,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__i),32);
            tracep->chgIData(oldp+11,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__j),32);
            tracep->chgIData(oldp+12,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__k),32);
            tracep->chgCData(oldp+13,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state),2);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+14,(vlTOPp->icache_fifo_tb__DOT__rst));
            tracep->chgIData(oldp+15,(vlTOPp->icache_fifo_tb__DOT__instr_addr),32);
            tracep->chgIData(oldp+16,(vlTOPp->icache_fifo_tb__DOT__mem_instr),32);
            tracep->chgIData(oldp+17,((0x3fffffU & 
                                       (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                        >> 0xaU))),22);
            tracep->chgCData(oldp+18,((0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                                >> 2U))),8);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+19,(vlTOPp->icache_fifo_tb__DOT__hit));
            tracep->chgBit(oldp+20,(vlTOPp->icache_fifo_tb__DOT__miss));
            tracep->chgIData(oldp+21,(vlTOPp->icache_fifo_tb__DOT__mem_addr),32);
            tracep->chgBit(oldp+22,(vlTOPp->icache_fifo_tb__DOT__mem_req));
            tracep->chgBit(oldp+23,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found));
            tracep->chgCData(oldp+24,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__matched_way),2);
            tracep->chgCData(oldp+25,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state),2);
        }
        tracep->chgBit(oldp+26,(vlTOPp->icache_fifo_tb__DOT__clk));
    }
}

void Vicache_fifo_tb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
    }
}
