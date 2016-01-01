##############################################
####  ZED Constraints
##############################################
## Constraints for out_clk (for oscill picture)
#set_property PACKAGE_PIN Y9 [get_ports {clk_i}]
#set_property IOSTANDARD LVCMOS33 [get_ports {clk_i}]

##constrain for MON Reset signal rst_n_i button SW0
#set_property PACKAGE_PIN F22 [get_ports {rst_n_i}]
#set_property IOSTANDARD LVCMOS33 [get_ports {rst_n_i}]

##output from mon_o (LED_4)
#set_property PACKAGE_PIN V22 [get_ports {mon_o}]
#set_property IOSTANDARD LVCMOS33 [get_ports {mon_o}]


## Constraints for launch_en_mon from rocket_sig_gen (JA2 on ZedBoard)
#set_property PACKAGE_PIN AA11 [get_ports {launch_en_mon}]
#set_property IOSTANDARD LVCMOS33 [get_ports {launch_en_mon}]

## output for fire_en from rocket_sig_gen (JA4 on ZedBoard)
#set_property PACKAGE_PIN AA9 [get_ports {fire_en}]
#set_property IOSTANDARD LVCMOS33 [get_ports {fire_en}]

## output for detonation_en from rocket_sig_gen (JA1 on ZedBoard)
#set_property PACKAGE_PIN Y11 [get_ports {detonation_en}]
#set_property IOSTANDARD LVCMOS33 [get_ports {detonation_en}]

## output for clk_div  (TC1_P on ZedBoard)
#set_property PACKAGE_PIN U22 [get_ports {clk_div}]
#set_property IOSTANDARD LVCMOS33 [get_ports {clk_div}]

## output for mon_o_scope  (JA3 on ZedBoard)
#set_property PACKAGE_PIN Y10 [get_ports {mon_o_scope}]
#set_property IOSTANDARD LVCMOS33 [get_ports {mon_o_scope}]

#############################################
###  ZYBO Constraints
#############################################
# Constraints for out_clk (for oscill picture)
set_property PACKAGE_PIN L16 [get_ports clk_i]
set_property IOSTANDARD LVCMOS33 [get_ports clk_i]

#constrain for MON Reset signal rst_n_i button SW0
set_property PACKAGE_PIN G15 [get_ports rst_n_i]
set_property IOSTANDARD LVCMOS33 [get_ports rst_n_i]

