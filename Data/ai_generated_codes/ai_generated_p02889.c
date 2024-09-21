#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 300
#define MAX_M (MAX_N * (MAX_N - 1) / 2)

// Structure to represent a road
typedef struct {
  int a;  // Town A
  int b;  // Town B
  int c;  // Length of the road
} Road;

// Structure to represent a graph using adjacency list
typedef struct {
  int n;         // Number of towns
  int m;         // Number of roads
  Road roads[MAX_M];
  int adj[MAX_N][MAX_N];  // Adjacency matrix for quick access
} Graph;

// Function to initialize a graph
Graph* init_graph(int n, int m) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->n = n;
  graph->m = m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph->adj[i][j] = INT_MAX;
    }
  }
  return graph;
}

// Function to add a road to the graph
void add_road(Graph* graph, int a, int b, int c) {
  graph->roads[graph->m].a = a;
  graph->roads[graph->m].b = b;
  graph->roads[graph->m].c = c;
  graph->adj[a - 1][b - 1] = c;  // Update adjacency matrix
  graph->adj[b - 1][a - 1] = c;  // Update adjacency matrix
  graph->m++;
}

// Function to find the shortest path between two towns using Dijkstra's algorithm
int shortest_path(Graph* graph, int s, int t, int l) {
  int dist[MAX_N];    // Distance from source to each town
  int visited[MAX_N];  // Flag to mark visited towns
  int prev[MAX_N];    // Previous town in the shortest path
  int count[MAX_N];   // Number of refuelings required to reach each town

  // Initialize distances, visited flags, and previous towns
  for (int i = 0; i < graph->n; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
    prev[i] = -1;
    count[i] = INT_MAX;
  }

  dist[s - 1] = 0;
  count[s - 1] = 0;

  // Dijkstra's algorithm
  for (int i = 0; i < graph->n; i++) {
    int u = -1;
    int min_dist = INT_MAX;

    // Find the town with the minimum distance that hasn't been visited
    for (int j = 0; j < graph->n; j++) {
      if (!visited[j] && dist[j] < min_dist) {
        u = j;
        min_dist = dist[j];
      }
    }

    if (u == -1) {
      break;
    }

    visited[u] = 1;

    // Update distances for adjacent towns
    for (int v = 0; v < graph->n; v++) {
      if (graph->adj[u][v] != INT_MAX) {
        int new_dist = dist[u] + graph->adj[u][v];
        if (new_dist < dist[v]) {
          dist[v] = new_dist;
          prev[v] = u;
          count[v] = count[u] + (new_dist > l ? 1 : 0);
        }
      }
    }
  }

  // Check if the destination town is reachable
  if (dist[t - 1] == INT_MAX) {
    return -1;
  }

  // Return the minimum number of refueling stops required
  return count[t - 1];
}

int main() {
  int n, m, l, q;
  scanf("%d %d %d", &n, &m, &l);

  // Initialize the graph
  Graph* graph = init_graph(n, m);

  // Read the roads
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    add_road(graph, a, b, c);
  }

  // Read the queries
  scanf("%d", &q);

  // Process the queries
  for (int i = 0; i < q; i++) {
    int s, t;
    scanf("%d %d", &s, &t);

    // Find the minimum number of refueling stops
    int result = shortest_path(graph, s, t, l);

    // Print the result
    printf("%d\n", result);
  }

  // Free the allocated memory
  free(graph);

  return 0;
}