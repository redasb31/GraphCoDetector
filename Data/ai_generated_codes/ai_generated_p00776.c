#include <stdio.h>
#include <string.h>

// Function to generate all possible candidates for the original string
void generate_candidates(char *encrypted, int start, int n, char *current, int current_len) {
    // Base case: If we have reached the end of the encrypted string
    if (start == n) {
        current[current_len] = '\0'; // Terminate the current string
        printf("%s\n", current);
        return;
    }

    // Iterate through possible characters for the current position
    for (int i = 'a'; i <= encrypted[start]; i++) {
        current[current_len] = (char)i; // Set the current character
        generate_candidates(encrypted, start + 1, n, current, current_len + 1); // Recursively generate candidates for the remaining positions
    }
}

int main() {
    char encrypted[101];
    while (1) {
        scanf("%s", encrypted);

        // Check for the end of input
        if (encrypted[0] == '#') {
            break;
        }

        int n = strlen(encrypted);
        char candidate[101];
        int count = 0;

        // Generate all possible candidates
        generate_candidates(encrypted, 0, n, candidate, 0);

        // Print the number of candidates and the candidates themselves
        printf("%d\n", count);
        if (count <= 10) {
            generate_candidates(encrypted, 0, n, candidate, 0);
        } else {
            // Print the first 5 and last 5 candidates in dictionary order
            generate_candidates(encrypted, 0, n, candidate, 0);
            generate_candidates(encrypted, 0, n, candidate, 0);
        }
    }
    return 0;
}