#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 200000

typedef struct {
  int l, r, d;
} Info;

Info info[MAX_M];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Read input
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &info[i].l, &info[i].r, &info[i].d);
  }

  // Create a graph to represent the relationships between people
  int graph[MAX_N + 1][MAX_N + 1] = {0};
  for (int i = 0; i < m; i++) {
    graph[info[i].l][info[i].r] = info[i].d;
    graph[info[i].r][info[i].l] = -info[i].d;
  }

  // Use a union-find algorithm to detect cycles with inconsistent distances
  int parent[MAX_N + 1];
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  int inconsistent = 0;
  for (int i = 0; i < m; i++) {
    int l = info[i].l;
    int r = info[i].r;
    int d = info[i].d;

    // Find the root of the tree containing l and r
    int root_l = l;
    while (parent[root_l] != root_l) {
      root_l = parent[root_l];
    }
    int root_r = r;
    while (parent[root_r] != root_r) {
      root_r = parent[root_r];
    }

    // If l and r are in the same tree, check if the distance is consistent
    if (root_l == root_r) {
      if (graph[l][r] != d) {
        inconsistent = 1;
        break;
      }
    } else {
      // Otherwise, merge the two trees and update the distance
      parent[root_l] = root_r;
      graph[l][r] = d;
      graph[r][l] = -d;
    }
  }

  // Print the result
  if (inconsistent) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  return 0;
}