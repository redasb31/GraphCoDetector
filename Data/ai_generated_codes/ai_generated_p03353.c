#include <stdio.h>
#include <string.h>

// Function to compare two strings lexicographically
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    // Read the input string
    char s[5001];
    scanf("%s", s);

    // Read the value of K
    int k;
    scanf("%d", &k);

    // Calculate the number of substrings
    int n = strlen(s);
    int num_substrings = n * (n + 1) / 2;

    // Create an array to store all substrings
    char **substrings = malloc(num_substrings * sizeof(char *));

    // Initialize the index for substrings array
    int index = 0;

    // Iterate over all possible starting indices
    for (int i = 0; i < n; i++) {
        // Iterate over all possible ending indices
        for (int j = i; j < n; j++) {
            // Create a substring from i to j
            substrings[index] = malloc((j - i + 2) * sizeof(char));
            strncpy(substrings[index], s + i, j - i + 1);
            substrings[index][j - i + 1] = '\0';
            index++;
        }
    }

    // Sort the substrings lexicographically
    qsort(substrings, num_substrings, sizeof(char *), compare);

    // Print the k-th lexicographically smallest substring
    printf("%s\n", substrings[k - 1]);

    // Free the memory allocated for substrings
    for (int i = 0; i < num_substrings; i++) {
        free(substrings[i]);
    }
    free(substrings);

    return 0;
}