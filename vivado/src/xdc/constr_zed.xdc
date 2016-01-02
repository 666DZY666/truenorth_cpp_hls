#############################################
###  ZED Constraints
#############################################
# Constraints for out_clk (for oscill picture)
set_property PACKAGE_PIN Y9 [get_ports {clk_i}]
set_property IOSTANDARD LVCMOS33 [get_ports {clk_i}]

#constrain for MON Reset signal rst_n_i button SW0
set_property PACKAGE_PIN F22 [get_ports {rst_n_i}]
set_property IOSTANDARD LVCMOS33 [get_ports {rst_n_i}]

#output from mon_o (LED_4)
set_property PACKAGE_PIN V22 [get_ports {mon_o}]
set_property IOSTANDARD LVCMOS33 [get_ports {mon_o}]


# Constraints for launch_en_mon from rocket_sig_gen (JA2 on ZedBoard)
set_property PACKAGE_PIN AA11 [get_ports {launch_en_mon}]
set_property IOSTANDARD LVCMOS33 [get_ports {launch_en_mon}]

# output for fire_en from rocket_sig_gen (JA4 on ZedBoard)
set_property PACKAGE_PIN AA9 [get_ports {fire_en}]
set_property IOSTANDARD LVCMOS33 [get_ports {fire_en}]

# output for detonation_en from rocket_sig_gen (JA1 on ZedBoard)
set_property PACKAGE_PIN Y11 [get_ports {detonation_en}]
set_property IOSTANDARD LVCMOS33 [get_ports {detonation_en}]

# output for clk_div  (TC1_P on ZedBoard)
set_property PACKAGE_PIN U22 [get_ports {clk_div}]
set_property IOSTANDARD LVCMOS33 [get_ports {clk_div}]

# output for mon_o_scope  (JA3 on ZedBoard)
set_property PACKAGE_PIN Y10 [get_ports {mon_o_scope}]
set_property IOSTANDARD LVCMOS33 [get_ports {mon_o_scope}]

