#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 30
#define MAX_PAGE_NUMBER 1000

// Structure to store a word and its corresponding page numbers
typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int page_numbers[MAX_PAGE_NUMBER];
    int count;
} WordEntry;

// Function to compare two words alphabetically
int compare_words(const void *a, const void *b) {
    return strcmp(((WordEntry *)a)->word, ((WordEntry *)b)->word);
}

int main() {
    WordEntry words[MAX_WORDS];
    int word_count = 0;

    // Read input pairs of words and page numbers
    char word[MAX_WORD_LENGTH + 1];
    int page_number;
    while (scanf("%s %d", word, &page_number) == 2) {
        // Find the word in the array
        int i;
        for (i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, word) == 0) {
                // Word found, add the page number
                words[i].page_numbers[words[i].count++] = page_number;
                break;
            }
        }

        // Word not found, add it to the array
        if (i == word_count) {
            strcpy(words[word_count].word, word);
            words[word_count].page_numbers[words[word_count].count++] = page_number;
            word_count++;
        }
    }

    // Sort the words alphabetically
    qsort(words, word_count, sizeof(WordEntry), compare_words);

    // Print the words and their page numbers
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i].word);
        for (int j = 0; j < words[i].count; j++) {
            printf("%d ", words[i].page_numbers[j]);
        }
        printf("\n");
    }

    return 0;
}