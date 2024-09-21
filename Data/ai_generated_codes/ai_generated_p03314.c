#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the factorial of n modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate the modular inverse of n modulo MOD
long long modInverse(long long n) {
    long long result = 1;
    long long power = MOD - 2;
    while (power > 0) {
        if (power & 1) {
            result = (result * n) % MOD;
        }
        n = (n * n) % MOD;
        power >>= 1;
    }
    return result;
}

// Function to calculate the number of ways to choose r elements from n
long long choose(int n, int r) {
    if (r > n) {
        return 0;
    }
    return (factorial(n) * modInverse(factorial(r)) % MOD * modInverse(factorial(n - r)) % MOD);
}

// Function to count the number of colorful sequences containing the given subsequence
long long countColorfulSequences(int n, int k, int m, int *a) {
    long long count = 0;

    // Calculate the number of ways to choose K positions for the subsequence
    long long waysToChooseK = choose(n, k);

    // Calculate the number of ways to fill the remaining positions
    long long waysToFillRemaining = factorial(n - k);

    // Calculate the number of colorful sequences containing the subsequence
    count = (waysToChooseK * waysToFillRemaining) % MOD;

    // Check if the subsequence is valid
    int i = 0;
    int j = 0;
    int found[k + 1];
    memset(found, 0, sizeof(found));
    while (i < m && j < k) {
        if (found[a[i]] == 0) {
            found[a[i]] = 1;
            j++;
        }
        i++;
    }

    // If the subsequence is valid, adjust the count accordingly
    if (j == k) {
        count = (count * (k - m + 1)) % MOD;
    }

    return count;
}

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    int *a = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    long long total = 0;

    // Iterate over all colorful sequences of length N
    for (int i = 0; i < k; i++) {
        long long count = countColorfulSequences(n, k, m, a);
        total = (total + count) % MOD;
    }

    printf("%lld\n", total);

    free(a);
    return 0;
}