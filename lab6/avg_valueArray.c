#include <stdio.h>

#define COUNT 7

int main()
{
    int myArr[COUNT];
    int num;
    int mySum = 0;

    for (int i = 0; i < COUNT; i++)
    {
        scanf("%d", &num);

        while (num < -5000 || num > 5000)
        {
            printf("Invalid num. Enter number in the interval [-5000..5000]: ");
            scanf("%d", &num);
        }

        myArr[i] = num;
        mySum += num;
    }

    double avgValue = (double)mySum / COUNT;
    printf("The avrage value of this array is %.2lf", avgValue);
    return 0;
}
