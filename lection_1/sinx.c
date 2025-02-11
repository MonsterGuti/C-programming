#include <stdio.h>
#include <math.h>

#define END 100
#define PI 3.14159265358979323846

int main()
{
    int xdeg;
    float xrad;
    double sin_approx, term;
    unsigned cnt = 3;

    printf("x= ");
    scanf("%d", &xdeg);

    xrad = xdeg * PI / 180;

    sin_approx = term = xrad;

    for (unsigned i = 1; i < END; ++i, cnt += 2)
    {
        term *= -1 * xrad * xrad / (cnt * (cnt - 1));
        sin_approx += term;
    }

    printf("sin(%d) ≈ %g (Taylor Series)\n", xdeg, sin_approx);
    printf("From math.h: sin(%d) = %g\n", xdeg, sin(xrad));

    return 0;
}
