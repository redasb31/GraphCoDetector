#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 998244353

// Structure for representing a node in the tree
typedef struct Node {
    int id;
    int parent;
    int depth;
    int subtree_size;
    int *children;
    int num_children;
} Node;

// Function to create a new node
Node* create_node(int id, int parent) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->parent = parent;
    node->depth = 0;
    node->subtree_size = 1;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

// Function to add a child to a node
void add_child(Node *parent, Node *child) {
    parent->children = (Node**)realloc(parent->children, sizeof(Node*) * (parent->num_children + 1));
    parent->children[parent->num_children++] = child;
}

// Function to perform a depth-first search (DFS)
void dfs(Node *node, Node *nodes, int *diameter) {
    // Calculate the depth of the current node
    node->depth = (node->parent == -1) ? 0 : nodes[node->parent].depth + 1;

    // Update the maximum diameter
    *diameter = (node->depth > *diameter) ? node->depth : *diameter;

    // Recursively traverse the children
    for (int i = 0; i < node->num_children; i++) {
        dfs(node->children[i], nodes, diameter);
        node->subtree_size += node->children[i]->subtree_size;
    }
}

// Function to calculate the number of valid graphs
long long calculate_graphs(Node *nodes, int N, int diameter) {
    // Calculate the number of nodes at the maximum depth
    int max_depth_count = 0;
    for (int i = 1; i <= N; i++) {
        if (nodes[i].depth == diameter) {
            max_depth_count++;
        }
    }

    // Calculate the number of valid graphs
    long long count = 1;
    for (int i = 1; i <= N; i++) {
        // If the current node is not at the maximum depth
        if (nodes[i].depth < diameter) {
            // Calculate the number of possible edges
            long long edges = (long long)nodes[i].subtree_size * (N - nodes[i].subtree_size);
            // Update the count
            count = (count * (edges + 1)) % MOD;
        }
    }

    // If there are multiple nodes at the maximum depth, we need to account for the edges between them
    if (max_depth_count > 1) {
        // Calculate the number of possible edges
        long long edges = (long long)max_depth_count * (max_depth_count - 1) / 2;
        // Update the count
        count = (count * (edges + 1)) % MOD;
    }

    // Return the final count
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    // Create an array of nodes
    Node *nodes = (Node*)malloc(sizeof(Node) * (N + 1));
    for (int i = 1; i <= N; i++) {
        nodes[i] = *create_node(i, -1);
    }

    // Read the edges of the tree
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_child(&nodes[a], &nodes[b]);
        nodes[b].parent = a;
    }

    // Find the diameter of the tree
    int diameter = 0;
    dfs(&nodes[1], nodes, &diameter);

    // Calculate the number of valid graphs
    long long count = calculate_graphs(nodes, N, diameter);

    // Print the answer
    printf("%lld\n", count);

    // Free the memory
    free(nodes);
    return 0;
}