#include <stdio.h>

#define MOD 1000000007

// Function to calculate the factorial of n modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate the combination of n choose k modulo MOD
long long combination(int n, int k) {
    // Calculate the factorial of n, k, and n-k modulo MOD
    long long fact_n = factorial(n);
    long long fact_k = factorial(k);
    long long fact_n_k = factorial(n - k);

    // Calculate the combination modulo MOD
    long long result = (fact_n * ((fact_k * fact_n_k) % MOD)) % MOD;
    return result;
}

int main() {
    int n, k;

    // Input the number of rooms (n) and the number of moves (k)
    scanf("%d %d", &n, &k);

    // Calculate the number of possible combinations modulo MOD
    long long count = combination(n + k - 1, k);

    // Print the count modulo MOD
    printf("%lld\n", count);

    return 0;
}