/*
 * once.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef ONCE_H_
#define ONCE_H_

#include "lif_class.h"
//===This once operator is untimed (i.e. does not have bounds)
//=====================================

// Test parameters
#include <ap_int.h>

//neuron parameters
#define ALPHA_N0		 4
#define BETA_N0			-4
#define LAMBDA_N0		 0
#define RES_VAL			 5
#define V_INIT			 0

const lif_out_t n0_hw_weights[CONNECTIONS_MAX] = {7, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n0_sw_weights[CONNECTIONS_MAX] = {7, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

// Top level function prototype - wraps all object, method and functions for HLS
void once(lif_in_t indata[CONNECTIONS_MAX],
			  lif_out_t *result,
			  lif_in_t *spike);

void once_sw(bool indata[CONNECTIONS_MAX],
				 int *result,
				 bool *spike);

#endif /* ONCE_H_ */
