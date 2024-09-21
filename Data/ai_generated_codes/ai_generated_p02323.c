#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 15

int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix to store the graph
int visited[MAX_VERTICES]; // Array to keep track of visited vertices
int min_distance = INT_MAX; // Variable to store the minimum distance

// Function to calculate the shortest distance using backtracking
void tsp(int current_vertex, int start_vertex, int distance, int num_vertices) {
  // If all vertices have been visited, update the minimum distance
  if (visited[current_vertex] == 1 && current_vertex == start_vertex && distance < min_distance) {
    min_distance = distance;
    return;
  }

  // Mark the current vertex as visited
  visited[current_vertex] = 1;

  // Iterate over all adjacent vertices
  for (int i = 0; i < num_vertices; i++) {
    // If the adjacent vertex is not visited and there is an edge between them
    if (visited[i] == 0 && graph[current_vertex][i] != 0) {
      // Recursively call the tsp function for the adjacent vertex
      tsp(i, start_vertex, distance + graph[current_vertex][i], num_vertices);
    }
  }

  // Unmark the current vertex as visited for backtracking
  visited[current_vertex] = 0;
}

int main() {
  int num_vertices, num_edges;
  scanf("%d %d", &num_vertices, &num_edges);

  // Initialize the adjacency matrix with 0s
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph[i][j] = 0;
    }
  }

  // Read the edges and their weights from input
  for (int i = 0; i < num_edges; i++) {
    int source, target, distance;
    scanf("%d %d %d", &source, &target, &distance);
    graph[source][target] = distance;
  }

  // Initialize the visited array with 0s
  for (int i = 0; i < num_vertices; i++) {
    visited[i] = 0;
  }

  // Start the backtracking algorithm from vertex 0
  tsp(0, 0, 0, num_vertices);

  // Print the shortest distance or -1 if no solution exists
  if (min_distance == INT_MAX) {
    printf("-1\n");
  } else {
    printf("%d\n", min_distance);
  }

  return 0;
}