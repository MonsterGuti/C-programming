#include <stdio.h>

int main()
{
    int num;
    int mySum = 0;

    do
    {
        scanf("%d", &num);
        mySum += num;
    }
    while(num != 0);

    printf("%d", mySum);
    return 0;
}