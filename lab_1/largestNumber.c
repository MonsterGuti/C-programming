#include <stdio.h>

int main() {
    unsigned a, b, c;

    printf("Enter three numbers: ");
    scanf("%u %u %u", &a, &b, &c);

    if (a >= b && a >= c) {
        printf("The largest num is %u\n", a);
    }
    else if (b >= a && b >= c) {
        printf("The largest num is %u\n", b);
    }
    else if (c >= a && c >= b) {
        printf("The largest num is %u\n", c);
    }
    return 0;
}
