#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize a graph
struct Graph* createGraph(int numVertices, int numEdges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int source, int target) {
    graph->adjMatrix[source][target] = 1;
}

// Function to perform Depth First Search (DFS)
void dfs(struct Graph* graph, int vertex, int* visited, int* stack) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    // Push the vertex onto the stack
    stack[vertex] = 1;

    // Iterate over adjacent vertices
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1) {
            // If an adjacent vertex is not visited, recursively call DFS
            if (!visited[i]) {
                dfs(graph, i, visited, stack);
            }
            // If an adjacent vertex is in the stack, a cycle exists
            else if (stack[i]) {
                printf("1\n"); // Cycle detected
                exit(0);
            }
        }
    }
    // Remove the vertex from the stack
    stack[vertex] = 0;
}

// Function to detect a cycle in the graph using DFS
void detectCycle(struct Graph* graph) {
    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};
    // Array to keep track of vertices on the stack
    int stack[MAX_VERTICES] = {0};

    // Iterate over each vertex
    for (int i = 0; i < graph->numVertices; i++) {
        // If a vertex is not visited, perform DFS
        if (!visited[i]) {
            dfs(graph, i, visited, stack);
        }
    }

    // If no cycle is detected, print 0
    printf("0\n");
}

int main() {
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);

    struct Graph* graph = createGraph(numVertices, numEdges);

    int source, target;
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &source, &target);
        addEdge(graph, source, target);
    }

    detectCycle(graph);

    free(graph);

    return 0;
}