/*
 * bounded_once.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#include "bounded_once.h"

using namespace neurons;

//Vivado HLS requires a top-level function definition that wraps all object
// instantiations and method calls to be synthesized as well as mapping
// the top-level I/O (function arguments) into/out of the methods/functions.
void bounded_once(
	  lif_in_t indata[CONNECTIONS_MAX],
      lif_out_t *result,
	  lif_in_t *spike)
{
#pragma HLS INLINE recursive
#pragma HLS LATENCY max=0
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
	n1.compute(indata, &n1_result, &n1_spike);

	lif_in_t n3_in[CONNECTIONS_MAX];
	n3_in[0] = n0_spike;
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
	n3.compute(n3_in, &n3_result, &n3_spike);

	lif_in_t n4_in[CONNECTIONS_MAX];
	n4_in[0] = indata[0];
	n4_in[1] = n3_spike;
#pragma HLS ARRAY_PARTITION variable=n4_in complete dim=1
    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n4(ALPHA_N4,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_N4,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_N4,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_N4,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_N4);
	initialize_weights(n4.weights_, n4_hw_weights);
	lif_out_t n4_result;
	lif_in_t  n4_spike;
	n4.reset_mode_ = non_reset;
	n4.neg_threshold_ = saturate;
	n4.compute(n4_in, &n4_result, &n4_spike);

	lif_in_t n5_in[CONNECTIONS_MAX];
	n5_in[0] = indata[0];
	n5_in[1] = n4_spike;
    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n5(ALPHA_N5,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_N5,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_N5,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_N5,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_N5);
	initialize_weights(n5.weights_, n5_hw_weights);

	n5.compute(n5_in, result, spike);
}

void bounded_once_sw(
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
	n1_in[0] = indata[0];
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
	n3_in[0] = n0_spike;
	n3_in[1] = n2_spike;

	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n3(ALPHA_N3,
													   BETA_N3,
													   RES_VAL_N3,
													   LAMBDA_N3,
													   V_INIT_N3);
	initialize_weights(n3.weights_, n3_sw_weights);
	int n3_result;
	bool n3_spike;
	n3.compute(n3_in, &n3_result, &n3_spike);

	bool n4_in[CONNECTIONS_MAX];
	n4_in[0] = indata[0];
	n4_in[1] = n3_spike;

	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n4(ALPHA_N4,
													   BETA_N4,
													   RES_VAL_N4,
													   LAMBDA_N4,
													   V_INIT_N4);
	initialize_weights(n4.weights_, n4_sw_weights);
	int n4_result;
	bool n4_spike;
	n4.reset_mode_ = non_reset;
	n4.neg_threshold_ = saturate;
	n4.compute(n4_in, &n4_result, &n4_spike);

	bool n5_in[CONNECTIONS_MAX];
	n5_in[0] = indata[0];
	n5_in[1] = n4_spike;

	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n5(ALPHA_N5,
													   BETA_N5,
													   RES_VAL_N5,
													   LAMBDA_N5,
													   V_INIT_N5);
	initialize_weights(n5.weights_, n5_sw_weights);

	n5.compute(n5_in, result, spike);
}



