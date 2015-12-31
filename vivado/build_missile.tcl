#********************************************************************************
# Author: Selyunin 
# Date : 30 December 2015
# Licence: BSDv2
# Device: Zybo
#********************************************************************************
#
#********************************************************************************
# Creating the project
set prj_name        {missile}

# setting up the relevant paths
set workspace_home           "[file normalize "./.."]"
set prj_root                 $workspace_home/vivado/$prj_name
set ip_path                  $workspace_home/ip_from_hls
set ip_infineon_path         $workspace_home/ip_infineon
set src_path                 $workspace_home/vivado/src

# set Zybo as a device board
set part                     {xc7z010clg400-1}
set board                    {digilentinc.com:zybo:part0:1.0}

puts "************************************************************************"
puts "Creating the project "
puts "************************************************************************"
create_project $prj_name $prj_root -part $part
set_property "board_part" $board [current_project]

# setting up project properties
set obj [get_projects $prj_name]
set_property "simulator_language" "Mixed" $obj
set_property "source_mgmt_mode" "DisplayOnly" $obj
set_property "target_language" "VHDL" $obj
set_property "target_simulator" "XSim" $obj

puts "************************************************************************"
puts "Creating source set "
puts "************************************************************************"

if {[string equal [get_filesets -quiet sources_1] ""]} {
  create_fileset -srcset sources_1
}

puts "************************************************************************"
puts "Adding IP path to the project "
puts "************************************************************************"

set obj [get_filesets sources_1]
set_property "ip_repo_paths" "[file normalize "$ip_path"] [file normalize "$ip_infineon_path"]" $obj
update_ip_catalog -rebuild
# get ip names (.zip files) in the ip_path directory
##############################################################
# 1) adding ip from HLS to the project (if not yet unpacked)
set ip_names "[glob -directory $ip_path *.zip]"
# add ips (.zip files) to the ip catalog if not unpacked
if { [string  equal [glob -directory $ip_path -types d -nocomplain xilinx_com_hls*] ""]} {
	puts "IPs from HLS are not yet unpacked. Unpacking.."
	foreach i $ip_names { update_ip_catalog -add_ip $i -repo_path $ip_path }
} else {
	#report what IPs in ip_path has been found
	set unpacked_ip_folders [glob -directory $ip_path -types d xilinx_com_hls*]
	set unpacked_ip_names [lsearch -regexp -all -inline [get_ipdefs] "xilinx.com:hls:*"]
	foreach i $unpacked_ip_folders { puts "IP folders found:\t [file tail $i]" }
	foreach i $unpacked_ip_names { puts "IP found:\t [file tail $i]" }
}
##############################################################
# 2) repeating 1) for infineon IPs
set ip_infineon_names "[glob -directory $ip_infineon_path *.zip]"
# add ips (.zip files) to the ip catalog if not unpacked
if { [string  equal [glob -directory $ip_infineon_path -types d -nocomplain infineon*] ""]} {
	puts "IPs from Infineon are not yet unpacked. Unpacking.."
	foreach i $ip_infineon_names { update_ip_catalog -add_ip $i -repo_path $ip_infineon_path }
} else {
	#report what IPs in ip_path has been found
	set unpacked_infineon_ip_folders [glob -directory $ip_infineon_path -types d infineon*]
	set unpacked_infineon_ip_names [lsearch -regexp -all -inline [get_ipdefs] "infineon*"]
	foreach i $unpacked_infineon_ip_folders { puts "IP folders found:\t [file tail $i]" }
	foreach i $unpacked_infineon_ip_names { puts "IP found:\t [file tail $i]" }
}
##############################################################
# get an IP name
# set ip_name      [lsearch -regexp -all -inline [get_ipdefs] "bounded_once"]

puts "************************************************************************"
puts "Adding constraints to the project "
puts "************************************************************************"
# Create 'constrs_1' fileset (if not found)
if {[string equal [get_filesets -quiet constrs_1] ""]} {
  create_fileset -constrset constrs_1
}

# Set 'constrs_1' fileset object
set obj [get_filesets constrs_1]
# Add/Import constrs file and set constrs file properties
set constr_file "[file normalize "$src_path/xdc/constr.xdc"]"
set file_added [add_files -norecurse -fileset $obj $constr_file]
set file_obj [get_files -of_objects [get_filesets constrs_1] [list "*$constr_file"]]
set_property "file_type" "XDC" $file_obj
# Set 'constrs_1' fileset properties
set_property "target_constrs_file" $constr_file $obj

puts "************************************************************************"
puts "Creating block designs ..."
puts "************************************************************************"
#creating block design for a neural monitor
source $src_path/bd/missile_bd.tcl

#creating block design for the whole system including signal generator
source $src_path/bd/rocket_stl_bd.tcl

##############################################################
#setting top object
set_property top rocket_stl_bd_wrapper [current_fileset]
##############################################################

puts "************************************************************************"
puts "Creating simulation fileset & adding simulation sources ..."
puts "************************************************************************"
# Create 'sim_1' fileset (if not found)
if {[string equal [get_filesets -quiet sim_1] ""]} {
  create_fileset -simset sim_1
}
# Adding simulation sources to the project
set obj [get_filesets sim_1]
set files [list \
 "[file normalize "$src_path/sim/missile_tb.vhd"]"\
 "[file normalize "$src_path/sim/edge_mon_tb.vhd"]"\
 "[file normalize "$src_path/sim/bounded_hist_tb.vhd"]"\
 "[file normalize "$src_path/sim/bounded_once_tb.vhd"]"\
 "[file normalize "$src_path/sim/rocket_top_tb.vhd"]"\
]
add_files -norecurse -fileset $obj $files

##############################################################
#setting top simulation object
set top_sim_file       rocket_top_tb
set_property top  $top_sim_file [get_filesets sim_1]
set_property top_lib xil_defaultlib [get_filesets sim_1]
##############################################################

