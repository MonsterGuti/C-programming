#include <stdio.h>

int main()
{
    int myArr[7];
    int num;
    int maxNum = -5000;

    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &num);
        while (num < -5000 || num > 5000)
        {
            printf("Invalid num. Enter number in the interval [-5000..5000]: ");
            scanf("%d", &num);
        }
        myArr[i] = num;

        if (num > maxNum)
            maxNum = num;
    }

    printf("The biggest num is %d\n", maxNum);
    return 0;
}
