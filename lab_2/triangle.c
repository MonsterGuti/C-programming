#include <stdio.h>
#define CONST 55
int main()
{
    for (int i = 0; i < CONST; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf("*");    
        }
        printf("\n");
    }
    return 0;

}