#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(long long n) {
    long long fact = 1;
    for (long long i = 2; i <= n; i++) {
        fact = (fact * i) % MOD;
    }
    return fact;
}

// Function to calculate nCk modulo MOD
long long nCk(long long n, long long k) {
    if (k > n) {
        return 0;
    }
    return (factorial(n) * (long long)1 / (factorial(k) * factorial(n - k))) % MOD;
}

int main() {
    long long N, K;
    scanf("%lld %lld", &N, &K);

    long long *a = (long long *)malloc(K * sizeof(long long));
    long long product = 1;

    for (long long i = 0; i < K; i++) {
        scanf("%lld", &a[i]);
        product = (product * nCk(N, a[i])) % MOD;
    }

    long long expectedHappiness = 1;
    for (long long i = 0; i < K; i++) {
        expectedHappiness = (expectedHappiness * (a[i] * (N - a[i]))) % MOD;
    }

    long long result = (expectedHappiness * product) % MOD;

    printf("%lld\n", result);

    free(a);

    return 0;
}