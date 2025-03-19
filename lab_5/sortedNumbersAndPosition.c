#include <stdio.h>

int main() {
    int a, b, c, d, e, new_value;
    int *ptr1 = &a, *ptr2 = &b, *ptr3 = &c, *ptr4 = &d, *ptr5 = &e;

    printf("Enter 5 unique numbers in increasing order:\n");

    do {
        printf("Enter first number: ");
        scanf("%d", ptr1);
        printf("Enter second number: ");
        scanf("%d", ptr2);
    } while (*ptr2 <= *ptr1);

    do {
        printf("Enter third number: ");
        scanf("%d", ptr3);
    } while (*ptr3 <= *ptr2);

    do {
        printf("Enter fourth number: ");
        scanf("%d", ptr4);
    } while (*ptr4 <= *ptr3);

    do {
        printf("Enter fifth number: ");
        scanf("%d", ptr5);
    } while (*ptr5 <= *ptr4);

    printf("Enter a new number to insert: ");
    scanf("%d", &new_value);

    printf("\nSorted sequence with new number inserted: ");

    int *arr[5] = {ptr1, ptr2, ptr3, ptr4, ptr5};
    int inserted = 0;

    for (int i = 0; i < 5; i++) {
        if (!inserted && new_value < *arr[i]) {
            printf("%d ", new_value);
            inserted = 1;
        }
        printf("%d ", *arr[i]);
    }
    if (!inserted) {
        printf("%d", new_value);
    }

    printf("\n");
    return 0;
}