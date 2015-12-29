#!/bin/bash

#IP blocks to copy
HLS_IPS=(and_mon bounded_hist bounded_once edge_mon impl_mon punc_once_4 punc_once_5)

for el in ${HLS_IPS[@]}
do
	cp ../hls_designs/${el}/solution1/impl/ip/*.zip .
done
