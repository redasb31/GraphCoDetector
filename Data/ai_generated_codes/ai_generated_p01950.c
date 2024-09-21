#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
  int adj[MAX_N + 1];
  int deg[MAX_N + 1];
} Graph;

// Function to initialize the graph
void init_graph(Graph *graph, int n) {
  for (int i = 1; i <= n; i++) {
    graph->deg[i] = 0;
  }
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int u, int v) {
  graph->adj[u] = v;
  graph->deg[u]++;
  graph->deg[v]++;
}

// Function to perform breadth-first search (BFS)
int bfs(Graph *graph, int start_vertex) {
  int current[MAX_N + 1] = {0};
  int found[MAX_N + 1] = {0};
  int visited[MAX_N + 1] = {0};
  int iterations = 0;
  
  // Initialize the current set with the start vertex
  current[start_vertex] = 1;
  visited[start_vertex] = 1;

  // Iterate until all vertices are visited
  while (1) {
    // Reset the found set
    for (int i = 1; i <= MAX_N; i++) {
      found[i] = 0;
    }

    // Explore the neighbors of each vertex in the current set
    for (int i = 1; i <= MAX_N; i++) {
      if (current[i]) {
        for (int j = 1; j <= graph->deg[i]; j++) {
          int neighbor = graph->adj[i];
          if (!visited[neighbor]) {
            found[neighbor] = 1;
            visited[neighbor] = 1;
          }
        }
      }
    }

    // Update the current set with the newly found vertices
    for (int i = 1; i <= MAX_N; i++) {
      current[i] = found[i];
    }

    iterations++;

    // Check if the program will stop
    bool stop = true;
    for (int i = 1; i <= MAX_N; i++) {
      if (current[i]) {
        stop = false;
        break;
      }
    }
    
    if (stop) {
      return iterations;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Initialize the graph
  Graph graph;
  init_graph(&graph, n);

  // Add edges to the graph
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    add_edge(&graph, u, v);
  }

  // Perform BFS and print the result
  int result = bfs(&graph, 1);
  if (result == -1) {
    printf("-1\n");
  } else {
    printf("%d\n", result);
  }

  return 0;
}