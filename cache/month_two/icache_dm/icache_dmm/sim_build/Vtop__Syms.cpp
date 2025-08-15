// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_icache_controller);

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
    __Vscope_icache_controller.configure(this, name(), "icache_controller", "icache_controller", "icache_controller", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_icache_controller);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_ADDRESS", &(TOP.CACHE_ADDRESS), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_READDATA", &(TOP.CACHE_READDATA), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_WRITEDATA", &(TOP.CACHE_WRITEDATA), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_TOP.varInsert(__Vfinal,"CACHE_WRITETAG", &(TOP.CACHE_WRITETAG), false, VLVT_UINT32,VLVD_OUT|VLVF_PUB_RW,0,1 ,26,0);
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
        __Vscope_TOP.varInsert(__Vfinal,"STORED_TAG", &(TOP.STORED_TAG), false, VLVT_UINT32,VLVD_IN|VLVF_PUB_RW,0,1 ,26,0);
        __Vscope_TOP.varInsert(__Vfinal,"VALID", &(TOP.VALID), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"WRITE_ENABLE", &(TOP.WRITE_ENABLE), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"reset", &(TOP.reset), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__ADDR_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CACHE_ADDRESS", &(TOP.icache_controller__DOT__CACHE_ADDRESS), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CACHE_READDATA", &(TOP.icache_controller__DOT__CACHE_READDATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CACHE_WRITEDATA", &(TOP.icache_controller__DOT__CACHE_WRITEDATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CACHE_WRITETAG", &(TOP.icache_controller__DOT__CACHE_WRITETAG), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,26,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CACHE_WRITEVALID", &(TOP.icache_controller__DOT__CACHE_WRITEVALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"COMPARE_EN", &(TOP.icache_controller__DOT__COMPARE_EN), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CPU_ADDRESS", &(TOP.icache_controller__DOT__CPU_ADDRESS), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CPU_BUSYWAIT", &(TOP.icache_controller__DOT__CPU_BUSYWAIT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CPU_INSTR", &(TOP.icache_controller__DOT__CPU_INSTR), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"CPU_READ", &(TOP.icache_controller__DOT__CPU_READ), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__DATA_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"HIT", &(TOP.icache_controller__DOT__HIT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"INDEX_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__INDEX_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"MEM_ADDRESS", &(TOP.icache_controller__DOT__MEM_ADDRESS), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"MEM_BUSYWAIT", &(TOP.icache_controller__DOT__MEM_BUSYWAIT), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"MEM_READDATA", &(TOP.icache_controller__DOT__MEM_READDATA), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"MEM_READDATA_VALID", &(TOP.icache_controller__DOT__MEM_READDATA_VALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"MEM_READ_REQ", &(TOP.icache_controller__DOT__MEM_READ_REQ), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"STORED_TAG", &(TOP.icache_controller__DOT__STORED_TAG), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,26,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"S_LOOKUP", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__S_LOOKUP))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"S_REQ_MEM", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__S_REQ_MEM))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"S_UPDATE", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__S_UPDATE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"S_WAIT_VALID", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__S_WAIT_VALID))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"TAG_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP.icache_controller__DOT__TAG_WIDTH))), true, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"VALID", &(TOP.icache_controller__DOT__VALID), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"WRITE_ENABLE", &(TOP.icache_controller__DOT__WRITE_ENABLE), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"addr_index", &(TOP.icache_controller__DOT__addr_index), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,4,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"addr_tag", &(TOP.icache_controller__DOT__addr_tag), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,26,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"clk", &(TOP.icache_controller__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"next_state", &(TOP.icache_controller__DOT__next_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"reset", &(TOP.icache_controller__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"saved_address", &(TOP.icache_controller__DOT__saved_address), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"saved_tag", &(TOP.icache_controller__DOT__saved_tag), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,26,0);
        __Vscope_icache_controller.varInsert(__Vfinal,"state", &(TOP.icache_controller__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
    }
}
