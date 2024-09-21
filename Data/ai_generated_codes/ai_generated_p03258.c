#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of strings that can be obtained
long long countStrings(char *s) {
    int n = strlen(s);
    long long dp[n + 1][2] = {0}; // dp[i][0] represents the number of strings with 'a' at the ith position, dp[i][1] represents the number of strings with 'b' at the ith position

    // Base case:
    dp[0][0] = 1; // Empty string can be obtained with 'a'
    dp[0][1] = 1; // Empty string can be obtained with 'b'

    // Iterate through the string
    for (int i = 1; i <= n; i++) {
        // If the current character is 'a'
        if (s[i - 1] == 'a') {
            // We can obtain a string with 'a' at the current position
            // from the previous string with 'a' or 'b'
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            // We can obtain a string with 'b' at the current position
            // only from the previous string with 'a'
            dp[i][1] = dp[i - 1][0];
        } else { // If the current character is 'b'
            // We can obtain a string with 'b' at the current position
            // from the previous string with 'a' or 'b'
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            // We can obtain a string with 'a' at the current position
            // only from the previous string with 'b'
            dp[i][0] = dp[i - 1][1];
        }
    }

    // Return the total number of strings
    return (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
    char s[100005];
    scanf("%s", s);

    // Calculate and print the number of strings
    printf("%lld\n", countStrings(s));

    return 0;
}