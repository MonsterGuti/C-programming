#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct
{
    char name[21];
    int code;
    char expiry[11];
    float price;
} Product;

// Task 2: Calculate average price of products cheaper than a given value
float avgByPrice(Product *arr, int n, float maxPrice)
{
    int count = 0;
    float sum = 0.0f;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].price < maxPrice)
        {
            count++;
            sum += arr[i].price;
        }
    }

    if (count == 0)
        return 0;
    return sum / count;
}

// Task 3: Save products to a text file if price is higher and expiry date is earlier than a given date
int writeTextFile(Product *arr, int n, const char *date, float minPrice)
{
    FILE *f = fopen("products.txt", "w");
    if (!f)
    {
        printf("Could not open products.txt\n");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i].expiry, date) < 0 && arr[i].price > minPrice)
        {
            count++;
            fprintf(f, "%s - %d - %s - %.2f lv.\n", arr[i].name, arr[i].code, arr[i].expiry, arr[i].price);
        }
    }
    fclose(f);
    return count;
}

// Task 4: Read binary file and search for product by name and code
void printInfo(const char *name, int targetCode)
{
    FILE *f = fopen("products.bin", "rb");
    if (!f)
    {
        printf("Could not open 'products.bin'\n");
        return;
    }

    while (!feof(f))
    {
        int nameLen;
        if (fread(&nameLen, sizeof(int), 1, f) != 1)
            break;

        char tempName[21];
        if (nameLen > 20) nameLen = 20;
        if (fread(tempName, sizeof(char), nameLen, f) != nameLen)
            break;
        tempName[nameLen] = '\0';

        int tempCode;
        if (fread(&tempCode, sizeof(int), 1, f) != 1)
            break;

        char expiry[11];
        if (fread(expiry, sizeof(char), 10, f) != 10)
            break;
        expiry[10] = '\0';

        float price;
        if (fread(&price, sizeof(float), 1, f) != 1)
            break;

        if (strcmp(tempName, name) == 0 && tempCode == targetCode)
        {
            printf("=== Product Found ===\n");
            printf("%s, code: %d, use before: %s - price %.2f leva\n", tempName, tempCode, expiry, price);
            fclose(f);
            return;
        }
    }
    printf("Product with name '%s' and code '%d' not found.\n", name, targetCode);
    fclose(f);
}

// Validate date format YYYY.MM.DD
bool isValidDateFormat(const char *date)
{
    if (strlen(date) != 10) return false;
    if (date[4] != '.' || date[7] != '.') return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    if (year < 2024 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

int main()
{
    int n;
    do
    {
        printf("Enter the quantity of products (10-30): ");
        scanf("%d", &n);
    } while (n < 10 || n > 30);

    Product *products = malloc(n * sizeof(Product));
    if (!products)
    {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Task 1: Input and store product data
    for (int i = 0; i < n; i++)
    {
        printf("Product #%d\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Code: ");
        scanf("%d", &products[i].code);
        do {
            printf("Expiry (YYYY.MM.DD): ");
            scanf("%s", products[i].expiry);
        } while (!isValidDateFormat(products[i].expiry));
        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    // Task 2
    float maxPrice;
    printf("Enter a maximum price criteria: ");
    scanf("%f", &maxPrice);
    float avgPrice = avgByPrice(products, n, maxPrice);
    printf("The average price of products below %.2f is %.2f lv.\n", maxPrice, avgPrice);

    // Task 3
    char date[11];
    float minPrice;
    do {
        printf("Enter expiry date (YYYY.MM.DD) and minimum price to save in file: ");
        scanf("%s %f", date, &minPrice);
    } while (!isValidDateFormat(date));

    int savedCount = writeTextFile(products, n, date, minPrice);
    printf("%d products saved to products.txt\n", savedCount);

    // Task 4
    char searchName[21];
    int searchCode;
    printf("Enter product name and code to search in binary file: ");
    scanf("%s %d", searchName, &searchCode);
    printInfo(searchName, searchCode);

    free(products);
    return 0;
}
