#include <stdio.h>

int main() {
    char binary[33];
    int decimal = 0, i = 0;

    printf("Enter a binary number (max 32 bits): ");
    scanf("%32s", binary);

    while (binary[i] != '\0') {
        if (binary[i] == '1') {
            decimal = decimal * 2 + 1;
        } else if (binary[i] == '0') {
            decimal = decimal * 2;
        } else {
            printf("Error: Invalid character entered!\n");
            return 1;
        }
        i++;
    }

    printf("The decimal number is: %d\n", decimal);
    return 0;
}
