#include <stdio.h>

int perimeterOfSquare(int a)
{
    return a * 4;
}

int areaOfSquare(int a)
{
    return a * a;
}

float areaOfTriangle(int a, int height)
{
    return (a * height) / 2.0;
}

int perimeterOfTriangle(int a, int b, int c)
{
    return a + b + c;
}

float perimeterOfCircle(int r)
{
    return 2 * 3.14 * r;
}

float areaOfCircle(int r)
{
    return 3.14 * r * r;
}

int main()
{
    int choice;

    while (1) 
    {
        printf("Please, select the function:\n");
        printf("1 Square\n");
        printf("2 Triangle\n");
        printf("3 Circle\n");
        printf("0 Quit\n");

        scanf("%d", &choice);

        if (choice == 0)
        {
            break;  // Exit the loop and quit the program
        }

        if (choice == 1)
        {
            int a;
            printf("Enter the side of the square: ");
            scanf("%d", &a);
            printf("The area of the square is %d\n", areaOfSquare(a));
            printf("The perimeter of the square is %d\n", perimeterOfSquare(a));
        }
        else if (choice == 2)
        {
            int a, b, c, h;
            printf("Enter the three sides of the triangle (a, b, c): ");
            scanf("%d %d %d", &a, &b, &c);
            printf("Enter the height of the triangle: ");
            scanf("%d", &h);
            printf("The area of the triangle is %.2f\n", areaOfTriangle(a, h));
            printf("The perimeter of the triangle is %d\n", perimeterOfTriangle(a, b, c));
        }
        else if (choice == 3)
        {
            int r;
            printf("Enter the radius of the circle: ");
            scanf("%d", &r);
            printf("The area of the circle is %.2f\n", areaOfCircle(r));
            printf("The perimeter (circumference) of the circle is %.2f\n", perimeterOfCircle(r));
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
