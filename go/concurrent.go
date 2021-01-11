package main

import (
	"fmt"
	"math"
	"runtime"
	"sync"
)

func main() {

	max := int(1e6)

	threads := runtime.NumCPU()

	var wg sync.WaitGroup
	for i := 0; i < threads; i++ {
		wg.Add(1)
		go func(i int) {
			// fmt.Println(i, i*max/threads, (i+1)*max/threads)
			primeFinder(i*max/threads, (i+1)*max/threads)
			wg.Done()
		}(i)
	}
	wg.Wait()
	// go primeFinder(1, 100)
	// go primeFinder(100, 200)
	// go primeFinder(200, 300)
	// go primeFinder(300, 400)

	return

	for num := 3; num < max; num += 2 {
		prime := true
		sqrt := int(math.Sqrt(float64(num)))

		for i := 3; i <= sqrt; i += 2 {
			if num%i == 0 {
				prime = false
				break
			}
		}

		if prime {
			fmt.Println(num)
		}

	}

}

func primeFinder(start int, end int) {
	if start%2 == 0 {
		start++
	}

	for num := start; num < end; num += 2 {
		prime := true
		sqrt := int(math.Sqrt(float64(num)))

		for i := 3; i <= sqrt; i += 2 {
			if num%i == 0 {
				prime = false
				break
			}
		}

		if prime {
			fmt.Println(num)
		}

	}
}
