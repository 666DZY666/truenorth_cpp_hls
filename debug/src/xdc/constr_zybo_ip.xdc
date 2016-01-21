#############################################
##  IPs from HLS Constraints
############################################
#create_clock -name ap_clk -period 65.000 [get_pins -hierarchical -regexp .*ap_clk]
#set_property HD.CLK_SRC BUFGCTRL_X0Y0 [get_pins -hierarchical -regexp .*ap_clk]



