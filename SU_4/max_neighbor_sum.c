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

    int max_sum = -1000000;
    int result = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int ni = i + dx;
                    int nj = j + dy;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (!(dx == 0 && dy == 0)) {
                            sum += matrix[ni][nj];
                        }
                    }
                }
            }

            if (sum > max_sum) {
                max_sum = sum;
                result = matrix[i][j];
            }
        }
    }

    printf("Element with max neighbor sum: %d\n", result);
    printf("Max neighbor sum: %d\n", max_sum);

    return 0;
}
