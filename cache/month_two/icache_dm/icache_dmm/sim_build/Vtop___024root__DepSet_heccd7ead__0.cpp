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

extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h4976e89c_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.icache_controller__DOT__clk = vlSelfRef.clk;
    vlSelfRef.icache_controller__DOT__reset = vlSelfRef.reset;
    vlSelfRef.icache_controller__DOT__CPU_READ = vlSelfRef.CPU_READ;
    vlSelfRef.icache_controller__DOT__CPU_ADDRESS = vlSelfRef.CPU_ADDRESS;
    vlSelfRef.icache_controller__DOT__MEM_BUSYWAIT 
        = vlSelfRef.MEM_BUSYWAIT;
    vlSelfRef.icache_controller__DOT__MEM_READDATA 
        = vlSelfRef.MEM_READDATA;
    vlSelfRef.icache_controller__DOT__MEM_READDATA_VALID 
        = vlSelfRef.MEM_READDATA_VALID;
    vlSelfRef.icache_controller__DOT__HIT = vlSelfRef.HIT;
    vlSelfRef.icache_controller__DOT__CACHE_READDATA 
        = vlSelfRef.CACHE_READDATA;
    vlSelfRef.icache_controller__DOT__STORED_TAG = vlSelfRef.STORED_TAG;
    vlSelfRef.icache_controller__DOT__VALID = vlSelfRef.VALID;
    vlSelfRef.icache_controller__DOT__addr_index = 
        (0x1fU & vlSelfRef.CPU_ADDRESS);
    vlSelfRef.icache_controller__DOT__addr_tag = (vlSelfRef.CPU_ADDRESS 
                                                  >> 5U);
    vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID = 0U;
    vlSelfRef.icache_controller__DOT__WRITE_ENABLE = 0U;
    vlSelfRef.icache_controller__DOT__COMPARE_EN = 0U;
    vlSelfRef.icache_controller__DOT__MEM_READ_REQ = 0U;
    vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA = 0U;
    vlSelfRef.icache_controller__DOT__MEM_ADDRESS = 0U;
    vlSelfRef.icache_controller__DOT__CACHE_ADDRESS = 0U;
    vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT = 0U;
    __Vtableidx1 = (((((IData)(vlSelfRef.VALID) << 6U) 
                      | ((IData)(vlSelfRef.HIT) << 5U)) 
                     | (((IData)(vlSelfRef.CPU_READ) 
                         << 4U) | ((IData)(vlSelfRef.MEM_BUSYWAIT) 
                                   << 3U))) | (((IData)(vlSelfRef.MEM_READDATA_VALID) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.icache_controller__DOT__state)));
    vlSelfRef.icache_controller__DOT__next_state = 
        Vtop__ConstPool__TABLE_h4976e89c_0[__Vtableidx1];
    vlSelfRef.icache_controller__DOT__saved_tag = (vlSelfRef.icache_controller__DOT__saved_address 
                                                   >> 5U);
    vlSelfRef.icache_controller__DOT__CPU_INSTR = 0U;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((2U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID = 1U;
                vlSelfRef.icache_controller__DOT__WRITE_ENABLE = 1U;
            }
            vlSelfRef.CACHE_WRITEVALID = vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID;
        } else {
            vlSelfRef.CACHE_WRITEVALID = vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID;
        }
        vlSelfRef.WRITE_ENABLE = vlSelfRef.icache_controller__DOT__WRITE_ENABLE;
        if ((1U & (~ ((IData)(vlSelfRef.icache_controller__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.icache_controller__DOT__state)))) {
                vlSelfRef.icache_controller__DOT__COMPARE_EN = 1U;
            }
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__MEM_READ_REQ = 1U;
                vlSelfRef.icache_controller__DOT__MEM_ADDRESS 
                    = vlSelfRef.icache_controller__DOT__saved_address;
            }
        }
        vlSelfRef.COMPARE_EN = vlSelfRef.icache_controller__DOT__COMPARE_EN;
        vlSelfRef.MEM_READ_REQ = vlSelfRef.icache_controller__DOT__MEM_READ_REQ;
        if ((2U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA 
                    = vlSelfRef.MEM_READDATA;
                vlSelfRef.CACHE_WRITEDATA = vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA;
                vlSelfRef.MEM_ADDRESS = vlSelfRef.icache_controller__DOT__MEM_ADDRESS;
                vlSelfRef.icache_controller__DOT__CACHE_ADDRESS 
                    = vlSelfRef.icache_controller__DOT__saved_address;
            } else {
                vlSelfRef.CACHE_WRITEDATA = vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA;
                vlSelfRef.MEM_ADDRESS = vlSelfRef.icache_controller__DOT__MEM_ADDRESS;
            }
            vlSelfRef.CACHE_ADDRESS = vlSelfRef.icache_controller__DOT__CACHE_ADDRESS;
            vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT 
                = (1U & (~ (IData)(vlSelfRef.icache_controller__DOT__state)));
            vlSelfRef.CPU_BUSYWAIT = vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT;
            vlSelfRef.icache_controller__DOT__CACHE_WRITETAG = 0U;
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__CPU_INSTR 
                    = vlSelfRef.MEM_READDATA;
                vlSelfRef.icache_controller__DOT__CACHE_WRITETAG 
                    = vlSelfRef.icache_controller__DOT__saved_tag;
            }
        } else {
            vlSelfRef.CACHE_WRITEDATA = vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA;
            vlSelfRef.MEM_ADDRESS = vlSelfRef.icache_controller__DOT__MEM_ADDRESS;
            if ((1U & (~ (IData)(vlSelfRef.icache_controller__DOT__state)))) {
                if (vlSelfRef.CPU_READ) {
                    vlSelfRef.icache_controller__DOT__CACHE_ADDRESS 
                        = vlSelfRef.CPU_ADDRESS;
                    if (((IData)(vlSelfRef.HIT) & (IData)(vlSelfRef.VALID))) {
                        vlSelfRef.icache_controller__DOT__CPU_INSTR 
                            = vlSelfRef.CACHE_READDATA;
                    }
                }
            }
            vlSelfRef.CACHE_ADDRESS = vlSelfRef.icache_controller__DOT__CACHE_ADDRESS;
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT = 1U;
            } else if (vlSelfRef.CPU_READ) {
                vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT 
                    = (1U & (~ ((IData)(vlSelfRef.HIT) 
                                & (IData)(vlSelfRef.VALID))));
            }
            vlSelfRef.CPU_BUSYWAIT = vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT;
            vlSelfRef.icache_controller__DOT__CACHE_WRITETAG = 0U;
        }
    } else {
        vlSelfRef.CACHE_WRITEVALID = vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID;
        vlSelfRef.WRITE_ENABLE = vlSelfRef.icache_controller__DOT__WRITE_ENABLE;
        vlSelfRef.COMPARE_EN = vlSelfRef.icache_controller__DOT__COMPARE_EN;
        vlSelfRef.MEM_READ_REQ = vlSelfRef.icache_controller__DOT__MEM_READ_REQ;
        vlSelfRef.CACHE_WRITEDATA = vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA;
        vlSelfRef.MEM_ADDRESS = vlSelfRef.icache_controller__DOT__MEM_ADDRESS;
        vlSelfRef.CACHE_ADDRESS = vlSelfRef.icache_controller__DOT__CACHE_ADDRESS;
        vlSelfRef.CPU_BUSYWAIT = vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT;
        vlSelfRef.icache_controller__DOT__CACHE_WRITETAG = 0U;
    }
    vlSelfRef.CPU_INSTR = vlSelfRef.icache_controller__DOT__CPU_INSTR;
    vlSelfRef.CACHE_WRITETAG = vlSelfRef.icache_controller__DOT__CACHE_WRITETAG;
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
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.icache_controller__DOT__saved_address = 0U;
        vlSelfRef.icache_controller__DOT__state = 0U;
    } else {
        if ((((0U == (IData)(vlSelfRef.icache_controller__DOT__state)) 
              & (IData)(vlSelfRef.CPU_READ)) & (~ ((IData)(vlSelfRef.HIT) 
                                                   & (IData)(vlSelfRef.VALID))))) {
            vlSelfRef.icache_controller__DOT__saved_address 
                = vlSelfRef.CPU_ADDRESS;
        }
        vlSelfRef.icache_controller__DOT__state = vlSelfRef.icache_controller__DOT__next_state;
    }
    vlSelfRef.icache_controller__DOT__saved_tag = (vlSelfRef.icache_controller__DOT__saved_address 
                                                   >> 5U);
    vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID = 0U;
    vlSelfRef.icache_controller__DOT__WRITE_ENABLE = 0U;
    vlSelfRef.icache_controller__DOT__COMPARE_EN = 0U;
    vlSelfRef.icache_controller__DOT__MEM_READ_REQ = 0U;
    vlSelfRef.icache_controller__DOT__CACHE_WRITETAG = 0U;
    vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA = 0U;
    vlSelfRef.icache_controller__DOT__MEM_ADDRESS = 0U;
    vlSelfRef.icache_controller__DOT__CACHE_ADDRESS = 0U;
    vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT = 0U;
    __Vtableidx1 = (((((IData)(vlSelfRef.VALID) << 6U) 
                      | ((IData)(vlSelfRef.HIT) << 5U)) 
                     | (((IData)(vlSelfRef.CPU_READ) 
                         << 4U) | ((IData)(vlSelfRef.MEM_BUSYWAIT) 
                                   << 3U))) | (((IData)(vlSelfRef.MEM_READDATA_VALID) 
                                                << 2U) 
                                               | (IData)(vlSelfRef.icache_controller__DOT__state)));
    vlSelfRef.icache_controller__DOT__next_state = 
        Vtop__ConstPool__TABLE_h4976e89c_0[__Vtableidx1];
    vlSelfRef.icache_controller__DOT__CPU_INSTR = 0U;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((2U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID = 1U;
                vlSelfRef.icache_controller__DOT__WRITE_ENABLE = 1U;
                vlSelfRef.icache_controller__DOT__CACHE_WRITETAG 
                    = vlSelfRef.icache_controller__DOT__saved_tag;
                vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA 
                    = vlSelfRef.MEM_READDATA;
                vlSelfRef.icache_controller__DOT__CACHE_ADDRESS 
                    = vlSelfRef.icache_controller__DOT__saved_address;
                vlSelfRef.icache_controller__DOT__CPU_INSTR 
                    = vlSelfRef.MEM_READDATA;
            }
            vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT 
                = (1U & (~ (IData)(vlSelfRef.icache_controller__DOT__state)));
        } else {
            if ((1U & (~ (IData)(vlSelfRef.icache_controller__DOT__state)))) {
                if (vlSelfRef.CPU_READ) {
                    vlSelfRef.icache_controller__DOT__CACHE_ADDRESS 
                        = vlSelfRef.CPU_ADDRESS;
                    if (((IData)(vlSelfRef.HIT) & (IData)(vlSelfRef.VALID))) {
                        vlSelfRef.icache_controller__DOT__CPU_INSTR 
                            = vlSelfRef.CACHE_READDATA;
                    }
                }
            }
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT = 1U;
            } else if (vlSelfRef.CPU_READ) {
                vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT 
                    = (1U & (~ ((IData)(vlSelfRef.HIT) 
                                & (IData)(vlSelfRef.VALID))));
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.icache_controller__DOT__state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlSelfRef.icache_controller__DOT__state)))) {
                vlSelfRef.icache_controller__DOT__COMPARE_EN = 1U;
            }
            if ((1U & (IData)(vlSelfRef.icache_controller__DOT__state))) {
                vlSelfRef.icache_controller__DOT__MEM_READ_REQ = 1U;
                vlSelfRef.icache_controller__DOT__MEM_ADDRESS 
                    = vlSelfRef.icache_controller__DOT__saved_address;
            }
        }
    }
    vlSelfRef.CACHE_WRITEVALID = vlSelfRef.icache_controller__DOT__CACHE_WRITEVALID;
    vlSelfRef.WRITE_ENABLE = vlSelfRef.icache_controller__DOT__WRITE_ENABLE;
    vlSelfRef.COMPARE_EN = vlSelfRef.icache_controller__DOT__COMPARE_EN;
    vlSelfRef.MEM_READ_REQ = vlSelfRef.icache_controller__DOT__MEM_READ_REQ;
    vlSelfRef.CACHE_WRITETAG = vlSelfRef.icache_controller__DOT__CACHE_WRITETAG;
    vlSelfRef.CACHE_WRITEDATA = vlSelfRef.icache_controller__DOT__CACHE_WRITEDATA;
    vlSelfRef.MEM_ADDRESS = vlSelfRef.icache_controller__DOT__MEM_ADDRESS;
    vlSelfRef.CACHE_ADDRESS = vlSelfRef.icache_controller__DOT__CACHE_ADDRESS;
    vlSelfRef.CPU_BUSYWAIT = vlSelfRef.icache_controller__DOT__CPU_BUSYWAIT;
    vlSelfRef.CPU_INSTR = vlSelfRef.icache_controller__DOT__CPU_INSTR;
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
            VL_FATAL_MT("cache_controller.v", 4, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("cache_controller.v", 4, "", "NBA region did not converge.");
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
                VL_FATAL_MT("cache_controller.v", 4, "", "Active region did not converge.");
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
    if (VL_UNLIKELY(((vlSelfRef.CPU_READ & 0xfeU)))) {
        Verilated::overWidthError("CPU_READ");}
    if (VL_UNLIKELY(((vlSelfRef.MEM_BUSYWAIT & 0xfeU)))) {
        Verilated::overWidthError("MEM_BUSYWAIT");}
    if (VL_UNLIKELY(((vlSelfRef.MEM_READDATA_VALID 
                      & 0xfeU)))) {
        Verilated::overWidthError("MEM_READDATA_VALID");}
    if (VL_UNLIKELY(((vlSelfRef.HIT & 0xfeU)))) {
        Verilated::overWidthError("HIT");}
    if (VL_UNLIKELY(((vlSelfRef.STORED_TAG & 0xf8000000U)))) {
        Verilated::overWidthError("STORED_TAG");}
    if (VL_UNLIKELY(((vlSelfRef.VALID & 0xfeU)))) {
        Verilated::overWidthError("VALID");}
}
#endif  // VL_DEBUG
