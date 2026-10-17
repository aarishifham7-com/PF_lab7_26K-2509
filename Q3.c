#include <stdio.h>

int main() {
    char secret_messages[3][100];

    printf("Enter 3 secret messages (only UPPERCASE letters and spaces are allowed):\n");

    for (int i = 0; i < 3; i++) {
        printf("Message %d: ", i + 1);
        scanf(" %[A-Z ]", secret_messages[i]);

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    printf("\n--- FILTERED MESSAGES & WORD COUNTS ---\n");
    for (int i = 0; i < 3; i++) {
        int spaces = 0;
        int is_word = 0;

        for (int j = 0; secret_messages[i][j] != '\0'; j++) {
            if (secret_messages[i][j] == ' ') {
                spaces++;
                is_word = 0;
            } else if (is_word == 0) {
                is_word = 1;
            }
        }

        int word_count = (secret_messages[i][0] == '\0') ? 0 : (spaces + 1);
        printf("Message %d: \"%s\" | Word Count: %d\n", i + 1, secret_messages[i], word_count);
    }

    return 0;
}