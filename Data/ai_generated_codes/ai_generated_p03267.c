#include <stdio.h>

int main() {
  // L: The desired number of different paths
  int L;

  // Read the input value for L
  scanf("%d", &L);

  // N: The number of vertices (at most 20)
  int N = 20;

  // M: The number of edges (at most 60)
  int M = 60;

  // Output the number of vertices and edges
  printf("%d %d\n", N, M);

  // Create edges to ensure L different paths
  int i = 1;
  int pathLength = 0;
  while (pathLength < L) {
    // Add edges to create a new path
    for (int j = i; j < N; j++) {
      // Add edge with length 0
      printf("%d %d 0\n", i, j + 1);
      // Update path length
      pathLength++;

      // Break loop when L paths are created
      if (pathLength == L) {
        break;
      }
    }

    // Add an edge with length 1 to create another path
    if (pathLength < L) {
      printf("%d %d 1\n", i, i + 1);
      pathLength++;
    }

    // Move to the next starting vertex
    i++;
  }

  return 0;
}