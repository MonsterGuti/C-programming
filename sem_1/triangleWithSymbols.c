#include <stdio.h>

int main()
{
    char symbol;
    int rows;

    printf("Enter a symbol: ");
    scanf(" %c", &symbol);

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < ((rows * 2) - 1); j++)
        {
            if (j == rows - 1 - i || j == rows - 1 + i || i == rows - 1)
            {
                printf("%c", symbol);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
