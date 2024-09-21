#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent an edge
typedef struct Edge {
  int src;
  int dest;
} Edge;

// Structure to represent an adjacency list
typedef struct AdjList {
  int count;
  Edge *edges;
} AdjList;

// Structure to represent a graph
typedef struct Graph {
  int numVertices;
  AdjList *adjLists;
} Graph;

// Function to create a new graph
Graph *createGraph(int numVertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = numVertices;
  graph->adjLists = (AdjList *)malloc(sizeof(AdjList) * numVertices);
  for (int i = 0; i < numVertices; i++) {
    graph->adjLists[i].count = 0;
    graph->adjLists[i].edges = NULL;
  }
  return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
  // Allocate memory for the new edge
  Edge *newEdge = (Edge *)malloc(sizeof(Edge));
  newEdge->src = src;
  newEdge->dest = dest;

  // Add the new edge to the adjacency list of the source vertex
  graph->adjLists[src - 1].count++;
  graph->adjLists[src - 1].edges =
      (Edge *)realloc(graph->adjLists[src - 1].edges,
                     sizeof(Edge) * graph->adjLists[src - 1].count);
  graph->adjLists[src - 1].edges[graph->adjLists[src - 1].count - 1] = *newEdge;
}

// Function to check if it is possible to assign directions to the edges
// such that every vertex has an even number of outgoing edges
int isPossible(Graph *graph) {
  // Calculate the degree of each vertex
  int *degree = (int *)calloc(graph->numVertices, sizeof(int));
  for (int i = 0; i < graph->numVertices; i++) {
    degree[i] = graph->adjLists[i].count;
  }

  // Check if the degree of every vertex is even
  for (int i = 0; i < graph->numVertices; i++) {
    if (degree[i] % 2 != 0) {
      free(degree);
      return 0;
    }
  }

  free(degree);
  return 1;
}

// Function to assign directions to the edges
void assignDirections(Graph *graph) {
  // Initialize an array to store the directions of the edges
  int *directions = (int *)malloc(sizeof(int) * graph->numVertices);
  for (int i = 0; i < graph->numVertices; i++) {
    directions[i] = 0;
  }

  // Iterate through the adjacency lists
  for (int i = 0; i < graph->numVertices; i++) {
    // Iterate through the edges of the current vertex
    for (int j = 0; j < graph->adjLists[i].count; j++) {
      // If the edge has not been assigned a direction yet
      if (directions[graph->adjLists[i].edges[j].dest - 1] == 0) {
        // Assign a direction to the edge
        directions[graph->adjLists[i].edges[j].dest - 1] = i + 1;
        // Mark the edge as assigned
        graph->adjLists[i].edges[j].src = directions[graph->adjLists[i].edges[j].dest - 1];
      }
    }
  }

  // Print the assigned directions
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->adjLists[i].count; j++) {
      if (graph->adjLists[i].edges[j].src != 0) {
        printf("%d %d\n", graph->adjLists[i].edges[j].src,
               graph->adjLists[i].edges[j].dest);
      }
    }
  }

  free(directions);
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Create a new graph
  Graph *graph = createGraph(N);

  // Add the edges to the graph
  for (int i = 0; i < M; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    addEdge(graph, A, B);
    addEdge(graph, B, A);
  }

  // Check if it is possible to assign directions to the edges
  if (isPossible(graph)) {
    // Assign directions to the edges
    assignDirections(graph);
  } else {
    printf("-1\n");
  }

  // Free the memory allocated for the graph
  for (int i = 0; i < graph->numVertices; i++) {
    free(graph->adjLists[i].edges);
  }
  free(graph->adjLists);
  free(graph);

  return 0;
}