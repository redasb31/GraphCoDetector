#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent a node in the tree
struct Node {
    int parent;
    int depth;
    int *children;
    int num_children;
};

// Function to allocate memory for a new node
struct Node* createNode(int parent, int depth) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->parent = parent;
    node->depth = depth;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

// Function to add a child to a node
void addChild(struct Node* parent, int child) {
    parent->num_children++;
    parent->children = (int*)realloc(parent->children, sizeof(int) * parent->num_children);
    parent->children[parent->num_children - 1] = child;
}

// Function to build the tree from the given input
struct Node* buildTree(int N, int A[], int B[]) {
    // Create an array of nodes
    struct Node* nodes = (struct Node*)malloc(sizeof(struct Node) * (N + 1));
    for (int i = 1; i <= N; i++) {
        nodes[i] = *createNode(-1, -1);
    }

    // Build the tree using the given edges
    for (int i = 0; i < N - 1; i++) {
        int u = A[i];
        int v = B[i];
        if (nodes[u].parent == -1) {
            nodes[u].parent = v;
            nodes[v].depth = 0;
            nodes[v].parent = 0;
            addChild(&nodes[v], u);
        } else if (nodes[v].parent == -1) {
            nodes[v].parent = u;
            nodes[u].depth = 0;
            nodes[u].parent = 0;
            addChild(&nodes[u], v);
        } else {
            // Both nodes are already part of the tree, so we need to find their lowest common ancestor
            int ancestor = u;
            while (nodes[ancestor].parent != -1) {
                ancestor = nodes[ancestor].parent;
            }
            // Update the depths of the nodes based on the depth of the LCA
            int depth_u = nodes[u].depth;
            int depth_v = nodes[v].depth;
            nodes[u].depth = nodes[ancestor].depth + depth_u;
            nodes[v].depth = nodes[ancestor].depth + depth_v;
            addChild(&nodes[ancestor], u);
            addChild(&nodes[ancestor], v);
        }
    }
    return nodes;
}

// Function to find the optimal number of moves Aoki needs to make
int findOptimalMoves(struct Node* nodes, int u, int v) {
    // Find the lowest common ancestor of u and v
    int ancestor = u;
    while (nodes[ancestor].parent != -1) {
        ancestor = nodes[ancestor].parent;
    }

    // Calculate the distance between u and the LCA
    int distance_u = nodes[u].depth - nodes[ancestor].depth;

    // Calculate the distance between v and the LCA
    int distance_v = nodes[v].depth - nodes[ancestor].depth;

    // If u and v are on the same branch, the optimal number of moves is the distance between them
    if (distance_u + distance_v == nodes[u].depth + nodes[v].depth - 2 * nodes[ancestor].depth) {
        return distance_u + distance_v - 1;
    } else {
        // If u and v are on different branches, the optimal number of moves is the sum of their distances to the LCA
        return distance_u + distance_v - 1;
    }
}

int main() {
    int N, u, v;
    scanf("%d %d %d", &N, &u, &v);

    // Create an array to store the edges
    int *A = (int*)malloc(sizeof(int) * (N - 1));
    int *B = (int*)malloc(sizeof(int) * (N - 1));

    // Read the edges from the input
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }

    // Build the tree
    struct Node* nodes = buildTree(N, A, B);

    // Find the optimal number of moves for Aoki
    int optimal_moves = findOptimalMoves(nodes, u, v);

    // Print the output
    printf("%d\n", optimal_moves);

    // Free the allocated memory
    free(A);
    free(B);
    free(nodes);

    return 0;
}