#include <stdio.h>

int main() {
    int size;
    printf("Enter_Num: ");
    scanf("%d",&size);

    for (int i = 0; i < 2 * size - 1; i++) {
        for (int j = 0; j < 2 * size - 1; j++) {
            int min = i;
            if (j < min) min = j;
            if (2 * size - 2 - i < min) min = 2 * size - 2 - i;
            if (2 * size - 2 - j < min) min = 2 * size - 2 - j;
            printf("%d", size - min);
        }
        printf("\n");
    }

    return 0;
}
