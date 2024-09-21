#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent an edge
typedef struct Edge {
    int u; // Starting vertex
    int v; // Ending vertex
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int n; // Number of vertices
    int m; // Number of edges
    Edge* edges; // Array of edges
} Graph;

// Function to create a graph
Graph* createGraph(int n, int m) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->m = m;
    graph->edges = (Edge*)malloc(m * sizeof(Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    graph->edges[graph->m].u = u;
    graph->edges[graph->m].v = v;
    graph->m++;
}

// Function to check if three circuits can be formed
int canFormThreeCircuits(Graph* graph) {
    // Check if the number of edges is a multiple of 3
    if (graph->m % 3 != 0) {
        return 0;
    }

    // Create an array to store the degree of each vertex
    int degree[MAX_N + 1] = {0};
    for (int i = 0; i < graph->m; i++) {
        degree[graph->edges[i].u]++;
        degree[graph->edges[i].v]++;
    }

    // Check if all vertices have an even degree
    for (int i = 1; i <= graph->n; i++) {
        if (degree[i] % 2 != 0) {
            return 0;
        }
    }

    // Check if the graph is connected
    // (This is already given in the problem statement)

    // If all conditions are satisfied, return 1
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph(n, m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if (canFormThreeCircuits(graph)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(graph->edges);
    free(graph);

    return 0;
}