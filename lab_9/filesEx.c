#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the number of integers (N): ");
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    FILE* file = fopen("data.bin", "wb");
    if (!file) {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    fwrite(&N, sizeof(int), 1, file);
    fwrite(arr, sizeof(int), N, file);
    fclose(file);
    free(arr);

    printf("File has been successfully created.\n");
    return 0;
}
