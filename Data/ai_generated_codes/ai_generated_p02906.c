#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 1000000

// Structure to represent an edge in the graph
typedef struct Edge {
    int u, v;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int n, m; // Number of vertices and edges
    Edge* edges; // Array of edges
} Graph;

// Function to initialize a graph
Graph* initGraph(int n, int m) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->n = n;
    graph->m = m;
    graph->edges = (Edge*) malloc(sizeof(Edge) * m);
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    graph->edges[graph->m].u = u;
    graph->edges[graph->m].v = v;
    graph->m++;
}

// Function to perform Depth First Search (DFS)
void dfs(Graph* graph, int u, int* visited) {
    visited[u] = 1;
    for (int i = 0; i < graph->m; i++) {
        if (graph->edges[i].u == u && !visited[graph->edges[i].v]) {
            dfs(graph, graph->edges[i].v, visited);
        }
        if (graph->edges[i].v == u && !visited[graph->edges[i].u]) {
            dfs(graph, graph->edges[i].u, visited);
        }
    }
}

// Function to check if the graph is connected
int isConnected(Graph* graph) {
    int visited[MAX_N] = {0};
    dfs(graph, 0, visited);
    for (int i = 0; i < graph->n; i++) {
        if (!visited[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if there is exactly one path between two vertices
int checkOnePath(Graph* graph, int u, int v) {
    int visited[MAX_N] = {0};
    dfs(graph, u, visited);
    return visited[v];
}

// Function to check if there are two or more paths between two vertices
int checkMultiplePaths(Graph* graph, int u, int v) {
    int visited[MAX_N] = {0};
    dfs(graph, u, visited);
    for (int i = 0; i < graph->m; i++) {
        if ((graph->edges[i].u == u || graph->edges[i].v == u) && !visited[graph->edges[i].u] && !visited[graph->edges[i].v]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given graph matches the clues
int checkClues(Graph* graph, int Q, int A[], int B[], int C[]) {
    for (int i = 0; i < Q; i++) {
        if (C[i] == 0 && !checkOnePath(graph, A[i], B[i])) {
            return 0;
        }
        if (C[i] == 1 && !checkMultiplePaths(graph, A[i], B[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    // Initialize the graph
    Graph* graph = initGraph(N, M);

    // Input the edges of the graph
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Input the clues
    int A[MAX_Q], B[MAX_Q], C[MAX_Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &A[i], &B[i], &C[i]);
    }

    // Check if the graph is connected
    if (!isConnected(graph)) {
        printf("No\n");
        free(graph->edges);
        free(graph);
        return 0;
    }

    // Check if the graph matches the clues
    if (checkClues(graph, Q, A, B, C)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(graph->edges);
    free(graph);

    return 0;
}