/*
 * common_test.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */
#ifndef COMMON_TEST_H_
#define COMMON_TEST_H_

#include "lif_class.h"

#ifdef FLOAT_DATA
#define ABS_ERR_THRESH 0.0
#else
#define ABS_ERR_THRESH 0.001
#endif

typedef void (*hw_func)(lif_in_t*, lif_out_t*, lif_in_t*);
typedef void (*sw_func)(bool*, int*, bool*);

struct Interval{
	bool value;
	unsigned int length;
	Interval(bool new_value, unsigned int new_length):
		value(new_value), length(new_length) { }
};

void conv_in_to_bool(bool* spike_vector, int spike_vector_size,
					 const Interval* signal,int signal_len);

int exec_tests(hw_func test_hw_func, sw_func test_sw_func);


#endif /* COMMON_TEST_H_ */
