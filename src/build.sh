#!/bin/bash

for ARCH in x86-64-bmi2 x86-64-avx2
do
    for NNARCH in halfkp_256x2-32-32 halfkp_384x2-32-32 halfkp_512x2-32-32
    do
        make clean
        make -j build ARCH=$ARCH NNARCH=$NNARCH COMP=gcc
    done
done
