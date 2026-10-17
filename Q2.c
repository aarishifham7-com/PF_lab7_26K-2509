#include <stdio.h>
#include <ctype.h>

int main() {
    char logs[3][30];
    int uppercase_count = 0;

    printf("Enter 3 CSV log entries (e.g., Admin_User,Access Granted,10:45AM):\n");
    
    for (int i = 0; i < 3; i++) {
        printf("Entry %d: ", i + 1);
        scanf(" %29[^,],%29[^,],%29[^\n]", logs[0], logs[1], logs[2]);

        for (int row = 0; row < 3; row++) {
            for (int col = 0; logs[row][col] != '\0'; col++) {
                if (isupper((unsigned char)logs[row][col])) {
                    uppercase_count++;
                }
            }
        }
    }

    printf("\nTotal uppercase letters (A-Z) across all log entries: %d\n", uppercase_count);

    return 0;
}