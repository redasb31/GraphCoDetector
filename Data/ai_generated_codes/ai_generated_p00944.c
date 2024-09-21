#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 50000
#define MAX_M 100000
#define MAX_Q 50000

int n, m, q;
int c[MAX_N + 1];
int adj[MAX_N + 1][11];
int adj_size[MAX_N + 1];

// Function to perform Depth-First Search (DFS) to find candidates for troubled post office
void dfs(int u, int *visited, int *candidates, int *candidate_count, int w) {
    visited[u] = 1;
    candidates[*candidate_count] = u;
    (*candidate_count)++;

    // Iterate over adjacent post offices
    for (int i = 0; i < adj_size[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, visited, candidates, candidate_count, w);
        }
    }
}

// Function to find the lowest-cost candidate for troubled post office
int find_lowest_cost_candidate(int *w, int k) {
    int visited[MAX_N + 1] = {0};
    int candidates[MAX_N + 1];
    int candidate_count = 0;

    // Perform DFS from each post office in the complaint list
    for (int i = 0; i < k; i++) {
        dfs(w[i], visited, candidates, &candidate_count, w[i]);
    }

    // Find the lowest-cost candidate
    int lowest_cost = INT_MAX;
    int lowest_cost_candidate = -1;
    for (int i = 0; i < candidate_count; i++) {
        int u = candidates[i];
        if (c[u] < lowest_cost) {
            lowest_cost = c[u];
            lowest_cost_candidate = u;
        }
    }

    return lowest_cost_candidate;
}

int main() {
    // Read input
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adj_size[u]++] = v;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &q);

    // Process queries
    for (int i = 0; i < q; i++) {
        int k;
        scanf("%d", &k);
        int w[MAX_Q];
        for (int j = 0; j < k; j++) {
            scanf("%d", &w[j]);
        }

        // Find the lowest-cost candidate and print the cost
        int candidate = find_lowest_cost_candidate(w, k);
        printf("%d\n", c[candidate]);
    }

    return 0;
}