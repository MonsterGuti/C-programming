#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// === task 1 ===
typedef struct
{
    char name[51];
    char date[11];
    int classes;
    float price;
} Course;

Course *coursesCount(int *count)
{
    FILE *f = fopen("courses.bin", "rb");
    if (!f)
    {
        printf("cannot open 'courses.bin'.\n");
        return 0;
    }

    fread(count, sizeof(int), 1, f);

    Course *courses = malloc(*count * sizeof(Course));
    if (!courses)
    {
        printf("Memory allocation error.\n");
        fclose(f);
        return 0;
    }

    fread(courses, sizeof(Course), *count, f);

    fclose(f);
    return courses;
}

// === task2 ===
void printDiscountCourse(Course *courses, int count, int index)
{
    if (index < 0 || index >= count)
    {
        printf("Index out of range.\n");
        return;
    }

    courses[index].price *= 0.9;

    printf("%.2flv. - %s - %s\n", courses[index].price,
           courses[index].name,
           courses[index].date);
}

// === task 3 ===
int writeToFile(Course *courses, int count, float minPrice, float maxPrice)
{
    FILE *f = fopen("offer.txt", "w");
    if (!f)
    {
        printf("cannot open 'offer.txt'.\n");
        return 0;
    }

    int writtenCourses = 0;
    for (int i = 0; i < count; i++)
    {
        if (courses[i].price >= minPrice && courses[i].price <= maxPrice)
        {
            fprintf(f, "%s\n", courses[i].name);
            fprintf(f, "%s\n", courses[i].date);
            fprintf(f, "%d\n", courses[i].classes);
            fprintf(f, "%.2flv.\n\n", courses[i].price);
            writtenCourses++;
        }
    }
    fclose(f);
    return writtenCourses;
}

// === task4 ===
Course *delCourse(Course **courses, int *count, const char *searchedName, const char *searchedDate)
{
    for (int i = 0; i < *count; i++)
    {
        if (strcmp((*courses)[i].name, searchedName) == 0 && strcmp((*courses)[i].date, searchedDate) == 0)
        {
            for (int j = i; j < (*count) - 1; j++)
            {
                (*courses)[j] = (*courses)[j + 1];
            }
            (*count)--;
            *courses = realloc(*courses, (*count) * sizeof(Course));
            printf("Course \"%s\" starting on %s has been deleted.\n", searchedName, searchedDate);
            return *courses;
        }
    }
    printf("No course found with name \"%s\" and start date %s.\n", searchedName, searchedDate);
    return *courses;
}

bool isValidDate(const char *date)
{
    if (strlen(date) != 10)
        return false;

    if (date[4] != '.' || date[7] != '.')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }

    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);

    if (year > 2025 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

int main()
{
    int count;
    Course *courses = coursesCount(&count);
    if (!courses)
        return 1;
    printf("The number of courses is %d\n", count);

    int index;
    printf("Enter index of course for discount: ");
    scanf("%d", &index);
    printDiscountCourse(courses, count, index);

    float minPrice, maxPrice;
    scanf("%f %f", &minPrice, &maxPrice);
    int coursesInRange = writeToFile(courses, count, minPrice, maxPrice);
    printf("%d\n", coursesInRange);

    char searchedName[51];
    char searchedDate[11];

    printf("Enter course name to delete: ");
    scanf("%s", searchedName);

    do
    {
        printf("Enter course date to delete (yyyy.mm.dd): ");
        scanf("%10s", searchedDate);
    } while (!isValidDate(searchedDate));
    
    courses = delCourse(&courses, &count, searchedName, searchedDate);

    free(courses);
    return 0;
}
