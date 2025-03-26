#include <stdio.h>

void find_primes(int n) {
    int limit = n * 10;
    int primes[limit]; 

    for (int i = 0; i < limit; i++)
        primes[i] = 1;

    primes[0] = primes[1] = 0; 

    for (int i = 2; i < limit; i++) {
        if (primes[i]) {
            for (int j = i * 2; j < limit; j += i)
                primes[j] = 0;
        }
    }

    int count = 0;
    for (int i = 2; i < limit && count < n; i++) {
        if (primes[i]) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    printf("First %d prime numbers:\n", n);
    find_primes(n);

    return 0;
}
