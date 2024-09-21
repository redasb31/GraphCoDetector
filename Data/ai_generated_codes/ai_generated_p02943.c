#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to find the lexicographically smallest substring of length N in the concatenated string
char *findSmallestSubstring(char *str, int N) {
    int len = strlen(str);
    char *smallestSubstring = malloc(N + 1); // Allocate memory for the substring

    // Initialize the smallestSubstring with the first N characters of the concatenated string
    strncpy(smallestSubstring, str, N);
    smallestSubstring[N] = '\0';

    // Iterate over all possible substrings of length N
    for (int i = 1; i <= len - N; i++) {
        char *currentSubstring = str + i;
        if (strcmp(currentSubstring, smallestSubstring) < 0) {
            strncpy(smallestSubstring, currentSubstring, N);
            smallestSubstring[N] = '\0';
        }
    }

    return smallestSubstring;
}

int main() {
    int N, K;
    scanf("%d %d\n", &N, &K);

    char S[5001];
    scanf("%s\n", S);

    // Perform K operations
    for (int i = 0; i < K; i++) {
        // Reverse the string S
        reverseString(S, 0, N - 1);

        // Concatenate S and the reversed string T
        char U[10001];
        strcpy(U, S);
        strcat(U, S);

        // Find the lexicographically smallest substring of length N in U
        char *smallestSubstring = findSmallestSubstring(U, N);

        // Update S with the smallestSubstring
        strcpy(S, smallestSubstring);

        // Free the allocated memory for the smallestSubstring
        free(smallestSubstring);
    }

    // Print the final string S
    printf("%s\n", S);

    return 0;
}