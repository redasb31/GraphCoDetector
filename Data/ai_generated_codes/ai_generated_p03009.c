#include <stdio.h>
#define MOD 1000000007

// Function to calculate the number of ways to add blocks to a square
long long count_ways(int min, int max, int d) {
    // If the range is empty, there are no ways
    if (min > max) {
        return 0;
    }
    // If the range is a single value, there is one way
    if (min == max) {
        return 1;
    }
    // Recursively calculate the number of ways for each possible addition
    long long ways = 0;
    for (int i = min; i <= max; i++) {
        ways = (ways + count_ways(min, i - 1, d)) % MOD;
    }
    return ways;
}

int main() {
    int n, h, d;
    scanf("%d %d %d", &n, &h, &d);

    // Initialize the number of ways to 1 (all squares start with 0 blocks)
    long long ways = 1;

    // Calculate the number of ways for each square
    for (int i = 0; i < n; i++) {
        ways = (ways * count_ways(0, h - i, d)) % MOD;
    }

    printf("%lld\n", ways);

    return 0;
}