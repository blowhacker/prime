#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const int max = 10000000;
    char *is_prime = malloc((max + 1) * sizeof(char));

    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize all entries as true (1)
    for (int i = 0; i <= max; i++) {
        is_prime[i] = 1;
    }

    is_prime[0] = is_prime[1] = 0;

    int limit = (int)sqrt(max);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= max; i++) {
        if (is_prime[i]) {
            printf("%d\n", i);
        }
    }

    free(is_prime);
    return 0;
}
