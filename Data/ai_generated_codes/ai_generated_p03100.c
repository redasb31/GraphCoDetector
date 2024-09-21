#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50000
#define MAX_M 50000
#define MAX_Q 50000

typedef struct Edge {
    int to;
    int cost;
    struct Edge *next;
} Edge;

Edge *adj[MAX_N + 1];
int N, M, Q, MOD;

// Function to add an edge to the graph
void add_edge(int from, int to, int cost) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->to = to;
    new_edge->cost = cost;
    new_edge->next = adj[from];
    adj[from] = new_edge;
}

// Function to perform a Depth-First Search (DFS) to check if a path exists with a specific length
int dfs(int u, int t, int r, int len) {
    // Check if we have reached the target vertex with the required length
    if (u == t && len == r) {
        return 1;
    }

    // Iterate through adjacent vertices
    for (Edge *e = adj[u]; e != NULL; e = e->next) {
        // Calculate the length of the path using the given formula
        int new_len = (len * 2 + e->cost) % MOD;
        // Recursively call DFS for the adjacent vertex
        if (dfs(e->to, t, r, new_len)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    // Read input from standard input
    scanf("%d %d %d %d", &N, &M, &Q, &MOD);

    // Initialize adjacency list
    for (int i = 1; i <= N; i++) {
        adj[i] = NULL;
    }

    // Read edges and add them to the graph
    for (int i = 0; i < M; i++) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        add_edge(A, B, C);
        add_edge(B, A, C);
    }

    // Process each query
    for (int i = 0; i < Q; i++) {
        int S, T, R;
        scanf("%d %d %d", &S, &T, &R);

        // Perform DFS to check if a path exists with the required length
        if (dfs(S, T, R, 0)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}