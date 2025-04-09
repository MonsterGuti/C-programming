#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int max = matrix[0][0], min = matrix[0][0];
    int max_row = 0, min_row = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_row = i;
            }
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                min_row = i;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int temp = matrix[max_row][j];
        matrix[max_row][j] = matrix[min_row][j];
        matrix[min_row][j] = temp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
