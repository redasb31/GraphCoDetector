#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 300
#define MAX_M 1000

// Structure to represent a graph edge
typedef struct Edge {
    int src;
    int dest;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    Edge *edge; // Array of edges
} Graph;

// Function to create a graph
Graph *createGraph(int V, int E) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge *)malloc(E * sizeof(Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    graph->edge[graph->E].src = src;
    graph->edge[graph->E].dest = dest;
    graph->E++;
}

// Function to find the maximum flow from source to sink using Ford-Fulkerson algorithm
int fordFulkerson(Graph *graph, int s, int t) {
    // Create a residual graph
    int rGraph[MAX_N][MAX_N];
    for (int u = 1; u <= graph->V; u++) {
        for (int v = 1; v <= graph->V; v++) {
            rGraph[u][v] = 0;
        }
    }

    // Initialize residual graph with original graph edges
    for (int i = 0; i < graph->E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        rGraph[u][v] = 1;
    }

    // Initialize flow to 0
    int max_flow = 0;

    // While there is an augmenting path
    while (bfs(rGraph, s, t, graph->V)) {
        // Find minimum capacity of the path
        int path_flow = INT_MAX;
        for (int u = t; u != s; u = graph->edge[parent[u]].src) {
            path_flow = min(path_flow, rGraph[graph->edge[parent[u]].src][u]);
        }

        // Augment the flow along the path
        for (int u = t; u != s; u = graph->edge[parent[u]].src) {
            rGraph[graph->edge[parent[u]].src][u] -= path_flow;
            rGraph[u][graph->edge[parent[u]].src] += path_flow;
        }

        // Update max_flow
        max_flow += path_flow;
    }

    return max_flow;
}

// Function to perform BFS to find an augmenting path
int bfs(int rGraph[][MAX_N], int s, int t, int V) {
    // Initialize visited array
    int visited[MAX_N];
    for (int i = 1; i <= V; i++) {
        visited[i] = 0;
    }

    // Create a queue
    int queue[MAX_N];
    int front = 0, rear = 0;

    // Enqueue the source vertex
    queue[rear++] = s;
    visited[s] = 1;

    // Perform BFS
    while (front < rear) {
        int u = queue[front++];
        for (int v = 1; v <= V; v++) {
            if (rGraph[u][v] > 0 && !visited[v]) {
                queue[rear++] = v;
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }

    // Return true if the sink vertex is visited
    return visited[t];
}

// Function to reverse the direction of an edge in the graph
void reverseEdge(Graph *graph, int edge_id) {
    int src = graph->edge[edge_id].src;
    int dest = graph->edge[edge_id].dest;
    graph->edge[edge_id].src = dest;
    graph->edge[edge_id].dest = src;
}

// Function to find the maximized flow by reversing some roads
int maximizeFlow(Graph *graph, int s, int t) {
    // Find the initial flow
    int max_flow = fordFulkerson(graph, s, t);

    // Iterate over all edges and reverse them one by one
    for (int i = 0; i < graph->E; i++) {
        // Reverse the edge
        reverseEdge(graph, i);

        // Calculate the flow after reversing the edge
        int new_flow = fordFulkerson(graph, s, t);

        // If the flow is increased, keep the reversed edge
        if (new_flow > max_flow) {
            max_flow = new_flow;
            reversed_edges[reversed_edges_count++] = i + 1;
        } else {
            // Otherwise, revert the edge back to its original direction
            reverseEdge(graph, i);
        }
    }

    return max_flow;
}

// Global variables to store parent node in BFS and reversed edges
int parent[MAX_N];
int reversed_edges[MAX_M];
int reversed_edges_count = 0;

int main() {
    int N, M, s, t;
    scanf("%d %d", &N, &M);

    // Create the graph
    Graph *graph = createGraph(N, M);

    // Read the edges
    for (int i = 0; i < M; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Read the source and sink vertices
    scanf("%d %d", &s, &t);

    // Find the maximized flow
    int max_flow = maximizeFlow(graph, s, t);

    // Print the maximized flow
    printf("%d\n", max_flow);

    // Print the number of reversed edges
    printf("%d\n", reversed_edges_count);

    // Print the reversed edges
    for (int i = 0; i < reversed_edges_count; i++) {
        printf("%d\n", reversed_edges[i]);
    }

    // Free the memory
    free(graph->edge);
    free(graph);

    return 0;
}