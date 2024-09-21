#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to calculate the power of a number modulo a given number
long long int power(long long int base, long long int exponent) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

// Function to calculate the number of combinations modulo 1,000,000,007
long long int calculateCombinations(long long int N, long long int K) {
    long long int result = 1;
    for (long long int i = 1; i <= N; i++) {
        result = (result * i) % MOD;
    }
    // Calculate the inverse of factorial(N-K) modulo 1,000,000,007
    long long int inverseFactorial = power(result, MOD - 2);
    result = (result * power(N - K, MOD - 2)) % MOD;
    return result;
}

int main() {
    long long int N, K;
    scanf("%lld %lld", &N, &K);

    // Calculate the number of combinations
    long long int combinations = calculateCombinations(N, K);

    // Print the result
    printf("%lld\n", combinations);

    return 0;
}