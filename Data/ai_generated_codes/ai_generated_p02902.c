#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 2000

int N, M;
int A[MAX_M], B[MAX_M];
int in_degree[MAX_N + 1], out_degree[MAX_N + 1];
int visited[MAX_N + 1];

// Function to check if a vertex has in-degree and out-degree both 1
int check_vertex(int v) {
  return (in_degree[v] == 1 && out_degree[v] == 1);
}

// Function to find an induced subgraph with in-degree and out-degree 1 for each vertex
int find_subgraph(int start) {
  int v = start;
  int count = 0;
  int subgraph[MAX_N + 1];

  // Traverse the graph starting from the given vertex
  while (!visited[v]) {
    visited[v] = 1;
    subgraph[count++] = v;

    // Find the next vertex in the cycle
    for (int i = 0; i < M; i++) {
      if (A[i] == v && !visited[B[i]]) {
        v = B[i];
        break;
      }
    }
  }

  // Check if all vertices in the cycle have in-degree and out-degree 1
  for (int i = 0; i < count; i++) {
    if (!check_vertex(subgraph[i])) {
      return -1;
    }
  }

  // Print the induced subgraph
  printf("%d\n", count);
  for (int i = 0; i < count; i++) {
    printf("%d\n", subgraph[i]);
  }

  return 0;
}

int main() {
  scanf("%d %d", &N, &M);

  // Read the edges of the graph
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &A[i], &B[i]);
    in_degree[B[i]]++;
    out_degree[A[i]]++;
  }

  // Find an induced subgraph
  int found = -1;
  for (int i = 1; i <= N; i++) {
    if (check_vertex(i) && !visited[i]) {
      found = find_subgraph(i);
      if (found == 0) {
        break;
      }
    }
  }

  // Print the result
  if (found == -1) {
    printf("-1\n");
  }

  return 0;
}