#############################################
###  ZYBO Constraints
#############################################
# Constraints for out_clk (for oscill picture)
set_property PACKAGE_PIN L16 [get_ports clk_i]
set_property IOSTANDARD LVCMOS33 [get_ports clk_i]

#constrain for MON Reset signal rst_n_i button SW0
set_property PACKAGE_PIN G15 [get_ports rst_i]
set_property IOSTANDARD LVCMOS33 [get_ports rst_i]

#output from mon_o (LED_4)

# output for gen_o from input_gen(JB3 on Zybo)
set_property PACKAGE_PIN V20 [get_ports {gen_o[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {gen_o[0]}]

# output for clk_div  (JC1 on Zybo)
set_property PACKAGE_PIN V15 [get_ports clk_div]
set_property IOSTANDARD LVCMOS33 [get_ports clk_div]

# output for mon_o_scope  (JB4 on Zybo)
set_property PACKAGE_PIN W20 [get_ports {spike_V[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {spike_V[0]}]



# set_output_delay -clock [get_generated_clocks -regexp .*clk_out1_ip_debug_bd_clk_wiz_0_0.*] 6.000 [get_ports -regexp spike_V.*]
# set_output_delay -clock [get_generated_clocks -regexp .*clk_out1_ip_debug_bd_clk_wiz_0_0.*] 6.000 [get_ports -regexp clk_div]
# set_input_delay -clock [get_clocks clk_i] -max 3.000 [get_ports rst_i]
# set_input_delay -clock [get_clocks clk_i] -min 1.000 [get_ports rst_i]



create_debug_core u_ila_0 ila
set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU_CNT 4 [get_debug_cores u_ila_0]
set_property C_ADV_TRIGGER true [get_debug_cores u_ila_0]
set_property C_DATA_DEPTH 16384 [get_debug_cores u_ila_0]
set_property C_EN_STRG_QUAL true [get_debug_cores u_ila_0]
set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
set_property port_width 1 [get_debug_ports u_ila_0/clk]
connect_debug_port u_ila_0/clk [get_nets [list clk_i_IBUF_BUFG]]
set_property port_width 1 [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list ip_debug_bd_i/bounded_once_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list ip_debug_bd_i/clk_wiz_out1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list ip_debug_bd_i/input_gen_0_gen_o]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe3]
connect_debug_port u_ila_0/probe3 [get_nets [list ip_debug_bd_i/util_vector_logic_0_Res]]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets clk_i_IBUF_BUFG]
