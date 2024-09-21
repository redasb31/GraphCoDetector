#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

long long int mod_pow(long long int base, long long int exponent) {
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

long long int mod_inverse(long long int a) {
    return mod_pow(a, MOD - 2);
}

int main() {
    int N;
    char s[1001];

    scanf("%d\n", &N);
    scanf("%s", s);

    // Calculate the number of occupied sections in the string
    int occupied_count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'X') {
            occupied_count++;
        }
    }

    // Calculate the probability of a section being occupied
    long long int p = (occupied_count * mod_inverse(N)) % MOD;

    // Calculate the probability of a section being unoccupied
    long long int q = (mod_inverse(N) - p + MOD) % MOD;

    // Calculate the probability of a section being occupied and its neighbors being unoccupied
    long long int r = 0;
    for (int i = 1; i < N - 1; i++) {
        if (s[i] == 'X' && s[i - 1] == '-' && s[i + 1] == '-') {
            r = (r + mod_inverse(N)) % MOD;
        }
    }

    // Calculate the probability of the entire string
    long long int e_sq = mod_pow(2, MOD - 2); // e^2 mod 10^9 + 7
    long long int e_cub = (e_sq * 2) % MOD; // e^3 mod 10^9 + 7

    // Calculate p, q, and r modulo 10^9 + 7
    long long int p_mod = (p * e_cub) % MOD;
    long long int q_mod = (q * e_sq) % MOD;
    long long int r_mod = (r * e_sq) % MOD;

    // Print the results
    printf("%lld %lld %lld\n", p_mod, q_mod, r_mod);

    return 0;
}