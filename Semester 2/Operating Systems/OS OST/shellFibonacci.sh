#!/bin/bash

echo "Enter number of terms:"
read n

a=0
b=1
count=0

echo "Fibonacci series:"

while (( $count < $n ))
do
    echo -n "$a " 
    # print a without going to new line 

    fn=$((a + b))
    # in a new var, store value of sum of a and b
    a=$b
    b=$fn

    count=$((count + 1))
done
