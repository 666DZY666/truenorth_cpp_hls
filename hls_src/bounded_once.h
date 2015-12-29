/*
 * bounded_once.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef BOUNDED_ONCE_H_
#define BOUNDED_ONCE_H_

#include "lif_class.h"

//===Change the time bound here====
#define TIME_BOUND		4
//=================================

// Test parameters
// Types and top-level function prototype
#include <ap_int.h>
#include "common_test.h"
// Define widths of fixed point fields
#define BOUNDED_ONCE

#define ALPHA_N0		 4
#define BETA_N0			-4
#define LAMBDA_N0		 4
#define RES_VAL_N0		 0
#define V_INIT_N0		 0
const lif_out_t n0_hw_weights[CONNECTIONS_MAX] = {-4, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n0_sw_weights[CONNECTIONS_MAX] = {-4, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

#define ALPHA_N1		 1
#define BETA_N1			 -1
#define LAMBDA_N1		 0
#define RES_VAL_N1		 0
#define V_INIT_N1		 0
// Define fixed  point types for input, output and coefficients
const lif_out_t n1_hw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n1_sw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

#define ALPHA_N2		 1
#define BETA_N2			 -1
#define LAMBDA_N2		 0
#define RES_VAL_N2		 0
#define V_INIT_N2		 0
// Define fixed  point types for input, output and coefficients
const lif_out_t n2_hw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n2_sw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

#define ALPHA_N3		 4
#define BETA_N3			 -4
#define LAMBDA_N3		 -14
#define RES_VAL_N3		 0
#define V_INIT_N3		 0
// Define fixed  point types for input, output and coefficients
const lif_out_t n3_hw_weights[CONNECTIONS_MAX] = {9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n3_sw_weights[CONNECTIONS_MAX] = {9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

#define ALPHA_N4		 1
#define BETA_N4			 0
#define LAMBDA_N4		 -1
#define RES_VAL_N4		 0
#define V_INIT_N4		 0
// Define fixed  point types for input, output and coefficients
const lif_out_t n4_hw_weights[CONNECTIONS_MAX] = {-(1<<22), TIME_BOUND + 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n4_sw_weights[CONNECTIONS_MAX] = {-(1<<22), TIME_BOUND + 1, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

#define ALPHA_N5		 4
#define BETA_N5			 -4
#define LAMBDA_N5		 -5
#define RES_VAL_N5		 0
#define V_INIT_N5		 0
// Define fixed  point types for input, output and coefficients
const lif_out_t n5_hw_weights[CONNECTIONS_MAX] = {9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n5_sw_weights[CONNECTIONS_MAX] = {9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};


// Top level function prototype - wraps all object, method and functions for HLS
void bounded_once(lif_in_t indata[CONNECTIONS_MAX],
				 lif_out_t *result,
				 lif_in_t *spike);

void bounded_once_sw(bool indata[CONNECTIONS_MAX],
					 int *result,
					 bool *spike);

#endif /* BOUNDED_ONCE_H_ */
