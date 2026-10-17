#include <stdio.h>
#include <string.h>

int main() {
    char word_grid[3][100];
    char longest_word[100] = "";
    int max_length = 0;
    int max_row = -1, max_col = -1;

    printf("Enter 3 rows (each containing 3 space-separated words):\n");
    for (int i = 0; i < 3; i++) {
        printf("Row %d: ", i + 1);
        scanf(" %[^\n]", word_grid[i]);
    }

    for (int i = 0; i < 3; i++) {
        int col = 0;
        int len = 0;
        int word_start = 0;
        
        for (int j = 0; ; j++) {
            if (word_grid[i][j] == ' ' || word_grid[i][j] == '\0') {
                if (len > 0) {
                    if (len > max_length) {
                        max_length = len;
                        max_row = i;
                        max_col = col;
                        
                        // Extract longest word
                        strncpy(longest_word, &word_grid[i][word_start], len);
                        longest_word[len] = '\0';
                    }
                    col++;
                    len = 0;
                }
                if (word_grid[i][j] == '\0') break;
            } else {
                if (len == 0) word_start = j;
                len++;
            }
        }
    }

    printf("\n--- LONGEST WORD RESULT ---\n");
    printf("Longest Word : \"%s\"\n", longest_word);
    printf("Length       : %d\n", max_length);
    printf("Grid Index   : Row %d, Column %d\n", max_row, max_col);

    return 0;
}