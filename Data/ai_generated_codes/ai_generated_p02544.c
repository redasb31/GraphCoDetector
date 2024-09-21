#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

long long int fact[200001];
long long int inv[200001];

// Function to calculate modular inverse using Fermat's Little Theorem
long long int mod_inverse(long long int a, long long int m) {
    long long int m0 = m, y = 0, x = 1;
    while (a > 1) {
        long long int q = a / m;
        long long int t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

// Function to calculate factorial modulo MOD
long long int factorial(long long int n) {
    if (n == 0)
        return 1;
    return (fact[n] * inv[n]) % MOD;
}

// Function to calculate the expected value of inversions
long long int calculate_expected_value(int n, int k, int* p) {
    long long int expected_value = 0;

    // Calculate the initial number of inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                expected_value++;
            }
        }
    }

    // Iterate over each window of size K
    for (int i = 0; i <= n - k; i++) {
        // Calculate the expected number of inversions within the window
        long long int window_inversions = 0;
        for (int j = i; j < i + k; j++) {
            for (int l = j + 1; l < i + k; l++) {
                if (p[j] > p[l]) {
                    window_inversions++;
                }
            }
        }

        // Add the contribution of the window to the total expected value
        expected_value += (window_inversions * factorial(k - 1)) % MOD;
        expected_value %= MOD;
    }

    // Calculate the total number of permutations
    long long int total_permutations = factorial(n);

    // Calculate the expected value as a fraction and reduce it modulo MOD
    long long int numerator = expected_value * total_permutations;
    long long int denominator = factorial(k);
    long long int result = (numerator * mod_inverse(denominator, MOD)) % MOD;

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* p = (int*)malloc(n * sizeof(int));

    // Read the permutation
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Precalculate factorials and inverses
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = mod_inverse(fact[i], MOD);
    }

    // Calculate and print the expected value
    long long int expected_value = calculate_expected_value(n, k, p);
    printf("%lld\n", expected_value);

    free(p);

    return 0;
}