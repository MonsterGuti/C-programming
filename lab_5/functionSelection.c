#include <stdio.h>
#include <math.h>

int Add(int a, int b) {
    return a + b;
}

int Subtract(int a, int b) {
    return a - b;
}

int Power(int a, int b) {
    return pow(a, b); // This will return a float, but we are returning an int.
}

int main() {
    int choice, num1, num2;
    int (*operation)(int, int); // Declare function pointer

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Power\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        printf("Enter two integers: ");
        scanf("%d %d", &num1, &num2);

        if (choice == 1) {
            operation = Add; // Point the function pointer to Add
            printf("Result: %d\n", operation(num1, num2));
        } else if (choice == 2) {
            operation = Subtract; // Point the function pointer to Subtract
            printf("Result: %d\n", operation(num1, num2));
        } else if (choice == 3) {
            printf("Result: %.0f\n", Power(num1, num2)); // Power returns float, hence %.0f format specifier
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
