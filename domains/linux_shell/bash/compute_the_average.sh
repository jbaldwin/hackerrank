#!/bin/bash

read n
total=0

for i in $(seq 1 $n)
do
    read x
    total=$(($total+$x))
done

printf "%.3f" $(echo "scale=5; ($total / $n)" | bc)
