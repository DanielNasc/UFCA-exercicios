#!/bin/bash

N=10
FILE=$1

for i in $(seq 1 $N); do
    ./$FILE >> results_$FILE.txt
done