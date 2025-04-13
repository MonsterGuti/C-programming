#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int num;
    int myCount = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        if (num > k && num % 3 == 0)
            myCount += 1;
    }
    printf("%d", myCount);
    return 0;
}