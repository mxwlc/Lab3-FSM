#!/bin/sh

rm -rf obj_dir
rm -f f1fsm.vcd

verilator -Wall --cc --trace f1fsm.sv --exe f1fsm_tb.cpp

make -j -C obj_dir/ -f Vf1fsm.mk Vf1fsm

sudo obj_dir/Vf1fsm