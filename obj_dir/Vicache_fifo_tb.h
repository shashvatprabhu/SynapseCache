// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VICACHE_FIFO_TB_H_
#define _VICACHE_FIFO_TB_H_  // guard

#include "verilated_heavy.h"

//==========

class Vicache_fifo_tb__Syms;
class Vicache_fifo_tb_VerilatedVcd;


//----------

VL_MODULE(Vicache_fifo_tb) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ icache_fifo_tb__DOT__clk;
    CData/*0:0*/ icache_fifo_tb__DOT__rst;
    CData/*0:0*/ icache_fifo_tb__DOT__mem_instr_valid;
    CData/*0:0*/ icache_fifo_tb__DOT__hit;
    CData/*0:0*/ icache_fifo_tb__DOT__miss;
    CData/*0:0*/ icache_fifo_tb__DOT__mem_req;
    CData/*7:0*/ icache_fifo_tb__DOT__state;
    CData/*0:0*/ icache_fifo_tb__DOT__uut__DOT__hit_found;
    CData/*1:0*/ icache_fifo_tb__DOT__uut__DOT__matched_way;
    CData/*1:0*/ icache_fifo_tb__DOT__uut__DOT__state;
    CData/*1:0*/ icache_fifo_tb__DOT__uut__DOT__next_state;
    IData/*31:0*/ icache_fifo_tb__DOT__instr_addr;
    IData/*31:0*/ icache_fifo_tb__DOT__mem_instr;
    IData/*31:0*/ icache_fifo_tb__DOT__instr;
    IData/*31:0*/ icache_fifo_tb__DOT__mem_addr;
    IData/*31:0*/ icache_fifo_tb__DOT__total_hits;
    IData/*31:0*/ icache_fifo_tb__DOT__total_misses;
    IData/*31:0*/ icache_fifo_tb__DOT__total_accesses;
    IData/*31:0*/ icache_fifo_tb__DOT__last_addr;
    IData/*31:0*/ icache_fifo_tb__DOT__cycle;
    IData/*31:0*/ icache_fifo_tb__DOT__i;
    IData/*31:0*/ icache_fifo_tb__DOT__unnamedblk1__DOT__j;
    IData/*31:0*/ icache_fifo_tb__DOT__uut__DOT__i;
    IData/*31:0*/ icache_fifo_tb__DOT__uut__DOT__j;
    IData/*31:0*/ icache_fifo_tb__DOT__uut__DOT__k;
    IData/*31:0*/ icache_fifo_tb__DOT__memory[1024];
    IData/*21:0*/ icache_fifo_tb__DOT__uut__DOT__tag_bits[256][1];
    CData/*0:0*/ icache_fifo_tb__DOT__uut__DOT__valid_bits[256][1];
    IData/*31:0*/ icache_fifo_tb__DOT__uut__DOT__data_bits[256][1][1];
    CData/*1:0*/ icache_fifo_tb__DOT__uut__DOT__fifo_ptr[256];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ icache_fifo_tb__DOT__uut__DOT____Vlvbound6;
    CData/*0:0*/ __Vdly__icache_fifo_tb__DOT__rst;
    CData/*0:0*/ __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__data_bits__v0;
    CData/*0:0*/ __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__tag_bits__v0;
    CData/*0:0*/ __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__valid_bits__v0;
    CData/*0:0*/ __Vdlyvset__icache_fifo_tb__DOT__uut__DOT__fifo_ptr__v0;
    CData/*0:0*/ __VinpClk__TOP__icache_fifo_tb__DOT__clk;
    CData/*0:0*/ __VinpClk__TOP__icache_fifo_tb__DOT__rst;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__icache_fifo_tb__DOT__rst;
    CData/*0:0*/ __Vchglast__TOP__icache_fifo_tb__DOT__clk;
    CData/*0:0*/ __Vchglast__TOP__icache_fifo_tb__DOT__rst;
    IData/*31:0*/ icache_fifo_tb__DOT__uut__DOT____Vlvbound4;
    IData/*21:0*/ icache_fifo_tb__DOT__uut__DOT____Vlvbound5;
    IData/*31:0*/ __Vdly__icache_fifo_tb__DOT__instr_addr;
    IData/*31:0*/ __Vdly__icache_fifo_tb__DOT__mem_instr;
    CData/*0:0*/ __Vm_traceActivity[5];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vicache_fifo_tb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vicache_fifo_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vicache_fifo_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vicache_fifo_tb();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vicache_fifo_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vicache_fifo_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vicache_fifo_tb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vicache_fifo_tb__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(Vicache_fifo_tb__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vicache_fifo_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vicache_fifo_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vicache_fifo_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vicache_fifo_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vicache_fifo_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vicache_fifo_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vicache_fifo_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vicache_fifo_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vicache_fifo_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vicache_fifo_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