#output from mon_o (LED_4)
set_property PACKAGE_PIN M14 [get_ports {mon_o[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {mon_o[0]}]

# Constraints for launch_en_mon from rocket_sig_gen (JB1 on Zybo)
set_property PACKAGE_PIN T20 [get_ports launch_en_mon]
set_property IOSTANDARD LVCMOS33 [get_ports launch_en_mon]

# output for fire_en from rocket_sig_gen (JB2 on Zybo)
set_property PACKAGE_PIN U20 [get_ports fire_en]
set_property IOSTANDARD LVCMOS33 [get_ports fire_en]

# output for detonation_en from rocket_sig_gen (JB3 on Zybo)
set_property PACKAGE_PIN V20 [get_ports detonation_en]
set_property IOSTANDARD LVCMOS33 [get_ports detonation_en]

# output for clk_div  (JC1 on Zybo)
set_property PACKAGE_PIN V15 [get_ports clk_div]
set_property IOSTANDARD LVCMOS33 [get_ports clk_div]

# output for mon_o_scope  (JB4 on Zybo)
set_property PACKAGE_PIN W20 [get_ports {mon_o_scope[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {mon_o_scope[0]}]

# create_debug_core u_ila_0_0 ila
# set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0_0]
# set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0_0]
# set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0_0]
# set_property C_DATA_DEPTH 32768 [get_debug_cores u_ila_0_0]
# set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0_0]
# set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0_0]
# set_property C_TRIGIN_EN false [get_debug_cores u_ila_0_0]
# set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0_0]
# set_property port_width 1 [get_debug_ports u_ila_0_0/clk]
# connect_debug_port u_ila_0_0/clk [get_nets [list clk_i_IBUF_BUFG]]
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe0]
# connect_debug_port u_ila_0_0/probe0 [get_nets [list {mon_o_scope_OBUF[0]}]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe1]
# connect_debug_port u_ila_0_0/probe1 [get_nets [list clk_div_OBUF]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe2]
# connect_debug_port u_ila_0_0/probe2 [get_nets [list detonation_en_OBUF]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe3]
# connect_debug_port u_ila_0_0/probe3 [get_nets [list fire_en_OBUF]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe4]
# connect_debug_port u_ila_0_0/probe4 [get_nets [list launch_en_mon_OBUF]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe5]
# connect_debug_port u_ila_0_0/probe5 [get_nets [list rocket_stl_demo2_i/neural_mon_0/punc_once_4_0/U0/n0_spike_V]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe6]
# connect_debug_port u_ila_0_0/probe6 [get_nets [list rocket_stl_demo2_i/neural_mon_0/bounded_once_0_spike_V]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe7]
# connect_debug_port u_ila_0_0/probe7 [get_nets [list rocket_stl_demo2_i/neural_mon_0/punc_once_5_1_spike_V]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe8]
# connect_debug_port u_ila_0_0/probe8 [get_nets [list rocket_stl_demo2_i/neural_mon_0/and_mon_0_spike_V]]
# create_debug_port u_ila_0_0 probe
# set_property port_width 1 [get_debug_ports u_ila_0_0/probe9]
# connect_debug_port u_ila_0_0/probe9 [get_nets [list rocket_stl_demo2_i/neural_mon_0/bounded_hist_0_spike_V]]
# set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
# set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
# set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
# connect_debug_port dbg_hub/clk [get_nets clk_i_IBUF_BUFG]

set_property port_width 1 [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list rocket_stl_bd_i/neural_mon_0/and_mon_0_spike_V]]

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
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list rocket_stl_bd_i/neural_mon_0/ap_clk_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list rocket_stl_bd_i/neural_mon_0/ap_rst_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe3]
connect_debug_port u_ila_0/probe3 [get_nets [list rocket_stl_bd_i/neural_mon_0/ap_start_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe4]
connect_debug_port u_ila_0/probe4 [get_nets [list rocket_stl_bd_i/neural_mon_0/bounded_hist_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe5]
connect_debug_port u_ila_0/probe5 [get_nets [list rocket_stl_bd_i/neural_mon_0/bounded_once_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe6]
connect_debug_port u_ila_0/probe6 [get_nets [list rocket_stl_bd_i/neural_mon_0/detonation_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe7]
connect_debug_port u_ila_0/probe7 [get_nets [list rocket_stl_bd_i/neural_mon_0/edge_mon_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe8]
connect_debug_port u_ila_0/probe8 [get_nets [list rocket_stl_bd_i/neural_mon_0/edge_mon_1_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe9]
connect_debug_port u_ila_0/probe9 [get_nets [list rocket_stl_bd_i/neural_mon_0/fire_en_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe10]
connect_debug_port u_ila_0/probe10 [get_nets [list rocket_stl_bd_i/neural_mon_0/impl_mon_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe11]
connect_debug_port u_ila_0/probe11 [get_nets [list rocket_stl_bd_i/neural_mon_0/launch_en_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe12]
connect_debug_port u_ila_0/probe12 [get_nets [list rocket_stl_bd_i/launch_en_1]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe13]
connect_debug_port u_ila_0/probe13 [get_nets [list rocket_stl_bd_i/neural_mon_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe14]
connect_debug_port u_ila_0/probe14 [get_nets [list rocket_stl_bd_i/neural_mon_0/punc_once_4_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe15]
connect_debug_port u_ila_0/probe15 [get_nets [list rocket_stl_bd_i/neural_mon_0/punc_once_5_0_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe16]
connect_debug_port u_ila_0/probe16 [get_nets [list rocket_stl_bd_i/neural_mon_0/punc_once_5_1_spike_V]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe17]
connect_debug_port u_ila_0/probe17 [get_nets [list rocket_stl_bd_i/rocket_gen_0_fire_en_o]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe18]
connect_debug_port u_ila_0/probe18 [get_nets [list rocket_stl_bd_i/rocket_gen_loop_0_detonation_o]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe19]
connect_debug_port u_ila_0/probe19 [get_nets [list rocket_stl_bd_i/uClkDiv_0_clk_o]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe20]
connect_debug_port u_ila_0/probe20 [get_nets [list rocket_stl_bd_i/util_vector_logic_0_Res]]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets clk_i_IBUF_BUFG]
