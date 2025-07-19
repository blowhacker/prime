import cupy as cp
import math
import time

"""
better algo, for sure
but does 10 billion in 2.9 seconds on a 3060 12GB

tested on:
Python 3.10.12
cupy-cuda11x==13.5.1
"""


def sieve_cupy_odd_only(max_n):
    # Only odd numbers ≥ 3: index i => number 2*i + 3
    size = (max_n - 1) // 2
    is_prime = cp.ones(size, dtype=cp.bool_)

    limit = int(math.sqrt(max_n))
    for i in range((limit - 3) // 2 + 1):
        if is_prime[i]:
            p = 2 * i + 3
            start = (p * p - 3) // 2
            is_prime[start::p] = False

    # Convert index back to actual prime values
    odd_primes = 2 * cp.nonzero(is_prime)[0] + 3
    return cp.concatenate((cp.array([2]), odd_primes))


if __name__ == "__main__":
    n = 10_000_000_000

    start = time.time()
    primes = sieve_cupy_odd_only(n)
    cp.cuda.Device(0).synchronize()
    end = time.time()

    print(f"Found {len(primes):,} primes up to {n:,} in {end - start:.3f} seconds")

    # fl = f"/tmp/cupysieve_odd_primes_{n}.txt"
    # print(f"Writing primes to {fl}")
    # with open(fl, "w") as f:
    #     f.write("\n".join(map(str, primes.get())) + "\n")
