harmonia_src
=============

Vivado & HLS project: neural monitor for missile case study 

### Description

This is a source code to generate a vivado project which is
used as a case study for a neural monitor in DATE'2016 paper.

### Requirements

* Vivado 2015.2
* Vivado HLS 

### Installation instructions

First we outline the structure of the repository:
* `hls_src` contains C/C++ sources for generating neural monitors 
   in vivado HLS. Each sub-monitor is generated in a sequence
   of steps which are governed by the corresponding tcl-scripts.
*  `ip_from_hls` is a folder to store IPs generated by vivado HLS.
   The script `copy_hls_ips.sh` in this folder copies generated IPs to 
   from `hls_src` to this directory.
* `ip_infineon` contains IPs that are used in the project developed by
   Infineon (e.g. RS-trigger, Clock divider, signal generator)
* `vivado` holds all vivado related source files and tcl-scripts for
   generating a vivado project. The script 	build_missile.tcl` is a
   main script for creating the project.


### License

Need to agree about licencing terms.

### About the author

I am a PhD Student at Vienna University of Technology and 
a project assistant in HARMONIA FFG Project.

Konstantin Selyunin
http://www.selyunin.com