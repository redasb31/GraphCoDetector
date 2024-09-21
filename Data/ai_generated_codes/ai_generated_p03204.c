#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

// Structure to represent an edge in the tree
typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

// Structure to represent a node in the tree
typedef struct Node {
    int id;
    Edge* edges;
    int visited;
    int distance;
} Node;

// Function to create a new edge
Edge* createEdge(int to) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->next = NULL;
    return newEdge;
}

// Function to add an edge to a node
void addEdge(Node* node, int to) {
    Edge* newEdge = createEdge(to);
    newEdge->next = node->edges;
    node->edges = newEdge;
}

// Function to perform Depth First Search (DFS) from a given node
void dfs(Node* node, Node* nodes, int* dist) {
    node->visited = 1;
    dist[node->id] = node->distance;

    // Iterate over all edges of the current node
    Edge* edge = node->edges;
    while (edge != NULL) {
        // If the adjacent node is not visited, perform DFS from it
        if (!nodes[edge->to].visited) {
            nodes[edge->to].distance = node->distance + 1;
            dfs(&nodes[edge->to], nodes, dist);
        }
        edge = edge->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // Create an array of nodes
    Node* nodes = (Node*)malloc(sizeof(Node) * (N + 1));

    // Initialize nodes
    for (int i = 1; i <= N; i++) {
        nodes[i].id = i;
        nodes[i].edges = NULL;
        nodes[i].visited = 0;
        nodes[i].distance = 0;
    }

    // Read input edges
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(&nodes[a], b);
        addEdge(&nodes[b], a);
    }

    // Perform DFS from node 1
    int dist[MAX_N + 1] = {0};
    dfs(&nodes[1], nodes, dist);

    // Print the distances for each node
    for (int i = 2; i <= N; i++) {
        printf("%d ", dist[i]);
    }

    printf("\n");

    // Free allocated memory
    free(nodes);

    return 0;
}