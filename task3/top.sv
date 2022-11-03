module top #(
    WIDTH = 16
)
(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [WIDTH-1:0] N,
    output logic [7:0] data_out    
);

wire logic tick;

clktick clock(
    .en(en),
    .rst(rst),
    .clk(clk),
    .N(N),
    .tick(tick) 
);

f1fsm f1(
    .en(tick),
    .clk(clk),
    .rst(rst),
    .data_out(data_out)
);

endmodule
