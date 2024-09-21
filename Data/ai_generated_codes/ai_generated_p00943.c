#include <stdio.h>
#include <limits.h>

#define MAX_JUNCTIONS 40
#define INF INT_MAX

int personnel[MAX_JUNCTIONS];
int graph[MAX_JUNCTIONS][MAX_JUNCTIONS];

int minPersonnel(int start, int goal, int n, int visited[], int currentPersonnel) {
  // Base case: If we reach the goal junction
  if (start == goal) {
    return currentPersonnel;
  }

  // Initialize minimum personnel to infinity
  int min = INF;
  visited[start] = 1; // Mark the current junction as visited

  // Explore all adjacent junctions
  for (int i = 1; i <= n; i++) {
    if (graph[start][i] && !visited[i]) {
      // Calculate personnel required for the adjacent junction
      int adjPersonnel = currentPersonnel + personnel[i];
      // Recursively explore the path from the adjacent junction
      int result = minPersonnel(i, goal, n, visited, adjPersonnel);

      // Update minimum personnel if a shorter path is found
      if (result < min) {
        min = result;
      }
    }
  }

  visited[start] = 0; // Unmark the current junction

  // Return the minimum personnel required
  return min;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Read personnel requirements for each junction
  for (int i = 1; i <= n; i++) {
    scanf("%d", &personnel[i]);
  }

  // Initialize adjacency matrix
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      graph[i][j] = 0;
    }
  }

  // Read street segments (edges)
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u][v] = graph[v][u] = 1; // Undirected graph
  }

  // Create a visited array to keep track of visited junctions
  int visited[MAX_JUNCTIONS] = {0};

  // Find the minimum personnel required using depth-first search
  int min = minPersonnel(1, n, n, visited, personnel[1]);

  // Output the minimum personnel required
  printf("%d\n", min);

  return 0;
}