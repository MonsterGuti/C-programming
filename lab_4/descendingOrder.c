#include <stdio.h>

int get_valid_five(int prev) {
    int num;
    do {
        printf("Enter a number greater than %d: ", prev);
        scanf("%d", &num);
    } while (num <= prev);
    return num;
}

int main() {
    int a, b, c, d, e;

    printf("Enter first number: ");
    scanf("%d", &a);
    b = get_valid_five(a);
    c = get_valid_five(b);
    d = get_valid_five(c);
    e = get_valid_five(d);

    printf("%d %d %d %d %d\n", e, d, c, b, a);

    return 0;
}
