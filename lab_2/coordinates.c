#include <stdio.h>

int main()
{
    int a, b, c, d;
    printf("Enter coordinates: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int sideA = a - c;
    if (sideA < 0)
    {
        sideA = -sideA;
    }

    int sideB = c - d;
    if (sideB <0)
    {
        sideB = -sideB;
    }

    int result = sideA * sideB;
    printf("The area is %d", result);
    return 0;
}