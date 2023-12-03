#!/bin/bash

echo "Enter the value of n:"
read n

a=0
b=1
non_fibonacci=""

while [ $b -le $n ]; do
    sum=$((a + b))
    non_fibonacci+=" $(seq $((b + 1)) $((sum - 1)))"
    a=$b
    b=$sum
done

echo "Non-Fibonacci numbers up to $n are:$non_fibonacci"
