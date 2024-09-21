#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an edge in the graph
struct Edge {
    int src;
    int dest;
    int weight;
};

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    struct Edge* edge;
};

// Function to create a graph
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the degree of a vertex
int findDegree(struct Graph* graph, int vertex) {
    int degree = 0;
    for (int i = 0; i < graph->E; i++) {
        if (graph->edge[i].src == vertex || graph->edge[i].dest == vertex) {
            degree++;
        }
    }
    return degree;
}

// Function to find the shortest distance using Chinese Postman Problem algorithm
int chinesePostman(struct Graph* graph) {
    // Find the vertices with odd degree
    int oddDegreeVertices = 0;
    for (int i = 0; i < graph->V; i++) {
        if (findDegree(graph, i) % 2 != 0) {
            oddDegreeVertices++;
        }
    }

    // If the number of odd degree vertices is even, then we can find a Eulerian cycle
    if (oddDegreeVertices % 2 == 0) {
        // Find the minimum weight matching for the odd degree vertices
        // ... (Implement your own minimum weight matching algorithm) ...
        // Calculate the total distance of the Eulerian cycle
        // ... (Implement your own algorithm to find the Eulerian cycle) ...
        // Return the total distance
    } else {
        // If the number of odd degree vertices is odd, then the problem has no solution
        return -1;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    // Create the graph
    struct Graph* graph = createGraph(V, E);

    // Read the edges and weights from the input
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    // Find the shortest distance using Chinese Postman Problem
    int shortestDistance = chinesePostman(graph);

    // Print the shortest distance
    printf("%d\n", shortestDistance);

    // Free memory
    free(graph->edge);
    free(graph);

    return 0;
}