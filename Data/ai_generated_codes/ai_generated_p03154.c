#include <stdio.h>

#define MOD 1000000007

long long int fast_pow(long long int base, long long int exp) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

long long int comb(long long int n, long long int k) {
    if (k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    long long int numerator = 1, denominator = 1;
    for (long long int i = n; i > n - k; i--) {
        numerator = (numerator * i) % MOD;
    }
    for (long long int i = 1; i <= k; i++) {
        denominator = (denominator * i) % MOD;
    }
    return (numerator * fast_pow(denominator, MOD - 2)) % MOD;
}

int main() {
    long long int H, W, K;
    scanf("%lld %lld %lld", &H, &W, &K);

    long long int total_cuts = H + W;
    long long int score_sum = 0;

    // Calculate the score sum using the combination formula
    for (long long int i = 1; i <= K; i++) {
        // Number of ways to choose i cuts out of total_cuts
        long long int combinations = comb(total_cuts, i);
        // Each cut adds i + 1 pieces
        long long int score_for_i_cuts = combinations * (i + 1) % MOD;
        score_sum = (score_sum + score_for_i_cuts) % MOD;
    }

    printf("%lld\n", score_sum);
    return 0;
}