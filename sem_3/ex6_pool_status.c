#include <stdio.h>

int main() {
    double V, debit1, debit2, N, water_in_pool;

    printf("Enter volume of pool (in liters): ");
    scanf("%lf", &V);
    
    printf("Enter debit of the first pipe (liters per hour): ");
    scanf("%lf", &debit1);
    
    printf("Enter debit of the second pipe (liters per hour): ");
    scanf("%lf", &debit2);
    
    printf("Enter number of hours the worker is away: ");
    scanf("%lf", &N);

    water_in_pool = (debit1 + debit2) * N;

    if (water_in_pool < V) {
        printf("The pool will be %lf liters full after %.2lf hours.\n", water_in_pool, N);
    } else if (water_in_pool == V) {
        printf("The pool will be exactly full after %.2lf hours.\n", N);
    } else {
        printf("The pool will overflow by %lf liters after %.2lf hours.\n", water_in_pool - V, N);
    }

    return 0;
}
