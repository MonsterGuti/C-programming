#include <stdio.h>

void find_max_sum_elements(int arr[], int N, int K) {
    int temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    find_max_sum_elements(arr, N, K);
    return 0;
}
