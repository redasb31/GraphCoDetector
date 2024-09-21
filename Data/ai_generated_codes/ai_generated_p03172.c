#include <stdio.h>

#define MOD 1000000007

// Function to calculate the factorial of n modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate the number of ways to distribute candies
long long countWays(int n, int k, int* a) {
    // Calculate the total number of ways to distribute k candies among n children
    long long totalWays = factorial(k + n - 1) / (factorial(k) * factorial(n - 1));

    // Calculate the number of ways to distribute candies violating the constraints
    long long invalidWays = 0;
    for (int i = 0; i < n; i++) {
        // If a_i + 1 candies are distributed to child i, the remaining k - (a_i + 1) candies can be distributed in any way
        invalidWays += (factorial(k - (a_i + 1) + n - 1) / (factorial(k - (a_i + 1)) * factorial(n - 1)));
        invalidWays %= MOD;
    }

    // Calculate the number of valid ways
    long long validWays = (totalWays - invalidWays + MOD) % MOD;
    return validWays;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long ways = countWays(n, k, a);
    printf("%lld\n", ways);

    return 0;
}