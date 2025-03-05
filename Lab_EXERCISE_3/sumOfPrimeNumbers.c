#include <stdio.h>

int main()
{
    int num;
    int primeSum = 0;
    scanf("%d", &num);

    if (num < 2) {
        printf("The sum of prime numbers is 0\n");
        return 0;
    }

    for (int i = 2; i < num; ++i)
    {
        int isPrime = 1;
        
        for (int j = 2; j < i; ++j)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break; 
            }
        }
        
        if (isPrime == 1)
            primeSum += i;
    }

    printf("The sum of prime numbers less than %d is %d\n", num, primeSum);
    return 0;
}
