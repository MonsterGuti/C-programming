#include <stdio.h>

int main()
{
    int num, mySum;
    do
    {
        scanf("%d", &num);
        mySum += num;

    } while (num != 0);
    printf("%d", mySum);
    return 0;
}