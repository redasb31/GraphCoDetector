#include <stdio.h>
#include <string.h>

#define MOD 998244353

long long fact[100001];
long long invfact[100001];

// Calculate factorial and its inverse modulo MOD
void precompute_factorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[n] = 1;
    for (int i = n; i > 0; i--) {
        invfact[i - 1] = (invfact[i] * i) % MOD;
    }
}

// Calculate nCr modulo MOD using precomputed factorials
long long nCr(int n, int r) {
    if (r < 0 || r > n) {
        return 0;
    }
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}

int main() {
    int n;
    char s[100001];

    scanf("%d", &n);
    scanf("%s", s);

    precompute_factorials(3 * n);

    // Calculate the number of ways to distribute red balls
    int red_count = 0;
    for (int i = 0; i < 3 * n; i++) {
        if (s[i] == 'R') {
            red_count++;
        }
    }
    long long ways_red = nCr(red_count, n);

    // Calculate the number of ways to distribute blue and green balls
    // after distributing red balls
    long long ways_blue_green = 1;
    for (int i = 1; i <= n; i++) {
        ways_blue_green = (ways_blue_green * i) % MOD;
    }

    // Calculate the total number of ways to distribute balls
    long long total_ways = (ways_red * ways_blue_green) % MOD;

    printf("%lld\n", total_ways);

    return 0;
}