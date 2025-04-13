#include <stdio.h>

int main()
{
    double m, n;
    scanf("%lf %lf", &m, &n);
    double currentValue;

    for (double  i = m; i <= n; i += 0.01)
    {
        currentValue = i * (i + 4);
        printf("%.2f", currentValue);
        printf("\n");
    }
    
    return 0;
}