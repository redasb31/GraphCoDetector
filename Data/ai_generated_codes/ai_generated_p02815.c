#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int calculateSum(int N, int *C) {
    long long int sum = 0;
    long long int cost = 0;
    long long int power2 = 1;
    for (int i = 0; i < N; i++) {
        // Calculate the cost of changing the i-th element
        cost = (power2 * C[i]) % MOD;
        // Add the cost to the sum
        sum = (sum + cost) % MOD;
        // Update power2 for the next iteration
        power2 = (power2 * 2) % MOD;
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    int *C = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    // Calculate the sum of f(S, T) for all pairs (S, T)
    long long int result = calculateSum(N, C);
    // Print the result modulo (10^9+7)
    printf("%lld\n", result);

    free(C);
    return 0;
}