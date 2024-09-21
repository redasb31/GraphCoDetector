#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000

// Structure for representing a node in the tree
typedef struct Node {
    int id;
    int height;
    struct Node *parent;
    struct Node *children[MAX_NODES];
    int num_children;
} Node;

// Function to create a new node
Node* createNode(int id) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->height = 0;
    node->parent = NULL;
    node->num_children = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to add an edge between two nodes
void addEdge(Node *node1, Node *node2, int weight) {
    // Update the parent-child relationship
    node1->children[node1->num_children] = node2;
    node1->num_children++;
    node2->parent = node1;
}

// Function to calculate the height of a node
int calculateHeight(Node *node) {
    // Base case: Leaf node
    if (node->num_children == 0) {
        return 0;
    }

    // Recursive case: Calculate height based on children
    int max_height = 0;
    for (int i = 0; i < node->num_children; i++) {
        int child_height = calculateHeight(node->children[i]) + 1; // Add 1 for the edge weight
        if (child_height > max_height) {
            max_height = child_height;
        }
    }
    return max_height;
}

int main() {
    int n;
    scanf("%d", &n);

    // Create an array of nodes
    Node *nodes[MAX_NODES];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(i);
    }

    // Read the edges of the tree
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        scanf("%d %d %d", &s, &t, &w);
        addEdge(nodes[s], nodes[t], w);
        addEdge(nodes[t], nodes[s], w); // Undirected edge
    }

    // Calculate the height of each node
    for (int i = 0; i < n; i++) {
        nodes[i]->height = calculateHeight(nodes[i]);
        printf("%d\n", nodes[i]->height);
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }

    return 0;
}