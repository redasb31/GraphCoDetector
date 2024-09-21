#include <stdio.h>

int main() {
  int n; // Number of vertices
  scanf("%d", &n);

  // Adjacency list representation
  int adj[101][101] = {0}; // Initialize a 2D array to store adjacency list
  
  // Input the adjacency list
  for (int i = 1; i <= n; i++) {
    int k, v; // k is the degree of the vertex, v is the adjacent vertex
    scanf("%d %d", &k, &v);
    adj[i][0] = k; // Store the degree of the vertex
    for (int j = 1; j <= k; j++) {
      scanf("%d", &v);
      adj[i][j] = v; // Store the adjacent vertex
    }
  }

  // Convert adjacency list to adjacency matrix
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= adj[i][0]; j++) {
      // if vertex j is adjacent to vertex i
      adj[i][adj[i][j]] = 1; // Set the corresponding entry in the matrix to 1
    }
  }

  // Print the adjacency matrix
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }

  return 0;
}