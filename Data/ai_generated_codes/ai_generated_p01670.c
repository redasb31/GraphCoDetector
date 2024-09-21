#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000
#define MAX_M 30000

int n, m, k;
int graph[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1];

int dfs(int node, int count) {
  visited[node] = 1;

  // Explore all connected nodes
  for (int i = 1; i <= n; i++) {
    if (graph[node][i] == 1 && !visited[i]) {
      count = dfs(i, count);
    }
  }

  // If a connected component is explored, increase the count
  if (count == 0) {
    return 1;
  } else {
    return count;
  }
}

int main() {
  // Input: N (number of islands), M (number of liners), K (maximum quarantine stations)
  scanf("%d %d %d", &n, &m, &k);

  // Initialize the graph to represent ocean liners
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      graph[i][j] = 0;
    }
  }

  // Read liner connections
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a][b] = 1;
    graph[b][a] = 1; // Undirected graph
  }

  // Initialize visited array
  for (int i = 1; i <= n; i++) {
    visited[i] = 0;
  }

  // Calculate the minimum number of quarantine stations
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      count += dfs(i, 0);
    }
  }

  // Check if the objective is achievable
  if (count <= k) {
    printf("%d\n", count);
  } else {
    printf("Impossible\n");
  }

  return 0;
}