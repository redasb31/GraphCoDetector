#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

// Structure to represent an edge
typedef struct Edge {
    int u, v, w;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int n, m;
    Edge *edges;
} Graph;

// Function to create a graph
Graph *createGraph(int n, int m) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->n = n;
    graph->m = m;
    graph->edges = (Edge *)malloc(sizeof(Edge) * m);
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v, int w) {
    graph->edges[graph->m].u = u;
    graph->edges[graph->m].v = v;
    graph->edges[graph->m].w = w;
    graph->m++;
}

// Function to compare two edges based on their weight
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
int kruskalMST(Graph *graph, int x) {
    // Sort the edges by weight
    qsort(graph->edges, graph->m, sizeof(Edge), compareEdges);

    // Create a parent array to track the parent of each node
    int *parent = (int *)malloc(sizeof(int) * (graph->n + 1));

    // Initialize the parent array
    for (int i = 1; i <= graph->n; i++) {
        parent[i] = i;
    }

    // Initialize the weight of the MST
    int mstWeight = 0;

    // Initialize the number of edges in the MST
    int mstEdges = 0;

    // Initialize the number of white edges in the MST
    int whiteEdges = 0;

    // Iterate over the sorted edges
    for (int i = 0; i < graph->m; i++) {
        // Get the current edge
        Edge edge = graph->edges[i];

        // Find the parent of the source node
        int uParent = parent[edge.u];

        // Find the parent of the destination node
        int vParent = parent[edge.v];

        // If the parents are different, then the edge is not in a cycle
        if (uParent != vParent) {
            // Add the edge to the MST
            mstWeight += edge.w;
            mstEdges++;

            // Update the parent of the destination node to the parent of the source node
            parent[vParent] = uParent;

            // If the weight of the MST is equal to X, then increment the number of white edges
            if (mstWeight == x) {
                whiteEdges++;
            }
        }
    }

    // If the number of edges in the MST is equal to the number of nodes minus 1, then the MST is valid
    if (mstEdges == graph->n - 1) {
        // Calculate the number of ways to paint the edges
        int ways = 1;
        for (int i = 0; i < graph->m; i++) {
            if (graph->edges[i].w == x) {
                ways = (ways * 2) % MOD;
            }
        }

        // If the number of white edges is greater than 0, then the MST contains both white and black edges
        if (whiteEdges > 0) {
            // Return the number of ways to paint the edges
            return ways;
        } else {
            // Return 0 as the MST does not contain both white and black edges
            return 0;
        }
    } else {
        // Return 0 as the graph is not connected
        return 0;
    }
}

int main() {
    // Read the input
    int n, m, x;
    scanf("%d %d", &n, &m);
    scanf("%d", &x);

    // Create a graph
    Graph *graph = createGraph(n, 0);

    // Read the edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    // Find the number of ways to paint the edges
    int ways = kruskalMST(graph, x);

    // Print the output
    printf("%d\n", ways);

    // Free the memory
    free(graph->edges);
    free(graph);

    return 0;
}