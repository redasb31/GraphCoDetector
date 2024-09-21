#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent a node in the tree
typedef struct Node {
    int parent;
    int degree;
    int children[MAX_N];
} Node;

// Function to create a new node
Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent = -1;
    node->degree = 0;
    return node;
}

// Function to add a child to a node
void addChild(Node* parent, int child) {
    parent->children[parent->degree] = child;
    parent->degree++;
}

// Function to find the root of the tree
int findRoot(Node* nodes, int n) {
    for (int i = 1; i <= n; i++) {
        if (nodes[i].parent == -1) {
            return i;
        }
    }
    return -1;
}

// Function to restore the original tree
void restoreTree(Node* nodes, int n, int m, int* a, int* b) {
    // Create a graph with the given edges
    for (int i = 0; i < n - 1 + m; i++) {
        nodes[b[i]].parent = a[i];
    }

    // Find the root of the tree
    int root = findRoot(nodes, n);

    // Iterate over each node
    for (int i = 1; i <= n; i++) {
        // If the node is not the root and its degree is greater than 1, it is not part of the original tree
        if (i != root && nodes[i].degree > 1) {
            // Find the parent of the node in the original tree
            for (int j = 0; j < nodes[i].degree; j++) {
                int child = nodes[i].children[j];
                if (child != nodes[i].parent) {
                    nodes[i].parent = child;
                    break;
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create an array of nodes
    Node* nodes = (Node*)malloc((n + 1) * sizeof(Node));
    for (int i = 1; i <= n; i++) {
        nodes[i] = *createNode();
    }

    // Read the edges
    int* a = (int*)malloc((n - 1 + m) * sizeof(int));
    int* b = (int*)malloc((n - 1 + m) * sizeof(int));
    for (int i = 0; i < n - 1 + m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        addChild(&nodes[a[i]], b[i]);
        addChild(&nodes[b[i]], a[i]); // Add edge in both directions for graph representation
    }

    // Restore the original tree
    restoreTree(nodes, n, m, a, b);

    // Print the parent of each node
    for (int i = 1; i <= n; i++) {
        printf("%d\n", nodes[i].parent);
    }

    free(nodes);
    free(a);
    free(b);
    return 0;
}