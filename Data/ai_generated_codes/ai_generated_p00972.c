#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int n, m;
int graph[MAX_N][MAX_N]; // Adjacency matrix for the graph
int degree[MAX_N]; // Degree of each vertex

// Function to add a new edge to the graph
void add_edge(int u, int v) {
  graph[u][v] = graph[v][u] = 1;
  degree[u]++;
  degree[v]++;
}

// Function to check if a vertex has an odd degree
int is_odd_degree(int u) {
  return degree[u] % 2 != 0;
}

// Function to find a set of additional edges to enable an Eulerian tour
void find_eulerian_edges() {
  int odd_count = 0;
  int odd_vertices[MAX_N];
  int i, j, k = 0;

  // Count the number of vertices with odd degrees
  for (i = 1; i <= n; i++) {
    if (is_odd_degree(i)) {
      odd_count++;
      odd_vertices[k++] = i;
    }
  }

  // If the number of odd-degree vertices is greater than 2, an Eulerian tour is impossible
  if (odd_count > 2) {
    printf("-1\n");
    return;
  }

  // If there are two odd-degree vertices, add an edge between them
  if (odd_count == 2) {
    printf("1\n");
    printf("%d %d\n", odd_vertices[0], odd_vertices[1]);
    add_edge(odd_vertices[0], odd_vertices[1]);
    return;
  }

  // If all vertices have even degrees, no additional edges are needed
  if (odd_count == 0) {
    printf("0\n");
    return;
  }

  // If there is only one odd-degree vertex, find two vertices that are not connected and add an edge between them
  for (i = 1; i <= n; i++) {
    if (is_odd_degree(i)) {
      for (j = i + 1; j <= n; j++) {
        if (graph[i][j] == 0) {
          printf("1\n");
          printf("%d %d\n", i, j);
          add_edge(i, j);
          return;
        }
      }
    }
  }

  // If no such pair of vertices is found, an Eulerian tour is impossible
  printf("-1\n");
}

int main() {
  int i, u, v;

  // Read input
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    add_edge(u, v);
  }

  // Find the additional edges to enable an Eulerian tour
  find_eulerian_edges();

  return 0;
}