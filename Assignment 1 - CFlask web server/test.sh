#!/bin/sh

# list=[1,2,3]

for i in 1 2 3 4 5 6 7 8
do
    echo "Data for -c="$i
    ab -n 100000 -c $i http://localhost:8081/arithmetic/prime?num=1009
    echo "========================================================"
done
