#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRINGS 12
#define MAX_STRING_LEN 20
#define MAX_TEXT_LEN 5000

// Structure to store a string and its length
typedef struct {
    char str[MAX_STRING_LEN + 1];
    int len;
} String;

// Function to calculate the number of occurrences of concatenated strings in the text
int count_occurrences(String *strings, int n, char *text, int text_len) {
    int occurrences = 0;
    // Create a table to store the concatenated strings
    char **concatenated_strings = (char **)malloc(sizeof(char *) * (1 << n));
    if (concatenated_strings == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    // Generate all possible concatenations of the strings
    for (int i = 0; i < (1 << n); i++) {
        int len = 0;
        concatenated_strings[i] = (char *)malloc(sizeof(char) * (MAX_STRING_LEN * n + 1));
        if (concatenated_strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                strcpy(concatenated_strings[i] + len, strings[j].str);
                len += strings[j].len;
            }
        }
        concatenated_strings[i][len] = '\0';
    }

    // Iterate through the text and count occurrences of each concatenated string
    for (int i = 0; i < text_len; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (strncmp(text + i, concatenated_strings[j], strlen(concatenated_strings[j])) == 0) {
                occurrences++;
                i += strlen(concatenated_strings[j]) - 1; // Move to the next position after the match
                break; // Move to the next position in the text
            }
        }
    }

    // Free the allocated memory
    for (int i = 0; i < (1 << n); i++) {
        free(concatenated_strings[i]);
    }
    free(concatenated_strings);

    return occurrences;
}

int main() {
    int n, m;
    String strings[MAX_STRINGS];
    char text[MAX_TEXT_LEN + 1];
    while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)) {
        // Read the element strings
        for (int i = 0; i < n; i++) {
            scanf("%s", strings[i].str);
            strings[i].len = strlen(strings[i].str);
        }
        // Read the text
        char line[101];
        text[0] = '\0';
        for (int i = 0; i < m; i++) {
            scanf("%s", line);
            strcat(text, line);
        }
        int text_len = strlen(text);
        // Calculate and print the number of occurrences
        printf("%d\n", count_occurrences(strings, n, text, text_len));
    }
    return 0;
}