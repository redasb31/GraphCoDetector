#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int n, m, q;
int graph[MAX_N][MAX_N]; // Adjacency matrix to represent the network
int visited[MAX_N]; // Array to keep track of visited nodes during DFS

// Depth-First Search to explore the connected component of a node
void dfs(int start) {
    visited[start] = 1; // Mark the starting node as visited
    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) { // If there's an edge to an unvisited node
            dfs(i); // Explore the connected component recursively
        }
    }
}

// Function to check if two nodes are reachable
int is_reachable(int s, int t) {
    // Reset visited nodes for each query
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(s); // Explore the connected component of node s
    return visited[t]; // Return true if node t was visited (reachable)
}

int main() {
    scanf("%d %d", &n, &m); // Read the number of users and relations

    // Initialize the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; // Initialize all connections to 0 (no connection)
        }
    }

    // Read the relations and update the adjacency matrix
    for (int i = 0; i < m; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        graph[s][t] = 1; // Mark connection between s and t
        graph[t][s] = 1; // Undirected graph: connection in both directions
    }

    scanf("%d", &q); // Read the number of queries

    // Process each query
    for (int i = 0; i < q; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        if (is_reachable(s, t)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}