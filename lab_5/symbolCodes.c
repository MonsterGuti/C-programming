#include <stdio.h>

int compare_strings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 < *str2) {
            return -1;
        } else if (*str1 > *str2) {
            return 1;
        }
        str1++;
        str2++;
    }

    if (*str1 < *str2) {
        return -1;
    } else if (*str1 > *str2) {
        return 1;
    }

    return 0;
}

int main() {
    char str1[256], str2[256];

    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);

    int result = compare_strings(str1, str2);

    if (result == 0) {
        printf("The strings are identical.\n");
    } else if (result == -1) {
        printf("The first string is smaller than the second.\n");
    } else {
        printf("The second string is smaller than the first.\n");
    }

    return 0;
}
