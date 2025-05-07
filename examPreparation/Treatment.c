#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// === task 1 ===
typedef struct
{
    int ID;
    char date[11];
    char name[31];
    char diagnose[50];
} Treatment;

bool isValidDate(const char *date)
{
    if (strlen(date) != 10)
        return false;

    if (date[2] != '.' || date[5] != '.')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int day = atoi(date);
    int month = atoi(date + 3);
    int year = atoi(date + 6);

    if (year > 2025 || year < 1900)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

// === task 2 ===
int countTreatment(Treatment *treatments, int n, const char *searchedName,
                   const char *searchedDiagnose)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(treatments[i].name, searchedName) == 0 &&
            strcmp(treatments[i].diagnose, searchedDiagnose) == 0)
            count++;
    }
    return count;
}

// === task 3 ===
Treatment *addNewTreatment(Treatment *treatments, int *n)
{
    Treatment newTreatment;

    printf("Enter ID: ");
    scanf("%d", &newTreatment.ID);
    getchar();

    do
    {
        printf("Enter date (DD.MM.YYYY): ");
        scanf(" %[^\n]", newTreatment.date);
        if (!isValidDate(newTreatment.date))
            printf("Invalid date format!\n");
    } while (!isValidDate(newTreatment.date));

    printf("Enter name: ");
    scanf(" %[^\n]", newTreatment.name);

    printf("Enter diagnosis: ");
    scanf(" %[^\n]", newTreatment.diagnose);

    Treatment *temp = realloc(treatments, (*n + 1) * sizeof(Treatment));
    if (!temp)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    treatments = temp;
    treatments[*n] = newTreatment;
    (*n)++;

    return treatments;
}

// === task 4 ===
int writeTextFile(Treatment *treatments, int n, const char *targetDiagnose)
{
    FILE *f = fopen("illness.txt", "w");
    if (!f)
    {
        printf("Cannot open 'illness.txt'\n");
        return 0;
    }

    int writtenCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(treatments[i].diagnose, targetDiagnose) == 0)
        {
            fprintf(f, "Hospital stay of %s\nfor treatment of %s\n%s\n\n",
                    treatments[i].name, treatments[i].diagnose, treatments[i].date);
            writtenCount++;
        }
    }
    fclose(f);
    return writtenCount;
}
    

int main()
{
    int n;
    FILE *f = fopen("history.bin", "rb");
    if (!f)
    {
        printf("cannot open 'history.bin'\n");
        return 1;
    }
    
    if (fread(&n, sizeof(int), 1, f) != 1)
    {
        printf("Failed to read number of records.\n");
        fclose(f);
        return 1;
    }

    Treatment *history = malloc(n * sizeof(Treatment));
    if (!history)
    {
        printf("Memory allocation failed.\n");
        fclose(f);
        return 1;
    }

    if (fread(history, sizeof(Treatment), n, f) != n)
    {
        printf("Failed to read treatments.\n");
        free(history);
        fclose(f);
        return 1;
    }
    fclose(f);

    char searchedName[31];
    char searchedDiagnose[51];
    fgets(searchedName, sizeof(searchedName), stdin);
    searchedName[strcspn(searchedName, "\n")] = 0;
    fgets(searchedDiagnose, sizeof(searchedDiagnose), stdin);
    searchedDiagnose[strcspn(searchedDiagnose, "\n")] = 0;
    int numberOfTreatments = countTreatment(history, n, searchedName, searchedDiagnose);
    printf("Number of treatments for Ivan Ivanov with Flu: %d\n", numberOfTreatments);

    history = addNewTreatment(history, &n);
    if(!history)
    return 1;


    int writtenCount = writeTextFile(history, n, searchedDiagnose);
    printf("The number of treatments for this diagnose is %d", writtenCount);
    return 0;
}
