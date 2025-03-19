#include <stdio.h>

int main() {
    int a, b, c, d, e;
    
    printf("Enter 5 numbers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int *p1 = &a, *p2 = &b, *p3 = &c, *p4 = &d, *p5 = &e;
    int *temp;

    if (*p1 > *p2) { temp = p1; p1 = p2; p2 = temp; }
    if (*p2 > *p3) { temp = p2; p2 = p3; p3 = temp; }
    if (*p3 > *p4) { temp = p3; p3 = p4; p4 = temp; }
    if (*p4 > *p5) { temp = p4; p4 = p5; p5 = temp; }

    if (*p1 > *p2) { temp = p1; p1 = p2; p2 = temp; }
    if (*p2 > *p3) { temp = p2; p2 = p3; p3 = temp; }
    if (*p3 > *p4) { temp = p3; p3 = p4; p4 = temp; }

    if (*p1 > *p2) { temp = p1; p1 = p2; p2 = temp; }
    if (*p2 > *p3) { temp = p2; p2 = p3; p3 = temp; }

    if (*p1 > *p2) { temp = p1; p1 = p2; p2 = temp; }

    printf("Numbers in ascending order: %d %d %d %d %d\n", *p1, *p2, *p3, *p4, *p5);

    return 0;
}
