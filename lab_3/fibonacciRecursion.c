#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int primeNumbersSum(int a) {
    int sumPrime = 0;
    for (int i = 2; i < a; i++) {
        if (isPrime(i)) {
            sumPrime += i;
        }
    }
    return sumPrime;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("The sum of prime numbers up to %d is %d\n", a, primeNumbersSum(a));
    return 0;
}
