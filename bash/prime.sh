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


# for num in range (3, max, 2) :
#     prime = 1
#     sqrt = int(math.sqrt(num))
#     for i in xrange(3, sqrt + 1, 2):
#         if num%i == 0:
#             prime =0
#             break

#     if prime == 1:
#         print(num)