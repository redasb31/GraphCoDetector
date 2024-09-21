#include <stdio.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate the number of ways to put n balls into k boxes
long long countWays(int n, int k) {
    if (n < k) {
        return 0;
    }

    // Calculate the number of ways to put n balls into k boxes without the constraint of at least one ball per box
    long long ways = factorial(n - 1) / (factorial(k - 1) * factorial(n - k));

    // Subtract the number of ways to put n balls into k boxes with some boxes empty
    long long emptyBoxes = 0;
    for (int i = 1; i <= k - 1; i++) {
        emptyBoxes = (emptyBoxes + factorial(n) / (factorial(i) * factorial(n - i))) % MOD;
    }
    ways = (ways - emptyBoxes + MOD) % MOD;

    return ways;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%lld\n", countWays(n, k));

    return 0;
}