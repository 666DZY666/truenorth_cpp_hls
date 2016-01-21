##===========================================
## Timing Assertions Section
##===========================================
##  Primary clocks
#############################################
#create_clock
create_clock -period 10.000 -name clk_i -waveform {0.000 5.000} [get_ports clk_i]

#############################################
##  Virtual clocks
#############################################

#############################################
##  Generated clocks
#############################################
#create_generated_clock
create_generated_clock -name clk_out1 \        
                       -source [get_ports clk_i] \                       
                       -divide_by 10  \
                       [get_pins -hierarchical -regexp .*uClkDiv_0/clk_o]

#############################################
##  Clock groups
#############################################get
#set_clock_groups

#############################################
##  Input and output delay constraints
#############################################
#set_input_delay
set_input_delay -clock [get_clocks clk_i] -max 3.000 [get_ports rst_i]
#report_timing -from [get_ports rst_i]

#set_input_delay -clock [get_clocks clk_i] \
#                        -max 3 \
#                        [get_ports clk_i]
#report_timing -from [get_ports clk_i]

#report_timing -from [all_inputs]


#set_output_delay
set_output_delay -clock [get_clocks -regexp .*clk_out1.*] 6.000 [get_ports -regexp spike_V.*]
#report_timing -to [get_ports -regexp spike_V.*]

set_output_delay -clock [get_clocks -regexp .*clk_out1.*] 6.000 [get_ports -regexp clk_div]
#report_timing -to [get_ports -regexp clk_div]

set_output_delay -clock [get_clocks -regexp .*clk_out1.*] 6.000 [get_ports -regexp gen_o.*]
#report_timing -to [get_ports -regexp gen_o.*]
##===========================================
## Timing Exceptions Section
##===========================================
## False Paths
#############################################
#set_false_path

#############################################
## Max Delay / Min Delay
#############################################
#set_max_delay

#############################################
## Multicycle Paths
#############################################
#set_multicycle_path

#############################################
## Case Analysis
#############################################

#############################################
## Disable Timing
#############################################

##===========================================
## Timing Reports Cheet Sheet
##===========================================
# report_timing_summary
# check_timing
# report_drc
# report_timing -to [all_outputs ]

# get_pins -of_objects [get_cells ip_debug_bd_i/input_gen_0]
# get_pins -hierarchical -regexp .*clk_out1



