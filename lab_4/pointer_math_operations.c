#include <stdio.h>

void Add(int *a, int *b)
{
    printf("The sum is %d\n", *a + *b);
}

void Substract(int *a, int *b)
{
    if (*a > *b)
        printf("The substract is %d\n", *a - *b);
    else
        printf("The substract is %d\n", *b - *a);
}

void Multiply(int *a, int *b)
{
    printf("The multiplication is %d\n", *a * *b);
}

void Divide(int *a, int *b)
{
    if (b != 0)
        printf("The division is %d\n", *a / *b);
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    Add(&a, &b);
    Substract(&a, &b);
    Multiply(&a, &b);
    Divide(&a, &b);

    return 0;
}