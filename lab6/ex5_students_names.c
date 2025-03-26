#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 32
#define MAX_NAME_LENGTH 128

void search_students(char students[MAX_STUDENTS][MAX_NAME_LENGTH], int count, char part_of_name[MAX_NAME_LENGTH]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strstr(students[i], part_of_name)) {
            printf("%s\n", students[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found with the given part of the name.\n");
    }
}

int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    char part_of_name[MAX_NAME_LENGTH];
    int count = 0;

    while (count < MAX_STUDENTS) {
        fgets(students[count], MAX_NAME_LENGTH, stdin);
        students[count][strcspn(students[count], "\n")] = '\0';
        
        if (strlen(students[count]) == 0) {
            break;
        }
        count++;
    }

    fgets(part_of_name, MAX_NAME_LENGTH, stdin);
    part_of_name[strcspn(part_of_name, "\n")] = '\0';

    search_students(students, count, part_of_name);

    return 0;
}
