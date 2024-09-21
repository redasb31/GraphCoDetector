#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50
#define MAX_E (MAX_N - 1)

// Structure to represent an edge
typedef struct Edge {
    int u, v;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int n; // Number of vertices
    Edge edges[MAX_E]; // Array of edges
} Graph;

// Function to create a new graph
Graph *createGraph(int n) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->n = n;
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->edges[graph->n - 1].u = u;
    graph->edges[graph->n - 1].v = v;
    graph->n++;
}

// Function to find the degree of a vertex
int degree(Graph *graph, int u) {
    int deg = 0;
    for (int i = 0; i < graph->n - 1; i++) {
        if (graph->edges[i].u == u || graph->edges[i].v == u) {
            deg++;
        }
    }
    return deg;
}

// Function to check if a vertex is a leaf
int isLeaf(Graph *graph, int u) {
    return degree(graph, u) == 1;
}

// Function to find the parent of a vertex in a tree
int findParent(Graph *graph, int u) {
    for (int i = 0; i < graph->n - 1; i++) {
        if (graph->edges[i].u == u || graph->edges[i].v == u) {
            if (graph->edges[i].u == u) {
                return graph->edges[i].v;
            } else {
                return graph->edges[i].u;
            }
        }
    }
    return -1;
}

// Function to check if two trees are isomorphic
int isIsomorphic(Graph *graph1, Graph *graph2) {
    if (graph1->n != graph2->n) {
        return 0;
    }

    // Sort the edges of both graphs
    for (int i = 0; i < graph1->n - 1; i++) {
        for (int j = i + 1; j < graph1->n - 1; j++) {
            if (graph1->edges[i].u > graph1->edges[i].v) {
                int temp = graph1->edges[i].u;
                graph1->edges[i].u = graph1->edges[i].v;
                graph1->edges[i].v = temp;
            }
            if (graph1->edges[j].u > graph1->edges[j].v) {
                int temp = graph1->edges[j].u;
                graph1->edges[j].u = graph1->edges[j].v;
                graph1->edges[j].v = temp;
            }
        }
    }
    for (int i = 0; i < graph2->n - 1; i++) {
        for (int j = i + 1; j < graph2->n - 1; j++) {
            if (graph2->edges[i].u > graph2->edges[i].v) {
                int temp = graph2->edges[i].u;
                graph2->edges[i].u = graph2->edges[i].v;
                graph2->edges[i].v = temp;
            }
            if (graph2->edges[j].u > graph2->edges[j].v) {
                int temp = graph2->edges[j].u;
                graph2->edges[j].u = graph2->edges[j].v;
                graph2->edges[j].v = temp;
            }
        }
    }

    // Compare the edges of both graphs
    for (int i = 0; i < graph1->n - 1; i++) {
        if (graph1->edges[i].u != graph2->edges[i].u ||
            graph1->edges[i].v != graph2->edges[i].v) {
            return 0;
        }
    }
    return 1;
}

// Function to find the minimum number of operations required to transform A to B
int minOperations(Graph *graphA, Graph *graphB) {
    if (!isIsomorphic(graphA, graphB)) {
        return -1;
    }

    // Create a copy of graphA
    Graph *graphAcopy = createGraph(graphA->n);
    for (int i = 0; i < graphA->n - 1; i++) {
        addEdge(graphAcopy, graphA->edges[i].u, graphA->edges[i].v);
    }

    int operations = 0;
    for (int i = 0; i < graphAcopy->n - 1; i++) {
        // Find a leaf vertex in graphAcopy
        int leaf = -1;
        for (int j = 1; j <= graphAcopy->n; j++) {
            if (isLeaf(graphAcopy, j)) {
                leaf = j;
                break;
            }
        }

        // Find the parent of the leaf vertex
        int parent = findParent(graphAcopy, leaf);

        // Find the edge in graphB that corresponds to the edge between the leaf and its parent
        int edgeIndex = -1;
        for (int j = 0; j < graphB->n - 1; j++) {
            if ((graphB->edges[j].u == leaf && graphB->edges[j].v == parent) ||
                (graphB->edges[j].u == parent && graphB->edges[j].v == leaf)) {
                edgeIndex = j;
                break;
            }
        }

        // If the corresponding edge is not found, then the trees cannot be transformed
        if (edgeIndex == -1) {
            return -1;
        }

        // Remove the edge between the leaf and its parent in graphAcopy
        for (int j = 0; j < graphAcopy->n - 1; j++) {
            if ((graphAcopy->edges[j].u == leaf && graphAcopy->edges[j].v == parent) ||
                (graphAcopy->edges[j].u == parent && graphAcopy->edges[j].v == leaf)) {
                graphAcopy->edges[j] = graphAcopy->edges[graphAcopy->n - 2];
                graphAcopy->n--;
                break;
            }
        }

        // Add the edge from the leaf vertex to the other vertex in the corresponding edge in graphB
        addEdge(graphAcopy, leaf, graphB->edges[edgeIndex].u == leaf ? graphB->edges[edgeIndex].v : graphB->edges[edgeIndex].u);

        // Increment the operation count
        operations++;
    }
    return operations;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N;
        scanf("%d", &N);

        // Create graph A
        Graph *graphA = createGraph(1);
        for (int i = 0; i < N - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            addEdge(graphA, a, b);
        }

        // Create graph B
        Graph *graphB = createGraph(1);
        for (int i = 0; i < N - 1; i++) {
            int c, d;
            scanf("%d %d", &c, &d);
            addEdge(graphB, c, d);
        }

        // Find the minimum number of operations required
        int operations = minOperations(graphA, graphB);

        // Print the result
        printf("%d\n", operations);

        // Free the memory
        free(graphA);
        free(graphB);
    }
    return 0;
}