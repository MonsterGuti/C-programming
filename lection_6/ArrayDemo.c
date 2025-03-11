#include <stdio.h>
#include <stdbool.h>
int findMin(int a[], unsigned size, int start)
{
    int index = start;
    for (int i = index + 1; i < size; ++i)
    {
        if (a[index] > a[i])
        {
            index = i;
        }
    }
    return index;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], unsigned size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[], unsigned size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = findMin(a, size, i);
        swap(&a[minIndex], &a[i]);
        printArray(a, size);
    }
}

void bubbleSort(int a[], unsigned size)
{
    bool isChanged;
    for (int i = 0; i < size - 1; ++i)
    {
        isChanged = false;
        for (int j = 0; j < size - 1 - i; ++j)  // Поправен вътрешен цикъл
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                isChanged = true;
            }
        }
        if (!isChanged) // Ако няма размяна, масивът е сортиран
            break;
    }
}

int main()
{
    int a[] = {8, 0, 1, 6, 7, 2, 5, 4, 3, 9, 8};
    const unsigned SIZE = sizeof(a) / sizeof(int);

    printf("Original array:\n");
    printArray(a, SIZE);

    printf("\nSelection Sort:\n");
    selectionSort(a, SIZE);

    printf("\nBubble Sort:\n");
    bubbleSort(a, SIZE);
    printArray(a, SIZE);

    return 0;
}
