#include <stdio.h>

int main() 
{
    printf("Enter width\n");
    double w;
    scanf_s("%lf", &w);

    printf("Enter enter height\n");
    double h;
    scanf_s("%lf", &h);

    w = w - 1;

    int possibleWidthwise = w / 1.2;

    int possivleHeightwise = h / 0.7;

    int possibleAll = (possibleWidthwise * possivleHeightwise) - 3;

    printf("Possible workstations: %d", possibleAll);
}