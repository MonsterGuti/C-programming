#include <stdio.h>

int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1, remainder;

    while (binary > 0)
    {
        remainder = binary % 10;
        decimal += remainder * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}

int decimalToBinary(int decimal)
{
    int binary = 0, remainder, base = 1;

    while (decimal > 0)
    {
        remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }

    return binary;
}

int main()
{
    int choice;
    int decimal, binary;
    
    printf("1-decimal, 2-binary");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        printf("Binary: %d\n", decimalToBinary(decimal));
    }
    else if (choice == 2)
    {
        printf("Enter a binary number: ");
        scanf("%d", &binary);
        printf("Decimal: %d\n", binaryToDecimal(binary));
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}
