#include <stdio.h>

int main()
{
    int arr[0] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int i, flag = 0;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            flag = 1;
            printf("The number %d is found on index %d \n", key, i);
            break;
        }
    }
    if (!flag)
    {
        printf("The number %d is not found \n", key);
    }
    return 0;
}