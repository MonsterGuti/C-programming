#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char name[31];
    char expiaryDate[9];
    int code;
    float price;
    int quantity;
} Medicine;

Medicine *LoadMedicines(const char *fileName, int *count)
{
    FILE *f = fopen(fileName, "rb");
    if (!f)
    {
        printf("cannot open file '%s'\n", fileName);
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    *count = size / sizeof(Medicine);
    if (*count == 0)
    {
        printf("No medicines.");
        fclose(f);
        return NULL;
    }

    Medicine *arr = malloc(*count * sizeof(Medicine));
    if (!arr)
    {
        printf("Memory allocation failed.");
        return NULL;
    }

    fread(arr, sizeof(Medicine), *count, f);
    fclose(f);
    return arr;
}

Medicine *getExpiaryMedicines(Medicine *arr, int count, const char *date, int *expiredCount)
{
    *expiredCount = 0;
    Medicine *result = malloc(count * sizeof(Medicine));
    if (!result)
        return NULL;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(arr[i].expiaryDate, date) < 0)
            result[(*expiredCount)++] = arr[i];
    }

    if (*expiredCount == 0)
    {
        free(result);
        return NULL;
    }

    Medicine *temp = realloc(result, (*expiredCount) * sizeof(Medicine));
    if (!temp)
        return NULL;

    result = temp;
    return result;
}

int SearchByPrice(Medicine *arr, int n, float minPrice, float maxPrice)
{
    FILE *f = fopen("offer.txt", "w");
    if (!f)
    {
        printf("cannot open this file");
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].price >= minPrice && arr[i].price <= maxPrice)
        {
            fprintf(f, "%s\n%s\n%d\n%.2f leva\n\n",
                    arr[i].name, arr[i].expiaryDate, arr[i].code, arr[i].price);
            count += 1;
        }
    }

    if (count == 0)
    {
        printf("No medicines in this price range.");
        return 0;
    }

    fclose(f);
    return count;
}

Medicine *DelByNameAndDate(Medicine **arr, int *n, const char *medName, const char *expDate)
{
    for (int i = 0; i < *n; i++)
    {
        if (strcmp((*arr)[i].name, medName) == 0 && strcmp((*arr)[i].expiaryDate, expDate) == 0)
        {
            for (int j = i; j < *n - 1; j++)
                (*arr)[j] = (*arr)[j + 1];
            (*n)--;
            i--;
        }
    }

    if (*n == 0)
    {
        free(*arr);
        *arr = NULL;
        return NULL;
    }

    Medicine *temp = realloc(*arr, (*n) * sizeof(Medicine));
    if (!temp)
    {
        printf("Error in realloc\n");
        return *arr;
    }

    *arr = temp;
    return *arr;
}

int main()
{
    int count;

    // === Task 1: Load medicines from binary file ===
    Medicine *meds = LoadMedicines("medicines.bin", &count);
    if (!meds)
        return 1;
    printf("Loaded %d medicines.\n", count);

    // === Task 2: Get expired medicines ===
    char date[9];
    printf("Enter a date to find expired medicines (YYYYMMDD): ");
    scanf("%s", date);

    int expiredCount;
    Medicine *expired = getExpiaryMedicines(meds, count, date, &expiredCount);
    if (expired)
    {
        printf("Found %d expired medicines before %s:\n", expiredCount, date);
        for (int i = 0; i < expiredCount; i++)
        {
            printf("%s - %s\n", expired[i].name, expired[i].expiaryDate);
        }
        free(expired);
    }
    else
    {
        printf("No expired medicines before %s.\n", date);
    }

    // === Task 3: Search by price range and write to file ===
    float minPrice, maxPrice;
    printf("Enter price range (min max): ");
    scanf("%f %f", &minPrice, &maxPrice);
    int foundInRange = SearchByPrice(meds, count, minPrice, maxPrice);
    printf("Medicines in price range: %d (saved in offer.txt)\n", foundInRange);

    // === Task 4: Delete medicine by name and expiry date ===
    char delName[31], delDate[9];
    printf("Enter medicine name and expiry date to delete: ");
    scanf("%s %s", delName, delDate);
    meds = DelByNameAndDate(&meds, &count, delName, delDate);
    printf("Remaining medicines: %d\n", count);

    free(meds);
    return 0;
}