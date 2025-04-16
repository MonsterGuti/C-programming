#include <stdio.h>
#include <math.h>

struct points
{
    int x, y;
};

struct triangles
{
    struct points A, B, C;
};

double sideLength(struct points p1, struct points p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
{
    struct triangles ABC;
    ABC.A.x = 3;
    ABC.A.y = 4;
    ABC.B.x = 6;
    ABC.B.y = 7;
    ABC.C.x = 5;
    ABC.C.y = -8;

    int AB = sideLength(ABC.A, ABC.B);
    int AC = sideLength(ABC.A, ABC.C);
    int BC = sideLength(ABC.B, ABC.C);

    printf("Len of AB: %d\n", AB);
    printf("Len of AC: %d\n", AC);
    printf("Len of BC: %d\n", BC);

    return 0;   
}
