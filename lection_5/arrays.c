#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void inputArray(int data[], unsigned len) {
    for (int i = 0; i < len; i++) {
        printf("A(%d)=", i + 1);
        scanf("%d", &data[i]);
    }
}

void inputRandomArray(int data[], unsigned len, bool isCustomSeed) {
    const int MIN = -10, MAX = 10;
    if (isCustomSeed)
        srand(time(NULL));

    for (int i = 0; i < len; ++i) {
        data[i] = rand() % (MAX - MIN + 1) + MIN;
    }
}

void outputArray(int *data, unsigned len) {
    for (int i = 0; i < len; ++i) {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

long sumArray(int data[], unsigned len) {
    long sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += data[i];
    }
    return sum;
}

double averageNegatives(int data[], unsigned len) {
    long sum = 0;
    unsigned count = 0;

    for (int i = 0; i < len; ++i) {
        if (data[i] < 0) {
            count++;
            sum += data[i];
        }
    }
    return (count > 0) ? (double)sum / count : 0;
}

int minEvenElement(int data[], unsigned len) {
    int index = -1;
    for (int i = 0; i < len; ++i) {
        if (data[i] % 2 == 0) {
            if (index == -1 || data[index] > data[i]) {
                index = i;
            }
        }
    }
    return index;
}

int maxArray(int data[], unsigned len) {
    int max = data[0];
    for (int i = 1; i < len; ++i) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

unsigned countElement(int data[], unsigned len, int element) {
    unsigned count = 0;
    for (int i = 0; i < len; ++i) {
        if (data[i] == element) {
            count++;
        }
    }
    return count;
}

void moveArray(int data[], unsigned len) {
    for (int i = 0; i < len; ++i) {
        data[i + len] = data[i];
    }
}

void extendArray(int data[], unsigned len) {
    moveArray(data, len);
    outputArray(data, 2 * len);
}

// **Function to insert negative after each positive number**
void insertNegativeAfterPositive(int data[], unsigned *len) {
    int newArray[*len * 2]; // Create a new array with a larger capacity
    int newIndex = 0;

    for (unsigned i = 0; i < *len; i++) {
        newArray[newIndex++] = data[i];  // Copy original value
        if (data[i] > 0) {
            newArray[newIndex++] = -data[i];  // Insert negative value if positive
        }
    }

    // Copy back modified values to original array
    for (unsigned i = 0; i < newIndex; i++) {
        data[i] = newArray[i];
    }

    *len = newIndex; // Update length of the array
}

int main() {
    const unsigned SIZE = 10;
    int array[SIZE * 2]; // Array with extra space for modifications
    double result;
    int index, max;

    // Generate a random array
    inputRandomArray(array, SIZE, true);
    printf("Original Array:\n");
    outputArray(array, SIZE);

    // Compute sum
    printf("Sum is: %ld\n", sumArray(array, SIZE));

    // Average of negative numbers
    result = averageNegatives(array, SIZE);
    if (result == 0) {
        printf("No such data\n");
    } else {
        printf("Average of negatives: %g\n", result);
    }

    // Find min even element
    index = minEvenElement(array, SIZE);
    if (index == -1) {
        printf("No such data...\n");
    } else {
        printf("Min even element's index: %d\n", index);
    }

    // Find max element and its count
    max = maxArray(array, SIZE);
    printf("The max is %d. It's repeated %u times.\n", max, countElement(array, SIZE, max));

    // Insert negative numbers after positive ones
    unsigned newSize = SIZE;
    insertNegativeAfterPositive(array, &newSize);
    printf("Modified Array (Negative inserted after Positive):\n");
    outputArray(array, newSize);

    return 0;
}
