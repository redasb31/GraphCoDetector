#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10000
#define MAX_EDGES 100000

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int indegree[MAX_VERTICES]; // Array to store indegree of each vertex
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    // Initialize adjacency matrix and indegree array to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
        graph->indegree[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int s, int t) {
    graph->adj[s][t] = 1;
    graph->indegree[t]++; // Increment indegree of the target vertex
}

// Function to perform topological sort using Kahn's algorithm
void topologicalSort(struct Graph* graph) {
    int *queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    // Add vertices with indegree 0 to the queue
    for (int i = 0; i < graph->V; i++) {
        if (graph->indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // While the queue is not empty
    while (front < rear) {
        // Dequeue a vertex from the queue
        int u = queue[front++];

        // Print the dequeued vertex
        printf("%d\n", u);

        // For each adjacent vertex of the dequeued vertex
        for (int v = 0; v < graph->V; v++) {
            if (graph->adj[u][v] == 1) {
                // Decrement the indegree of the adjacent vertex
                graph->indegree[v]--;
                // If the indegree of the adjacent vertex becomes 0, enqueue it
                if (graph->indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    free(queue);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Create a graph with V vertices and E edges
    struct Graph* graph = createGraph(V, E);

    // Add edges to the graph
    for (int i = 0; i < E; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        addEdge(graph, s, t);
    }

    // Perform topological sort
    topologicalSort(graph);

    free(graph);

    return 0;
}