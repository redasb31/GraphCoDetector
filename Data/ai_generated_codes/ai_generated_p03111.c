#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum MP needed to achieve the objective
int min_mp(int N, int A, int B, int C, int *l) {
    // Create a 2D array to store the minimum MP needed for each combination of bamboos
    int dp[N + 1][A + 1][B + 1][C + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= A; j++) {
            for (int k = 0; k <= B; k++) {
                for (int m = 0; m <= C; m++) {
                    dp[i][j][k][m] = 1000000; // Initialize with a large value
                }
            }
        }
    }

    // Base case: no bamboos, no MP needed
    dp[0][0][0][0] = 0;

    // Iterate over each bamboo
    for (int i = 1; i <= N; i++) {
        // Iterate over all possible lengths for each bamboo
        for (int j = 0; j <= A; j++) {
            for (int k = 0; k <= B; k++) {
                for (int m = 0; m <= C; m++) {
                    // Don't use the current bamboo
                    dp[i][j][k][m] = dp[i - 1][j][k][m];

                    // Use Extension Magic
                    if (j >= l[i - 1]) {
                        dp[i][j][k][m] = min(dp[i][j][k][m], dp[i - 1][j - l[i - 1]][k][m] + 1);
                    }

                    // Use Shortening Magic
                    if (l[i - 1] >= 2 && j >= l[i - 1] - 1) {
                        dp[i][j][k][m] = min(dp[i][j][k][m], dp[i - 1][j - (l[i - 1] - 1)][k][m] + 1);
                    }

                    // Use Composition Magic
                    if (k >= l[i - 1] && m >= j - l[i - 1]) {
                        dp[i][j][k][m] = min(dp[i][j][k][m], dp[i - 1][j - l[i - 1]][k - l[i - 1]][m] + 10);
                    }
                }
            }
        }
    }

    // Return the minimum MP needed to achieve the objective
    return dp[N][A][B][C];
}

int main() {
    int N, A, B, C;
    scanf("%d %d %d %d", &N, &A, &B, &C);

    // Read the lengths of the bamboos
    int *l = (int *) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &l[i]);
    }

    // Calculate and print the minimum MP needed
    int min_mp_needed = min_mp(N, A, B, C, l);
    printf("%d\n", min_mp_needed);

    free(l);

    return 0;
}