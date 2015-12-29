/*
 * previous.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef PREVIOUS_H_
#define PREVIOUS_H_


#include "lif_class.h"

//===Previous does not have time bounds
//=====================================

// Test parameters
#include <ap_int.h>

//neuron parameters
#define ALPHA_N0		 1
#define BETA_N0			-1
#define LAMBDA_N0		 0
#define RES_VAL			 0
#define V_INIT			 0

#define ALPHA_N1		 1
#define BETA_N1			 -1
#define LAMBDA_N1		 0
#define RES_VAL			 0
#define V_INIT			 0

const lif_out_t n0_hw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n0_sw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

const lif_out_t n1_hw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};
const int 		n1_sw_weights[CONNECTIONS_MAX] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0};

// Top level function prototype - wraps all object, method and functions for HLS
void previous(lif_in_t indata[CONNECTIONS_MAX],
			  lif_out_t *result,
			  lif_in_t *spike);

void previous_sw(bool indata[CONNECTIONS_MAX],
				 int *result,
				 bool *spike);

#endif /* PREVIOUS_H_ */
