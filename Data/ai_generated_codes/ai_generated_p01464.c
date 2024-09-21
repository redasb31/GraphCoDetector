#include <stdio.h>
#include <stdbool.h>

#define MAX_N 200
#define MAX_M 20000

// Adjacency list representation of the graph
int adj[MAX_N + 1][MAX_M + 1];
int degree[MAX_N + 1];

// Depth-first search to check for cycles and components
void dfs(int v, int parent, int* visited, int* stack, bool* has_cycle, int* component_size) {
    visited[v] = 1;
    stack[v] = 1;
    *component_size += 1;

    for (int i = 1; i <= degree[v]; i++) {
        int u = adj[v][i];
        if (u != parent) {
            if (!visited[u]) {
                dfs(u, v, visited, stack, has_cycle, component_size);
            } else if (stack[u]) {
                *has_cycle = true;
            }
        }
    }

    stack[v] = 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize adjacency list and degree array
    for (int i = 1; i <= N; i++) {
        degree[i] = 0;
    }

    // Read the edges and populate the adjacency list
    for (int i = 1; i <= M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][++degree[u]] = v;
        adj[v][++degree[v]] = u;
    }

    // Check if the graph is "Sunny"
    bool is_sunny = false;

    int visited[MAX_N + 1] = {0};
    int stack[MAX_N + 1] = {0};
    bool has_cycle = false;

    // Perform DFS starting from vertex 1
    int component_size = 0;
    dfs(1, 0, visited, stack, &has_cycle, &component_size);

    // Check if the connected component containing vertex 1 is a cycle of at least 3 vertices
    if (has_cycle && component_size >= 3) {
        // Check if all other components have exactly two vertices
        for (int i = 2; i <= N; i++) {
            if (!visited[i]) {
                component_size = 0;
                dfs(i, 0, visited, stack, &has_cycle, &component_size);
                if (component_size != 2) {
                    is_sunny = false;
                    break;
                }
            }
        }

        if (is_sunny) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    } else {
        printf("No\n");
    }

    return 0;
}