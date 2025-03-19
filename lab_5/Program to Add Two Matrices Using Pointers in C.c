#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3

void input_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", (matrix + i * cols + j));
        }
    }
}

void sum_matrices(int *matrix1, int *matrix2, int *result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(matrix1 + i * cols + j) + *(matrix2 + i * cols + j);
        }
    }
}

void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    printf("Enter elements for Matrix 1:\n");
    input_matrix((int *)matrix1, MAX_ROWS, MAX_COLS);

    printf("Enter elements for Matrix 2:\n");
    input_matrix((int *)matrix2, MAX_ROWS, MAX_COLS);

    sum_matrices((int *)matrix1, (int *)matrix2, (int *)result, MAX_ROWS, MAX_COLS);

    printf("\nSum of the two matrices is:\n");
    print_matrix((int *)result, MAX_ROWS, MAX_COLS);

    return 0;
}
