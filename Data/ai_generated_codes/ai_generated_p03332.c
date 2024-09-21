#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

long long dp[300001][3]; // dp[i][j] is the number of ways to paint the first i layers with beauty j, where j = 0, A, or A+B
long long a, b;

// Function to calculate the number of ways to paint the tower with beauty K
long long solve(int n, long long k) {
    // Base case: no layers
    if (n == 0) {
        return (k == 0);
    }

    // If we have already calculated the result, return it
    if (dp[n][k % 3] != -1) {
        return dp[n][k % 3];
    }

    // Calculate the number of ways to paint the first n layers with beauty k
    long long ways = 0;
    // Case 1: Paint the nth layer red
    if (k >= a) {
        ways = (ways + solve(n - 1, k - a)) % MOD;
    }
    // Case 2: Paint the nth layer green
    if (k >= a + b) {
        ways = (ways + solve(n - 1, k - (a + b))) % MOD;
    }
    // Case 3: Paint the nth layer blue
    if (k >= b) {
        ways = (ways + solve(n - 1, k - b)) % MOD;
    }
    // Case 4: Don't paint the nth layer
    ways = (ways + solve(n - 1, k)) % MOD;

    // Store the result for future use
    return dp[n][k % 3] = ways;
}

int main() {
    int n;
    long long k;

    // Read the input
    scanf("%d %lld %lld %lld", &n, &a, &b, &k);

    // Initialize the dp array with -1
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -1;
        }
    }

    // Calculate the number of ways to paint the tower
    long long ways = solve(n, k);

    // Print the result
    printf("%lld\n", ways);

    return 0;
}