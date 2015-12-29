/*
 * edge.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef IMPL_MON_H_
#define IMPL_MON_H_

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
const lif_out_t n0_hw_weights[CONNECTIONS_MAX] = {-9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n0_sw_weights[CONNECTIONS_MAX] = {-9, 9, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

// Top level function prototype - wraps all object, method and functions for HLS
void impl_mon(lif_in_t indata[CONNECTIONS_MAX],
				 lif_out_t *result,
				 lif_in_t *spike);

void impl_mon_sw(bool indata[CONNECTIONS_MAX],
					 int *result,
					 bool *spike);

#endif /* IMPL_MON_H_ */
