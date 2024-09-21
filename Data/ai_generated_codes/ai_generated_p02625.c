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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the total number of sequences possible
    long long total_sequences = factorial(m);

    // Calculate the number of sequences where A_i = B_i for some i
    long long invalid_sequences = factorial(m - n);

    // Calculate the number of valid sequences
    long long valid_sequences = (total_sequences - invalid_sequences + MOD) % MOD;

    printf("%lld\n", valid_sequences);

    return 0;
}