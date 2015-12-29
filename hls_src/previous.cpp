/*
 * previous.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#include "previous.h"

using namespace neurons;

//Vivado HLS requires a top-level function definition that wraps all object
// instantiations and method calls to be synthesized as well as mapping
// the top-level I/O (function arguments) into/out of the methods/functions.
void previous(
	  lif_in_t indata[CONNECTIONS_MAX],
      lif_out_t *result,
	  lif_in_t *spike)
{
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS ARRAY_PARTITION variable=indata complete dim=1
   // Instantiate a lif_neuron - types and params defined in header file
	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n0(ALPHA_N0,
		   	   	   	   	   	   	   	   	   	   	   	   	   	 	 	  BETA_N0,
																	  RES_VAL,
																	  LAMBDA_N0,
																	  V_INIT);
	initialize_weights(n0.weights_, n0_hw_weights);
	// Call the compute() method - to output a weighted sum
	lif_out_t n0_result;
	lif_in_t  n0_spike = n0.spike_;

	lif_in_t n_hist_in[CONNECTIONS_MAX];
	n_hist_in[0] = n0_spike;
    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n1(ALPHA_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT);
	initialize_weights(n1.weights_, n1_hw_weights);

	n1.compute(n_hist_in, result, spike);
	n0.compute(indata, &n0_result, &n0_spike);
}

void previous_sw(
	  bool indata[CONNECTIONS_MAX],
      int *result,
	  bool* spike)
{
   // Instantiate a lif_neuron - types and params defined in header file
    static lif_neuron<bool,int,int,CONNECTIONS_MAX> n0(ALPHA_N0,
  	   	   	   	   	   	 	 	  	  	  	  	  	   BETA_N0,
													   RES_VAL,
													   LAMBDA_N0,
													   V_INIT);
	initialize_weights(n0.weights_, n0_sw_weights);
	int n0_result;
	bool n0_spike = n0.spike_;

	bool n_hist_in[CONNECTIONS_MAX];
	n_hist_in[0] = n0_spike;
	//Call the compute() method - to execute computataion of a model
    static lif_neuron<bool,int,int,CONNECTIONS_MAX> n1(ALPHA_N1,
													   BETA_N1,
													   RES_VAL,
													   LAMBDA_N1,
													   V_INIT);
	initialize_weights(n1.weights_, n1_sw_weights);

    n1.compute(n_hist_in, result, spike);
	n0.compute(indata, &n0_result, &n0_spike);
}




