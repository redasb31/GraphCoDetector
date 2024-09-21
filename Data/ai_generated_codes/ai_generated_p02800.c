#include <stdio.h>
#include <string.h>

#define MOD 998244353

// Function to calculate the number of ways to paint the grid
long long countWays(int H, int W, char A[][W]) {
    // Initialize dp[i][j][k][l] to store the number of ways to paint the grid
    // where the first i rows and j columns are painted,
    // the i-th row is painted with color k (0 for white, 1 for black),
    // and the j-th column is painted with color l (0 for white, 1 for black).
    long long dp[H + 1][W + 1][2][2] = {0};
    dp[0][0][0][0] = 1;

    // Iterate over each row
    for (int i = 0; i <= H; i++) {
        // Iterate over each column
        for (int j = 0; j <= W; j++) {
            // Iterate over the color of the current row
            for (int k = 0; k <= 1; k++) {
                // Iterate over the color of the current column
                for (int l = 0; l <= 1; l++) {
                    // If we are not at the first row or column,
                    // we can transition from the previous row or column.
                    if (i > 0 && j > 0) {
                        // Transition from the previous row
                        dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k][l]) % MOD;
                        // Transition from the previous column
                        dp[i][j][k][l] = (dp[i][j][k][l] + dp[i][j - 1][k][l]) % MOD;
                    }

                    // If we are at a row or column that is not the first,
                    // we need to check if the current row or column is painted with the correct color.
                    if (i > 0) {
                        if (k == 0 && A[i - 1][j] == '#') {
                            // If the current row is white but the previous row is black,
                            // we cannot transition from the previous row.
                            dp[i][j][k][l] = 0;
                        } else if (k == 1 && A[i - 1][j] == '.') {
                            // If the current row is black but the previous row is white,
                            // we cannot transition from the previous row.
                            dp[i][j][k][l] = 0;
                        }
                    }
                    if (j > 0) {
                        if (l == 0 && A[i][j - 1] == '#') {
                            // If the current column is white but the previous column is black,
                            // we cannot transition from the previous column.
                            dp[i][j][k][l] = 0;
                        } else if (l == 1 && A[i][j - 1] == '.') {
                            // If the current column is black but the previous column is white,
                            // we cannot transition from the previous column.
                            dp[i][j][k][l] = 0;
                        }
                    }
                }
            }
        }
    }

    // Return the total number of ways to paint the grid.
    return dp[H][W][0][0] + dp[H][W][0][1] + dp[H][W][1][0] + dp[H][W][1][1];
}

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char A[H][W];
    for (int i = 0; i < H; i++) {
        scanf("%s", A[i]);
    }
    printf("%lld\n", countWays(H, W, A));
    return 0;
}