#include <stdio.h>

void by_value(int a, int b) {
    printf("Before modification (By Value), sum: %d\n", a + b);
    a = a * 5;
    b = b - 10;
    printf("After modification (By Value), sum: %d\n", a + b);
}

void by_reference(int *a, int *b) {
    printf("Before modification (By Reference), sum: %d\n", *a + *b);
    *a = *a * 5;
    *b = *b - 10;
    printf("After modification (By Reference), sum: %d\n", *a + *b);
}

int main() {
    int num1 = 5, num2 = 15;
    printf("by value:\n");
    by_value(num1, num2);
    printf("\nFinal sum after byValue function: %d\n", num1 + num2);
    printf("\nby reference:\n");
    by_reference(&num1, &num2);
    printf("\nFinal sum after reference function: %d\n", num1 + num2);
    return 0;
}
