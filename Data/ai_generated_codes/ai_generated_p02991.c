#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent an edge in the graph
typedef struct Edge {
    int src;
    int dest;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int numEdges;
    Edge* edges;
} Graph;

// Function to create a new graph
Graph* createGraph(int numVertices, int numEdges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (Edge*)malloc(numEdges * sizeof(Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->edges[graph->numEdges].src = src;
    graph->edges[graph->numEdges].dest = dest;
    graph->numEdges++;
}

// Function to perform Breadth-First Search (BFS) to find the shortest path from source to destination
int bfs(Graph* graph, int source, int destination) {
    // Create a queue for BFS
    int queue[MAX_N];
    int front = 0;
    int rear = 0;

    // Create a distance array to store the shortest distance from the source to each vertex
    int distance[MAX_N];
    for (int i = 1; i <= graph->numVertices; i++) {
        distance[i] = INT_MAX;
    }

    // Initialize the distance of the source vertex to 0
    distance[source] = 0;

    // Add the source vertex to the queue
    queue[rear++] = source;

    // Perform BFS
    while (front != rear) {
        // Dequeue the front vertex
        int currentVertex = queue[front++];

        // Iterate over all edges from the current vertex
        for (int i = 0; i < graph->numEdges; i++) {
            if (graph->edges[i].src == currentVertex) {
                // Get the destination vertex of the current edge
                int nextVertex = graph->edges[i].dest;

                // If the destination vertex has not been visited yet
                if (distance[nextVertex] == INT_MAX) {
                    // Update the distance of the destination vertex
                    distance[nextVertex] = distance[currentVertex] + 1;

                    // Enqueue the destination vertex
                    queue[rear++] = nextVertex;

                    // If the destination vertex is found, return the distance
                    if (nextVertex == destination) {
                        return distance[destination] / 3;
                    }
                }
            }
        }
    }

    // If the destination vertex is not found, return -1
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Create a graph with N vertices and M edges
    Graph* graph = createGraph(N, M);

    // Read the edges from the input
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Read the source and destination vertices from the input
    int S, T;
    scanf("%d %d", &S, &T);

    // Find the minimum number of ken-ken-pa needed to reach the destination vertex
    int minKenKenPa = bfs(graph, S, T);

    // Print the result
    printf("%d\n", minKenKenPa);

    // Free the memory allocated for the graph
    free(graph->edges);
    free(graph);

    return 0;
}