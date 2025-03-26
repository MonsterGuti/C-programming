#include <stdio.h>

int main() {
    double x1, y1, x2, y2, x, y;

    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x, &y);

    if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
        printf("Inside\n");
    } else {
        printf("Outside\n");
    }

    return 0;
}
