#include <stdio.h>

int main() {
    int num;
    int firstDigit, lastDigit;

    scanf("%d", &num);

    lastDigit = num % 10;

    while (num >= 10) {
        num /= 10;
    }
    firstDigit = num;

    printf("Sum of the first and last digits is: %d\n", firstDigit + lastDigit);

    return 0;
}
