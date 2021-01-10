<?php
$max = 1e6;

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
        echo "{$num}\n";
    }
}
