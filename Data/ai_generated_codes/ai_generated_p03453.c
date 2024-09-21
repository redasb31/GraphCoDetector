#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007

typedef struct {
    int u, v, d;
} Edge;

typedef struct {
    int *adj;
    int *dist;
    int *path;
    int num_edges;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->adj = (int *)malloc(sizeof(int) * num_vertices);
    graph->dist = (int *)malloc(sizeof(int) * num_vertices);
    graph->path = (int *)malloc(sizeof(int) * num_vertices);
    graph->num_edges = 0;
    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int u, int v, int d) {
    graph->adj[graph->num_edges] = v;
    graph->dist[graph->num_edges] = d;
    graph->num_edges++;
}

// Function to perform Dijkstra's algorithm
void dijkstra(Graph *graph, int source, int num_vertices) {
    int *visited = (int *)calloc(num_vertices, sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        graph->dist[i] = INT_MAX;
        graph->path[i] = -1;
    }
    graph->dist[source] = 0;
    graph->path[source] = source;

    for (int i = 0; i < num_vertices - 1; i++) {
        int min_dist = INT_MAX, min_index = -1;
        for (int j = 0; j < num_vertices; j++) {
            if (!visited[j] && graph->dist[j] < min_dist) {
                min_dist = graph->dist[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;
        for (int j = 0; j < graph->num_edges; j++) {
            if (graph->adj[j] == min_index && graph->dist[min_index] + graph->dist[j] < graph->dist[graph->adj[j]]) {
                graph->dist[graph->adj[j]] = graph->dist[min_index] + graph->dist[j];
                graph->path[graph->adj[j]] = min_index;
            }
        }
    }
    free(visited);
}

// Function to count the number of non-intersecting paths
long long count_paths(Graph *graph_t, Graph *graph_a, int s, int t, int num_vertices) {
    // Calculate shortest paths for Takahashi and Aoki
    dijkstra(graph_t, s, num_vertices);
    dijkstra(graph_a, t, num_vertices);

    // Create a matrix to store the number of paths to each vertex
    long long **dp = (long long **)malloc(sizeof(long long *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        dp[i] = (long long *)calloc(num_vertices, sizeof(long long));
    }

    // Initialize the base case
    dp[s][t] = 1;

    // Iterate over all vertices
    for (int i = 0; i < num_vertices; i++) {
        // Iterate over all edges from the current vertex
        for (int j = 0; j < graph_t->num_edges; j++) {
            if (graph_t->adj[j] == i) {
                // If the edge is not part of the shortest path for either Takahashi or Aoki
                if (graph_t->path[i] != graph_t->adj[j] && graph_a->path[i] != graph_t->adj[j]) {
                    // Add the number of paths to the current vertex to the number of paths to the adjacent vertex
                    dp[graph_t->adj[j]][i] = (dp[graph_t->adj[j]][i] + dp[i][t]) % MOD;
                }
            }
        }
        for (int j = 0; j < graph_a->num_edges; j++) {
            if (graph_a->adj[j] == i) {
                // If the edge is not part of the shortest path for either Takahashi or Aoki
                if (graph_a->path[i] != graph_a->adj[j] && graph_t->path[i] != graph_a->adj[j]) {
                    // Add the number of paths to the current vertex to the number of paths to the adjacent vertex
                    dp[i][graph_a->adj[j]] = (dp[i][graph_a->adj[j]] + dp[s][i]) % MOD;
                }
            }
        }
    }

    // The answer is the number of paths from S to T
    long long count = dp[t][s];

    // Free memory
    for (int i = 0; i < num_vertices; i++) {
        free(dp[i]);
    }
    free(dp);
    return count;
}

int main() {
    int n, m, s, t, u, v, d;

    // Read input
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);

    // Create graphs for Takahashi and Aoki
    Graph *graph_t = create_graph(n);
    Graph *graph_a = create_graph(n);

    // Add edges to the graphs
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &d);
        add_edge(graph_t, u - 1, v - 1, d);
        add_edge(graph_a, v - 1, u - 1, d);
    }

    // Count the number of non-intersecting paths
    long long count = count_paths(graph_t, graph_a, s - 1, t - 1, n);

    // Print the answer
    printf("%lld\n", count);

    // Free memory
    free(graph_t->adj);
    free(graph_t->dist);
    free(graph_t->path);
    free(graph_t);
    free(graph_a->adj);
    free(graph_a->dist);
    free(graph_a->path);
    free(graph_a);

    return 0;
}