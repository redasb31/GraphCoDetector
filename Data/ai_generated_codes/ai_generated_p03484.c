#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent a node in the tree
typedef struct Node {
    int parent;
    int depth;
    int size;
    int visited;
} Node;

// Structure to represent an edge in the tree
typedef struct Edge {
    int u;
    int v;
} Edge;

// Function to find the depth of a node in the tree
int find_depth(Node *nodes, int u) {
    if (nodes[u].parent == -1) {
        return 0;
    }
    return find_depth(nodes, nodes[u].parent) + 1;
}

// Function to find the size of a subtree rooted at a given node
int find_size(Node *nodes, int u) {
    if (nodes[u].visited) {
        return 0;
    }
    nodes[u].visited = 1;
    int size = 1;
    for (int i = 0; i < nodes[u].size; i++) {
        size += find_size(nodes, nodes[u].size);
    }
    return size;
}

// Function to find the lexicographically smallest pair (A, B)
void find_min_pair(Node *nodes, int N, int *A, int *B) {
    // Initialize A and B to the maximum possible values
    *A = N - 1;
    *B = MAX_N;

    // Find the depth of each node
    for (int i = 1; i <= N; i++) {
        nodes[i].depth = find_depth(nodes, i);
    }

    // Find the size of each subtree
    for (int i = 1; i <= N; i++) {
        nodes[i].size = find_size(nodes, i);
    }

    // Iterate over all nodes
    for (int i = 1; i <= N; i++) {
        // If the current node is a leaf node
        if (nodes[i].size == 1) {
            // Calculate the number of Christmas Paths needed
            int a = (nodes[i].depth - 1) / *B + 1;

            // Update the minimum A and B values
            if (a < *A || (a == *A && nodes[i].depth < *B)) {
                *A = a;
                *B = nodes[i].depth;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // Create an array of nodes
    Node *nodes = malloc((N + 1) * sizeof(Node));
    if (nodes == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    // Initialize the nodes
    for (int i = 1; i <= N; i++) {
        nodes[i].parent = -1;
        nodes[i].depth = 0;
        nodes[i].size = 0;
        nodes[i].visited = 0;
    }

    // Create an array of edges
    Edge *edges = malloc((N - 1) * sizeof(Edge));
    if (edges == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    // Read the edges from the input
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
        // Update the parent of each node
        nodes[edges[i].v].parent = edges[i].u;
        nodes[edges[i].u].size++;
    }

    // Find the lexicographically smallest pair (A, B)
    int A, B;
    find_min_pair(nodes, N, &A, &B);

    // Print the results
    printf("%d %d\n", A, B);

    // Free the allocated memory
    free(nodes);
    free(edges);

    return 0;
}