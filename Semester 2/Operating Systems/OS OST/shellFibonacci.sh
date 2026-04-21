#!/bin/bash

echo "Enter number of terms:"
read n

a=0
b=1
count=0

echo "Fibonacci series:"

while [ $count -lt $n ]
do
    echo -n "$a "

    fn=$((a + b))
    a=$b
    b=$fn

    count=$((count + 1))
done
