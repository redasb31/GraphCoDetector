#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent an edge in the tree
struct Edge {
    int u;
    int v;
};

// Structure to represent a node in the tree
struct Node {
    int id;
    int size;
    int parent;
    struct Edge* edge;
    struct Node* children;
    int child_count;
};

// Function to create a new node
struct Node* createNode(int id) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->id = id;
    node->size = 1;
    node->parent = -1;
    node->edge = NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// Function to create a new edge
struct Edge* createEdge(int u, int v) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->u = u;
    edge->v = v;
    return edge;
}

// Function to add a child to a node
void addChild(struct Node* parent, struct Node* child, struct Edge* edge) {
    parent->child_count++;
    parent->children = (struct Node*)realloc(parent->children, parent->child_count * sizeof(struct Node));
    parent->children[parent->child_count - 1] = child;
    child->parent = parent->id;
    child->edge = edge;
}

// Function to build the tree from the input edges
struct Node* buildTree(int n, struct Edge* edges) {
    struct Node* nodes[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        nodes[i] = createNode(i);
    }

    for (int i = 0; i < n - 1; i++) {
        struct Edge* edge = &edges[i];
        addChild(nodes[edge->u], nodes[edge->v], edge);
        addChild(nodes[edge->v], nodes[edge->u], edge);
    }

    return nodes[1];
}

// Function to calculate the size of a subtree rooted at a given node
int calculateSubtreeSize(struct Node* node) {
    if (node->size != -1) {
        return node->size;
    }

    node->size = 1;
    for (int i = 0; i < node->child_count; i++) {
        node->size += calculateSubtreeSize(node->children[i]);
    }

    return node->size;
}

// Function to find the optimal path that maximizes the number of connected components
int findOptimalPath(struct Node* root, int k, int* max_components) {
    // Calculate the size of each subtree
    calculateSubtreeSize(root);

    // Initialize the maximum number of components to 0
    *max_components = 0;

    // Iterate over all edges in the tree
    for (int i = 0; i < root->child_count; i++) {
        struct Node* child = root->children[i];
        struct Edge* edge = child->edge;

        // Calculate the number of components if the current edge is removed
        int components = 0;
        if (root->size - child->size >= k) {
            components++;
        }
        if (child->size >= k) {
            components++;
        }

        // Recursively explore the child subtree to find the best path
        int child_components;
        findOptimalPath(child, k, &child_components);

        // Update the maximum number of components
        *max_components = (*max_components > components + child_components) ? *max_components : components + child_components;
    }

    return *max_components;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Allocate memory for the edges of the tree
    struct Edge* edges = (struct Edge*)malloc((n - 1) * sizeof(struct Edge));

    // Read the edges from the input
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    // Build the tree from the edges
    struct Node* root = buildTree(n, edges);

    // Find the optimal path and the maximum number of components
    int max_components;
    findOptimalPath(root, k, &max_components);

    // Print the result
    printf("%d\n", max_components);

    // Free the allocated memory
    free(edges);
    free(root);

    return 0;
}