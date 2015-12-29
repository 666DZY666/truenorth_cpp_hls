/*
 * edge.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef PUNC_ONCE_H_
#define PUNC_ONCE_H_

#include "lif_class.h"

// Test parameters
// Types and top-level function prototype
#include <ap_int.h>
#include "common_test.h"
// Define widths of fixed point fields
#define BOUNDED_ONCE

#define ALPHA_PREV		 1
#define BETA_PREV		-1
#define LAMBDA_PREV		 0
#define RES_VAL_PREV	 0
#define V_INIT_PREV		 0
const lif_out_t prev_hw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		prev_sw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

// Top level function prototype - wraps all object, method and functions for HLS
void punc_once_4(lif_in_t indata[CONNECTIONS_MAX],
				 lif_out_t *result,
				 lif_in_t *spike);

void punc_once_4_sw(bool indata[CONNECTIONS_MAX],
					 int *result,
					 bool *spike);

void punc_once_5(lif_in_t indata[CONNECTIONS_MAX],
				 lif_out_t *result,
				 lif_in_t *spike);

void punc_once_5_sw(bool indata[CONNECTIONS_MAX],
					 int *result,
					 bool *spike);
#endif /* EDGE_MON_H_ */
