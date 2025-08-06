// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr CData/*1:0*/ Vtop___024root::cache_controller__DOT__IDLE;
constexpr CData/*1:0*/ Vtop___024root::cache_controller__DOT__READ_MEM;
constexpr CData/*1:0*/ Vtop___024root::cache_controller__DOT__UPDATE_CACHE;
constexpr CData/*1:0*/ Vtop___024root::cache_controller__DOT__WAIT_READ;
constexpr IData/*31:0*/ Vtop___024root::cache_controller__DOT__ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::cache_controller__DOT__DATA_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::cache_controller__DOT__BLOCK_SIZE;
constexpr IData/*31:0*/ Vtop___024root::cache_controller__DOT__INDEX_WIDTH;
constexpr IData/*31:0*/ Vtop___024root::cache_controller__DOT__TAG_WIDTH;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
