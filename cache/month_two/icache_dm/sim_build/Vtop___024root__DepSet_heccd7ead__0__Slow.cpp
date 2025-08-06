// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("cache_controller.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->CPU_READ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8728119870417344569ull);
    vlSelf->CPU_ADDRESS = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15870464728466469800ull);
    vlSelf->CPU_INSTR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15183103259789498190ull);
    vlSelf->CPU_BUSYWAIT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13596960644078480115ull);
    vlSelf->MEM_BUSYWAIT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1487226233562718543ull);
    vlSelf->MEM_READ_REQ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9911250878735112898ull);
    vlSelf->MEM_ADDRESS = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12486810987649948314ull);
    vlSelf->MEM_READDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9011119576949603273ull);
    vlSelf->MEM_READDATA_VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11115987122272987866ull);
    vlSelf->HIT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18144133743596233896ull);
    vlSelf->CACHE_READDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16344613094206565354ull);
    vlSelf->STORED_TAG = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 2344449877356559551ull);
    vlSelf->VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18201917029856479561ull);
    vlSelf->COMPARE_EN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14755224549993236668ull);
    vlSelf->WRITE_ENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7819514466406160716ull);
    vlSelf->CACHE_ADDRESS = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14174890813470876409ull);
    vlSelf->CACHE_WRITEDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3374284196261281179ull);
    vlSelf->CACHE_WRITETAG = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 7815650447955329043ull);
    vlSelf->CACHE_WRITEVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7081914342710034041ull);
    vlSelf->cache_controller__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5960853030403222491ull);
    vlSelf->cache_controller__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4069364118278662780ull);
    vlSelf->cache_controller__DOT__CPU_READ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9943107489872831784ull);
    vlSelf->cache_controller__DOT__CPU_ADDRESS = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8607296870248225419ull);
    vlSelf->cache_controller__DOT__CPU_INSTR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6328138069265495951ull);
    vlSelf->cache_controller__DOT__CPU_BUSYWAIT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14455107349600838950ull);
    vlSelf->cache_controller__DOT__MEM_BUSYWAIT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9844009210491165242ull);
    vlSelf->cache_controller__DOT__MEM_READ_REQ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10090438094384629285ull);
    vlSelf->cache_controller__DOT__MEM_ADDRESS = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12065229836410236663ull);
    vlSelf->cache_controller__DOT__MEM_READDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11792763192468404183ull);
    vlSelf->cache_controller__DOT__MEM_READDATA_VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4675102845850545702ull);
    vlSelf->cache_controller__DOT__HIT = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 216809233358098995ull);
    vlSelf->cache_controller__DOT__CACHE_READDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17962846834126092663ull);
    vlSelf->cache_controller__DOT__STORED_TAG = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 6786351749279284149ull);
    vlSelf->cache_controller__DOT__VALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17297903929304810088ull);
    vlSelf->cache_controller__DOT__COMPARE_EN = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9356821599526693189ull);
    vlSelf->cache_controller__DOT__WRITE_ENABLE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11890113157019505659ull);
    vlSelf->cache_controller__DOT__CACHE_ADDRESS = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15841919507902910821ull);
    vlSelf->cache_controller__DOT__CACHE_WRITEDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11712176356694100774ull);
    vlSelf->cache_controller__DOT__CACHE_WRITETAG = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 17647435065261754787ull);
    vlSelf->cache_controller__DOT__CACHE_WRITEVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9789558683569940636ull);
    vlSelf->cache_controller__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4313193883373079642ull);
    vlSelf->cache_controller__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14295214001468867897ull);
    vlSelf->cache_controller__DOT__saved_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18053024517134317112ull);
    vlSelf->cache_controller__DOT__tag = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 3525228238504667639ull);
    vlSelf->cache_controller__DOT__index = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1670893845618925737ull);
    vlSelf->cache_controller__DOT__offset = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5182718782705620207ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1487628987237401141ull);
}
