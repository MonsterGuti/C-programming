#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int my_sum = 0;

    if (a >= b)
    {
        printf("Invalid range. 'a' should be less than 'b'.\n");
    }
    else
    {
        for (int i = a + 1; i < b; ++i)
        {
            my_sum += i;
        }

        printf("Sum of numbers between %d and %d: %d\n", a, b, my_sum);
    }

    return 0;
}
