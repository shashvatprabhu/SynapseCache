// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"write_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"write_tag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+8,0,"way_select",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+9,0,"write_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"read_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+11,0,"hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("cache_storage", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+123,0,"WORD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"INDEX_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"TAG_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"ASSOCIATIVITY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"write_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"write_tag",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+19,0,"way_select",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+20,0,"write_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"read_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"hit",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"NUM_SETS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("valid_bits", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+23,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+25,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+27,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+29,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[4]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+31,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[5]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+33,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[6]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+35,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[7]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+37,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[8]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+39,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[9]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+41,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[10]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+43,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[11]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+45,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[12]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+47,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[13]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+49,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[14]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+51,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("[15]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBit(c+53,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tag_array", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+55,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+56,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+57,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+58,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+59,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+60,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+61,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+62,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[4]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+63,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+64,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[5]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+65,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+66,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[6]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+67,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+68,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[7]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+69,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+70,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[8]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+71,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+72,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[9]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+73,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+74,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[10]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+75,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+76,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[11]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+77,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+78,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[12]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+79,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+80,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[13]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+81,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+82,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[14]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+83,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+84,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->pushPrefix("[15]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+85,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+86,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("data_array", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->pushPrefix("[0]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+87,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[1]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+89,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[2]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+91,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[3]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+93,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[4]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+95,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[5]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+97,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[6]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+99,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[7]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+101,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[8]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+103,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[9]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+105,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[10]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+107,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[11]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+109,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[12]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+111,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[13]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+113,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[14]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+115,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("[15]", VerilatedTracePrefixType::ARRAY_UNPACKED);
    tracep->declBus(c+117,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBus(c+119,0,"index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+120,0,"tag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+121,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("RESET_LOOP", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+122,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+123,(0x20U),32);
    bufp->fullIData(oldp+124,(4U),32);
    bufp->fullIData(oldp+125,(0x18U),32);
    bufp->fullIData(oldp+126,(2U),32);
    bufp->fullIData(oldp+127,(0x10U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.clk));
    bufp->fullBit(oldp+2,(vlSelfRef.reset));
    bufp->fullBit(oldp+3,(vlSelfRef.read));
    bufp->fullBit(oldp+4,(vlSelfRef.write));
    bufp->fullIData(oldp+5,(vlSelfRef.address),32);
    bufp->fullIData(oldp+6,(vlSelfRef.write_data),32);
    bufp->fullIData(oldp+7,(vlSelfRef.write_tag),24);
    bufp->fullBit(oldp+8,(vlSelfRef.way_select));
    bufp->fullBit(oldp+9,(vlSelfRef.write_valid));
    bufp->fullIData(oldp+10,(vlSelfRef.read_data),32);
    bufp->fullBit(oldp+11,(vlSelfRef.hit));
    bufp->fullBit(oldp+12,(vlSelfRef.cache_storage__DOT__clk));
    bufp->fullBit(oldp+13,(vlSelfRef.cache_storage__DOT__reset));
    bufp->fullBit(oldp+14,(vlSelfRef.cache_storage__DOT__read));
    bufp->fullBit(oldp+15,(vlSelfRef.cache_storage__DOT__write));
    bufp->fullIData(oldp+16,(vlSelfRef.cache_storage__DOT__address),32);
    bufp->fullIData(oldp+17,(vlSelfRef.cache_storage__DOT__write_data),32);
    bufp->fullIData(oldp+18,(vlSelfRef.cache_storage__DOT__write_tag),24);
    bufp->fullBit(oldp+19,(vlSelfRef.cache_storage__DOT__way_select));
    bufp->fullBit(oldp+20,(vlSelfRef.cache_storage__DOT__write_valid));
    bufp->fullIData(oldp+21,(vlSelfRef.cache_storage__DOT__read_data),32);
    bufp->fullBit(oldp+22,(vlSelfRef.cache_storage__DOT__hit));
    bufp->fullBit(oldp+23,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0U][0U]));
    bufp->fullBit(oldp+24,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0U][1U]));
    bufp->fullBit(oldp+25,(vlSelfRef.cache_storage__DOT__valid_bits
                           [1U][0U]));
    bufp->fullBit(oldp+26,(vlSelfRef.cache_storage__DOT__valid_bits
                           [1U][1U]));
    bufp->fullBit(oldp+27,(vlSelfRef.cache_storage__DOT__valid_bits
                           [2U][0U]));
    bufp->fullBit(oldp+28,(vlSelfRef.cache_storage__DOT__valid_bits
                           [2U][1U]));
    bufp->fullBit(oldp+29,(vlSelfRef.cache_storage__DOT__valid_bits
                           [3U][0U]));
    bufp->fullBit(oldp+30,(vlSelfRef.cache_storage__DOT__valid_bits
                           [3U][1U]));
    bufp->fullBit(oldp+31,(vlSelfRef.cache_storage__DOT__valid_bits
                           [4U][0U]));
    bufp->fullBit(oldp+32,(vlSelfRef.cache_storage__DOT__valid_bits
                           [4U][1U]));
    bufp->fullBit(oldp+33,(vlSelfRef.cache_storage__DOT__valid_bits
                           [5U][0U]));
    bufp->fullBit(oldp+34,(vlSelfRef.cache_storage__DOT__valid_bits
                           [5U][1U]));
    bufp->fullBit(oldp+35,(vlSelfRef.cache_storage__DOT__valid_bits
                           [6U][0U]));
    bufp->fullBit(oldp+36,(vlSelfRef.cache_storage__DOT__valid_bits
                           [6U][1U]));
    bufp->fullBit(oldp+37,(vlSelfRef.cache_storage__DOT__valid_bits
                           [7U][0U]));
    bufp->fullBit(oldp+38,(vlSelfRef.cache_storage__DOT__valid_bits
                           [7U][1U]));
    bufp->fullBit(oldp+39,(vlSelfRef.cache_storage__DOT__valid_bits
                           [8U][0U]));
    bufp->fullBit(oldp+40,(vlSelfRef.cache_storage__DOT__valid_bits
                           [8U][1U]));
    bufp->fullBit(oldp+41,(vlSelfRef.cache_storage__DOT__valid_bits
                           [9U][0U]));
    bufp->fullBit(oldp+42,(vlSelfRef.cache_storage__DOT__valid_bits
                           [9U][1U]));
    bufp->fullBit(oldp+43,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xaU][0U]));
    bufp->fullBit(oldp+44,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xaU][1U]));
    bufp->fullBit(oldp+45,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xbU][0U]));
    bufp->fullBit(oldp+46,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xbU][1U]));
    bufp->fullBit(oldp+47,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xcU][0U]));
    bufp->fullBit(oldp+48,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xcU][1U]));
    bufp->fullBit(oldp+49,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xdU][0U]));
    bufp->fullBit(oldp+50,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xdU][1U]));
    bufp->fullBit(oldp+51,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xeU][0U]));
    bufp->fullBit(oldp+52,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xeU][1U]));
    bufp->fullBit(oldp+53,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xfU][0U]));
    bufp->fullBit(oldp+54,(vlSelfRef.cache_storage__DOT__valid_bits
                           [0xfU][1U]));
    bufp->fullIData(oldp+55,(vlSelfRef.cache_storage__DOT__tag_array
                             [0U][0U]),24);
    bufp->fullIData(oldp+56,(vlSelfRef.cache_storage__DOT__tag_array
                             [0U][1U]),24);
    bufp->fullIData(oldp+57,(vlSelfRef.cache_storage__DOT__tag_array
                             [1U][0U]),24);
    bufp->fullIData(oldp+58,(vlSelfRef.cache_storage__DOT__tag_array
                             [1U][1U]),24);
    bufp->fullIData(oldp+59,(vlSelfRef.cache_storage__DOT__tag_array
                             [2U][0U]),24);
    bufp->fullIData(oldp+60,(vlSelfRef.cache_storage__DOT__tag_array
                             [2U][1U]),24);
    bufp->fullIData(oldp+61,(vlSelfRef.cache_storage__DOT__tag_array
                             [3U][0U]),24);
    bufp->fullIData(oldp+62,(vlSelfRef.cache_storage__DOT__tag_array
                             [3U][1U]),24);
    bufp->fullIData(oldp+63,(vlSelfRef.cache_storage__DOT__tag_array
                             [4U][0U]),24);
    bufp->fullIData(oldp+64,(vlSelfRef.cache_storage__DOT__tag_array
                             [4U][1U]),24);
    bufp->fullIData(oldp+65,(vlSelfRef.cache_storage__DOT__tag_array
                             [5U][0U]),24);
    bufp->fullIData(oldp+66,(vlSelfRef.cache_storage__DOT__tag_array
                             [5U][1U]),24);
    bufp->fullIData(oldp+67,(vlSelfRef.cache_storage__DOT__tag_array
                             [6U][0U]),24);
    bufp->fullIData(oldp+68,(vlSelfRef.cache_storage__DOT__tag_array
                             [6U][1U]),24);
    bufp->fullIData(oldp+69,(vlSelfRef.cache_storage__DOT__tag_array
                             [7U][0U]),24);
    bufp->fullIData(oldp+70,(vlSelfRef.cache_storage__DOT__tag_array
                             [7U][1U]),24);
    bufp->fullIData(oldp+71,(vlSelfRef.cache_storage__DOT__tag_array
                             [8U][0U]),24);
    bufp->fullIData(oldp+72,(vlSelfRef.cache_storage__DOT__tag_array
                             [8U][1U]),24);
    bufp->fullIData(oldp+73,(vlSelfRef.cache_storage__DOT__tag_array
                             [9U][0U]),24);
    bufp->fullIData(oldp+74,(vlSelfRef.cache_storage__DOT__tag_array
                             [9U][1U]),24);
    bufp->fullIData(oldp+75,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xaU][0U]),24);
    bufp->fullIData(oldp+76,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xaU][1U]),24);
    bufp->fullIData(oldp+77,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xbU][0U]),24);
    bufp->fullIData(oldp+78,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xbU][1U]),24);
    bufp->fullIData(oldp+79,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xcU][0U]),24);
    bufp->fullIData(oldp+80,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xcU][1U]),24);
    bufp->fullIData(oldp+81,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xdU][0U]),24);
    bufp->fullIData(oldp+82,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xdU][1U]),24);
    bufp->fullIData(oldp+83,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xeU][0U]),24);
    bufp->fullIData(oldp+84,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xeU][1U]),24);
    bufp->fullIData(oldp+85,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xfU][0U]),24);
    bufp->fullIData(oldp+86,(vlSelfRef.cache_storage__DOT__tag_array
                             [0xfU][1U]),24);
    bufp->fullIData(oldp+87,(vlSelfRef.cache_storage__DOT__data_array
                             [0U][0U]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.cache_storage__DOT__data_array
                             [0U][1U]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.cache_storage__DOT__data_array
                             [1U][0U]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.cache_storage__DOT__data_array
                             [1U][1U]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.cache_storage__DOT__data_array
                             [2U][0U]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.cache_storage__DOT__data_array
                             [2U][1U]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.cache_storage__DOT__data_array
                             [3U][0U]),32);
    bufp->fullIData(oldp+94,(vlSelfRef.cache_storage__DOT__data_array
                             [3U][1U]),32);
    bufp->fullIData(oldp+95,(vlSelfRef.cache_storage__DOT__data_array
                             [4U][0U]),32);
    bufp->fullIData(oldp+96,(vlSelfRef.cache_storage__DOT__data_array
                             [4U][1U]),32);
    bufp->fullIData(oldp+97,(vlSelfRef.cache_storage__DOT__data_array
                             [5U][0U]),32);
    bufp->fullIData(oldp+98,(vlSelfRef.cache_storage__DOT__data_array
                             [5U][1U]),32);
    bufp->fullIData(oldp+99,(vlSelfRef.cache_storage__DOT__data_array
                             [6U][0U]),32);
    bufp->fullIData(oldp+100,(vlSelfRef.cache_storage__DOT__data_array
                              [6U][1U]),32);
    bufp->fullIData(oldp+101,(vlSelfRef.cache_storage__DOT__data_array
                              [7U][0U]),32);
    bufp->fullIData(oldp+102,(vlSelfRef.cache_storage__DOT__data_array
                              [7U][1U]),32);
    bufp->fullIData(oldp+103,(vlSelfRef.cache_storage__DOT__data_array
                              [8U][0U]),32);
    bufp->fullIData(oldp+104,(vlSelfRef.cache_storage__DOT__data_array
                              [8U][1U]),32);
    bufp->fullIData(oldp+105,(vlSelfRef.cache_storage__DOT__data_array
                              [9U][0U]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.cache_storage__DOT__data_array
                              [9U][1U]),32);
    bufp->fullIData(oldp+107,(vlSelfRef.cache_storage__DOT__data_array
                              [0xaU][0U]),32);
    bufp->fullIData(oldp+108,(vlSelfRef.cache_storage__DOT__data_array
                              [0xaU][1U]),32);
    bufp->fullIData(oldp+109,(vlSelfRef.cache_storage__DOT__data_array
                              [0xbU][0U]),32);
    bufp->fullIData(oldp+110,(vlSelfRef.cache_storage__DOT__data_array
                              [0xbU][1U]),32);
    bufp->fullIData(oldp+111,(vlSelfRef.cache_storage__DOT__data_array
                              [0xcU][0U]),32);
    bufp->fullIData(oldp+112,(vlSelfRef.cache_storage__DOT__data_array
                              [0xcU][1U]),32);
    bufp->fullIData(oldp+113,(vlSelfRef.cache_storage__DOT__data_array
                              [0xdU][0U]),32);
    bufp->fullIData(oldp+114,(vlSelfRef.cache_storage__DOT__data_array
                              [0xdU][1U]),32);
    bufp->fullIData(oldp+115,(vlSelfRef.cache_storage__DOT__data_array
                              [0xeU][0U]),32);
    bufp->fullIData(oldp+116,(vlSelfRef.cache_storage__DOT__data_array
                              [0xeU][1U]),32);
    bufp->fullIData(oldp+117,(vlSelfRef.cache_storage__DOT__data_array
                              [0xfU][0U]),32);
    bufp->fullIData(oldp+118,(vlSelfRef.cache_storage__DOT__data_array
                              [0xfU][1U]),32);
    bufp->fullCData(oldp+119,(vlSelfRef.cache_storage__DOT__index),4);
    bufp->fullIData(oldp+120,(vlSelfRef.cache_storage__DOT__tag),24);
    bufp->fullIData(oldp+121,(vlSelfRef.cache_storage__DOT__i),32);
    bufp->fullIData(oldp+122,(vlSelfRef.cache_storage__DOT__RESET_LOOP__DOT__j),32);
}
