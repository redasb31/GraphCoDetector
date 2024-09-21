#include <stdio.h>
#include <string.h>

#define MAX_LEN 300

// Function to calculate the length of the longest common subsequence (LCS)
int lcs(char *s1, char *s2, int len) {
    int dp[MAX_LEN + 1][MAX_LEN + 1]; // DP table for LCS calculation

    // Initialize DP table
    for (int i = 0; i <= len; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= len; j++) {
        dp[0][j] = 0;
    }

    // Fill the DP table using the recursive formula
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // Return the length of the LCS
    return dp[len][len];
}

int main() {
    char s[MAX_LEN + 1];
    int k;

    // Read input string and K
    scanf("%s", s);
    scanf("%d", &k);

    int len = strlen(s);

    // Create a reversed string
    char reversed_s[MAX_LEN + 1];
    for (int i = 0; i < len; i++) {
        reversed_s[i] = s[len - i - 1];
    }
    reversed_s[len] = '\0';

    // Calculate the initial value
    int max_value = lcs(s, reversed_s, len);

    // Try changing characters to maximize the value
    for (int i = 0; i < len; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            // If the current character is already the optimal character, skip it
            if (s[i] == c) {
                continue;
            }

            // Temporarily change the character
            char temp = s[i];
            s[i] = c;

            // Calculate the value with the changed character
            int value = lcs(s, reversed_s, len);

            // Update the maximum value if necessary
            if (value > max_value) {
                max_value = value;
            }

            // Restore the original character
            s[i] = temp;
        }
    }

    // Print the highest possible value
    printf("%d\n", max_value);

    return 0;
}