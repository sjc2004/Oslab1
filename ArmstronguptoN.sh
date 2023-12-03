#!/bin/bash

is_armstrong() {
    num=$1
    len=${#num}
    sum=0
    temp=$num

    while [ $temp -gt 0 ]; do
        digit=$((temp % 10))
        sum=$((sum + digit ** len))
        temp=$((temp / 10))
    done

    [ $num -eq $sum ]
}

echo "Enter the value of n:"
read n

armstrong_numbers=""

for ((i = 1; i <= n; i++)); do
    if is_armstrong $i; then
        armstrong_numbers+=" $i"
    fi
done

echo "Armstrong numbers up to $n are:$armstrong_numbers"
