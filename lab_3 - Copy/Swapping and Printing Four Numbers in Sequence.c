#include <stdio.h>

void printNumbers(int a, int b, int c, int d) {
    printf("Entered numbers: %d %d %d %d\n", a, b, c, d);
}

void swapNumbers(int *a, int *b, int *c, int *d) {
    int temp;
    temp = *a;
    *a = *d;
    *d = temp;
    
    temp = *b;
    *b = *c;
    *c = temp;
}

int main() {
    int a, b, c, d;

    printf("Enter four numbers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printNumbers(a, b, c, d);
    swapNumbers(&a, &b, &c, &d);
    printNumbers(a, b, c, d);

    return 0;
}
