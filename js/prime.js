const max = 1e6;

for (let num = 3; num < max; num += 2) {
    prime = true;
    sqrt = Math.sqrt(num);
    for (let i = 3; i <= sqrt; i += 2) {
        if (num % i == 0) {
            prime = false;
            break;
        }
    }
    if (prime) {
        console.log(num);
    }
}