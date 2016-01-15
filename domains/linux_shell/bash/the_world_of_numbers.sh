#!/bin/bash

read x
read y

sum=$(($x+$y))
difference=$(($x-$y))
product=$(($x*$y))
quotient=$(($x/$y))

echo $sum
echo $difference
echo $product
echo $quotient
