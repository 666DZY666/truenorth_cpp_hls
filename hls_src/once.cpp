/*
 * once.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#include "once.h"

using namespace neurons;

//Vivado HLS requires a top-level function definition that wraps all object
// instantiations and method calls to be synthesized as well as mapping
// the top-level I/O (function arguments) into/out of the methods/functions.
void once(
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
	// Call the compute() method - to execute a LIF model
	n0.compute(indata, result, spike);

}

void once_sw(
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

	n0.compute(indata, result, spike);
}




