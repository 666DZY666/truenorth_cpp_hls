/*
 * common_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
//for printing in binary format
#include <bitset>

using namespace std;

#include "lif_class.h"
#include "common_test.h"
#include "common_test_input.h"

void conv_in_to_bool(bool* spike_vector, int spike_vector_size,
					 const Interval* signal,int signal_len){
	int cnt = signal->length;
	int current_interval = 0;
	for(int j=0; j<spike_vector_size;j++){
		if(signal_len > 0){
			if(cnt > 0){
				cnt--;
			} else{
				signal_len--;
				current_interval++;
				cnt = (signal+current_interval)->length-1;
			}
			spike_vector[j] = (signal+current_interval)->value;
		}else{
			spike_vector[j] = 0;
		}
	}
}

int exec_tests(hw_func test_hw_func, sw_func test_sw_func)
{
	ofstream f_in_data_input;
	f_in_data_input.open("./golden/lif.input.dat", std::ios::out);

	bool spike_vector[TESTS_NUM];
	bool input_spikes[TESTS_NUM][CONNECTIONS_MAX];

	//initialize input to zero
	for(int i=0; i<TESTS_NUM; i++){
		for(int j=0; j<CONNECTIONS_MAX; j++){
			input_spikes[i][j] = 0;
		}
	}
	//convert input from in[] to input spikes
	for(unsigned int i=0;i<in_size;i++){
		conv_in_to_bool(spike_vector,TESTS_NUM, in[i], in_len_array[i]);
		for(int j=0;j<TESTS_NUM;j++){
			input_spikes[j][i] = spike_vector[j];
		}
	}

	for(int i=0;i<TESTS_NUM;i++){
		for(int j=0;j<CONNECTIONS_MAX;j++){
			f_in_data_input<<input_spikes[i][j]<<" ";
		}
		f_in_data_input<<endl;
	}
	f_in_data_input.close();

	ofstream f_out_data_sw;
	f_out_data_sw.open("./golden/lif.sw_output.dat", std::ios::out);

	int sw_result;
	bool sw_spike;
	for(int i=0; i<TESTS_NUM; i++){
		//run golden model
		test_sw_func(input_spikes[i], &sw_result, &sw_spike);
		// write results to the file
		f_out_data_sw<<sw_result<<" "<<sw_spike<<endl;
	}
	f_out_data_sw.close();

	lif_in_t test_data[TESTS_NUM][CONNECTIONS_MAX];
    lif_out_t hw_result;
    lif_in_t hw_spike;

	//read 2-dimentional array from ./golden/lif.input.dat
	ifstream f_in_data;
	string line;
	f_in_data.open("./golden/lif.input.dat", std::ios::in);
	int j=0;
	while(getline(f_in_data, line)){
		istringstream iss(line);
		int val;
		int i = 0;
		while(iss>>val){
			test_data[j][i++] = val;
		}
		j++;
	}
	f_in_data.close();

	//in a loop execute lif_neuron_top function and record results
	ofstream f_out_data;
	f_out_data.open("./golden/lif.hw_output.dat", std::ios::out);
	// Run test benches
	for (int i=0;i<TESTS_NUM;i++){
		// Run the DUT
		test_hw_func(test_data[i], &hw_result, &hw_spike);
		// write results to the file
		f_out_data<<hw_result<<" "<<hw_spike<<endl;
	}

	 //use diff system call to compare two files and report errors
	 /* Check the result */
	  int ret = system("diff --brief -w ./golden/lif.sw_output.dat ./golden/lif.hw_output.dat");

	  if (ret) {
		  printf("\n *** DUT hardware test FAILED ! *** \n\n");
	  } else {
		  printf("\n *** DUT hardware test PASSED ! *** \n\n");
	  }
	  // Only return 0 on success
	  return ret;
}


