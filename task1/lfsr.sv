module lfsr (
    input logic clk,
    input logic rst,
    output logic [6:0] data_out,
    input logic en
);

logic [7:1] sreg;

always_ff @ (posedge clk)
    if (rst)
        sreg <= 7'b1;
    else if(en)
        sreg <= {sreg[6:1], sreg[3]^sreg[7]};

assign data_out = sreg; 
endmodule
