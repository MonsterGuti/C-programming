#include <stdio.h>

int digitMultiplication(int num)
{
    int countOfDigits = 1;
    while (num != 0)
    {
        countOfDigits *= num % 10;
        num /= 10;
    }

    return countOfDigits;
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("The multiplication of the digits of %d is %d", num, digitMultiplication(num));
    return 0;
}

