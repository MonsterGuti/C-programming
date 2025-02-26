#include <stdio.h>

int main()
{
    char symbol;
    printf("Enter a symbol for the frame: ");
    scanf("%c", &symbol);

    for (int row = 1; row <= 5; row++)
    {
        if (row == 1 || row == 5) {
            for (int col = 1; col <= 10; col++) {
                printf("%c", symbol);
            }
            printf("\n");
        }
        else {
            printf("%c", symbol);
            for (int col = 1; col <= 8; col++) {
                printf(" ");
            }
            printf("%c\n", symbol);
        }
    }

    return 0;
}
