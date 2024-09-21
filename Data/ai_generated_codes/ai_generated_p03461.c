#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a graph edge
struct Edge {
    int src;
    int dest;
    char weight;
};

// Function to create a graph with given number of vertices and edges
struct Edge* createGraph(int V, int E) {
    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Edge* graph, int src, int dest, char weight, int E) {
    graph[E].src = src;
    graph[E].dest = dest;
    graph[E].weight = weight;
}

// Function to find the shortest distance between two vertices using Bellman-Ford algorithm
int shortestDistance(struct Edge* graph, int V, int E, int S, int T, char X, char Y, int x, int y) {
    int dist[V + 1];
    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX;
    }
    dist[S] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j].src;
            int v = graph[j].dest;
            char weight = graph[j].weight;
            int edgeWeight = (weight == X) ? x : (weight == Y) ? y : (int)weight;

            if (dist[u] != INT_MAX && dist[u] + edgeWeight < dist[v]) {
                dist[v] = dist[u] + edgeWeight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = graph[j].src;
        int v = graph[j].dest;
        char weight = graph[j].weight;
        int edgeWeight = (weight == X) ? x : (weight == Y) ? y : (int)weight;

        if (dist[u] != INT_MAX && dist[u] + edgeWeight < dist[v]) {
            return -1; // Negative weight cycle detected
        }
    }

    return dist[T];
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int distances[A + 1][B + 1];
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            scanf("%d", &distances[i][j]);
        }
    }

    // Find the minimum number of vertices required
    int N = 3; // Start with 3 vertices for initial construction
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            N = (distances[i][j] > N) ? distances[i][j] : N;
        }
    }

    // Initialize the graph
    int E = 0;
    struct Edge* graph = createGraph(N, N * N);

    // Try to construct the graph by adding edges and checking for shortest distances
    int S = 1, T = N;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            if (distances[i][j] > 2) {
                // Add edges to create a path of length distances[i][j]
                for (int k = 1; k < distances[i][j]; k++) {
                    addEdge(graph, k, k + 1, '0' + k, E++);
                }
                addEdge(graph, distances[i][j], 2, 'X', E++);
                addEdge(graph, 2, 1, 'Y', E++);
            } else if (distances[i][j] == 2) {
                // Add edges to create a path of length 2
                addEdge(graph, 1, 2, 'X', E++);
                addEdge(graph, 2, 1, 'Y', E++);
            } else if (distances[i][j] == 1) {
                // Add a direct edge
                addEdge(graph, 1, N, '0' + i, E++);
            }
        }
    }

    // Check if the constructed graph satisfies the conditions
    int valid = 1;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            int actualDistance = shortestDistance(graph, N, E, S, T, 'X', 'Y', i, j);
            if (actualDistance != distances[i][j]) {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            break;
        }
    }

    // Print the output
    if (valid) {
        printf("Possible\n");
        printf("%d %d\n", N, E);
        for (int i = 0; i < E; i++) {
            printf("%d %d %c\n", graph[i].src, graph[i].dest, graph[i].weight);
        }
        printf("%d %d\n", S, T);
    } else {
        printf("Impossible\n");
    }

    free(graph);
    return 0;
}