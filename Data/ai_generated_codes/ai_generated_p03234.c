#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to find the number of connected components in a graph
int count_components(int n, int **edges, int k) {
    // Create a disjoint set data structure
    int *parent = malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Union-find algorithm to connect the components
    for (int i = 0; i < k; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        int pa = parent[a];
        int pb = parent[b];
        if (pa != pb) {
            parent[pa] = pb;
        }
    }

    // Count the number of connected components
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) {
            count++;
        }
    }
    free(parent);
    return count;
}

// Function to calculate the sum of the number of connected components
// for all possible ways to make the remaining N-K pairs
int calculate_sum(int n, int k, int **edges) {
    // Calculate the number of connected components for the already connected pairs
    int initial_components = count_components(2 * n, edges, k);

    // Calculate the number of ways to connect the remaining pairs
    int remaining_pairs = n - k;
    int ways = 1;
    for (int i = 1; i <= remaining_pairs; i++) {
        ways = (ways * (2 * n - 2 * k - 2 * i + 1)) % MOD;
        ways = (ways * (2 * i - 1)) % MOD;
    }

    // Calculate the sum of the number of connected components for all possible ways
    int sum = 0;
    for (int i = 0; i <= remaining_pairs; i++) {
        int components = initial_components + i;
        sum = (sum + components * ways) % MOD;
        ways = (ways * (2 * n - 2 * k - 2 * i + 1)) % MOD;
        ways = (ways * (2 * i + 1)) % MOD;
        ways = (ways * (2 * n - 2 * k - 2 * i)) % MOD;
        ways = (ways * (2 * i + 2)) % MOD;
        ways = (ways * (MOD - 1)) % MOD;
    }

    return sum;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Allocate memory for the edges
    int **edges = malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i++) {
        edges[i] = malloc(sizeof(int) * 2);
    }

    // Read the already connected pairs
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Calculate the sum of the number of connected components
    int sum = calculate_sum(n, k, edges);

    // Print the result
    printf("%d\n", sum);

    // Free the allocated memory
    for (int i = 0; i < k; i++) {
        free(edges[i]);
    }
    free(edges);

    return 0;
}