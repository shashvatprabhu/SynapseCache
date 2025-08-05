// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vicache_fifo_tb.h for the primary calling header

#include "Vicache_fifo_tb.h"
#include "Vicache_fifo_tb__Syms.h"

//==========

VL_CTOR_IMP(Vicache_fifo_tb) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = __VlSymsp = new Vicache_fifo_tb__Syms(this, name());
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vicache_fifo_tb::__Vconfigure(Vicache_fifo_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vicache_fifo_tb::~Vicache_fifo_tb() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vicache_fifo_tb::_initial__TOP__1(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_initial__TOP__1\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->icache_fifo_tb__DOT__clk = 0U;
    vlTOPp->icache_fifo_tb__DOT__total_hits = 0U;
    vlTOPp->icache_fifo_tb__DOT__total_misses = 0U;
    vlTOPp->icache_fifo_tb__DOT__total_accesses = 0U;
    vlTOPp->icache_fifo_tb__DOT__cycle = 0U;
    vlTOPp->icache_fifo_tb__DOT__i = 0U;
    vlTOPp->icache_fifo_tb__DOT__state = 0U;
    vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_GTS_III(1,32,32, 0x400U, vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j)) {
        vlTOPp->icache_fifo_tb__DOT__memory[(0x3ffU 
                                             & vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j)] 
            = ((IData)(0xa0000000U) + vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j);
        vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j 
            = ((IData)(1U) + vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j);
    }
    VL_WRITEF("Starting simulation...\n");
}

void Vicache_fifo_tb::_settle__TOP__5(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_settle__TOP__5\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->icache_fifo_tb__DOT__uut__DOT__i = 1U;
    vlTOPp->icache_fifo_tb__DOT__uut__DOT__matched_way = 0U;
    if ((vlTOPp->icache_fifo_tb__DOT__uut__DOT__valid_bits
         [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                    >> 2U))][0U] & (vlTOPp->icache_fifo_tb__DOT__uut__DOT__tag_bits
                                    [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                               >> 2U))]
                                    [0U] == (0x3fffffU 
                                             & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                                >> 0xaU))))) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__matched_way = 0U;
    }
    vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found = 0U;
    if ((vlTOPp->icache_fifo_tb__DOT__uut__DOT__valid_bits
         [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                    >> 2U))][0U] & (vlTOPp->icache_fifo_tb__DOT__uut__DOT__tag_bits
                                    [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                               >> 2U))]
                                    [0U] == (0x3fffffU 
                                             & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                                >> 0xaU))))) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found = 1U;
    }
    vlTOPp->icache_fifo_tb__DOT__clk = (1U & (~ (IData)(vlTOPp->icache_fifo_tb__DOT__clk)));
    vlTOPp->icache_fifo_tb__DOT__hit = 0U;
    if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
        if (vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found) {
            vlTOPp->icache_fifo_tb__DOT__hit = 1U;
        }
    }
    vlTOPp->icache_fifo_tb__DOT__miss = 0U;
    if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found)))) {
            vlTOPp->icache_fifo_tb__DOT__miss = 1U;
        }
    }
    vlTOPp->icache_fifo_tb__DOT__mem_req = 0U;
    if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found)))) {
            vlTOPp->icache_fifo_tb__DOT__mem_req = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
            vlTOPp->icache_fifo_tb__DOT__mem_req = 1U;
        }
    }
    vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state 
        = vlTOPp->icache_fifo_tb__DOT__uut__DOT__state;
    if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found)))) {
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state = 1U;
        }
    } else {
        if ((1U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
            if (vlTOPp->icache_fifo_tb__DOT__mem_instr_valid) {
                vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state = 2U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
                vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state = 0U;
            }
        }
    }
    vlTOPp->icache_fifo_tb__DOT__mem_addr = 0U;
    if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found)))) {
            vlTOPp->icache_fifo_tb__DOT__mem_addr = 
                (0xfffffffcU & vlTOPp->icache_fifo_tb__DOT__instr_addr);
        }
    } else {
        if ((1U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
            vlTOPp->icache_fifo_tb__DOT__mem_addr = 
                (0xfffffffcU & vlTOPp->icache_fifo_tb__DOT__instr_addr);
        }
    }
}

