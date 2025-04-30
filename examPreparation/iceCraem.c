#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === task1 ===

typedef struct
{
    char code[3];
    char productName[21];
    int productWeight;
    double price;
} iceCream;

iceCream *inputIceCreams(int n)
{
    if (n <= 5 || n >= 15) {
        printf("Invalid number of icecreams. It must be between 6 and 14.\n");
        return NULL;
    }

    iceCream *arr = malloc(n * sizeof(iceCream));
    if (!arr) {
        printf("Cannot allocate memory.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        printf("Ice cream #%d:\n", i + 1);

        printf("Write code: \n");
        scanf("%s", arr[i].code);

        printf("Name: \n");
        scanf("%s", arr[i].productName);

        printf("Weight: \n");
        scanf("%d", &arr[i].productWeight);

        printf("Price per kilogram: \n");
        scanf("%lf", &arr[i].price);
    }
    return arr;
}

// === task2 ===

float totalPriceByLetter(iceCream *arr, int n, char letter)
{
    float totalPrice = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].productName[0] == letter)
            totalPrice += arr[i].price;
    }
    return totalPrice;
}

// === task3 ===

int saveToFile(iceCream *arr, int n, float maxPrice, int minWeight)
{
    FILE *fp = fopen("info.txt", "w");

    if (!fp) {
        printf("Cannot open this file.\n");
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i].price < maxPrice && arr[i].productWeight > minWeight) {
            fprintf(fp, "%s;%s;%d;%.2f leva\n", arr[i].code, arr[i].productName, arr[i].productWeight, arr[i].price);
            count++;
        }
    }

    fclose(fp);
    return count;
}

// === task4 ===

void findByCodeBinFile(const char *myCode)
{
    FILE *f = fopen("icecream.bin", "rb");

    if (!f) {
        printf("Cannot open this file.\n");
        return;
    }

    while (!feof(f)) {
        char code[3];
        int nameLen;
        char name[21];
        int weight;
        float price;

        if (fread(code, sizeof(char), 2, f) != 2)
            break;
        code[2] = '\0';

        fread(&nameLen, sizeof(int), 1, f);
        fread(name, sizeof(char), nameLen, f);
        name[nameLen] = '\0';

        fread(&weight, sizeof(int), 1, f);
        fread(&price, sizeof(float), 1, f);

        if (strcmp(code, myCode) == 0) {
            printf("====================\n");
            printf("IceCream - %s\n", name);
            printf("Price - %.2f BGN\n", price);
            printf("====================\n");

            fclose(f);
            return;
        }
    }
    printf("This ice cream with code %s does not exist.\n", myCode);
    fclose(f);
}

int main()
{
    int n;
    printf("Enter number of ice creams (6-14): ");
    scanf("%d", &n);

    iceCream *icecreams = inputIceCreams(n);
    if (!icecreams)
        return 1;

    char letter;
    printf("Enter starting letter to search for: ");
    getchar();
    scanf("%c", &letter);
    float total_price = totalPriceByLetter(icecreams, n, letter);
    printf("Total price of ice creams starting with '%c': %.2f BGN\n", letter, total_price);

    float maxPrice;
    int minWeight;
    printf("Enter max price for filter: ");
    scanf("%f", &maxPrice);
    printf("Enter min weight for filter: ");
    scanf("%d", &minWeight);
    int written = saveToFile(icecreams, n, maxPrice, minWeight);
    printf("%d ice creams saved to file.\n", written);

    char code[3];
    printf("Enter code to search in binary file: ");
    scanf("%s", code);
    findByCodeBinFile(code);

    free(icecreams);
    return 0;
}
