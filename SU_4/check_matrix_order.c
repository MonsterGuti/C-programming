#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int **matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int valid = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (matrix[i][j] > matrix[i][j + 1]) {
                valid = 0;
                break;
            }
        }
    }

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 1; i++) {
            if (matrix[i][j] < matrix[i + 1][j]) {
                valid = 0;
                break;
            }
        }
    }

    if (valid) {
        printf("Each row is increasing and each column is decreasing.\n");
    } else {
        printf("Condition is not satisfied.\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
