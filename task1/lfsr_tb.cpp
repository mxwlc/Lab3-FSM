#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vlfsr.h"
#include "vbuddy.cpp"

#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env)
{
    int clk;
    int simcyc;
    int tick;
    // init top verilog instance
    Verilated::commandArgs(argc, argv);
    Vlfsr *top = new Vlfsr;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("lfsr.vcd");

    if (!vbdOpen())
    {
        return (-1);
    }
    vbdHeader("Lab 3: FSM");

    top->rst = 0;
    top->clk = 0;
    top->en = 0;
    vbdSetMode(1);

    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++)
    {
        for (tick = 0; tick < 2; tick++)
        {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }
        vbdHex(2, (int(top->data_out) >> 4) & 0xF);
        vbdHex(1, top->data_out & 0xF);
        
        vbdBar(top->data_out & 0xFF);
        top->en = vbdFlag();
        top->rst = (simcyc < 2);
    }
}