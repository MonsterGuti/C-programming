#include <stdio.h>

int inputCel()
{
    int cel;
    printf("Cel: ");
    scanf("%d", &cel);
    return cel;
}

void output(int cel, float far)
{
    printf("%d\t\t%g\n", cel, far);
}

int input(char prompt[])
{
    int result;
    printf(prompt);
    scanf("%d", &result);
    return result;
}

int main()
{
    int start, end, step;
    float far;
    int cel;
    start = input("START= ");
    end = input("END= ");
    do
    {
        step = input("STEP= ");
    } while (step <= 0);
    printf("Cel\t\tFAR\n");
    for (cel = start; cel <= end; cel += step)
    {
        output(cel, cel * 9. / 5 + 32);
    }
    return 0;
}