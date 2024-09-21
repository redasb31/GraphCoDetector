#include <stdio.h>
#include <string.h>

#define MAX_N 20
#define MAX_LEN (1 << MAX_N)

int N, K;
char X[MAX_N + 1][MAX_LEN];
int count[MAX_LEN + 1];

// Check if string 's' is a subsequence of string 't'
int is_subsequence(char *s, char *t) {
    int i = 0, j = 0;
    while (i < strlen(s) && j < strlen(t)) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == strlen(s);
}

// Find the lexicographically smallest longest subsequence
void find_longest_subsequence() {
    // Initialize count array to 0
    memset(count, 0, sizeof(count));

    // Iterate over all possible subsequences
    for (int i = 0; i < (1 << (N + 1)); i++) {
        char subsequence[MAX_LEN + 1] = {0};
        int len = 0;
        // Construct the subsequence based on the binary representation of i
        for (int j = 0; j <= N; j++) {
            if (i & (1 << j)) {
                subsequence[len++] = X[j][(i >> (j + 1)) & ((1 << (j + 1)) - 1)];
            }
        }

        // Count the number of strings in S that have this subsequence
        for (int j = 0; j <= N; j++) {
            if (is_subsequence(subsequence, X[j])) {
                count[len]++;
            }
        }
    }

    // Find the longest subsequence with at least K occurrences
    int max_len = 0;
    for (int i = MAX_LEN; i >= 0; i--) {
        if (count[i] >= K) {
            max_len = i;
            break;
        }
    }

    // Iterate over all possible subsequences of length max_len
    for (int i = 0; i < (1 << (N + 1)); i++) {
        char subsequence[MAX_LEN + 1] = {0};
        int len = 0;
        for (int j = 0; j <= N; j++) {
            if (i & (1 << j)) {
                subsequence[len++] = X[j][(i >> (j + 1)) & ((1 << (j + 1)) - 1)];
            }
        }
        if (len == max_len && count[len] >= K) {
            // Print the lexicographically smallest subsequence
            printf("%s\n", subsequence);
            return;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i <= N; i++) {
        scanf("%s", X[i]);
    }

    find_longest_subsequence();

    return 0;
}