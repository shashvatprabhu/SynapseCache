// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vicache_fifo_tb__Syms.h"


//======================

void Vicache_fifo_tb::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vicache_fifo_tb::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vicache_fifo_tb::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vicache_fifo_tb::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vicache_fifo_tb::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+28,"icache_fifo_tb ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+28,"icache_fifo_tb DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+29,"icache_fifo_tb WORD_SIZE", false,-1, 31,0);
        tracep->declBus(c+30,"icache_fifo_tb BLOCK_SIZE", false,-1, 31,0);
        tracep->declBus(c+30,"icache_fifo_tb DEG_ASSOCIATIVITY", false,-1, 31,0);
        tracep->declBus(c+31,"icache_fifo_tb CAPACITY", false,-1, 31,0);
        tracep->declBus(c+32,"icache_fifo_tb NUM_WORDS", false,-1, 31,0);
        tracep->declBus(c+33,"icache_fifo_tb NUM_ACCESSES", false,-1, 31,0);
        tracep->declBit(c+27,"icache_fifo_tb clk", false,-1);
        tracep->declBit(c+15,"icache_fifo_tb rst", false,-1);
        tracep->declBus(c+16,"icache_fifo_tb instr_addr", false,-1, 31,0);
        tracep->declBus(c+17,"icache_fifo_tb mem_instr", false,-1, 31,0);
        tracep->declBit(c+2,"icache_fifo_tb mem_instr_valid", false,-1);
        tracep->declBus(c+10,"icache_fifo_tb instr", false,-1, 31,0);
        tracep->declBit(c+20,"icache_fifo_tb hit", false,-1);
        tracep->declBit(c+21,"icache_fifo_tb miss", false,-1);
        tracep->declBus(c+22,"icache_fifo_tb mem_addr", false,-1, 31,0);
        tracep->declBit(c+23,"icache_fifo_tb mem_req", false,-1);
        tracep->declBus(c+3,"icache_fifo_tb total_hits", false,-1, 31,0);
        tracep->declBus(c+4,"icache_fifo_tb total_misses", false,-1, 31,0);
        tracep->declBus(c+5,"icache_fifo_tb total_accesses", false,-1, 31,0);
        tracep->declBus(c+6,"icache_fifo_tb last_addr", false,-1, 31,0);
        tracep->declBus(c+7,"icache_fifo_tb cycle", false,-1, 31,0);
        tracep->declBus(c+8,"icache_fifo_tb i", false,-1, 31,0);
        tracep->declBus(c+9,"icache_fifo_tb state", false,-1, 7,0);
        tracep->declBus(c+1,"icache_fifo_tb unnamedblk1 j", false,-1, 31,0);
        tracep->declBus(c+28,"icache_fifo_tb uut ADDR_WIDTH", false,-1, 31,0);
        tracep->declBus(c+28,"icache_fifo_tb uut DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+29,"icache_fifo_tb uut WORD_SIZE", false,-1, 31,0);
        tracep->declBus(c+30,"icache_fifo_tb uut BLOCK_SIZE", false,-1, 31,0);
        tracep->declBus(c+30,"icache_fifo_tb uut DEG_ASSOCIATIVITY", false,-1, 31,0);
        tracep->declBus(c+31,"icache_fifo_tb uut CAPACITY", false,-1, 31,0);
        tracep->declBus(c+31,"icache_fifo_tb uut NUM_SETS", false,-1, 31,0);
        tracep->declBus(c+34,"icache_fifo_tb uut BYTE_OFFSET", false,-1, 31,0);
        tracep->declBus(c+35,"icache_fifo_tb uut BLOCK_OFFSET", false,-1, 31,0);
        tracep->declBus(c+36,"icache_fifo_tb uut SET_BITS", false,-1, 31,0);
        tracep->declBus(c+37,"icache_fifo_tb uut TAG_WIDTH", false,-1, 31,0);
        tracep->declBit(c+27,"icache_fifo_tb uut clk", false,-1);
        tracep->declBit(c+15,"icache_fifo_tb uut rst", false,-1);
        tracep->declBus(c+16,"icache_fifo_tb uut instr_addr", false,-1, 31,0);
        tracep->declBus(c+10,"icache_fifo_tb uut instr", false,-1, 31,0);
        tracep->declBit(c+20,"icache_fifo_tb uut hit", false,-1);
        tracep->declBit(c+21,"icache_fifo_tb uut miss", false,-1);
        tracep->declBus(c+22,"icache_fifo_tb uut mem_addr", false,-1, 31,0);
        tracep->declBit(c+23,"icache_fifo_tb uut mem_req", false,-1);
        tracep->declBus(c+17,"icache_fifo_tb uut mem_instr", false,-1, 31,0);
        tracep->declBit(c+2,"icache_fifo_tb uut mem_instr_valid", false,-1);
        tracep->declBus(c+18,"icache_fifo_tb uut tag", false,-1, 21,0);
        tracep->declBus(c+19,"icache_fifo_tb uut set", false,-1, 7,0);
        tracep->declBus(c+38,"icache_fifo_tb uut block_offset", false,-1, -1,0);
        tracep->declBus(c+11,"icache_fifo_tb uut i", false,-1, 31,0);
        tracep->declBus(c+12,"icache_fifo_tb uut j", false,-1, 31,0);
        tracep->declBus(c+13,"icache_fifo_tb uut k", false,-1, 31,0);
        tracep->declBit(c+24,"icache_fifo_tb uut hit_found", false,-1);
        tracep->declBus(c+25,"icache_fifo_tb uut matched_way", false,-1, -1,0);
        tracep->declBus(c+38,"icache_fifo_tb uut IDLE", false,-1, 1,0);
        tracep->declBus(c+39,"icache_fifo_tb uut WAIT_MEM", false,-1, 1,0);
        tracep->declBus(c+40,"icache_fifo_tb uut UPDATE_CACHE", false,-1, 1,0);
        tracep->declBus(c+14,"icache_fifo_tb uut state", false,-1, 1,0);
        tracep->declBus(c+26,"icache_fifo_tb uut next_state", false,-1, 1,0);
    }
}

