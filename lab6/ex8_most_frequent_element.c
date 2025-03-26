#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int arr[MAX_SIZE];
    int frequency[MAX_SIZE] = {0};
    int n;

    printf("Enter the number of elements (max 10): ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("The number of elements exceeds the limit!\n");
        return 0;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                frequency[i]++;
            }
        }
    }

    int max_frequency = 0;
    int most_frequent_element;

    for (int i = 0; i < n; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
            most_frequent_element = arr[i];
        }
    }

    printf("%d (%d times)\n", most_frequent_element, max_frequency + 1);

    return 0;
}
