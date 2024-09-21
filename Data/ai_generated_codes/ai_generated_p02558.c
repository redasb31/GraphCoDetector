#include <stdio.h>

// Define the maximum number of vertices
#define MAX_N 200000

// Declare an array to store the parent of each vertex
int parent[MAX_N];

// Function to find the parent of a vertex using path compression
int find(int u) {
  // If the parent of u is not u, recursively find the parent of the parent
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

// Function to unite two vertices using union by rank
void unite(int u, int v) {
  // Find the parents of u and v
  int pu = find(u);
  int pv = find(v);

  // If they have the same parent, they are already in the same component
  if (pu == pv) {
    return;
  }

  // Otherwise, unite them by setting the parent of one to the other
  parent[pu] = pv;
}

int main() {
  // Declare variables for the number of vertices and queries
  int N, Q;

  // Read the input
  scanf("%d %d", &N, &Q);

  // Initialize the parent array
  for (int i = 0; i < N; i++) {
    parent[i] = i;
  }

  // Process each query
  for (int i = 0; i < Q; i++) {
    // Declare variables for the query type and vertices
    int t, u, v;

    // Read the query
    scanf("%d %d %d", &t, &u, &v);

    // If the query type is 0, add an edge
    if (t == 0) {
      unite(u, v);
    }

    // If the query type is 1, check if the vertices are in the same component
    else if (t == 1) {
      // Print 1 if they are in the same component, 0 otherwise
      printf("%d\n", (find(u) == find(v)));
    }
  }

  return 0;
}