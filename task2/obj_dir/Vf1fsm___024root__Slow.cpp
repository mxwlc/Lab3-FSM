// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1fsm.h for the primary calling header

#include "verilated.h"

#include "Vf1fsm__Syms.h"
#include "Vf1fsm___024root.h"

void Vf1fsm___024root___ctor_var_reset(Vf1fsm___024root* vlSelf);

Vf1fsm___024root::Vf1fsm___024root(Vf1fsm__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vf1fsm___024root___ctor_var_reset(this);
}

void Vf1fsm___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vf1fsm___024root::~Vf1fsm___024root() {
}
