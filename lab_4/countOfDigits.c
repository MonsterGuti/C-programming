#include <stdio.h>

int countOfDigits(int num)
{
    int count = 0;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int main()
{
    int num;
    scanf("%d", &num);
    printf("The number of digits of %d is: %d\n", num, countOfDigits(num));
    
    return 0;
}
