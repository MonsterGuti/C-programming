#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int arr[MAX_SIZE];
int size = 0;

void add(int x) {
    arr[size++] = x;
}

void delete(int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }
}

void smallest() {
    if (size == 0) {
        printf("No elements\n");
        return;
    }
    int min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("%d\n", min);
}

int main() {
    int command, x;
    while (1) {
        scanf("%d", &command);
        if (command == 1) {
            scanf("%d", &x);
            add(x);
        } else if (command == 2) {
            scanf("%d", &x);
            delete(x);
        } else if (command == 3) {
            smallest();
        }
    }
    return 0;
}
