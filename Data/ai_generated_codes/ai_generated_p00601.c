#include <stdio.h>
#include <limits.h>

// Function to find the minimum dominating set using a brute force approach
int findMinDominatingSet(int n, int adj[][n]) {
  // Initialize the minimum dominating set size to the maximum possible value
  int minDominatingSetSize = INT_MAX;

  // Iterate through all possible subsets of vertices
  for (int i = 1; i < (1 << n); i++) {
    // Check if the current subset is a dominating set
    int isDominatingSet = 1;
    for (int j = 0; j < n; j++) {
      // If the vertex is not in the subset
      if (!(i & (1 << j))) {
        // Check if it is adjacent to any vertex in the subset
        int isAdjacent = 0;
        for (int k = 0; k < n; k++) {
          if ((i & (1 << k)) && adj[j][k]) {
            isAdjacent = 1;
            break;
          }
        }
        // If the vertex is not adjacent to any vertex in the subset, it's not a dominating set
        if (!isAdjacent) {
          isDominatingSet = 0;
          break;
        }
      }
    }
    // If the current subset is a dominating set, update the minimum size if necessary
    if (isDominatingSet) {
      int currentSize = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          currentSize++;
        }
      }
      minDominatingSetSize = (currentSize < minDominatingSetSize) ? currentSize : minDominatingSetSize;
    }
  }
  // Return the size of the minimum dominating set
  return minDominatingSetSize;
}

int main() {
  int n, m;
  while (1) {
    // Read the number of nodes and edges
    scanf("%d %d", &n, &m);
    // Terminate the loop if the input is 0 0
    if (n == 0 && m == 0) {
      break;
    }
    // Create an adjacency matrix to represent the graph
    int adj[n][n];
    // Initialize the adjacency matrix to 0s
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        adj[i][j] = 0;
      }
    }
    // Read the edges and update the adjacency matrix
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u][v] = 1;
      adj[v][u] = 1; // Undirected graph
    }
    // Find the minimum dominating set size and print it
    int minDominatingSetSize = findMinDominatingSet(n, adj);
    printf("%d\n", minDominatingSetSize);
  }
  return 0;
}