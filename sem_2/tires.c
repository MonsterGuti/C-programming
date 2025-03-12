#include <stdio.h>
#include <math.h>
 
double calculate_tiles(double N, double W, double L, double M, double O) {
    double total_area = N * N;
    double bench_area = M * O;
    double area_to_cover = total_area - bench_area;
    double tile_area = W * L;
    return area_to_cover / tile_area;
}
 
int main() {
    double N, W, L, M, O;
 
    printf("Enter the side length of the square area (N): ");
    scanf("%lf", &N);
 
    printf("Enter the width and length of a tile (W L): ");
    scanf("%lf %lf", &W, &L);
 
    printf("Enter the width and length of the bench (M O): ");
    scanf("%lf %lf", &M, &O);
 
    double tiles_needed = calculate_tiles(N, W, L, M, O);
    double time_needed = tiles_needed * 0.2;
 
    printf("Number of tiles needed: %.2f\n", tiles_needed);
    printf("Time needed: %.2f minutes\n", time_needed);
 
    return 0;
}