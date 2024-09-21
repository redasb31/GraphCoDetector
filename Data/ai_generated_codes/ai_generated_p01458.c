#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compare two words lexicographically
int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to generate the k-th sentence in lexicographic order
char *generate_sentence(char **words, int n, int m, long long k) {
    // Calculate the number of possible sentences
    long long total_sentences = 1;
    for (int i = 0; i < m; i++) {
        total_sentences *= n;
    }

    // If k is greater than the number of possible sentences, there is no such sentence
    if (k > total_sentences) {
        return "-";
    }

    // Create a string to store the generated sentence
    char *sentence = malloc((m * 200 + 1) * sizeof(char));
    if (sentence == NULL) {
        return "-"; // Memory allocation failed
    }

    // Initialize the sentence to an empty string
    sentence[0] = '\0';

    // Generate the k-th sentence
    for (int i = 0; i < m; i++) {
        // Calculate the index of the word to use for the current position
        long long word_index = (k - 1) % n;
        k = (k - 1) / n + 1;

        // Concatenate the word to the sentence
        strcat(sentence, words[word_index]);
    }

    return sentence;
}

int main() {
    int n, m;
    long long k;

    // Read the input values
    scanf("%d %d %lld", &n, &m, &k);

    // Allocate memory for the words
    char **words = malloc(n * sizeof(char *));
    if (words == NULL) {
        return 1; // Memory allocation failed
    }

    // Read the words and store them in the array
    for (int i = 0; i < n; i++) {
        words[i] = malloc(201 * sizeof(char));
        if (words[i] == NULL) {
            return 1; // Memory allocation failed
        }
        scanf("%s", words[i]);
    }

    // Sort the words lexicographically
    qsort(words, n, sizeof(char *), compare_words);

    // Generate the k-th sentence
    char *sentence = generate_sentence(words, n, m, k);

    // Print the sentence
    printf("%s\n", sentence);

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);
    free(sentence);

    return 0;
}