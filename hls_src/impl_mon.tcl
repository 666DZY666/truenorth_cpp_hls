#********************************************************************************
# Author: Selyunin 
# Date : 13 August 2015
# Licence: BSDv2
# Device: Zynq
#********************************************************************************
#                                                 
##############################################
# Project settings
set part 			{xc7z020clg484-1}
set top_fn_name		impl_mon
set proj_name		impl_mon

# open_project	-reset lif_prj
puts "************************************************************************"
puts "Opening the project. Adding source and testbench files "
puts "************************************************************************"
# Create a project
open_project	-reset $proj_name
# open_project	lif_prj

# specify the top-level function for synthesis
# set_top lif_top
set_top $top_fn_name

# list source files
add_files			impl_mon.cpp
# CPP testbench files
add_files -tb		impl_mon_test.cpp
add_files -tb		common_test.cpp
add_files -tb		golden

open_solution "solution1"
set_part $part
create_clock -period 40

puts "************************************************************************"
puts "Simulating C/C++ design "
puts "************************************************************************"
csim_design -clean

set_directive_pipeline "$top_fn_name"
set_directive_array_partition -type complete -dim 1 "$top_fn_name" indata

puts "************************************************************************"
puts "Synthesizing HDL code "
puts "************************************************************************"
csynth_design

puts "************************************************************************"
puts "C/C++ synthesis report "
puts "************************************************************************"
# puts [ read [ open "lif_prj/solution1/syn/report/lif_top_csynth.rpt" r ]]
puts [ read [ open "${proj_name}/solution1/syn/report/${top_fn_name}_csynth.rpt" r ]]

puts "************************************************************************"
puts "Running RTL-cosimulation of the synthesized code"
puts "************************************************************************"
cosim_design -trace_level all -rtl verilog

puts "************************************************************************"
puts "Exporting design as an IP"
puts "************************************************************************"
export_design

# Do not perform any other steps
# - The basic project will be opened in the GUI 
exit
