package main

import (
	"fmt"
	"math"
)

func main() {
	max := 1000000

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

/*
for ($num = 3; $num < $max; $num += 2) {
    $prime = true;
    $sqrt = sqrt($num);
    for ($i = 3; $i <= $sqrt; $i += 2) {
        if ($num % $i == 0) {
            $prime = false;
            break;
        }
    }
    if ($prime) {
        echo $num;
        echo "\n";
    }
}
*/
