#include <stdio.h>

int main()
{
    int arr[20];

    for (int i = 0; i < 20; i++)
        arr[i] = i * 5;

    printf("The values of the array:\n");
    for (int i = 0; i < 20; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
