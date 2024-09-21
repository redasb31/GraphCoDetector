#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_W 1000

// Structure to represent an edge in the tree
typedef struct Edge {
    int to; // Destination node
    int weight; // Weight of the edge
    struct Edge *next; // Pointer to the next edge in the adjacency list
} Edge;

// Structure to represent a node in the tree
typedef struct Node {
    Edge *adj; // Adjacency list of the node
} Node;

// Function to add an edge to the adjacency list
void addEdge(Node *nodes, int from, int to, int weight) {
    Edge *newEdge = (Edge *)malloc(sizeof(Edge));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = nodes[from].adj;
    nodes[from].adj = newEdge;
}

// Function to perform Depth First Search (DFS) from a given node
int dfs(Node *nodes, int node, int parent, int *depth) {
    int maxDepth = 0; // Maximum depth reached from the current node
    Edge *currEdge = nodes[node].adj;

    while (currEdge != NULL) {
        if (currEdge->to != parent) {
            int childDepth = dfs(nodes, currEdge->to, node, depth);
            // Update the maximum depth reached from the current node
            maxDepth = (maxDepth > childDepth + currEdge->weight) ? maxDepth : childDepth + currEdge->weight;
        }
        currEdge = currEdge->next;
    }

    // Update the depth of the current node in the 'depth' array
    depth[node] = maxDepth;
    return maxDepth;
}

// Function to find the diameter of the tree
int findDiameter(Node *nodes, int n) {
    int *depth = (int *)malloc(sizeof(int) * n); // Array to store depths of nodes
    int diameter = 0; // Variable to store the diameter of the tree

    // Perform DFS from an arbitrary node (node 0 in this case) to find the node with the maximum depth
    dfs(nodes, 0, -1, depth);

    int maxDepthNode = 0; // Node with the maximum depth
    for (int i = 0; i < n; i++) {
        if (depth[maxDepthNode] < depth[i]) {
            maxDepthNode = i;
        }
    }

    // Perform DFS from the node with the maximum depth to find the diameter
    dfs(nodes, maxDepthNode, -1, depth);

    // Find the maximum depth from the node with the maximum depth, which represents the diameter
    for (int i = 0; i < n; i++) {
        diameter = (diameter > depth[i]) ? diameter : depth[i];
    }

    free(depth);
    return diameter;
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for nodes
    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        nodes[i].adj = NULL;
    }

    // Read edges from input
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        scanf("%d %d %d", &s, &t, &w);
        addEdge(nodes, s, t, w);
        addEdge(nodes, t, s, w); // Since the graph is undirected
    }

    // Find the diameter of the tree
    int diameter = findDiameter(nodes, n);

    // Print the diameter
    printf("%d\n", diameter);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        Edge *currEdge = nodes[i].adj;
        while (currEdge != NULL) {
            Edge *nextEdge = currEdge->next;
            free(currEdge);
            currEdge = nextEdge;
        }
    }
    free(nodes);

    return 0;
}