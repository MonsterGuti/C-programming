#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int N;
    printf("Въведи броя на числата (N): ");
    scanf("%d", &N);
 
    int* arr = (int*)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Грешка при заделяне на памет.\n");
        return 1;
    }
 
    printf("Въведи %d цели числа:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
 
    FILE* file = fopen("data.bin", "wb");
    if (!file) {
        printf("Грешка при отваряне на файл.\n");
        free(arr);
        return 1;
    }
 
    fwrite(&N, sizeof(int), 1, file);
    fwrite(arr, sizeof(int), N, file);
    fclose(file);
    free(arr);
 
    printf("Файлът е създаден успешно.\n");
    return 0;
}