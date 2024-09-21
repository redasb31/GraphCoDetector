#include <stdio.h>

// Function to find the minimum number of bridges to remove
int minBridgesToRemove(int N, int M, int a[], int b[]) {
  // Create a disjoint set data structure to track connected islands
  int parent[N + 1];
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  // Function to find the parent of a node in the disjoint set
  int findParent(int x) {
    if (parent[x] != x) {
      parent[x] = findParent(parent[x]);
    }
    return parent[x];
  }

  // Function to merge two sets in the disjoint set
  void merge(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);
    parent[px] = py;
  }

  // Count the number of bridges to be removed
  int bridgesToRemove = 0;

  // Iterate over all the requests
  for (int i = 0; i < M; i++) {
    // Find the parent of the two islands involved in the request
    int pa = findParent(a[i]);
    int pb = findParent(b[i]);

    // If the two islands are not already connected, remove a bridge
    if (pa != pb) {
      bridgesToRemove++;
      merge(pa, pb);
    }
  }

  // Return the minimum number of bridges to be removed
  return bridgesToRemove;
}

int main() {
  // Read the input
  int N, M;
  scanf("%d %d", &N, &M);
  int a[M], b[M];
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }

  // Calculate and print the minimum number of bridges to remove
  int result = minBridgesToRemove(N, M, a, b);
  printf("%d\n", result);

  return 0;
}