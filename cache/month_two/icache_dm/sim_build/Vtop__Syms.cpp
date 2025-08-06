// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_cache_controller);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(31);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_cache_controller.configure(this, name(), "cache_controller", "cache_controller", "cache_controller", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_cache_controller);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_ADDRESS", &(TOP.CACHE_ADDRESS), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_READDATA", &(TOP.CACHE_READDATA), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_WRITEDATA", &(TOP.CACHE_WRITEDATA), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_WRITETAG", &(TOP.CACHE_WRITETAG), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,24,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_WRITEVALID", &(TOP.CACHE_WRITEVALID), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"COMPARE_EN", &(TOP.COMPARE_EN), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"CPU_ADDRESS", &(TOP.CPU_ADDRESS), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CPU_BUSYWAIT", &(TOP.CPU_BUSYWAIT), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"CPU_INSTR", &(TOP.CPU_INSTR), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CPU_READ", &(TOP.CPU_READ), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"HIT", &(TOP.HIT), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM_ADDRESS", &(TOP.MEM_ADDRESS), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM_BUSYWAIT", &(TOP.MEM_BUSYWAIT), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM_READDATA", &(TOP.MEM_READDATA), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM_READDATA_VALID", &(TOP.MEM_READDATA_VALID), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"MEM_READ_REQ", &(TOP.MEM_READ_REQ), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"STORED_TAG", &(TOP.STORED_TAG), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,24,0);
        __Vscope_TOP.varInsert(__Vfinal,"VALID", &(TOP.VALID), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"WRITE_ENABLE", &(TOP.WRITE_ENABLE), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"BLOCK_SIZE", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__BLOCK_SIZE))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CACHE_ADDRESS", &(TOP.cache_controller__DOT__CACHE_ADDRESS), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CACHE_READDATA", &(TOP.cache_controller__DOT__CACHE_READDATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CACHE_WRITEDATA", &(TOP.cache_controller__DOT__CACHE_WRITEDATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CACHE_WRITETAG", &(TOP.cache_controller__DOT__CACHE_WRITETAG), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,24,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CACHE_WRITEVALID", &(TOP.cache_controller__DOT__CACHE_WRITEVALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"COMPARE_EN", &(TOP.cache_controller__DOT__COMPARE_EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CPU_ADDRESS", &(TOP.cache_controller__DOT__CPU_ADDRESS), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CPU_BUSYWAIT", &(TOP.cache_controller__DOT__CPU_BUSYWAIT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CPU_INSTR", &(TOP.cache_controller__DOT__CPU_INSTR), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"CPU_READ", &(TOP.cache_controller__DOT__CPU_READ), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"HIT", &(TOP.cache_controller__DOT__HIT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"IDLE", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__IDLE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"INDEX_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__INDEX_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"MEM_ADDRESS", &(TOP.cache_controller__DOT__MEM_ADDRESS), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"MEM_BUSYWAIT", &(TOP.cache_controller__DOT__MEM_BUSYWAIT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"MEM_READDATA", &(TOP.cache_controller__DOT__MEM_READDATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"MEM_READDATA_VALID", &(TOP.cache_controller__DOT__MEM_READDATA_VALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"MEM_READ_REQ", &(TOP.cache_controller__DOT__MEM_READ_REQ), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"READ_MEM", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__READ_MEM))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"STORED_TAG", &(TOP.cache_controller__DOT__STORED_TAG), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,24,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"TAG_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__TAG_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"UPDATE_CACHE", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__UPDATE_CACHE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"VALID", &(TOP.cache_controller__DOT__VALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"WAIT_READ", const_cast<void*>(static_cast<const void*>(&(TOP.cache_controller__DOT__WAIT_READ))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"WRITE_ENABLE", &(TOP.cache_controller__DOT__WRITE_ENABLE), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"clk", &(TOP.cache_controller__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"index", &(TOP.cache_controller__DOT__index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"next_state", &(TOP.cache_controller__DOT__next_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"offset", &(TOP.cache_controller__DOT__offset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"reset", &(TOP.cache_controller__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"saved_address", &(TOP.cache_controller__DOT__saved_address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"state", &(TOP.cache_controller__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_cache_controller.varInsert(__Vfinal,"tag", &(TOP.cache_controller__DOT__tag), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,24,0);
    }
}
