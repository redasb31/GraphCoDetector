#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
typedef struct Edge {
  int dest; // Destination vertex
  int weight; // Weight of the edge
  struct Edge* next; // Pointer to the next edge
} Edge;

// Structure to represent an adjacency list node
typedef struct AdjListNode {
  Edge* head; // Pointer to the head of the list of edges
} AdjListNode;

// Structure to represent the graph
typedef struct Graph {
  int V; // Number of vertices
  AdjListNode* array; // Array of adjacency lists
} Graph;

// Function to create a new edge
Edge* newEdge(int dest, int weight) {
  Edge* newEdge = (Edge*)malloc(sizeof(Edge));
  newEdge->dest = dest;
  newEdge->weight = weight;
  newEdge->next = NULL;
  return newEdge;
}

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int V) {
  AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
  newNode->head = NULL;
  return newNode;
}

// Function to create a new graph
Graph* createGraph(int V) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->V = V;
  graph->array = (AdjListNode*)malloc(V * sizeof(AdjListNode));
  for (int i = 0; i < V; ++i) {
    graph->array[i].head = NULL;
  }
  return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
  Edge* newEdge = newEdge(dest, weight);
  newEdge->next = graph->array[src].head;
  graph->array[src].head = newEdge;
}

// Function to implement Dijkstra's algorithm
void dijkstra(Graph* graph, int src) {
  int V = graph->V;
  int dist[V]; // Array to store the shortest distances from the source
  int visited[V]; // Array to keep track of visited vertices
  
  // Initialize distances to infinity and visited to false
  for (int i = 0; i < V; ++i) {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }

  // Initialize distance of source to 0
  dist[src] = 0;

  // Main loop to find shortest paths
  for (int count = 0; count < V - 1; ++count) {
    // Find the vertex with the minimum distance
    int minDistance = INT_MAX;
    int u = 0;
    for (int v = 0; v < V; ++v) {
      if (!visited[v] && dist[v] <= minDistance) {
        minDistance = dist[v];
        u = v;
      }
    }

    // Mark the selected vertex as visited
    visited[u] = 1;

    // Update distances of adjacent vertices
    Edge* adj = graph->array[u].head;
    while (adj != NULL) {
      int v = adj->dest;
      int weight = adj->weight;
      if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
      adj = adj->next;
    }
  }

  // Print the shortest distances from the source
  for (int i = 0; i < V; ++i) {
    printf("%d %d\n", i, dist[i]);
  }
}

int main() {
  int V, src, dest, weight;
  scanf("%d", &V);

  // Create the graph
  Graph* graph = createGraph(V);
  src = 0; // Source vertex

  // Read the graph input
  for (int i = 0; i < V; ++i) {
    int k;
    scanf("%d %d", &src, &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d %d", &dest, &weight);
      addEdge(graph, src, dest, weight);
    }
  }

  // Run Dijkstra's algorithm
  dijkstra(graph, src);

  return 0;
}