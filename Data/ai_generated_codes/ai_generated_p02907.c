#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the modular inverse
long long mod_inverse(long long a, long long m) {
    long long m0 = m, y = 0, x = 1;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) {
        x += m0;
    }
    return x;
}

// Function to calculate the expected value
long long expected_value(long long* A, long long* B, int N) {
    long long S = 0;
    for (int i = 0; i < N; i++) {
        S += A[i];
    }

    // Create a dp table to store the expected values for each state
    long long** dp = (long long**)malloc(sizeof(long long*) * (N + 1));
    for (int i = 0; i <= N; i++) {
        dp[i] = (long long*)malloc(sizeof(long long) * (401));
        for (int j = 0; j <= 400; j++) {
            dp[i][j] = 0;
        }
    }

    // Initialize the base case
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    // Iterate over each state
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 400; j++) {
            for (int k = 0; k < N; k++) {
                // If the current integer has not been generated enough times
                if (j - B[k] >= 0) {
                    // Add the expected value of the previous state
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - B[k]] * A[k] % MOD) % MOD;
                }
            }
        }
    }

    // Calculate the expected value
    long long expected = dp[N][400];
    long long inverse_S = mod_inverse(S, MOD);
    expected = (expected * inverse_S) % MOD;

    // Free the dp table
    for (int i = 0; i <= N; i++) {
        free(dp[i]);
    }
    free(dp);

    return expected;
}

int main() {
    int N;
    scanf("%d", &N);

    long long* A = (long long*)malloc(sizeof(long long) * N);
    long long* B = (long long*)malloc(sizeof(long long) * N);

    // Read the input
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &A[i], &B[i]);
    }

    // Calculate the expected value and print the result
    printf("%lld\n", expected_value(A, B, N));

    free(A);
    free(B);

    return 0;
}