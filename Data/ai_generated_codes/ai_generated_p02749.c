#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

int n;
int a[MAX_N], b[MAX_N];
int deg[MAX_N]; // Degree of each vertex
int visited[MAX_N];
int p[MAX_N]; // Permutation array

// Function to find the permutation
int find_permutation(int v, int d) {
  // If the vertex has been visited, return
  if (visited[v]) {
    return 0;
  }

  // Mark the vertex as visited
  visited[v] = 1;

  // Assign a number to the current vertex based on its distance from the root
  p[v] = d;

  // Iterate over the neighbors of the current vertex
  for (int i = 0; i < n - 1; i++) {
    if ((a[i] == v && b[i] != v) || (b[i] == v && a[i] != v)) {
      // Recursively call the function for each neighbor
      if (!find_permutation(a[i] == v ? b[i] : a[i], d + 1)) {
        return 0;
      }
    }
  }

  // Unmark the vertex as visited
  visited[v] = 0;

  return 1;
}

int main() {
  // Input the number of vertices
  scanf("%d", &n);

  // Input the edges of the tree
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &a[i], &b[i]);
    // Increment the degree of the vertices connected by the edge
    deg[a[i]]++;
    deg[b[i]]++;
  }

  // Check if there exists a vertex with degree greater than 2
  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 2) {
      root = i;
      break;
    }
  }

  // If there is no vertex with degree greater than 2, the tree is a path
  if (root == -1) {
    // Find a permutation that satisfies the condition for a path
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
    for (int i = 1; i <= n; i++) {
      printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
  }

  // Find the permutation starting from the root vertex
  if (!find_permutation(root, 1)) {
    // If no permutation satisfying the condition is found, print -1
    printf("-1\n");
    return 0;
  }

  // Print the permutation
  for (int i = 1; i <= n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");

  return 0;
}