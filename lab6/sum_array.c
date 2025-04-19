#include <stdio.h>

int main()
{
    int myArr[7];
    int num;
    int mySum = 0;

    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &num);
        while (num < -5000 || num > 5000)
        {
            printf("invalid num. Enter number in the interval [-5000..5000]: ");
            scanf("%d", &num);
        }
        myArr[i] = num;
        mySum += num;
    }
    printf("The sum is %d", mySum);
    return 0;
}
