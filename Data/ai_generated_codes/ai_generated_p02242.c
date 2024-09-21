#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MAX_EDGES 10000

// Structure for a graph edge
struct Edge {
  int dest; // Destination vertex
  int weight; // Edge weight
  struct Edge* next; // Pointer to the next edge in the adjacency list
};

// Structure for a graph
struct Graph {
  int numVertices; // Number of vertices
  struct Edge* adjList[MAX_VERTICES]; // Adjacency list for each vertex
};

// Function to create a new edge
struct Edge* createEdge(int dest, int weight) {
  struct Edge* newEdge = (struct Edge*) malloc(sizeof(struct Edge));
  newEdge->dest = dest;
  newEdge->weight = weight;
  newEdge->next = NULL;
  return newEdge;
}

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;

  // Initialize adjacency lists as empty
  for (int i = 0; i < numVertices; i++) {
    graph->adjList[i] = NULL;
  }

  return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
  // Create a new edge
  struct Edge* newEdge = createEdge(dest, weight);

  // Add the new edge to the adjacency list of the source vertex
  newEdge->next = graph->adjList[src];
  graph->adjList[src] = newEdge;
}

// Function to implement Dijkstra's algorithm for finding shortest paths
void dijkstra(struct Graph* graph, int src) {
  int dist[MAX_VERTICES]; // Array to store shortest distances from the source
  int visited[MAX_VERTICES]; // Array to keep track of visited vertices

  // Initialize distances to infinity and visited to false
  for (int i = 0; i < graph->numVertices; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }

  // Set the distance of the source vertex to 0
  dist[src] = 0;

  // Iterate over all vertices
  for (int count = 0; count < graph->numVertices - 1; count++) {
    int minDistance = INT_MAX;
    int u = -1;

    // Find the vertex with the minimum distance that is not yet visited
    for (int v = 0; v < graph->numVertices; v++) {
      if (!visited[v] && dist[v] < minDistance) {
        minDistance = dist[v];
        u = v;
      }
    }

    // Mark the vertex with the minimum distance as visited
    visited[u] = 1;

    // Update distances of adjacent vertices
    struct Edge* adj = graph->adjList[u];
    while (adj != NULL) {
      if (!visited[adj->dest] && dist[u] != INT_MAX && dist[u] + adj->weight < dist[adj->dest]) {
        dist[adj->dest] = dist[u] + adj->weight;
      }
      adj = adj->next;
    }
  }

  // Print the shortest distances from the source to each vertex
  for (int i = 0; i < graph->numVertices; i++) {
    printf("%d %d\n", i, dist[i]);
  }
}

int main() {
  int numVertices;
  scanf("%d", &numVertices);

  // Create a new graph
  struct Graph* graph = createGraph(numVertices);

  // Read the adjacency list input
  for (int i = 0; i < numVertices; i++) {
    int src, numEdges, dest, weight;
    scanf("%d %d", &src, &numEdges);
    for (int j = 0; j < numEdges; j++) {
      scanf("%d %d", &dest, &weight);
      addEdge(graph, src, dest, weight);
    }
  }

  // Run Dijkstra's algorithm from vertex 0
  dijkstra(graph, 0);

  return 0;
}