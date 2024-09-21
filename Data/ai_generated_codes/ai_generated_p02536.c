#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

int n, m;
int a[MAX_M], b[MAX_M];
int parent[MAX_N];

// Find the root of the tree containing the given node
int find(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = find(parent[x]);
}

// Union two trees containing given nodes
void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    parent[x] = y;
  }
}

int main() {
  // Input the number of cities and roads
  scanf("%d %d", &n, &m);

  // Input the roads
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }

  // Initialize parent array for disjoint set union
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  // Union the cities connected by roads
  for (int i = 0; i < m; i++) {
    unite(a[i] - 1, b[i] - 1);
  }

  // Count the number of connected components
  int num_components = 0;
  for (int i = 0; i < n; i++) {
    if (parent[i] == i) {
      num_components++;
    }
  }

  // Print the minimum number of roads to be built
  printf("%d\n", num_components - 1);

  return 0;
}