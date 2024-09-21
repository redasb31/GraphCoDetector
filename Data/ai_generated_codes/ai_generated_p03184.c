#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the number of paths from (1, 1) to (H, W)
long long countPaths(int H, int W, int N, int **walls) {
    // Create a 2D array to store the number of paths to each cell
    long long **dp = (long long **)malloc(sizeof(long long *) * (H + 1));
    for (int i = 0; i <= H; i++) {
        dp[i] = (long long *)malloc(sizeof(long long) * (W + 1));
    }

    // Initialize dp[1][1] to 1 as there is only one path to reach (1, 1)
    dp[1][1] = 1;

    // Iterate over all cells in the grid
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            // If the current cell is a wall, skip it
            if (walls[i][j]) {
                continue;
            }

            // Calculate the number of paths to the current cell
            // by adding the number of paths to the cell above and the cell to the left
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    // Return the number of paths to the destination cell (H, W)
    long long result = dp[H][W];

    // Free the allocated memory
    for (int i = 0; i <= H; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);

    // Create a 2D array to store the wall squares
    int **walls = (int **)malloc(sizeof(int *) * (H + 1));
    for (int i = 0; i <= H; i++) {
        walls[i] = (int *)malloc(sizeof(int) * (W + 1));
    }

    // Initialize all squares as empty squares
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            walls[i][j] = 0;
        }
    }

    // Read the coordinates of the wall squares and mark them in the array
    for (int i = 0; i < N; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        walls[r][c] = 1;
    }

    // Calculate and print the number of paths
    long long paths = countPaths(H, W, N, walls);
    printf("%lld\n", paths);

    // Free the allocated memory
    for (int i = 0; i <= H; i++) {
        free(walls[i]);
    }
    free(walls);

    return 0;
}