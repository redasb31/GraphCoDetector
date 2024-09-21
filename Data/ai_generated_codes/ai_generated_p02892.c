#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200

// Structure to represent a graph
typedef struct Graph {
    int n; // Number of vertices
    int **adj_matrix; // Adjacency matrix
} Graph;

// Function to create a graph
Graph *create_graph(int n) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->n = n;
    graph->adj_matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph->adj_matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return graph;
}

// Function to free the memory allocated for the graph
void free_graph(Graph *graph) {
    for (int i = 0; i < graph->n; i++) {
        free(graph->adj_matrix[i]);
    }
    free(graph->adj_matrix);
    free(graph);
}

// Function to perform Depth First Search (DFS)
void dfs(Graph *graph, int start, int *visited, int *color) {
    visited[start] = 1;
    for (int i = 0; i < graph->n; i++) {
        if (graph->adj_matrix[start][i] && !visited[i]) {
            color[i] = 1 - color[start]; // Assign opposite color to adjacent vertices
            dfs(graph, i, visited, color);
        }
    }
}

// Function to check if the graph is bipartite
int is_bipartite(Graph *graph) {
    int *visited = (int *)calloc(graph->n, sizeof(int));
    int *color = (int *)malloc(graph->n * sizeof(int));

    // Start DFS from each unvisited vertex
    for (int i = 0; i < graph->n; i++) {
        if (!visited[i]) {
            color[i] = 0; // Assign initial color
            dfs(graph, i, visited, color);
        }
    }

    // Check if any edge connects vertices with the same color
    for (int i = 0; i < graph->n; i++) {
        for (int j = i + 1; j < graph->n; j++) {
            if (graph->adj_matrix[i][j] && color[i] == color[j]) {
                free(visited);
                free(color);
                return 0; // Not bipartite
            }
        }
    }

    free(visited);
    free(color);
    return 1; // Bipartite
}

int main() {
    int n, max_sets = -1;
    scanf("%d", &n);

    // Create the graph
    Graph *graph = create_graph(n);

    // Read the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph->adj_matrix[i][j]);
        }
    }

    // Check if the graph is bipartite
    if (is_bipartite(graph)) {
        max_sets = 2; // A bipartite graph can be divided into two sets
    }

    // Print the maximum number of sets
    printf("%d\n", max_sets);

    // Free the memory allocated for the graph
    free_graph(graph);

    return 0;
}