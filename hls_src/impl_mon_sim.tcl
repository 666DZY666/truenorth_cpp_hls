set top_name {impl_mon}
set prj_name {impl_mon}
set prj_home {/home/selyunin/Dropbox/villach_2015/hls_designs}

cd ${prj_name}/solution1/sim/verilog/
current_fileset
open_wave_database ${top_name}.wdb
open_wave_config ${top_name}.wcfg