void Vicache_fifo_tb::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vicache_fifo_tb::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vicache_fifo_tb::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vicache_fifo_tb__Syms* __restrict vlSymsp = static_cast<Vicache_fifo_tb__Syms*>(userp);
    Vicache_fifo_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->icache_fifo_tb__DOT__unnamedblk1__DOT__j),32);
        tracep->fullBit(oldp+2,(vlTOPp->icache_fifo_tb__DOT__mem_instr_valid));
        tracep->fullIData(oldp+3,(vlTOPp->icache_fifo_tb__DOT__total_hits),32);
        tracep->fullIData(oldp+4,(vlTOPp->icache_fifo_tb__DOT__total_misses),32);
        tracep->fullIData(oldp+5,(vlTOPp->icache_fifo_tb__DOT__total_accesses),32);
        tracep->fullIData(oldp+6,(vlTOPp->icache_fifo_tb__DOT__last_addr),32);
        tracep->fullIData(oldp+7,(vlTOPp->icache_fifo_tb__DOT__cycle),32);
        tracep->fullIData(oldp+8,(vlTOPp->icache_fifo_tb__DOT__i),32);
        tracep->fullCData(oldp+9,(vlTOPp->icache_fifo_tb__DOT__state),8);
        tracep->fullIData(oldp+10,(vlTOPp->icache_fifo_tb__DOT__instr),32);
        tracep->fullIData(oldp+11,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__i),32);
        tracep->fullIData(oldp+12,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__j),32);
        tracep->fullIData(oldp+13,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__k),32);
        tracep->fullCData(oldp+14,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__state),2);
        tracep->fullBit(oldp+15,(vlTOPp->icache_fifo_tb__DOT__rst));
        tracep->fullIData(oldp+16,(vlTOPp->icache_fifo_tb__DOT__instr_addr),32);
        tracep->fullIData(oldp+17,(vlTOPp->icache_fifo_tb__DOT__mem_instr),32);
        tracep->fullIData(oldp+18,((0x3fffffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                                 >> 0xaU))),22);
        tracep->fullCData(oldp+19,((0xffU & (vlTOPp->icache_fifo_tb__DOT__instr_addr 
                                             >> 2U))),8);
        tracep->fullBit(oldp+20,(vlTOPp->icache_fifo_tb__DOT__hit));
        tracep->fullBit(oldp+21,(vlTOPp->icache_fifo_tb__DOT__miss));
        tracep->fullIData(oldp+22,(vlTOPp->icache_fifo_tb__DOT__mem_addr),32);
        tracep->fullBit(oldp+23,(vlTOPp->icache_fifo_tb__DOT__mem_req));
        tracep->fullBit(oldp+24,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__hit_found));
        tracep->fullCData(oldp+25,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__matched_way),2);
        tracep->fullCData(oldp+26,(vlTOPp->icache_fifo_tb__DOT__uut__DOT__next_state),2);
        tracep->fullBit(oldp+27,(vlTOPp->icache_fifo_tb__DOT__clk));
        tracep->fullIData(oldp+28,(0x20U),32);
        tracep->fullIData(oldp+29,(4U),32);
        tracep->fullIData(oldp+30,(1U),32);
        tracep->fullIData(oldp+31,(0x100U),32);
        tracep->fullIData(oldp+32,(0x400U),32);
        tracep->fullIData(oldp+33,(0x1f4U),32);
        tracep->fullIData(oldp+34,(2U),32);
        tracep->fullIData(oldp+35,(0U),32);
        tracep->fullIData(oldp+36,(8U),32);
        tracep->fullIData(oldp+37,(0x16U),32);
        tracep->fullCData(oldp+38,(0U),2);
        tracep->fullCData(oldp+39,(1U),2);
        tracep->fullCData(oldp+40,(2U),2);
    }
}
