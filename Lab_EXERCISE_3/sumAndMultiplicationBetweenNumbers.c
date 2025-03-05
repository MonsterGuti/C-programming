#include <stdio.h>

int main()
{
    int a, b;
    int mySum = 0;
    int myMultiplication = 1;
    scanf("%d %d", &a, &b);
    for (int i = a + 1; i < b; ++i)
    {
        if (i % 2 == 0)
            mySum += i;

        else
            myMultiplication *= i;
    }
    printf("The sum of evens is: %d \n The multiplication of odds is: %d", mySum, myMultiplication);
    return 0;
}