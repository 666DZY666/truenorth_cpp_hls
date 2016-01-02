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

