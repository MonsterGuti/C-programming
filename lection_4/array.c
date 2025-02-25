#include <stdio.h>

int main ()
{
    printf("Enter 5 numbers: \n");
    int numbers[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("numbers[%d] = %d \n", i, numbers[i]);

    }
    return 0;
}