void Vicache_fifo_tb::_eval_initial(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_eval_initial\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk 
        = vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__rst 
        = vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__rst;
}

void Vicache_fifo_tb::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::final\n"); );
    // Variables
    Vicache_fifo_tb__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vicache_fifo_tb::_eval_settle(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_eval_settle\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vicache_fifo_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_ctor_var_reset\n"); );
    // Body
    icache_fifo_tb__DOT__clk = VL_RAND_RESET_I(1);
    icache_fifo_tb__DOT__rst = VL_RAND_RESET_I(1);
    icache_fifo_tb__DOT__instr_addr = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__mem_instr = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__mem_instr_valid = VL_RAND_RESET_I(1);
    icache_fifo_tb__DOT__instr = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__hit = VL_RAND_RESET_I(1);
    icache_fifo_tb__DOT__miss = VL_RAND_RESET_I(1);
    icache_fifo_tb__DOT__mem_addr = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__mem_req = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            icache_fifo_tb__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    icache_fifo_tb__DOT__total_hits = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__total_misses = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__total_accesses = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__last_addr = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__cycle = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__i = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__state = VL_RAND_RESET_I(8);
    icache_fifo_tb__DOT__unnamedblk1__DOT__j = 0;
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            { int __Vi1=0; for (; __Vi1<1; ++__Vi1) {
                    icache_fifo_tb__DOT__uut__DOT__tag_bits[__Vi0][__Vi1] = VL_RAND_RESET_I(22);
            }}
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            { int __Vi1=0; for (; __Vi1<1; ++__Vi1) {
                    icache_fifo_tb__DOT__uut__DOT__valid_bits[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
            }}
    }}
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            { int __Vi1=0; for (; __Vi1<1; ++__Vi1) {
                    { int __Vi2=0; for (; __Vi2<1; ++__Vi2) {
                            icache_fifo_tb__DOT__uut__DOT__data_bits[__Vi0][__Vi1][__Vi2] = VL_RAND_RESET_I(32);
                    }}
            }}
    }}
    icache_fifo_tb__DOT__uut__DOT__i = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__uut__DOT__j = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__uut__DOT__k = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__uut__DOT__hit_found = VL_RAND_RESET_I(1);
    icache_fifo_tb__DOT__uut__DOT__matched_way = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            icache_fifo_tb__DOT__uut__DOT__fifo_ptr[__Vi0] = VL_RAND_RESET_I(2);
    }}
    icache_fifo_tb__DOT__uut__DOT__state = VL_RAND_RESET_I(2);
    icache_fifo_tb__DOT__uut__DOT__next_state = VL_RAND_RESET_I(2);
    icache_fifo_tb__DOT__uut__DOT____Vlvbound4 = VL_RAND_RESET_I(32);
    icache_fifo_tb__DOT__uut__DOT____Vlvbound5 = VL_RAND_RESET_I(22);
    icache_fifo_tb__DOT__uut__DOT____Vlvbound6 = VL_RAND_RESET_I(1);
    __Vdly__icache_fifo_tb__DOT__rst = VL_RAND_RESET_I(1);
    __Vdly__icache_fifo_tb__DOT__instr_addr = VL_RAND_RESET_I(32);
    __Vdly__icache_fifo_tb__DOT__mem_instr = VL_RAND_RESET_I(32);
    __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__data_bits__v0 = 0;
    __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0 = 0;
    __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0 = 0;
    __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0 = 0;
    __VinpClk__TOP__icache_fifo_tb__DOT__clk = VL_RAND_RESET_I(1);
    __VinpClk__TOP__icache_fifo_tb__DOT__rst = VL_RAND_RESET_I(1);
    __Vchglast__TOP__icache_fifo_tb__DOT__clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__icache_fifo_tb__DOT__rst = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
