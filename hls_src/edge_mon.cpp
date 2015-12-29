/*
 * bounded_once.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#include "edge_mon.h"

using namespace neurons;

//Vivado HLS requires a top-level function definition that wraps all object
// instantiations and method calls to be synthesized as well as mapping
// the top-level I/O (function arguments) into/out of the methods/functions.
void edge_mon(
	  lif_in_t indata[CONNECTIONS_MAX],
      lif_out_t *result,
	  lif_in_t *spike)
{
#pragma HLS LATENCY max=1
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS ARRAY_PARTITION variable=indata complete dim=1

   // Instantiate a lif_neuron - types and params defined in header file
	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n0(ALPHA_N0,
		   	   	   	   	   	   	   	   	   	   	   	   	   	 	 	  BETA_N0,
																	  RES_VAL_N0,
																	  LAMBDA_N0,
																	  V_INIT_N0);
	initialize_weights(n0.weights_, n0_hw_weights);

	lif_out_t n0_result;
	lif_in_t  n0_spike;
	n0.compute(indata, &n0_result, &n0_spike);

	lif_in_t n1_in[CONNECTIONS_MAX];
	n1_in[0] = n0_spike;
    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n1(ALPHA_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_N1,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_N1);
	initialize_weights(n1.weights_, n1_hw_weights);
	lif_out_t n1_result;
	lif_in_t  n1_spike = n1.spike_;

	lif_in_t n2_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n2_in complete dim=1
	n2_in[0] = n1_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n2(ALPHA_N2,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_N2,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_N2,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_N2,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_N2);
	initialize_weights(n2.weights_, n2_hw_weights);
	lif_out_t n2_result;
	lif_in_t  n2_spike;

	n2.compute(n2_in, &n2_result, &n2_spike);
	n1.compute(n1_in, &n1_result, &n1_spike);

	lif_in_t n3_in[CONNECTIONS_MAX];
	n3_in[0] = indata[0];
	n3_in[1] = n2_spike;
#pragma HLS ARRAY_PARTITION variable=n3_in complete dim=1

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n3(ALPHA_N3,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_N3,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_N3,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_N3,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_N3);
	initialize_weights(n3.weights_, n3_hw_weights);
	lif_out_t n3_result;
	lif_in_t  n3_spike;
	n3.compute(n3_in, result, spike);

}

void edge_mon_sw(
	  bool indata[CONNECTIONS_MAX],
      int *result,
	  bool* spike)
{
   // Instantiate a lif_neuron - types and params defined in header file
    static lif_neuron<bool,int,int,CONNECTIONS_MAX> n0(ALPHA_N0,
  	   	   	   	   	   	 	 	  	  	  	  	  	   BETA_N0,
													   RES_VAL_N0,
													   LAMBDA_N0,
													   V_INIT_N0);
	initialize_weights(n0.weights_, n0_sw_weights);
	int n0_result;
	bool n0_spike;
	n0.compute(indata, &n0_result, &n0_spike);

	bool n1_in[CONNECTIONS_MAX];
	n1_in[0] = n0_spike;
    static lif_neuron<bool,int,int,CONNECTIONS_MAX> n1(ALPHA_N1,
													   BETA_N1,
													   RES_VAL_N1,
													   LAMBDA_N1,
													   V_INIT_N1);
	initialize_weights(n1.weights_, n1_sw_weights);
	int n1_result;
	bool n1_spike = n1.spike_;

	bool n2_in[CONNECTIONS_MAX];
	n2_in[0] = n1_spike;

	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n2(ALPHA_N2,
													   BETA_N2,
													   RES_VAL_N2,
													   LAMBDA_N2,
													   V_INIT_N2);
	initialize_weights(n2.weights_, n2_sw_weights);
	int n2_result;
	bool n2_spike;

	n2.compute(n2_in, &n2_result, &n2_spike);
	n1.compute(n1_in, &n1_result, &n1_spike);

	bool n3_in[CONNECTIONS_MAX];
	n3_in[0] = indata[0];
	n3_in[1] = n2_spike;

	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n3(ALPHA_N3,
													   BETA_N3,
													   RES_VAL_N3,
													   LAMBDA_N3,
													   V_INIT_N3);
	initialize_weights(n3.weights_, n3_sw_weights);
	int n3_result;
	bool n3_spike;
	n3.compute(n3_in, result, spike);

}
