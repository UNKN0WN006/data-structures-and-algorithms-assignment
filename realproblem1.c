#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 3
#define PASS_MARK 40
#define SUBJECTS 5

typedef struct {
    char name[50];
    char address[100];
    int marks[SUBJECTS];
} Student;

void findPassFail(Student students[], int count);
void findMaxMathMarks(Student students[], int count);
void findMinPhysicsMarks(Student students[], int count);
void findMaxAverageMarks(Student students[], int count);
void printRecords(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0, choice;

    // Input student data from the user
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &count);

    if (count > MAX_STUDENTS) {
        count = MAX_STUDENTS;
        printf("Limiting to maximum number of students (%d).\n", MAX_STUDENTS);
    }

    for (int i = 0; i < count; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name); // Read full line including spaces
        printf("Address: ");
        scanf(" %[^\n]%*c", students[i].address); // Read full line including spaces

        printf("Enter marks for %d subjects:\n", SUBJECTS);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Find students who passed/failed in minimum 3 subjects\n");
        printf("2. Show record with max marks in Mathematics\n");
        printf("3. Show record with min marks in Physics\n");
        printf("4. Show record with max average marks\n");
        printf("5. Print all student records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: findPassFail(students, count); break;
            case 2: findMaxMathMarks(students, count); break;
            case 3: findMinPhysicsMarks(students, count); break;
            case 4: findMaxAverageMarks(students, count); break;
            case 5: printRecords(students, count); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void findPassFail(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        int passCount = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            if (students[i].marks[j] >= PASS_MARK) passCount++;
        }
        printf("Student %s has %s in at least three subjects.\n", students[i].name, passCount < 3 ? "failed" : "passed");
    }
}

void findMaxMathMarks(Student students[], int count) {
    int maxIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks[0] > students[maxIndex].marks[0]) maxIndex = i;
    }
    printf("Student with max marks in Mathematics: %s, Marks: %d\n", students[maxIndex].name, students[maxIndex].marks[0]);
}

void findMinPhysicsMarks(Student students[], int count) {
    int minIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks[1] < students[minIndex].marks[1]) minIndex = i;
    }
    printf("Student with min marks in Physics: %s, Marks: %d\n", students[minIndex].name, students[minIndex].marks[1]);
}

void findMaxAverageMarks(Student students[], int count) {
    int maxIndex = 0;
    float maxAvg = 0;
    for (int i = 0; i < count; i++) {
        float avg = 0;
        for (int j = 0; j < SUBJECTS; j++) avg += students[i].marks[j];
        avg /= SUBJECTS;
        if (avg > maxAvg) {
            maxAvg = avg;
            maxIndex = i;
        }
    }
    printf("Student with max average marks: %s, Average: %.2f\n", students[maxIndex].name, maxAvg);
}

void printRecords(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        int total = 0;
        printf("Name: %s, Address: %s, Marks:", students[i].name, students[i].address);
        for (int j = 0; j < SUBJECTS; j++) {
            printf(" %d", ",",students[i].marks[j]);
            total += students[i].marks[j];
        }
        printf(", Total: %d\n", total);
    }
}
