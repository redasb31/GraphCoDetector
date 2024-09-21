#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

// Structure to represent an edge
typedef struct Edge {
    int src;
    int dest;
    int cost;
} Edge;

// Structure to represent a node in the graph
typedef struct Node {
    int id;
    int visited;
    Edge *edges;
    int edgeCount;
} Node;

// Function to create a new node
Node *createNode(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->visited = 0;
    node->edges = NULL;
    node->edgeCount = 0;
    return node;
}

// Function to add an edge to a node
void addEdge(Node *node, Edge edge) {
    node->edges = (Edge *)realloc(node->edges, (node->edgeCount + 1) * sizeof(Edge));
    node->edges[node->edgeCount++] = edge;
}

// Function to find the minimum cost edge
Edge findMinEdge(Node *nodes, int n) {
    Edge minEdge = {0, 0, 1001}; // Initialize with a high cost
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nodes[i].edgeCount; j++) {
            Edge edge = nodes[i].edges[j];
            if (edge.cost < minEdge.cost) {
                minEdge = edge;
            }
        }
    }
    return minEdge;
}

// Function to find a spanning tree using Prim's algorithm
void findSpanningTree(Node *nodes, int n, int m) {
    int treeEdges = 0;
    Edge minEdge;
    Edge edges[MAX_EDGES]; // Store the edges in the spanning tree

    // Start with an arbitrary node
    nodes[0].visited = 1;

    // Find the minimum cost edge connecting the tree to a non-tree node
    while (treeEdges < n - 1) {
        minEdge = findMinEdge(nodes, n);

        // Add the edge to the spanning tree
        edges[treeEdges++] = minEdge;

        // Mark the destination node as visited
        nodes[minEdge.dest].visited = 1;
    }

    // Calculate the median cost of edges in the spanning tree
    int costSum = 0;
    for (int i = 0; i < n - 1; i++) {
        costSum += edges[i].cost;
    }

    // Calculate the median cost
    int medianCost = costSum / (n - 1);

    printf("%d\n", medianCost);
}

int main() {
    int n, m;

    while (1) {
        scanf("%d %d", &n, &m);

        // Termination condition
        if (n == 0 && m == 0) {
            break;
        }

        // Create nodes
        Node nodes[MAX_NODES];
        for (int i = 0; i < n; i++) {
            nodes[i] = *createNode(i + 1);
        }

        // Read edges and add them to nodes
        int src, dest, cost;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &src, &dest, &cost);
            addEdge(&nodes[src - 1], (Edge){src - 1, dest - 1, cost});
            addEdge(&nodes[dest - 1], (Edge){dest - 1, src - 1, cost});
        }

        // Find the spanning tree and print the median cost
        findSpanningTree(nodes, n, m);

        // Free allocated memory
        for (int i = 0; i < n; i++) {
            free(nodes[i].edges);
        }
    }

    return 0;
}