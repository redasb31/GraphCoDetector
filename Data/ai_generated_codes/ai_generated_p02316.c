/*
 *  Knapsack Problem: Find the maximum total value of items in a knapsack.
 *
 *  Input:
 *      N W
 *      v1 w1
 *      v2 w2
 *      ...
 *      vN wN
 *
 *  Output:
 *      The maximum total value of the items in the knapsack.
 *
 *  Constraints:
 *      1 ≤ N ≤ 100
 *      1 ≤ vi ≤ 1000
 *      1 ≤ wi ≤ 1000
 *      1 ≤ W ≤ 10000
 *
 *  Example Input:
 *      4 8
 *      4 2
 *      5 2
 *      2 1
 *      8 3
 *
 *  Example Output:
 *      21
 */

#include <stdio.h>

int main() {
    int N, W; // Number of items and knapsack capacity
    int v[101], w[101]; // Value and weight of each item
    int dp[101][10001]; // DP table to store maximum value for each capacity
    int i, j;

    // Read input
    scanf("%d %d", &N, &W);
    for (i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }

    // Initialize DP table
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill DP table using dynamic programming
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= W; j++) {
            // If the current item's weight is less than or equal to the current capacity
            if (w[i] <= j) {
                // Take the maximum of:
                //  - Value of the previous state (without including current item)
                //  - Value of including current item (previous state + current item value)
                dp[i][j] =  dp[i - 1][j] > dp[i - 1][j - w[i]] + v[i] ? dp[i - 1][j] : dp[i - 1][j - w[i]] + v[i];
            } else {
                // If the current item's weight is greater than the current capacity,
                // just use the value from the previous state.
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Print the maximum value
    printf("%d\n", dp[N][W]);

    return 0;
}