#include <stdio.h>

int main() {
    char student_names[3][50];
    int marks[3][3];
    
    for (int i = 0; i < 3; i++) {
        printf("Enter full name of Student %d: ", i + 1);
        scanf(" %[^\n]", student_names[i]);
        
        printf("Enter 3 subject marks for %s:\n", student_names[i]);
        for (int j = 0; j < 3; j++) {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    printf("\n--- STUDENT MARKS REPORT ---\n");
    for (int i = 0; i < 3; i++) {
        int total = 0;
        for (int j = 0; j < 3; j++) {
            total += marks[i][j];
        }
        float average = total / 3.0f;
        printf("Student: %-20s | Average Marks: %.2f\n", student_names[i], average);
    }

    return 0;
}