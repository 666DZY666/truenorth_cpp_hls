/*
 * edge.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef EDGE_MON_H_
#define EDGE_MON_H_

#include "lif_class.h"

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

// Top level function prototype - wraps all object, method and functions for HLS
void edge_mon(lif_in_t indata[CONNECTIONS_MAX],
				 lif_out_t *result,
				 lif_in_t *spike);

void edge_mon_sw(bool indata[CONNECTIONS_MAX],
					 int *result,
					 bool *spike);

#endif /* EDGE_MON_H_ */
