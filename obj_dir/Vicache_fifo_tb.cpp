// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vicache_fifo_tb.h for the primary calling header

#include "Vicache_fifo_tb.h"
#include "Vicache_fifo_tb__Syms.h"

//==========

void Vicache_fifo_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vicache_fifo_tb::eval\n"); );
    Vicache_fifo_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb/icache_fifo_tb.v", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vicache_fifo_tb::_eval_initial_loop(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tb/icache_fifo_tb.v", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vicache_fifo_tb::_combo__TOP__2(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_combo__TOP__2\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->icache_fifo_tb__DOT__clk = (1U & (~ (IData)(vlTOPp->icache_fifo_tb__DOT__clk)));
}

VL_INLINE_OPT void Vicache_fifo_tb::_sequent__TOP__3(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_sequent__TOP__3\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0 = 0U;
    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__data_bits__v0 = 0U;
    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0 = 0U;
    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0 = 0U;
}

VL_INLINE_OPT void Vicache_fifo_tb::_sequent__TOP__4(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_sequent__TOP__4\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__icache_fifo_tb__DOT__state;
    IData/*31:0*/ __Vdly__icache_fifo_tb__DOT__cycle;
    IData/*31:0*/ __Vdly__icache_fifo_tb__DOT__total_hits;
    IData/*31:0*/ __Vdly__icache_fifo_tb__DOT__total_misses;
    IData/*31:0*/ __Vdly__icache_fifo_tb__DOT__total_accesses;
    // Body
    vlTOPp->__Vdly__icache_fifo_tb__DOT__rst = vlTOPp->icache_fifo_tb__DOT__rst;
    vlTOPp->__Vdly__icache_fifo_tb__DOT__mem_instr 
        = vlTOPp->icache_fifo_tb__DOT__mem_instr;
    __Vdly__icache_fifo_tb__DOT__total_accesses = vlTOPp->icache_fifo_tb__DOT__total_accesses;
    __Vdly__icache_fifo_tb__DOT__total_misses = vlTOPp->icache_fifo_tb__DOT__total_misses;
    __Vdly__icache_fifo_tb__DOT__total_hits = vlTOPp->icache_fifo_tb__DOT__total_hits;
    __Vdly__icache_fifo_tb__DOT__state = vlTOPp->icache_fifo_tb__DOT__state;
    __Vdly__icache_fifo_tb__DOT__cycle = vlTOPp->icache_fifo_tb__DOT__cycle;
    vlTOPp->__Vdly__icache_fifo_tb__DOT__instr_addr 
        = vlTOPp->icache_fifo_tb__DOT__instr_addr;
    __Vdly__icache_fifo_tb__DOT__cycle = ((IData)(1U) 
                                          + vlTOPp->icache_fifo_tb__DOT__cycle);
    if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__state))) {
        vlTOPp->__Vdly__icache_fifo_tb__DOT__rst = 1U;
        vlTOPp->__Vdly__icache_fifo_tb__DOT__instr_addr = 0U;
        vlTOPp->__Vdly__icache_fifo_tb__DOT__mem_instr = 0U;
        vlTOPp->icache_fifo_tb__DOT__mem_instr_valid = 0U;
        __Vdly__icache_fifo_tb__DOT__state = 1U;
    } else {
        if ((1U == (IData)(vlTOPp->icache_fifo_tb__DOT__state))) {
            if (VL_LTES_III(1,32,32, 0xaU, vlTOPp->icache_fifo_tb__DOT__cycle)) {
                vlTOPp->__Vdly__icache_fifo_tb__DOT__rst = 0U;
                __Vdly__icache_fifo_tb__DOT__state = 2U;
            }
        } else {
            if ((2U == (IData)(vlTOPp->icache_fifo_tb__DOT__state))) {
                if (VL_GTS_III(1,32,32, 0x1f4U, vlTOPp->icache_fifo_tb__DOT__i)) {
                    vlTOPp->icache_fifo_tb__DOT__last_addr 
                        = vlTOPp->icache_fifo_tb__DOT__instr_addr;
                    __Vdly__icache_fifo_tb__DOT__state = 3U;
                    vlTOPp->__Vdly__icache_fifo_tb__DOT__instr_addr 
                        = (0xffcU & VL_RANDOM_I(32));
                } else {
                    __Vdly__icache_fifo_tb__DOT__state = 0xaU;
                }
            } else {
                if ((3U == (IData)(vlTOPp->icache_fifo_tb__DOT__state))) {
                    if (vlTOPp->icache_fifo_tb__DOT__mem_req) {
                        vlTOPp->__Vdly__icache_fifo_tb__DOT__mem_instr 
                            = vlTOPp->icache_fifo_tb__DOT__memory
                            [(0x3ffU & (vlTOPp->icache_fifo_tb__DOT__mem_addr 
                                        >> 2U))];
                        vlTOPp->icache_fifo_tb__DOT__mem_instr_valid = 1U;
                        __Vdly__icache_fifo_tb__DOT__state = 4U;
                    } else {
                        __Vdly__icache_fifo_tb__DOT__state = 5U;
                    }
                } else {
                    if ((4U == (IData)(vlTOPp->icache_fifo_tb__DOT__state))) {
                        vlTOPp->icache_fifo_tb__DOT__mem_instr_valid = 0U;
                        __Vdly__icache_fifo_tb__DOT__state = 5U;
                    } else {
                        if ((5U == (IData)(vlTOPp->icache_fifo_tb__DOT__state))) {
                            if (VL_UNLIKELY(((IData)(vlTOPp->icache_fifo_tb__DOT__hit) 
                                             | (IData)(vlTOPp->icache_fifo_tb__DOT__miss)))) {
                                if (vlTOPp->icache_fifo_tb__DOT__hit) {
                                    __Vdly__icache_fifo_tb__DOT__total_hits 
                                        = ((IData)(1U) 
                                           + vlTOPp->icache_fifo_tb__DOT__total_hits);
                                } else {
                                    __Vdly__icache_fifo_tb__DOT__total_misses 
                                        = ((IData)(1U) 
                                           + vlTOPp->icache_fifo_tb__DOT__total_misses);
                                }
                                __Vdly__icache_fifo_tb__DOT__total_accesses 
                                    = ((IData)(1U) 
                                       + vlTOPp->icache_fifo_tb__DOT__total_accesses);
                                VL_WRITEF("[%0t ns] Addr = 0x%08x | HIT = %b | MISS = %b | INSTR = 0x%08x\n",
                                          64,(0x3e8ULL 
                                              * (QData)(VL_TIME_UNITED_Q(1000))),
                                          32,vlTOPp->icache_fifo_tb__DOT__instr_addr,
                                          1,(IData)(vlTOPp->icache_fifo_tb__DOT__hit),
                                          1,vlTOPp->icache_fifo_tb__DOT__miss,
                                          32,vlTOPp->icache_fifo_tb__DOT__instr);
                                vlTOPp->icache_fifo_tb__DOT__i 
                                    = ((IData)(1U) 
                                       + vlTOPp->icache_fifo_tb__DOT__i);
                                __Vdly__icache_fifo_tb__DOT__state = 2U;
                            }
                        } else {
                            if (VL_UNLIKELY((0xaU == (IData)(vlTOPp->icache_fifo_tb__DOT__state)))) {
                                VL_WRITEF("\n=== CACHE PERFORMANCE ===\n");
                                VL_WRITEF("Total Accesses : %0d\n",
                                          32,vlTOPp->icache_fifo_tb__DOT__total_accesses);
                                VL_WRITEF("Total Hits     : %0d\n",
                                          32,vlTOPp->icache_fifo_tb__DOT__total_hits);
                                VL_WRITEF("Total Misses   : %0d\n",
                                          32,vlTOPp->icache_fifo_tb__DOT__total_misses);
                                VL_WRITEF("Hit Rate       : %0.2f%%\n",
                                          64,((100.0 
                                               * VL_ITOR_D_I(vlTOPp->icache_fifo_tb__DOT__total_hits)) 
                                              / VL_ITOR_D_I(vlTOPp->icache_fifo_tb__DOT__total_accesses)));
                                VL_WRITEF("Miss Rate      : %0.2f%%\n",
                                          64,((100.0 
                                               * VL_ITOR_D_I(vlTOPp->icache_fifo_tb__DOT__total_misses)) 
                                              / VL_ITOR_D_I(vlTOPp->icache_fifo_tb__DOT__total_accesses)));
                                VL_WRITEF("==================================\n");
                                VL_FINISH_MT("tb/icache_fifo_tb.v", 138, "");
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->icache_fifo_tb__DOT__cycle = __Vdly__icache_fifo_tb__DOT__cycle;
    vlTOPp->icache_fifo_tb__DOT__state = __Vdly__icache_fifo_tb__DOT__state;
    vlTOPp->icache_fifo_tb__DOT__total_hits = __Vdly__icache_fifo_tb__DOT__total_hits;
    vlTOPp->icache_fifo_tb__DOT__total_misses = __Vdly__icache_fifo_tb__DOT__total_misses;
    vlTOPp->icache_fifo_tb__DOT__total_accesses = __Vdly__icache_fifo_tb__DOT__total_accesses;
}

VL_INLINE_OPT void Vicache_fifo_tb::_sequent__TOP__6(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_sequent__TOP__6\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__data_bits__v0;
    CData/*0:0*/ __Vdlyvdim2__icache_fifo_tb__DOT__uut__DOT__data_bits__v0;
    CData/*7:0*/ __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0;
    CData/*0:0*/ __Vdlyvdim1__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0;
    CData/*7:0*/ __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0;
    CData/*0:0*/ __Vdlyvdim1__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0;
    CData/*0:0*/ __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0;
    CData/*7:0*/ __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0;
    CData/*1:0*/ __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0;
    IData/*31:0*/ __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__data_bits__v0;
    IData/*21:0*/ __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0;
    // Body
    if (vlTOPp->icache_fifo_tb__DOT__rst) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__i = 0U;
        vlTOPp->icache_fifo_tb__DOT__instr = 0U;
        while (VL_GTS_III(1,32,32, 0x100U, vlTOPp->icache_fifo_tb__DOT__uut__DOT__i)) {
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr[(0xffU 
                                                             & vlTOPp->icache_fifo_tb__DOT__uut__DOT__i)] = 0U;
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__valid_bits[(0xffU 
                                                               & vlTOPp->icache_fifo_tb__DOT__uut__DOT__i)][0U] = 0U;
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__tag_bits[(0xffU 
                                                             & vlTOPp->icache_fifo_tb__DOT__uut__DOT__i)][0U] = 0U;
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__data_bits[(0xffU 
                                                              & vlTOPp->icache_fifo_tb__DOT__uut__DOT__i)][0U][0U] = 0U;
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__k = 1U;
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__j = 1U;
            vlTOPp->icache_fifo_tb__DOT__uut__DOT__i 
                = ((IData)(1U) + vlTOPp->icache_fifo_tb__DOT__uut__DOT__i);
        }
    } else {
        if ((0U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
            if (vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found) {
                vlTOPp->icache_fifo_tb__DOT__instr 
                    = ((0U >= (1U & (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__matched_way)))
                        ? vlTOPp->icache_fifo_tb__DOT__uut__DOT__data_bits
                       [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                  >> 2U))][0U][(1U 
                                                & (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__matched_way))]
                        : 0U);
            }
        } else {
            if ((2U == (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state))) {
                vlTOPp->icache_fifo_tb__DOT__uut__DOT____Vlvbound4 
                    = vlTOPp->icache_fifo_tb__DOT__mem_instr;
                if ((0U >= (1U & vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                            [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                       >> 2U))]))) {
                    __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__data_bits__v0 
                        = vlTOPp->icache_fifo_tb__DOT__uut__DOT____Vlvbound4;
                    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__data_bits__v0 = 1U;
                    __Vdlyvdim2__icache_fifo_tb__DOT__uut__DOT__data_bits__v0 
                        = (1U & vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                           [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                      >> 2U))]);
                    __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__data_bits__v0 
                        = (0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                    >> 2U));
                }
                vlTOPp->icache_fifo_tb__DOT__uut__DOT____Vlvbound5 
                    = (0x3fffffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                    >> 0xaU));
                if ((0U >= (1U & vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                            [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                       >> 2U))]))) {
                    __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0 
                        = vlTOPp->icache_fifo_tb__DOT__uut__DOT____Vlvbound5;
                    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0 = 1U;
                    __Vdlyvdim1__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0 
                        = (1U & vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                           [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                      >> 2U))]);
                    __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0 
                        = (0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                    >> 2U));
                }
                vlTOPp->icache_fifo_tb__DOT__uut__DOT____Vlvbound6 = 1U;
                if ((0U >= (1U & vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                            [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                       >> 2U))]))) {
                    __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0 
                        = vlTOPp->icache_fifo_tb__DOT__uut__DOT____Vlvbound6;
                    vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0 = 1U;
                    __Vdlyvdim1__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0 
                        = (1U & vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                           [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                      >> 2U))]);
                    __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0 
                        = (0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                    >> 2U));
                }
                __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0 
                    = ((0U == vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                        [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                   >> 2U))]) ? 0U : 
                       (3U & ((IData)(1U) + vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr
                              [(0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                         >> 2U))])));
                vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0 = 1U;
                __Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0 
                    = (0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                >> 2U));
            }
        }
    }
    if (vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__fifo_ptr[__Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0] 
            = __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0;
    }
    if (vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__data_bits__v0) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__data_bits[__Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__data_bits__v0][0U][__Vdlyvdim2__icache_fifo_tb__DOT__uut__DOT__data_bits__v0] 
            = __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__data_bits__v0;
    }
    if (vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__tag_bits[__Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0][__Vdlyvdim1__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0] 
            = __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0;
    }
    if (vlTOPp->__Vdlyvset__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0) {
        vlTOPp->icache_fifo_tb__DOT__uut__DOT__valid_bits[__Vdlyvdim0__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0][__Vdlyvdim1__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0] 
            = __Vdlyvval__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0;
    }
    vlTOPp->icache_fifo_tb__DOT__uut__DOT__state = 
        ((IData)(vlTOPp->icache_fifo_tb__DOT__rst) ? 0U
          : (IData)(vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state));
}

