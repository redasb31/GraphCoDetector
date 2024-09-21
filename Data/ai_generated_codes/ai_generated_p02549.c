#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the number of ways to reach Cell N
long long int count_ways(int N, int K, int *L, int *R) {
    // Create a dp array to store the number of ways to reach each cell
    long long int *dp = (long long int *)malloc(sizeof(long long int) * (N + 1));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize the dp array
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = 0;
    }

    // Iterate over each segment
    for (int i = 0; i < K; i++) {
        // Iterate over each cell within the segment
        for (int j = L[i]; j <= R[i]; j++) {
            // Update the dp array for the current cell
            if (j >= i + 1) {
                dp[j] = (dp[j] + dp[j - L[i]]) % MOD;
            }
        }
    }

    // Return the number of ways to reach Cell N
    long long int ways = dp[N];
    free(dp);
    return ways;
}

int main() {
    // Read the input values
    int N, K;
    scanf("%d %d", &N, &K);

    // Allocate memory for the segments
    int *L = (int *)malloc(sizeof(int) * K);
    int *R = (int *)malloc(sizeof(int) * K);
    if (L == NULL || R == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Read the segments
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &L[i], &R[i]);
    }

    // Calculate the number of ways to reach Cell N
    long long int ways = count_ways(N, K, L, R);

    // Print the result
    printf("%lld\n", ways);

    // Free the allocated memory
    free(L);
    free(R);

    return 0;
}