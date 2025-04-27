#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int is_even(int num) {
    return num % 2 == 0;
}

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

    file = fopen("data.bin", "rb");
    if (!file) {
        printf("Error opening file for reading.\n");
        free(arr);
        return 1;
    }

    fread(&N, sizeof(int), 1, file);
    fread(arr, sizeof(int), N, file);
    fclose(file);

    int even_count = 0, odd_count = 0;
    for (int i = 0; i < N; i++) {
        int num = arr[i];
        while (num != 0) {
            int digit = num % 10;
            if (is_even(digit)) {
                even_count++;
            } else {
                odd_count++;
            }
            num /= 10;
        }
    }
    printf("Even digits: %d\n", even_count);
    printf("Odd digits: %d\n", odd_count);

    qsort(arr, N, sizeof(int), compare);

    FILE* txt = fopen("sorted_numbers.txt", "w");
    if (!txt) {
        printf("Error opening text file.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fprintf(txt, "%d\n", arr[i]);
    }
    fclose(txt);

    free(arr);

    printf("Sorted numbers have been written to 'sorted_numbers.txt'.\n");

    return 0;

}