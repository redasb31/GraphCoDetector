#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MOD 1000000007

typedef struct Edge {
  int u;
  int v;
  int s;
} Edge;

// Function to add an edge to the graph
void addEdge(Edge *edges, int *numEdges, int u, int v, int s) {
  edges[*numEdges].u = u;
  edges[*numEdges].v = v;
  edges[*numEdges].s = s;
  (*numEdges)++;
}

// Function to perform Depth First Search (DFS) on the graph
int dfs(int node, int *visited, Edge *edges, int numEdges, int *values) {
  visited[node] = 1;

  // Iterate through all edges connected to the current node
  for (int i = 0; i < numEdges; i++) {
    if (edges[i].u == node) {
      // If the adjacent node is not visited, recursively call DFS
      if (!visited[edges[i].v]) {
        if (dfs(edges[i].v, visited, edges, numEdges, values)) {
          values[node] = edges[i].s - values[edges[i].v];
          return 1;
        }
      } else {
        // If the adjacent node is already visited, check if the edge condition holds
        if (values[node] + values[edges[i].v] != edges[i].s) {
          return 0;
        }
      }
    } else if (edges[i].v == node) {
      // If the adjacent node is not visited, recursively call DFS
      if (!visited[edges[i].u]) {
        if (dfs(edges[i].u, visited, edges, numEdges, values)) {
          values[node] = edges[i].s - values[edges[i].u];
          return 1;
        }
      } else {
        // If the adjacent node is already visited, check if the edge condition holds
        if (values[node] + values[edges[i].u] != edges[i].s) {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  int n, m, u, v, s;
  Edge *edges = malloc(sizeof(Edge) * MAX_N);
  int *visited = malloc(sizeof(int) * (MAX_N + 1));
  int *values = malloc(sizeof(int) * (MAX_N + 1));
  int numEdges = 0;

  // Read input
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &s);
    addEdge(edges, &numEdges, u, v, s);
  }

  // Initialize visited array
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
  }

  // Start DFS from any node
  if (dfs(1, visited, edges, numEdges, values)) {
    // If DFS completes successfully, calculate the number of ways
    long long count = 1;
    for (int i = 2; i <= n; i++) {
      // If a node has a fixed value, it contributes one way
      if (visited[i]) {
        count = (count * 1) % MOD;
      } else {
        // If a node's value is not fixed, it contributes an infinite number of ways
        count = (count * 2) % MOD;
      }
    }
    printf("%lld\n", count);
  } else {
    // If DFS fails, there are no ways to satisfy the condition
    printf("0\n");
  }

  free(edges);
  free(visited);
  free(values);

  return 0;
}