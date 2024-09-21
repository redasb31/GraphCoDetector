#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 14
#define MAX_M 100

// Structure to represent an edge in the graph
typedef struct Edge {
    int u, v;
} Edge;

// Function to perform Depth First Search (DFS)
void dfs(int node, int visited[], int graph[][MAX_N]) {
    visited[node] = 1;

    // Iterate over adjacent nodes
    for (int i = 1; i <= MAX_N; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i, visited, graph);
        }
    }
}

// Function to calculate the probability of the graph remaining connected
double calculate_probability(int N, int M, Edge edges[], int P) {
    // Convert probability to decimal
    double p = (double) P / 100;

    // Calculate probability of an edge being removed
    double q = 1 - p;

    // Create a graph adjacency matrix
    int graph[MAX_N + 1][MAX_N + 1] = {0};

    // Initialize the graph with all edges present
    for (int i = 0; i < M; i++) {
        graph[edges[i].u][edges[i].v] = 1;
        graph[edges[i].v][edges[i].u] = 1;
    }

    // Initialize the probability of the graph being connected to 1
    double prob = 1.0;

    // Iterate over all possible combinations of edges being removed
    for (int i = 0; i < (1 << M); i++) {
        // Create a temporary graph
        int temp_graph[MAX_N + 1][MAX_N + 1] = {0};
        for (int j = 0; j < M; j++) {
            temp_graph[edges[j].u][edges[j].v] = graph[edges[j].u][edges[j].v];
            temp_graph[edges[j].v][edges[j].u] = graph[edges[j].v][edges[j].u];
        }

        // Remove edges based on the current combination
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                temp_graph[edges[j].u][edges[j].v] = 0;
                temp_graph[edges[j].v][edges[j].u] = 0;
            }
        }

        // Check if the remaining graph is connected
        int visited[MAX_N + 1] = {0};
        dfs(1, visited, temp_graph);
        int connected = 1;
        for (int j = 1; j <= N; j++) {
            if (visited[j] == 0) {
                connected = 0;
                break;
            }
        }

        // Update the probability based on the connected state
        if (connected == 0) {
            prob -= pow(q, __builtin_popcount(i)) * pow(p, M - __builtin_popcount(i));
        }
    }

    return prob;
}

int main() {
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);

    Edge edges[MAX_M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    double probability = calculate_probability(N, M, edges, P);
    printf("%.12lf\n", probability);

    return 0;
}