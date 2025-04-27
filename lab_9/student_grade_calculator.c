#include <stdio.h>

#define MAX_STUDENTS 30
#define MAX_CLASSES 3

struct Student {
    char name[50];
    float grade;
};

struct Class {
    struct Student students[MAX_STUDENTS];
    int numStudents;
};

struct GraduationYear {
    struct Class classes[MAX_CLASSES];
    int numClasses;
};

float calculateClassAverage(struct Class *class) {
    float totalGrade = 0.0;
    for (int i = 0; i < class->numStudents; i++) {
        totalGrade += class->students[i].grade;
    }
    return totalGrade / class->numStudents;
}

float calculateGraduationYearAverage(struct GraduationYear *year) {
    float totalGrade = 0.0;
    int totalStudents = 0;

    for (int i = 0; i < year->numClasses; i++) {
        totalGrade += calculateClassAverage(&year->classes[i]) * year->classes[i].numStudents;
        totalStudents += year->classes[i].numStudents;
    }

    return totalGrade / totalStudents;
}

int main() {
    struct GraduationYear year;
    int numClasses;

    printf("Enter the number of classes in the graduation year: ");
    scanf("%d", &numClasses);
    year.numClasses = numClasses;

    for (int i = 0; i < numClasses; i++) {
        printf("\nEnter data for class %d\n", i + 1);
        printf("Enter the number of students in the class: ");
        scanf("%d", &year.classes[i].numStudents);

        for (int j = 0; j < year.classes[i].numStudents; j++) {
            printf("Enter the name of student %d: ", j + 1);
            scanf("%s", year.classes[i].students[j].name);
            printf("Enter the grade of student %d: ", j + 1);
            scanf("%f", &year.classes[i].students[j].grade);
        }
    }

    for (int i = 0; i < year.numClasses; i++) {
        printf("\nClass %d average grade: %.2f\n", i + 1, calculateClassAverage(&year.classes[i]));
    }

    printf("\nGraduation year average grade: %.2f\n", calculateGraduationYearAverage(&year));

    return 0;
}