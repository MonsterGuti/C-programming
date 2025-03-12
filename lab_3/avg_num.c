#include <stdio.h>

float getAverage(int sum, int count) {
    return (float)sum / count;
}

int minNum(int num, int min) {
    if (num < min) {
        return num;
    }
    return min;
}

int maxNum(int num, int max) {
    if (num > max) {
        return num;
    }
    return max;
}

int main() {
    int num, count = 0, sum = 0, min, max;

    if (scanf("%d", &num) && num != 0) {
        min = max = num;
        sum += num;
        count++;
    } 
    
    while (scanf("%d", &num) && num != 0) {
        sum += num;
        count++;
        min = minNum(num, min);
        max = maxNum(num, max);
    }

    printf("Sum: %d\n", sum);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Average: %f\n", getAverage(sum, count));

    return 0;
}
