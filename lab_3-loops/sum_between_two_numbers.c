#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int mySum = 0;

    if (x > y)
    {
        for (int i = y + 1; i < x; i++)
        {
            mySum += i;
        }
    }
    else if (x < y)
    {
        for (int i = x + 1; i < y; i++)
        {
            mySum += i;
        }
    }
    printf("%d", mySum);
    return 0;
}