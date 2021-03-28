**How To And Results**

**/bash**
The bash version of this script only calculates primes up to 100
*requires bc* https://www.gnu.org/software/bc/manual/html_mono/bc.html

    cd bash
    time ./prime.sh

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.487s
user	0m0.064s
sys	0m0.168s


**/c**
Implementations:
prime.c
prime-newton.c (compute square roots using Newton's method)

Compile

     clang prime.c -o prime
     clang prime-newton.c -o prime-newton

Execute

    time ./prime
  
**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.234s
user	0m0.143s
sys	0m0.050s
    
Some time is wasted just displaying primes to the std out. Let's try again by redirecting output to /dev/null

    time ./prime > /dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.126s
user	0m0.115s
sys	0m0.003s

Much better!

Let's see if it is faster using Newton's method.

    time ./prime-newton >/dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.252s
user	0m0.240s
sys	0m0.004s

This is slower. This indicates that the math coprocessor on the machine is fast. On earlier machines the reverse would be true.


**/go**

Let's try without compiling

    cd go
    time go run prime.go > /dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.733s
user	0m0.519s
sys	0m0.292s

Let's compile and time

    go build prime.go
    time ./prime > /dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.359s
user	0m0.317s
sys	0m0.034s
 
Much more impressive! But of course, nothing beats c for raw performance :-)

Let's try running this concurrently using go channels

    time go run concurrent.go >/dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.615s
user	0m0.747s
sys	0m0.452s

Compiled version

    go build concurrent.go
    time ./concurrent >/dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz**
real	0m0.223s
user	0m0.531s
sys	0m0.178s


**/java**

    cd java
    time java prime.java >/dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz (java version 15.0.1 2020-10-20)**

real	0m0.653s
user	0m1.092s
sys	0m0.102s


**/js**
(Node.js)

    cd js
    time node prime.js >/dev/null
    
**Results on MacBook pro Intel Core i5 @ 2.4GHz (Node.js 15.5.1)**
real	0m0.463s
user	0m0.434s
sys	0m0.054s


**/php**

    cd php
    time php prime.php > /dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz (PHP 7.3.11)**
real	0m0.923s
user	0m0.862s
sys	0m0.050s

**/python**

    cd python
    time python prime.py >/dev/null

**Results on MacBook pro Intel Core i5 @ 2.4GHz (Python 3.7.6)**
real	0m3.660s
user	0m3.324s
sys	0m0.137s


**/rust**

    cd rust
    rustc prime.rs
    time ./prime >/dev/null
    
**Results on MacBook pro Intel Core i5 @ 2.4GHz (Rustc 1.37.0)**
real	0m0.921s
user	0m0.877s
sys	0m0.033s
