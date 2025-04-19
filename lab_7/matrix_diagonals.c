#include <stdio.h>

#define N 4

int main()
{
    int matrix[N][N];
    printf("Enter the elements of a %dx%d matrix:\n", N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMain diagonal: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", matrix[i][i]);
    }

    printf("\nSecondary diagonal: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", matrix[i][N - 1 - i]);
    }

    printf("\nElements above the main diagonal: ");
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
            printf("%d ", matrix[i][j]);
    }

    printf("\nElements below the main diagonal: ");
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            printf("%d ", matrix[i][j]);
    }
    printf("\n");

    return 0;
}