#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    double grade;
};

struct Class {
    char name[20];
    struct Student* students;
};

struct GraduatingClass {
    struct Class* classes;
};

double calculate_class_average(struct Class cls, int num_students) {
    double sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += cls.students[i].grade;
    }
    return sum / num_students;
}

double calculate_graduating_class_average(struct GraduatingClass grad, int num_classes, int num_students) {
    double sum = 0;
    for (int i = 0; i < num_classes; i++) {
        sum += calculate_class_average(grad.classes[i], num_students);
    }
    return sum / num_classes;
}

void fill_graduating_class(struct GraduatingClass* grad, int num_classes, int num_students) {
    for (int i = 0; i < num_classes; i++) {
        printf("Enter name of class %d: ", i + 1);
        fgets(grad->classes[i].name, sizeof(grad->classes[i].name), stdin);
        grad->classes[i].name[strcspn(grad->classes[i].name, "\n")] = 0;

        grad->classes[i].students = malloc(num_students * sizeof(struct Student));

        for (int j = 0; j < num_students; j++) {
            printf("Enter name of student %d in class %s: ", j + 1, grad->classes[i].name);
            fgets(grad->classes[i].students[j].name, sizeof(grad->classes[i].students[j].name), stdin);
            grad->classes[i].students[j].name[strcspn(grad->classes[i].students[j].name, "\n")] = 0;

            printf("Enter grade of %s: ", grad->classes[i].students[j].name);
            scanf("%lf", &grad->classes[i].students[j].grade);
            getchar();
        }

        double class_avg = calculate_class_average(grad->classes[i], num_students);
        printf("Average grade for class %s: %.2f\n\n", grad->classes[i].name, class_avg);
    }
}

int main() {
    int num_classes, num_students;

    printf("Enter number of classes: ");
    scanf("%d", &num_classes);
    printf("Enter number of students per class: ");
    scanf("%d", &num_students);
    getchar();

    struct GraduatingClass grad;
    grad.classes = malloc(num_classes * sizeof(struct Class));

    fill_graduating_class(&grad, num_classes, num_students);

    double overall_avg = calculate_graduating_class_average(grad, num_classes, num_students);
    printf("Average grade for the graduating class: %.2f\n", overall_avg);

    for (int i = 0; i < num_classes; i++) {
        free(grad.classes[i].students);
    }
    free(grad.classes);

    return 0;
}
