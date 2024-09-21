#include <stdio.h>

int main() {
  // Input the desired number of paths (L)
  int L;
  scanf("%d", &L);

  // Determine the number of vertices (N) and edges (M)
  int N = L + 1;  // N is at least L + 1 to ensure L distinct paths
  int M = 2 * L;  // M can be 2*L to achieve the required number of paths

  // Print the number of vertices and edges
  printf("%d %d\n", N, M);

  // Create an array to store the edge lengths
  int edge_lengths[M];

  // Initialize edge lengths to 0 for the first L edges
  for (int i = 0; i < L; i++) {
    edge_lengths[i] = i; // Assign distinct lengths from 0 to L-1
  }

  // Create L edges with lengths 0 to L-1 for the first L edges
  for (int i = 1; i <= L; i++) {
    printf("%d %d %d\n", i, i + 1, edge_lengths[i - 1]);
  }

  // Create another L edges with lengths 0 to L-1 for the last L edges
  int edge_offset = L - 1;
  for (int i = 1; i <= L; i++) {
    printf("%d %d %d\n", i, i + 1, edge_lengths[i - 1 + edge_offset]); // Add offset
  }

  return 0;
}