#include <Stdio.h>

float squareArea(float sideA)
{
    return sideA * sideA;
}

float rectangleArea(float sideA, float sideB)
{
    return sideA * sideB;
}

float triangleArea(float sideA, float height)
{
    return sideA * height / 2;
}

float circleArea(float radius)
{
    return 3.14 * radius * radius;
}

int main()
{
    float a, b, h, r, area;

    printf("Choose a geometric figure by code:\n");
    printf("1 - Square\n");
    printf("2 - Rectangle\n");
    printf("3 - Right Triangle\n");
    printf("4 - Circle\n");

    printf("Enter the figure code (1-4): ");
    int choice;
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            printf("Enter the side length of the square: ");
            scanf("%f", &a);
            area = squareArea(a);
            printf("Figure: Square\n");
            break;

        case 2:
            printf("Enter length and width of the rectangle:\n");
            scanf("%f %f", &a, &b);
            area = rectangleArea(a, b);
            printf("Figure: Rectangle\n");
            break;

        case 3:
            printf("Enter base and height of the triangle:\n");
            scanf("%f %f", &a, &h);
            area = triangleArea(a, h);
            printf("Figure: Right Triangle\n");
            break;

        case 4:
            printf("Enter the radius of the circle: ");
            scanf("%f", &r);
            area = circleArea(r);
            printf("Figure: Circle\n");
            break;

        default:
            printf("Invalid figure code!\n");
            return 1;
    }
    printf("Area of the figure: %.2f", area);
    return 0;
}