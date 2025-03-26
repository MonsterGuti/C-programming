#include <stdio.h>

int main() {
    int arr[20];
    int n = 0;
    int maxCount = 1, currentCount = 1;
    int maxValue = 0, currentValue;

    while (1) {
        scanf("%d", &arr[n]);
        if (arr[n] == -1 || n == 20) {
            break;
        }
        n++;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxValue = arr[i - 1];
            }
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxValue = arr[n - 1];
    }

    for (int i = 0; i < maxCount; i++) {
        printf("%d ", maxValue);
    }
    printf("\n");

    return 0;
}
