#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char surname[20];
    int grade1;
    int grade2;
    float average;
};

int main() {

    system("chcp 65001");

    struct Student students[] = {
        {"Горовий", 3, 3, 0},
        {"Чудіченко", 4, 2, 0},
        {"Зеленський", 666, 777, 0},
        {"Крячко", 2, 112, 0}
    };

    int countStud = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < countStud; i += 1) {
        students[i].average = (students[i].grade1 + students[i].grade2) / 2.0;
    }

    printf("Студенти з середнім балом 3.0:\n");
    int found = 0;
    for (int i = 0; i < countStud; i += 1) {
        if (students[i].average == 3.0) {
            printf("%s\n", students[i].surname);
            found = 1;
        }
    }

    if (!found) {
        printf("НЕМА\n");
    }

    return 0;
}