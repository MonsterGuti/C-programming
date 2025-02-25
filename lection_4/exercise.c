#include <stdio.h>

int main()
{
    int myArr[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &myArr[i]);
    }

    int mySum = 0;
    int evenCount = 0;
    int minNum = myArr[0];
    for (int j = 0; j < 10; j++)
    {
        if (myArr[j] >= 10 && myArr[j] <= 50)
            mySum += myArr[j];

        if (myArr[j] % 2 == 0)
            evenCount++;

        if (myArr[j] < minNum)
            minNum = myArr[j];

        if (j % 2 != 0)
            printf("%d\n", myArr[j]);
    }
    printf("The sum: %d\n", mySum);
    printf("min num: %d \n", minNum);
    printf("Even count: %d\n", evenCount);
    return 0;
}