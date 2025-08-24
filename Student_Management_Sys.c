//STUDENT MANAGEMENT SYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 20

// Structure to store student details
struct Student {
    int rollNo;
    char name[50];
    int age;
    char course[50];
};

// Array to store students and a count of students
struct Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Database is full.\n");
        return;
    }

    struct Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);
    printf("Enter Name: ");
    scanf(" %s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Course: ");
    scanf(" %s", s.course);

    students[studentCount++] = s;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("Roll No\tName\t\tAge\tCourse\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t\t%d\t%s\n", students[i].rollNo, students[i].name, students[i].age, students[i].course);
    }
}

// Function to search for a student by roll number
void searchStudent() {
    int rollNo;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Course: %s\n", students[i].course);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", rollNo);
}

// Function to delete a student by roll number
void deleteStudent() {
    int rollNo, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with Roll Number %d deleted successfully.\n", rollNo);
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNo);
    }
}

// Main function to handle the menu and user inputs
int main() {
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student by Roll Number\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}