#include <stdio.h>

void print_numbers(int a, int b, int c, int d) {
    printf("Numbers: %d %d %d %d\n", a, b, c, d);
}

void swap_values(int *a, int *b, int *c, int *d) {
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

    print_numbers(a, b, c, d);

    swap_values(&a, &b, &c, &d);

    printf("After swapping:\n");
    print_numbers(a, b, c, d);

    return 0;
}
