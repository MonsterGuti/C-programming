#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates (x1 y1 x2 y2 x3 y3): ");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    double area = 0.5*(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (area < 0)
        area = - area;

    printf("Triangle area: %.2f\n", area);
    return 0;
}