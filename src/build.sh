#!/bin/bash

for ARCH in x86-64-bmi2 x86-64-avx2 x86-64-modern
do
    for NN_TRANSFORMED_FEATURE_DIMENSIONS in 192 256 384 512
    do
        for NN_NET_WIDTH in 16 24 32
        do
            make clean
            make -j build ARCH=$ARCH NN_TRANSFORMED_FEATURE_DIMENSIONS=$NN_TRANSFORMED_FEATURE_DIMENSIONS NN_NET_WIDTH=$NN_NET_WIDTH COMP=gcc
        done
    done
done
