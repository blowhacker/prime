import math

max = 1000000

for num in range (3, max, 2) :
    prime = 1
    sqrt = int(math.sqrt(num))
    for i in range(3, sqrt, 2):
        if num%i == 0:
            prime =0
            break

    if prime == 1:
        print(num)