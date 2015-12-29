/*
 * bounded_once.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#include "punc_once.h"

using namespace neurons;

//Vivado HLS requires a top-level function definition that wraps all object
// instantiations and method calls to be synthesized as well as mapping
// the top-level I/O (function arguments) into/out of the methods/functions.
void punc_once_4(
	  lif_in_t indata[CONNECTIONS_MAX],
      lif_out_t *result,
	  lif_in_t *spike)
{
#pragma HLS LATENCY max=0
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS ARRAY_PARTITION variable=indata complete dim=1


    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n0(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n0.weights_, prev_hw_weights);
	lif_out_t n0_result;
	lif_in_t  n0_spike = n0.spike_;

	lif_in_t n1_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n1_in complete dim=1
	n1_in[0] = n0_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n1(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n1.weights_, prev_hw_weights);
	lif_out_t n1_result;
	lif_in_t  n1_spike = n1.spike_;

	n1.compute(n1_in, &n1_result, &n1_spike);
	n0.compute(indata, &n0_result, &n0_spike);

	lif_in_t n2_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n2_in complete dim=1
	n2_in[0] = n1_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n2(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n2.weights_, prev_hw_weights);
	lif_out_t n2_result;
	lif_in_t  n2_spike = n2.spike_;

	lif_in_t n3_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n3_in complete dim=1
	n3_in[0] = n2_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n3(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n3.weights_, prev_hw_weights);
	lif_out_t n3_result;
	lif_in_t  n3_spike = n3.spike_;

	n3.compute(n3_in, &n3_result, &n3_spike);
	n2.compute(n2_in, &n2_result, &n2_spike);

	lif_in_t n4_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n4_in complete dim=1
	n4_in[0] = n3_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n4(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n4.weights_, prev_hw_weights);
	lif_out_t n4_result;
	lif_in_t  n4_spike = n4.spike_;

	lif_in_t n5_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n5_in complete dim=1
	n5_in[0] = n4_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n5(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n5.weights_, prev_hw_weights);
	lif_out_t n5_result;
	lif_in_t  n5_spike = n5.spike_;

	n5.compute(n5_in, &n5_result, &n5_spike);
	n4.compute(n4_in, &n4_result, &n4_spike);

	lif_in_t n6_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n6_in complete dim=1
	n6_in[0] = n5_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n6(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n6.weights_, prev_hw_weights);
	lif_out_t n6_result;
	lif_in_t  n6_spike = n6.spike_;

	lif_in_t n7_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n5_in complete dim=1
	n7_in[0] = n6_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n7(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n7.weights_, prev_hw_weights);
	lif_out_t n7_result;
	lif_in_t  n7_spike = n7.spike_;

	n7.compute(n7_in, result, spike);
	n6.compute(n6_in, &n6_result, &n6_spike);
}

void punc_once_4_sw(
	  bool indata[CONNECTIONS_MAX],
      int *result,
	  bool* spike)
{
    static lif_neuron<bool,int,int,CONNECTIONS_MAX> n0(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n0.weights_, prev_sw_weights);
	int n0_result;
	bool n0_spike = n0.spike_;

	bool n1_in[CONNECTIONS_MAX];
	n1_in[0] = n0_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n1(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n1.weights_, prev_sw_weights);
	int n1_result;
	bool n1_spike = n1.spike_;

	n1.compute(n1_in, &n1_result, &n1_spike);
	n0.compute(indata, &n0_result, &n0_spike);

	bool n2_in[CONNECTIONS_MAX];
	n2_in[0] = n1_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n2(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n2.weights_, prev_sw_weights);
	int n2_result;
	bool n2_spike = n2.spike_;

	bool n3_in[CONNECTIONS_MAX];
	n3_in[0] = n2_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n3(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n3.weights_, prev_sw_weights);
	int n3_result;
	bool n3_spike = n3.spike_;

	n3.compute(n3_in, &n3_result, &n3_spike);
	n2.compute(n2_in, &n2_result, &n2_spike);

	bool n4_in[CONNECTIONS_MAX];
	n4_in[0] = n3_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n4(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n4.weights_, prev_sw_weights);
	int n4_result;
	bool n4_spike = n4.spike_;

	bool n5_in[CONNECTIONS_MAX];
	n5_in[0] = n4_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n5(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n5.weights_, prev_sw_weights);
	int n5_result;
	bool n5_spike = n5.spike_;

	n5.compute(n5_in, &n5_result, &n5_spike);
	n4.compute(n4_in, &n4_result, &n4_spike);


	bool n6_in[CONNECTIONS_MAX];
	n6_in[0] = n5_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n6(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n6.weights_, prev_sw_weights);
	int n6_result;
	bool n6_spike = n6.spike_;

	bool n7_in[CONNECTIONS_MAX];
	n7_in[0] = n6_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n7(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n7.weights_, prev_sw_weights);
	int n7_result;
	bool n7_spike = n7.spike_;

	n7.compute(n7_in, result, spike);
	n6.compute(n6_in, &n6_result, &n6_spike);

}

void punc_once_5(
	  lif_in_t indata[CONNECTIONS_MAX],
      lif_out_t *result,
	  lif_in_t *spike)
{
#pragma HLS LATENCY max=0
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS ARRAY_PARTITION variable=indata complete dim=1


    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n0(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n0.weights_, prev_hw_weights);
	lif_out_t n0_result;
	lif_in_t  n0_spike = n0.spike_;

	lif_in_t n1_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n1_in complete dim=1
	n1_in[0] = n0_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n1(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n1.weights_, prev_hw_weights);
	lif_out_t n1_result;
	lif_in_t  n1_spike = n1.spike_;

	n1.compute(n1_in, &n1_result, &n1_spike);
	n0.compute(indata, &n0_result, &n0_spike);

	lif_in_t n2_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n2_in complete dim=1
	n2_in[0] = n1_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n2(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n2.weights_, prev_hw_weights);
	lif_out_t n2_result;
	lif_in_t  n2_spike = n2.spike_;

	lif_in_t n3_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n3_in complete dim=1
	n3_in[0] = n2_spike;

    static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n3(ALPHA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      BETA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      RES_VAL_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      LAMBDA_PREV,
		   	   	   	   	   	   	   	   	   	   	  	   	   	   	      V_INIT_PREV);
	initialize_weights(n3.weights_, prev_hw_weights);
	lif_out_t n3_result;
	lif_in_t  n3_spike = n3.spike_;

	n3.compute(n3_in, &n3_result, &n3_spike);
	n2.compute(n2_in, &n2_result, &n2_spike);

	lif_in_t n4_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n4_in complete dim=1
	n4_in[0] = n3_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n4(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n4.weights_, prev_hw_weights);
	lif_out_t n4_result;
	lif_in_t  n4_spike = n4.spike_;

	lif_in_t n5_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n5_in complete dim=1
	n5_in[0] = n4_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n5(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n5.weights_, prev_hw_weights);
	lif_out_t n5_result;
	lif_in_t  n5_spike = n5.spike_;

	n5.compute(n5_in, &n5_result, &n5_spike);
	n4.compute(n4_in, &n4_result, &n4_spike);

	lif_in_t n6_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n6_in complete dim=1
	n6_in[0] = n5_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n6(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n6.weights_, prev_hw_weights);
	lif_out_t n6_result;
	lif_in_t  n6_spike = n6.spike_;

	lif_in_t n7_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n7_in complete dim=1
	n7_in[0] = n6_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n7(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n7.weights_, prev_hw_weights);
	lif_out_t n7_result;
	lif_in_t  n7_spike = n7.spike_;

	n7.compute(n7_in, &n7_result, &n7_spike);
	n6.compute(n6_in, &n6_result, &n6_spike);


	lif_in_t n8_in[CONNECTIONS_MAX];
	#pragma HLS ARRAY_PARTITION variable=n8_in complete dim=1
	n8_in[0] = n7_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n8(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n8.weights_, prev_hw_weights);
	lif_out_t n8_result;
	lif_in_t  n8_spike = n8.spike_;

	lif_in_t n9_in[CONNECTIONS_MAX];
#pragma HLS ARRAY_PARTITION variable=n9_in complete dim=1
	n9_in[0] = n8_spike;

	static lif_neuron<lif_in_t,lif_out_t,lif_rm_t,CONNECTIONS_MAX> n9(ALPHA_PREV,
																	  BETA_PREV,
																	  RES_VAL_PREV,
																	  LAMBDA_PREV,
																	  V_INIT_PREV);
	initialize_weights(n9.weights_, prev_hw_weights);
	lif_out_t n9_result;
	lif_in_t  n9_spike = n9.spike_;

	n9.compute(n9_in, result, spike);
	n8.compute(n8_in, &n8_result, &n8_spike);
}




void punc_once_5_sw(
	  bool indata[CONNECTIONS_MAX],
      int *result,
	  bool* spike)
{
    static lif_neuron<bool,int,int,CONNECTIONS_MAX> n0(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n0.weights_, prev_sw_weights);
	int n0_result;
	bool n0_spike = n0.spike_;

	bool n1_in[CONNECTIONS_MAX];
	n1_in[0] = n0_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n1(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n1.weights_, prev_sw_weights);
	int n1_result;
	bool n1_spike = n1.spike_;

	n1.compute(n1_in, &n1_result, &n1_spike);
	n0.compute(indata, &n0_result, &n0_spike);

	bool n2_in[CONNECTIONS_MAX];
	n2_in[0] = n1_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n2(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n2.weights_, prev_sw_weights);
	int n2_result;
	bool n2_spike = n2.spike_;

	bool n3_in[CONNECTIONS_MAX];
	n3_in[0] = n2_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n3(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n3.weights_, prev_sw_weights);
	int n3_result;
	bool n3_spike = n3.spike_;

	n3.compute(n3_in, &n3_result, &n3_spike);
	n2.compute(n2_in, &n2_result, &n2_spike);

	bool n4_in[CONNECTIONS_MAX];
	n4_in[0] = n3_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n4(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n4.weights_, prev_sw_weights);
	int n4_result;
	bool n4_spike = n4.spike_;

	bool n5_in[CONNECTIONS_MAX];
	n5_in[0] = n4_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n5(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n5.weights_, prev_sw_weights);
	int n5_result;
	bool n5_spike = n5.spike_;

	n5.compute(n5_in, &n5_result, &n5_spike);
	n4.compute(n4_in, &n4_result, &n4_spike);


	bool n6_in[CONNECTIONS_MAX];
	n6_in[0] = n5_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n6(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n6.weights_, prev_sw_weights);
	int n6_result;
	bool n6_spike = n6.spike_;

	bool n7_in[CONNECTIONS_MAX];
	n7_in[0] = n6_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n7(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n7.weights_, prev_sw_weights);
	int n7_result;
	bool n7_spike = n7.spike_;

	n7.compute(n7_in, &n7_result, &n7_spike);
	n6.compute(n6_in, &n6_result, &n6_spike);

	bool n8_in[CONNECTIONS_MAX];
	n8_in[0] = n7_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n8(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n8.weights_, prev_sw_weights);
	int n8_result;
	bool n8_spike = n8.spike_;

	bool n9_in[CONNECTIONS_MAX];
	n9_in[0] = n8_spike;
	static lif_neuron<bool,int,int,CONNECTIONS_MAX> n9(ALPHA_PREV,
													   BETA_PREV,
													   RES_VAL_PREV,
													   LAMBDA_PREV,
													   V_INIT_PREV);
	initialize_weights(n9.weights_, prev_sw_weights);
	int n9_result;
	bool n9_spike = n9.spike_;

	n9.compute(n9_in, result, spike);
	n8.compute(n8_in, &n8_result, &n8_spike);

}
