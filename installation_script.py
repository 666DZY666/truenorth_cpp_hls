#!/usr/bin/python

# This script:
# 1 states prerequisites 
# 2 checks versions of vivado & vivado hls
# 2 generates vivado HLS IPs
# 3 copies the IPs from vivado HLS to a folder 
# 4 generates final Vivado project

import os
import re
import sys
import csv
import glob
import argparse
import cmd, sys
import datetime
import shutil 
import tempfile 
import subprocess 
from lxml import etree as ET
import numpy as np
import matplotlib.pyplot as plt

sub_monitors = [
'and_mon', 
'bounded_hist',
'bounded_once', 
'edge_mon',
'impl_mon', 
'punc_once_4', 
'punc_once_5']

vivado_exec = ""
hls_exec = ""
root_dir_name = ""

def print_prereqs():
    print "To execute the following script you need:"
    print "1) Be on a *nix based platform (e.g. Linux, Mac)"
    print "2) Python 2.7 installed under /usr/bin/python"
    print "3) Vivado HLS 2015.2"
    print "4) Vivado 2015.2"
    print "Executing with other 2015.* versions should be fine as well\n"

def check_prereqs():
    global vivado_exec, hls_exec
    print "Checking installed versions of Vivado & HLS..."
    vivado_path = glob.glob("/opt/Xilinx/Vivado/*/bin")
    hls_path = glob.glob("/opt/Xilinx/Vivado_HLS/*/bin")
    if len(vivado_path) == 0:
        print "No Vivado Installation found under /opt/Xilinx/"
        print "Exit.."
        exit(1)
    elif len(hls_path) == 0:
        print "No Vivado HLS Installation found under /opt/Xilinx/"
        print "Exit.."
        exit(2)
    vivado_version = re.match(".*([0-9]{4}.[1-4]{1})", vivado_path[0]).group(1)
    print "Vivado Installation found:\t\t" + vivado_version
    hls_version = re.match(".*([0-9]{4}.[1-4]{1})", hls_path[0]).group(1)
    print "Vivado HLS Installation found:\t\t" + hls_version
    vivado_exec = vivado_path[0] + '/vivado'
    hls_exec    = hls_path[0] + '/vivado_hls'
    print "Checking if Vivado & HLS can be invoked ..."
    vivado_test = vivado_exec + ' -version' 
    hls_test    = hls_exec + ' --help'
    FNULL = open(os.devnull, 'w')
    exit_code_hls = subprocess.call([hls_test], 
                        shell=True, stderr=subprocess.STDOUT, stdout=FNULL)
    exit_code_vivado = subprocess.call([vivado_test], 
                        shell=True, stderr=subprocess.STDOUT, stdout=FNULL)
    if exit_code_hls != 0:
        print "Vivado HLS cannot be invoked from its standard location"
        print "Exit.."
        exit(3)
    elif exit_code_vivado != 0:
        print "Vivado cannot be invoked from its standard location"
        print "Exit.."
        exit(4)
    else:
        print "Vivado successfully invoked. Executable located\n" + vivado_exec
        print "Vivado HLS successfully invoked. Executable located\n" + hls_exec
    
def generate_hls_ips():
    global root_dir_name
    print "Generating monitor IPs using Vivado HLS..."
    #cd to the directory from where the script is invoked
    root_dir_name = os.path.dirname(os.path.abspath(__file__))
    print "root_dir_name:\t" + root_dir_name
    os.chdir(root_dir_name)
    print "going to the directory ./hls_src/  ..."
    hls_dir = root_dir_name + '/hls_src/'
    os.chdir(hls_dir)
    print "==================================="
    print "Generation of HLS IPs: started  ..."
    print "==================================="
    for monitor in sub_monitors:
        print "-----------------------------------"
        print "Generating HLS IP:\t\t" + monitor
        print "-----------------------------------"
        hls_command = hls_exec + ' -f ' + monitor + '.tcl'
        exit_code_IP = subprocess.call([hls_command], 
                           shell=True, stderr=False, stdout=False)
    print "==================================="
    print "Generation of HLS IPs: finished    "
    print "==================================="
    os.chdir(root_dir_name)
    
def copy_ips():
    print "==================================="
    print "Copying IPs to ip_from_hls folder.."
    print "==================================="

    ip_from_hls_dir = root_dir_name + '/ip_from_hls'
    os.chdir(ip_from_hls_dir)
    copy_ip_cmd = 'bash ' + 'copy_hls_ips.sh'
    exit_code_copy = subprocess.call([copy_ip_cmd], 
                        shell=True, stderr=False, stdout=False)
    if exit_code_copy == 0:
        print "==================================="
        print "Copying done successfully          "
        print "==================================="

    
def generate_vivado_prj():
    print "==================================="
    print "Generating Vivado project...       "
    print "==================================="
    vivado_dir = root_dir_name + '/vivado'
    os.chdir(vivado_dir)
    vivado_cmd = vivado_exec + ' -mode batch -source build_missile.tcl'
    exit_code_vivado = subprocess.call([vivado_cmd], 
                        shell=True, stderr=False, stdout=False)
    if exit_code_vivado == 0:
        print "==================================="
        print "Vivado project generated           "
        print "==================================="
    
def main(argv):
    print_prereqs()
    check_prereqs()
    generate_hls_ips()
    copy_ips()
    generate_vivado_prj()
   

if __name__ == "__main__":
    main(sys.argv[1:])
