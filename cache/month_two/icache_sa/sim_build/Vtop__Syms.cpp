// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_cache_storage);
    __Vhier.remove(&__Vscope_cache_storage, &__Vscope_cache_storage__RESET_LOOP);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(69);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_cache_storage.configure(this, name(), "cache_storage", "cache_storage", "cache_storage", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_cache_storage__RESET_LOOP.configure(this, name(), "cache_storage.RESET_LOOP", "RESET_LOOP", "<null>", -9, VerilatedScope::SCOPE_OTHER);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_cache_storage);
    __Vhier.add(&__Vscope_cache_storage, &__Vscope_cache_storage__RESET_LOOP);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"address", &(TOP.address), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"hit", &(TOP.hit), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"read", &(TOP.read), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"read_data", &(TOP.read_data), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"way_select", &(TOP.way_select), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"write", &(TOP.write), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"write_data", &(TOP.write_data), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"write_tag", &(TOP.write_tag), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,23,0);
        __Vscope_TOP.varInsert(__Vfinal,"write_valid", &(TOP.write_valid), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"ASSOCIATIVITY", const_cast<void*>(static_cast<const void*>(&(TOP.cache_storage__DOT__ASSOCIATIVITY))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"INDEX_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.cache_storage__DOT__INDEX_BITS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"NUM_SETS", const_cast<void*>(static_cast<const void*>(&(TOP.cache_storage__DOT__NUM_SETS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"TAG_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.cache_storage__DOT__TAG_BITS))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"WORD_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.cache_storage__DOT__WORD_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"address", &(TOP.cache_storage__DOT__address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"clk", &(TOP.cache_storage__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"data_array", &(TOP.cache_storage__DOT__data_array), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2,1 ,15,0 ,1,0 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"hit", &(TOP.cache_storage__DOT__hit), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"i", &(TOP.cache_storage__DOT__i), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"index", &(TOP.cache_storage__DOT__index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"read", &(TOP.cache_storage__DOT__read), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"read_data", &(TOP.cache_storage__DOT__read_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"reset", &(TOP.cache_storage__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"tag", &(TOP.cache_storage__DOT__tag), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,23,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"tag_array", &(TOP.cache_storage__DOT__tag_array), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2,1 ,15,0 ,1,0 ,23,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"valid_bits", &(TOP.cache_storage__DOT__valid_bits), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,2,0 ,15,0 ,1,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"way_select", &(TOP.cache_storage__DOT__way_select), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"write", &(TOP.cache_storage__DOT__write), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"write_data", &(TOP.cache_storage__DOT__write_data), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"write_tag", &(TOP.cache_storage__DOT__write_tag), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,23,0);
        __Vscope_cache_storage.varInsert(__Vfinal,"write_valid", &(TOP.cache_storage__DOT__write_valid), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_storage__RESET_LOOP.varInsert(__Vfinal,"j", &(TOP.cache_storage__DOT__RESET_LOOP__DOT__j), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
    }
}
