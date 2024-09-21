#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
    int a;
    int b;
} Pair;

// Function to find the connected components using Depth First Search (DFS)
void dfs(int node, int* visited, int* component, int** adj, int n) {
    visited[node] = 1;
    component[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, visited, component, adj, n);
        }
    }
}

// Function to count the number of essentially different characters
int count_characters(int n, Pair* pairs, int m) {
    // Create an adjacency matrix to represent the connections between attributes
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }

    // Fill the adjacency matrix based on the special pairs
    for (int i = 0; i < m; i++) {
        adj[pairs[i].a - 1][pairs[i].b - 1] = 1;
        adj[pairs[i].b - 1][pairs[i].a - 1] = 1;
    }

    // Initialize arrays to track visited nodes and connected components
    int* visited = (int*)calloc(n, sizeof(int));
    int* component = (int*)calloc(n, sizeof(int));
    int components = 0;

    // Perform DFS to find connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, component, adj, n);
            components++;
        }
    }

    // Calculate the number of essentially different characters
    long long count = 1;
    for (int i = 0; i < components; i++) {
        count = (count * 3) % MOD;
    }

    // Free allocated memory
    free(visited);
    free(component);
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return (int)count;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)) {
        Pair* pairs = (Pair*)malloc(m * sizeof(Pair));
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &pairs[i].a, &pairs[i].b);
        }

        // Calculate and print the number of essentially different characters
        int count = count_characters(n, pairs, m);
        printf("%d\n", count);

        free(pairs);
    }

    return 0;
}