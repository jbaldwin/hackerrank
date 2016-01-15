#!/bin/bash

read math

printf "%.3f" $(echo "scale=5; $math" | bc)
