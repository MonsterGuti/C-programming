#include <stdio.h>

int main()
{
    char arrChar[20];
    char myChar;
    int index = 0;

    while (index < 20)
    {
        scanf("%c", &myChar);
        if (myChar == '\n')
            break;
        arrChar[index++] = myChar;
    }

    int mySize = index;

    for (int i = 0; i < mySize; i++)
    {
        char currentChar = arrChar[i];
        int currentCount = 1;

        if (currentChar == '\0')
            continue;

        for (int j = i + 1; j < mySize; j++)
        {
            if (arrChar[j] == currentChar)
            {
                currentCount++;
                arrChar[j] = '\0';
            }
        }

        printf("%c - %d\n", currentChar, currentCount);
    }

    return 0;
}
