#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int mySum = 0;
    int myMult = 1;

    if (x > y)
    {
        for (int i = y + 1; i < x; i++)
        {
            if (i % 2 == 0)
                mySum += i;
            else
                myMult *= i;
        }
    }
    else if (x < y)
    {
        for (int i = x + 1; i < y; i++)
        {
            if (i % 2 == 0)
                mySum += i;
            else
                myMult *= i;
        }
    }
    printf("%d", mySum);
    printf("\n");
    printf("%d", myMult);
    return 0;
}