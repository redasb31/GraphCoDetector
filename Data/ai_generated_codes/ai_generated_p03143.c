#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent an edge
typedef struct Edge {
  int a, b; // Vertices connected by the edge
  int weight; // Weight of the edge
} Edge;

// Structure to represent a vertex
typedef struct Vertex {
  int weight; // Weight of the vertex
  int visited; // Flag to indicate if the vertex has been visited
} Vertex;

// Structure to represent a connected component
typedef struct Component {
  int size; // Number of vertices in the component
  int total_weight; // Sum of weights of vertices in the component
} Component;

// Function to find the minimum number of edges to remove
int find_min_edges_to_remove(Vertex *vertices, Edge *edges, int n, int m) {
  // Initialize the connected components
  Component *components = (Component *)malloc(sizeof(Component) * (n + 1));
  for (int i = 1; i <= n; i++) {
    components[i].size = 1;
    components[i].total_weight = vertices[i].weight;
  }

  // Sort the edges in descending order of weight
  for (int i = 0; i < m - 1; i++) {
    for (int j = i + 1; j < m; j++) {
      if (edges[i].weight < edges[j].weight) {
        Edge temp = edges[i];
        edges[i] = edges[j];
        edges[j] = temp;
      }
    }
  }

  // Initialize the number of edges removed
  int edges_removed = 0;

  // Iterate over the edges in descending order of weight
  for (int i = 0; i < m; i++) {
    // If the edge has already been removed, continue
    if (edges[i].weight == -1) {
      continue;
    }

    // Get the vertices connected by the edge
    int a = edges[i].a;
    int b = edges[i].b;

    // If the vertices belong to the same connected component, remove the edge
    if (components[a].size == components[b].size && components[a].total_weight == components[b].total_weight) {
      edges_removed++;
      edges[i].weight = -1;
    }
    // Otherwise, merge the connected components
    else {
      // Merge the components based on the component size
      if (components[a].size < components[b].size) {
        components[a].size += components[b].size;
        components[a].total_weight += components[b].total_weight;
        components[b].size = 0;
        components[b].total_weight = 0;
      } else {
        components[b].size += components[a].size;
        components[b].total_weight += components[a].total_weight;
        components[a].size = 0;
        components[a].total_weight = 0;
      }
    }
  }

  // Free the memory allocated for the connected components
  free(components);

  // Return the number of edges removed
  return edges_removed;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  // Create an array to store the vertices
  Vertex *vertices = (Vertex *)malloc(sizeof(Vertex) * (n + 1));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &vertices[i].weight);
    vertices[i].visited = 0;
  }

  // Create an array to store the edges
  Edge *edges = (Edge *)malloc(sizeof(Edge) * m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].weight);
  }

  // Find the minimum number of edges to remove
  int edges_removed = find_min_edges_to_remove(vertices, edges, n, m);

  // Print the result
  printf("%d\n", edges_removed);

  // Free the memory allocated for the vertices and edges
  free(vertices);
  free(edges);

  return 0;
}