VL_INLINE_OPT void Vicache_fifo_tb::_sequent__TOP__7(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_sequent__TOP__7\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->icache_fifo_tb__DOT__mem_instr = vlTOPp->__Vdly__icache_fifo_tb__DOT__mem_instr;
    vlTOPp->icache_fifo_tb__DOT__instr_addr = vlTOPp->__Vdly__icache_fifo_tb__DOT__instr_addr;
    vlTOPp->icache_fifo_tb__DOT__rst = vlTOPp->__Vdly__icache_fifo_tb__DOT__rst;
}

VL_INLINE_OPT void Vicache_fifo_tb::_sequent__TOP__8(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_sequent__TOP__8\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vicache_fifo_tb::_eval(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_eval\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__2(vlSymsp);
    if ((((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__rst) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__rst))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__rst) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__rst))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__rst) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__rst))))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk 
        = vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__rst 
        = vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__rst;
    vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__clk 
        = vlTOPp->icache_fifo_tb__DOT__clk;
    vlTOPp->__VinpClk__TOP__icache_fifo_tb__DOT__rst 
        = vlTOPp->icache_fifo_tb__DOT__rst;
}

VL_INLINE_OPT QData Vicache_fifo_tb::_change_request(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_change_request\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vicache_fifo_tb::_change_request_1(Vicache_fifo_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_change_request_1\n"); );
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->icache_fifo_tb__DOT__clk ^ vlTOPp->__Vchglast__TOP__icache_fifo_tb__DOT__clk)
         | (vlTOPp->icache_fifo_tb__DOT__rst ^ vlTOPp->__Vchglast__TOP__icache_fifo_tb__DOT__rst));
    VL_DEBUG_IF( if(__req && ((vlTOPp->icache_fifo_tb__DOT__clk ^ vlTOPp->__Vchglast__TOP__icache_fifo_tb__DOT__clk))) VL_DBG_MSGF("        CHANGE: tb/icache_fifo_tb.v:15: icache_fifo_tb.clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->icache_fifo_tb__DOT__rst ^ vlTOPp->__Vchglast__TOP__icache_fifo_tb__DOT__rst))) VL_DBG_MSGF("        CHANGE: tb/icache_fifo_tb.v:15: icache_fifo_tb.rst\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__icache_fifo_tb__DOT__clk 
        = vlTOPp->icache_fifo_tb__DOT__clk;
    vlTOPp->__Vchglast__TOP__icache_fifo_tb__DOT__rst 
        = vlTOPp->icache_fifo_tb__DOT__rst;
    return __req;
}

#ifdef VL_DEBUG
void Vicache_fifo_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vicache_fifo_tb::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
