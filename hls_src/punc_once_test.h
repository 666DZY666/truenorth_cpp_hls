/*
 * bounded_once_test.h
 *
 *  Created on: Aug 13, 2015
 *      Author: selyunin
 */

#ifndef PUNC_ONCE_TEST_H_
#define PUNC_ONCE_TEST_H_

#include "common_test.h"
#include "lif_class.h"
#include "punc_once.h"

#ifdef BOUNDED_ONCE
const Interval in_1[] = {
						 Interval(SPIKE,14),
						 Interval(NOTSPIKE,8),
						 Interval(SPIKE,8),
						 Interval(NOTSPIKE,3),
						 Interval(SPIKE,5),
						 Interval(NOTSPIKE,6),
						 Interval(SPIKE,24),
						 Interval(NOTSPIKE,15),
						 Interval(SPIKE,45),
						 Interval(NOTSPIKE,30),
						};
const long unsigned int len_in_1 = sizeof(in_1)/sizeof(Interval);

const Interval in_2[] = {
						 Interval(NOTSPIKE,7),
						 Interval(SPIKE,33),
						 Interval(NOTSPIKE,15),
						 Interval(SPIKE,19),
						 Interval(NOTSPIKE,41),
						 Interval(SPIKE,46),
						 Interval(NOTSPIKE,24),
						 Interval(SPIKE,32),
						 Interval(NOTSPIKE,18),
						};
const long unsigned int len_in_2 = sizeof(in_2)/sizeof(Interval);

const Interval in_3[] = {
							Interval(SPIKE,3),
							Interval(NOTSPIKE,3),
							Interval(SPIKE,5)
						};
const long unsigned int len_in_3 = sizeof(in_3)/sizeof(Interval);

const Interval* in[] = {in_1, in_2, in_3};
const long unsigned int in_len_array[] = {len_in_1, len_in_2, len_in_3};
const long unsigned int in_size = sizeof(in)/sizeof(Interval*);

#endif



#endif /* PUNC_ONCE_TEST_H_ */
