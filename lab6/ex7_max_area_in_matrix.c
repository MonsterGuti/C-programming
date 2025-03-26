#include <stdio.h>

#define MAX_SIZE 100

int find_max_area(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int max_area = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current_value = matrix[i][j];
            int area = 0;
            
            for (int k = j; k < cols && matrix[i][k] == current_value; k++) {
                area++;
            }
            max_area = (area > max_area) ? area : max_area;
        }
    }

    return max_area;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int max_area = find_max_area(matrix, rows, cols);
    printf("%d\n", max_area);

    return 0;
}
