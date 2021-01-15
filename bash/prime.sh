#!/bin/bash

max=1000000

for ((num=3;num<max;num=num+2))
do
echo $num
    prime=1
    sqr=$(echo "sqrt($num)" | bc)

    for ((i=3;i<sqr;i=i+2))
    do
        rem=$(($num%$i))
        if [ rem = 0 ]
        then
            prime=0
            break
        fi
    done

    if [ prime = 1 ]
    then
        echo $num
    fi

done