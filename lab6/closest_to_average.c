#include <stdio.h>
#include <math.h>

#define COUNT 7

int main()
{
    int myArr[COUNT];
    int num;
    int mySum = 0;
    double avgValue;

    for (int i = 0; i < COUNT; i++)
    {
        scanf("%d", &num);
        while (num < -5000 || num > 5000)
        {
            printf("Invalid number. Enter a number in the interval [-5000..5000]: ");
            scanf("%d", &num);
        }
        myArr[i] = num;
        mySum += num;
    }

    avgValue = (double)mySum / COUNT;

    int closestIndex = 0;
    double minDiff = fabs(myArr[0] - avgValue);

    for (int i = 1; i < COUNT; i++)
    {
        double currentDiff = fabs(myArr[i] - avgValue);
        if (currentDiff < minDiff)
        {
            minDiff = currentDiff;
            closestIndex = i;
        }
    }

    printf("Average value: %.2lf\n", avgValue);
    printf("Closest number to the average: %d at position %d\n", myArr[closestIndex], closestIndex + 1);

    return 0;
}
