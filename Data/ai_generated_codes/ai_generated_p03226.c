#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate factorial modulo 998244353
long long factorial_mod(long long n) {
    long long result = 1;
    for (long long i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to calculate the number of valid permutations
long long count_permutations(int *a, int n) {
    int *count = (int *)calloc(n + 1, sizeof(int));
    int *cycle_size = (int *)calloc(n + 1, sizeof(int));
    int *visited = (int *)calloc(n + 1, sizeof(int));

    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    // Calculate the size of each cycle
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int current = i;
            cycle_size[i]++;
            visited[i] = 1;
            while (a[current - 1] != i) {
                current = a[current - 1];
                cycle_size[i]++;
                visited[current] = 1;
            }
        }
    }

    // Calculate the number of permutations
    long long result = factorial_mod(n);
    for (int i = 1; i <= n; i++) {
        if (cycle_size[i] > 1) {
            result = (result * factorial_mod(cycle_size[i] - 1)) % MOD;
        }
    }

    free(count);
    free(cycle_size);
    free(visited);

    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long answer = count_permutations(a, n);
    printf("%lld\n", answer);

    free(a);

    return 0;
}