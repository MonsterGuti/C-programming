#include <stdio.h>

const char EXISTING_VALUE[] = "This Value Already Exist";
const char UNIQUE_VALUE[] = "This Value is unique for now";

const char* check_value(int *ptr1, int *ptr2, int *ptr3, int *ptr4, int *ptr5, int new_val) {
    if (*ptr1 == new_val || *ptr2 == new_val || *ptr3 == new_val || *ptr4 == new_val || *ptr5 == new_val) {
        return EXISTING_VALUE;
    }
    return UNIQUE_VALUE;
}

int main() {
    int a, b, c, d, e, new_value;

    printf("Enter five numbers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    printf("Enter a new number: ");
    scanf("%d", &new_value);

    printf("%s\n", check_value(&a, &b, &c, &d, &e, new_value));

    return 0;
}
