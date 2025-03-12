#include <stdio.h>

int calculate_workstations(double w, double h) {
    w -= 1.0;

    if (w <= 0 || h <= 0) {
        return 0;
    }

    int possibleWidthwise = (int)(w / 1.2);
    int possibleHeightwise = (int)(h / 0.7);

    int totalWorkstations = (possibleWidthwise * possibleHeightwise) - 3;

    return totalWorkstations > 0 ? totalWorkstations : 0;
}

int main() {
    double w, h;

    printf("Enter width (m): ");
    scanf("%lf", &w);

    printf("Enter height (m): ");
    scanf("%lf", &h);

    if (w < 1.2 || h < 0.7) {
        printf("Room dimensions are too small for any workstations.\n");
        return 0;
    }

    int possibleAll = calculate_workstations(w, h);

    printf("Possible workstations: %d\n", possibleAll);

    return 0;
}
