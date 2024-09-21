#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent an edge in the graph
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge* edges;
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (Edge*)malloc(numEdges * sizeof(Edge));
    return graph;
}

// Function to perform Dijkstra's algorithm
void dijkstra(Graph* graph, int source) {
    // Array to store the shortest distance from the source to each vertex
    int distances[graph->numVertices];

    // Array to keep track of visited vertices
    int visited[graph->numVertices];

    // Initialize distances and visited arrays
    for (int i = 0; i < graph->numVertices; ++i) {
        distances[i] = INF;
        visited[i] = 0;
    }

    // Set distance to source vertex as 0
    distances[source] = 0;

    // Loop until all vertices are visited
    for (int count = 0; count < graph->numVertices - 1; ++count) {
        int minDistance = INF;
        int minIndex = -1;

        // Find the vertex with the minimum distance
        for (int i = 0; i < graph->numVertices; ++i) {
            if (!visited[i] && distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = 1;

        // Update distances of adjacent vertices
        for (int i = 0; i < graph->numEdges; ++i) {
            if (graph->edges[i].src == minIndex && !visited[graph->edges[i].dest]) {
                if (distances[graph->edges[i].src] + graph->edges[i].weight < distances[graph->edges[i].dest]) {
                    distances[graph->edges[i].dest] = distances[graph->edges[i].src] + graph->edges[i].weight;
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < graph->numVertices; ++i) {
        if (distances[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", distances[i]);
        }
    }
}

int main() {
    int numVertices, numEdges, source;

    // Read input
    scanf("%d %d %d", &numVertices, &numEdges, &source);

    // Create graph
    Graph* graph = createGraph(numVertices, numEdges);

    // Read edges
    for (int i = 0; i < numEdges; ++i) {
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }

    // Run Dijkstra's algorithm
    dijkstra(graph, source);

    // Free memory
    free(graph->edges);
    free(graph);

    return 0;
}