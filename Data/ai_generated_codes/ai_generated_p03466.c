#include <stdio.h>
#include <string.h>

// Function to find the substring of f(A, B) from position C to position D
char* findSubstring(int A, int B, int C, int D) {
    // Calculate the length of the substring
    int length = D - C + 1;

    // Allocate memory for the substring
    char* substring = malloc((length + 1) * sizeof(char));
    if (substring == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    // Determine the pattern of A's and B's in the substring
    int A_count = 0;
    int B_count = 0;
    for (int i = C - 1; i < D; i++) {
        if (i % (A + B) < A) {
            substring[i - C + 1] = 'A';
            A_count++;
        } else {
            substring[i - C + 1] = 'B';
            B_count++;
        }
    }

    // Adjust the pattern if necessary to ensure lexicographically smallest substring
    if (A_count > A || B_count > B) {
        int extra_A = A_count - A;
        int extra_B = B_count - B;

        // Replace extra A's with B's from the right
        for (int i = length - 1; extra_A > 0 && i >= 0; i--) {
            if (substring[i] == 'A') {
                substring[i] = 'B';
                extra_A--;
            }
        }

        // Replace extra B's with A's from the left
        for (int i = 0; extra_B > 0 && i < length; i++) {
            if (substring[i] == 'B') {
                substring[i] = 'A';
                extra_B--;
            }
        }
    }

    // Null-terminate the substring
    substring[length] = '\0';

    return substring;
}

int main() {
    int Q;
    scanf("%d", &Q);

    // Process each query
    for (int i = 0; i < Q; i++) {
        int A, B, C, D;
        scanf("%d %d %d %d", &A, &B, &C, &D);

        // Find the substring and print it
        char* substring = findSubstring(A, B, C, D);
        printf("%s\n", substring);

        // Free the allocated memory
        free(substring);
    }

    return 0;
}