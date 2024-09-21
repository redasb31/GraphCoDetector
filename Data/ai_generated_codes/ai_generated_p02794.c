#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50
#define MAX_M 20

// Structure to represent a node in the tree
typedef struct Node {
    int id;
    int parent;
    int num_children;
    struct Node *children[MAX_N];
} Node;

// Function to create a new node
Node *newNode(int id, int parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->parent = parent;
    node->num_children = 0;
    for (int i = 0; i < MAX_N; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to add a child to a node
void addChild(Node *parent, Node *child) {
    parent->children[parent->num_children] = child;
    parent->num_children++;
}

// Function to build the tree from the input edges
Node *buildTree(int N, int a[], int b[]) {
    // Create a root node
    Node *root = newNode(1, -1);

    // Create nodes for all vertices
    Node *nodes[MAX_N];
    nodes[0] = root;
    for (int i = 1; i < N; i++) {
        nodes[i] = newNode(i + 1, -1);
    }

    // Connect the nodes based on the edges
    for (int i = 0; i < N - 1; i++) {
        int u = a[i] - 1;
        int v = b[i] - 1;

        // Connect the nodes if they are not already connected
        if (nodes[u]->parent == -1) {
            nodes[u]->parent = v;
            addChild(nodes[v], nodes[u]);
        } else if (nodes[v]->parent == -1) {
            nodes[v]->parent = u;
            addChild(nodes[u], nodes[v]);
        }
    }

    return root;
}

// Function to count the number of ways to paint the edges
int countWays(Node *root, int M, int u[], int v[]) {
    // Initialize the number of ways to 2^(N-1)
    int ways = 1 << (root->num_children);

    // Iterate over the restrictions
    for (int i = 0; i < M; i++) {
        // Find the LCA of u[i] and v[i]
        Node *lca = root;
        int found = 0;
        while (!found) {
            for (int j = 0; j < lca->num_children; j++) {
                if (lca->children[j]->id == u[i] || lca->children[j]->id == v[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                lca = lca->children[0];
            }
        }

        // If the LCA is not the root, then the number of ways is reduced by half
        if (lca != root) {
            ways /= 2;
        }
    }

    return ways;
}

int main() {
    int N, M;
    int a[MAX_N], b[MAX_N];
    int u[MAX_M], v[MAX_M];

    // Read the input
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }

    // Build the tree
    Node *root = buildTree(N, a, b);

    // Count the number of ways to paint the edges
    int ways = countWays(root, M, u, v);

    // Print the result
    printf("%d\n", ways);

    return 0;
}