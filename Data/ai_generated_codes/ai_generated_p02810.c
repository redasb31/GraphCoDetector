#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the number of ways to cover the land
long long countWays(int n, int x, int* lengths) {
    // Create a DP table to store the number of ways to cover the land up to a certain point
    long long** dp = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (long long*)calloc(x + 1, sizeof(long long));
    }

    // Base case: If there are no sheets, there are no ways to cover the land
    dp[0][0] = 1;

    // Iterate over the sheets
    for (int i = 1; i <= n; i++) {
        // Iterate over the possible starting points of the sheet
        for (int j = 0; j <= x; j++) {
            // If the current point can be covered by the sheet, add the number of ways to cover the land up to the previous point to the current point
            if (j >= lengths[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - lengths[i - 1]]) % MOD;
            }
            // Otherwise, the number of ways to cover the land up to the current point is the same as the number of ways to cover the land up to the previous point
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
        }
    }

    // The answer is the number of ways to cover the whole land
    long long result = dp[n][x];

    // Free the DP table
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    // Read the input
    int n, x;
    scanf("%d %d", &n, &x);

    int* lengths = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &lengths[i]);
    }

    // Calculate and print the answer
    printf("%lld\n", countWays(n, x, lengths));

    // Free the memory
    free(lengths);

    return 0;
}