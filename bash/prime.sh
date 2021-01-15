#!/bin/bash

max=100

for ((num=3;num<max;num=num+2))
do
    prime=1
    sqr=$(echo "sqrt($num)+1" | bc)

    for ((i=3;i<sqr;i=i+2))
    do    
        rem=$(($num%$i))

    if [[ $rem -lt 1 ]]; then
        prime=0
        break
    fi
    done

    if [[ $prime -gt 0 ]]; then    
        echo $num
    fi

done