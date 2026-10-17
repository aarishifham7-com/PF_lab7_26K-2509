#include <stdio.h>
#include <ctype.h>

int main() {
    char sentences[3][100];

    printf("Enter a paragraph of 3 sentences separated by semicolons (;):\n");

    for (int i = 0; i < 3; i++) {
        scanf(" %99[^;\n]%*c", sentences[i]);
    }

    printf("\n--- VOWEL ANALYSIS REPORT ---\n");
    for (int i = 0; i < 3; i++) {
        int vowel_count = 0;

        for (int j = 0; sentences[i][j] != '\0'; j++) {
            char ch = tolower((unsigned char)sentences[i][j]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowel_count++;
            }
        }

        printf("Sentence %d: \"%s\"\n", i + 1, sentences[i]);
        printf("Vowel Count: %d\n\n", vowel_count);
    }

    return 0;
}