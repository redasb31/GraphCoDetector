#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50
#define MAX_SEQUENCE_LEN 300

// Structure to represent a word and its corresponding button sequence
typedef struct {
    char word[MAX_WORD_LEN + 1];
    char sequence[MAX_SEQUENCE_LEN + 1];
} Word;

// Function to generate the button sequence for a given word
void generateSequence(char *word, char *sequence) {
    int i, j;
    for (i = 0, j = 0; word[i] != '\0'; i++) {
        switch (word[i]) {
            case 'a': case 'b': case 'c':
                sequence[j++] = '2';
                break;
            case 'd': case 'e': case 'f':
                sequence[j++] = '3';
                break;
            case 'g': case 'h': case 'i':
                sequence[j++] = '4';
                break;
            case 'j': case 'k': case 'l':
                sequence[j++] = '5';
                break;
            case 'm': case 'n': case 'o':
                sequence[j++] = '6';
                break;
            case 'p': case 'q': case 'r': case 's':
                sequence[j++] = '7';
                break;
            case 't': case 'u': case 'v':
                sequence[j++] = '8';
                break;
            case 'w': case 'x': case 'y': case 'z':
                sequence[j++] = '9';
                break;
        }
    }
    sequence[j] = '\0';
}

// Function to find all possible word sequences for the given input sequence
void findSequences(Word *words, int numWords, char *sequence) {
    int i, j, k, matchFound = 0;
    char tempSequence[MAX_SEQUENCE_LEN + 1];

    for (i = 0; i < numWords; i++) {
        // Check if the current word's sequence matches the input sequence
        if (strncmp(words[i].sequence, sequence, strlen(words[i].sequence)) == 0) {
            // If a match is found, recursively check for remaining sequences
            strcpy(tempSequence, sequence + strlen(words[i].sequence));
            if (tempSequence[0] == '\0') {
                // If the entire sequence is matched, print the word sequence
                printf("%s.", words[i].word);
                matchFound = 1;
            } else {
                // Recursively check for remaining sequences
                findSequences(words, numWords, tempSequence);
            }
        }
    }

    // If no matching sequence is found, print the terminating line
    if (!matchFound) {
        printf("–\n");
    }
}

int main() {
    int n, i;
    Word words[MAX_WORDS];
    char sequence[MAX_SEQUENCE_LEN + 1];

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        // Read the dictionary words and generate their button sequences
        for (i = 0; i < n; i++) {
            scanf("%s", words[i].word);
            generateSequence(words[i].word, words[i].sequence);
        }

        // Read the input button sequence
        scanf("%s", sequence);

        // Find and print all possible word sequences
        findSequences(words, n, sequence);
    }

    return 0;
}