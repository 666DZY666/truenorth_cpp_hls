/*
 * bounded_hist.h
 *
 *  Created on: Aug 12, 2015
 *      Author: selyunin
 */

#ifndef BOUNDED_HIST_H_
#define BOUNDED_HIST_H_

#include "lif_class.h"

//===Change the time bound here====
#define TIME_BOUND		5
//=================================

// Test parameters
//neuron parameters
#define ALPHA_N0		 4
#define BETA_N0			-4
#define LAMBDA_N0		 4
#define RES_VAL			 0
#define V_INIT			 0

#define ALPHA_N1		 (TIME_BOUND)
#define BETA_N1			 0
#define LAMBDA_N1		 0
#define RES_VAL			 0
#define V_INIT			 0

const lif_out_t n0_hw_weights[CONNECTIONS_MAX] = {-4, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n0_sw_weights[CONNECTIONS_MAX] = {-4, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

const lif_out_t n1_hw_weights[CONNECTIONS_MAX] = {1, -(1<<23), 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n1_sw_weights[CONNECTIONS_MAX] = {1, -(1<<23), 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

// Top level function prototype - wraps all object, method and functions for HLS
void bounded_hist(lif_in_t indata[CONNECTIONS_MAX],
				 lif_out_t *result,
				 lif_in_t *spike);

void bounded_hist_sw(bool indata[CONNECTIONS_MAX],
					 int *result,
					 bool *spike);

#endif /* BOUNDED_HIST_H_ */
