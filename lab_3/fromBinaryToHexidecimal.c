#include <stdio.h>

unsigned long long binaryToDecimal(unsigned long long binary) {
    unsigned long long decimal = 0, base = 1, remainder;
    
    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}

int main() {
    unsigned long long binary;

    scanf("%llu", &binary);

    unsigned long long decimal = binaryToDecimal(binary);
    
    printf("Hexadecimal: %llX\n", decimal);

    return 0;
}
