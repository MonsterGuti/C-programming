#include <stdio.h>

double calculateTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    double area = 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (area < 0)
        area = -area;
    return area;
}

int main() {
    int x1, y1, x2, y2, x3, y3;

    printf("Enter coordinates (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    double area = calculateTriangleArea(x1, y1, x2, y2, x3, y3);

    printf("Triangle area: %.2f\n", area);
    return 0;
}

