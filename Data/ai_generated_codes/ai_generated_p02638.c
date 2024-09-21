#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

// Function to calculate the factorial of a number modulo P
long long factorial(long long n, long long p) {
    long long result = 1;
    for (long long i = 2; i <= n; ++i) {
        result = (result * i) % p;
    }
    return result;
}

// Function to calculate the binomial coefficient (n choose k) modulo P
long long binomial(long long n, long long k, long long p) {
    if (k < 0 || k > n) {
        return 0;
    }
    return (factorial(n, p) * ((factorial(k, p) * factorial(n - k, p)) % p)) % p;
}

// Function to calculate the number of directed graphs satisfying the conditions
long long count_graphs(long long n, long long k, long long p) {
    long long count = 0;
    // Iterate over the possible in-degrees of the first vertex
    for (long long i = 0; i <= k; ++i) {
        // Calculate the number of graphs with the current in-degree
        long long current_count = binomial(n - 1, i, p);
        // Iterate over the possible in-degrees of the remaining vertices
        for (long long j = 0; j <= k; ++j) {
            // Calculate the number of graphs with the current in-degree
            long long current_count2 = binomial(n - 2, j, p);
            // Calculate the number of graphs with the current in-degree and the forbidden subgraphs removed
            current_count2 = (current_count2 * current_count) % p;
            // Add the count to the total
            count = (count + current_count2) % p;
        }
    }
    // Return the total count
    return count;
}

int main() {
    long long n, k, p;
    // Read the input
    scanf("%lld %lld %lld", &n, &k, &p);
    // Calculate the number of graphs
    long long result = count_graphs(n, k, p);
    // Print the result
    printf("%lld\n", result);
    return 0;
}