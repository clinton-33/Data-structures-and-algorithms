#include <stdio.h>
#include <stdlib.h>

char Registration_number[20];
char name[50];
int age;
struct course {
    char course_code;
    char course_name;
};

int Mark[4];
int totalmarks = 0;

double average(int b);

int main() {
    printf("name of student: ");
    scanf("%s", name);
    printf("Reg.no: ");
    scanf("%s", Registration_number);
    printf("age: ");
    scanf("%d", &age);
    printf("enter marks for 4 subjects:\n");

    for (int i = 0; i < 4; i++) {
        printf("subject %d: ", i + 1);
        scanf("%d", &Mark[i]);

        if (Mark[i] < 0 || Mark[i] > 100) {
            printf("Invalid marks! Marks should be between 0 and 100.\n");
            return 1;
        }

        totalmarks += Mark[i];
    }

    double avg = average(totalmarks);

    printf("total marks: %d\n", totalmarks);
    printf("average marks: %.2f\n", avg);

    char grades[2];
    if (avg >= 69) {
        grades[0] = 'A';
    } else if (avg >= 59) {
        grades[0] = 'B';
    } else if (avg >= 49) {
        grades[0] = 'C';
    } else if (avg >= 39) {
        grades[0] = 'D';
    } else {
        grades[0] = 'E';
    }
    grades[1] = '\0';

    printf("GRADE: %s\n", grades);

    return 0;
}

double average(int b) {
    return (double)b / 4;
}
