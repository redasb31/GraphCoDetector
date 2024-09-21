#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent a node in the tree
typedef struct Node {
    int id; // Node ID
    int color; // Color of the node
    int degree; // Number of edges connected to the node
    struct Node *parent; // Pointer to the parent node
    struct Node *children[MAX_N]; // Array to store pointers to child nodes
} Node;

// Function to create a new node
Node *createNode(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->color = 0; // Initially uncolored
    node->degree = 0;
    node->parent = NULL;
    for (int i = 0; i < MAX_N; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to add an edge between two nodes
void addEdge(Node *node1, Node *node2) {
    node1->children[node1->degree] = node2;
    node1->degree++;
    node2->children[node2->degree] = node1;
    node2->degree++;
}

// Function to color the tree using a greedy approach
int colorTree(Node *root, int *colors) {
    // Color the root node with color 1
    root->color = 1;
    int maxColor = 1;

    // Traverse the tree in a depth-first manner
    for (int i = 0; i < root->degree; i++) {
        Node *child = root->children[i];
        // If the child is not the parent, color it
        if (child != root->parent) {
            // Find the minimum available color for the child
            int color = 1;
            while (color <= maxColor && (child->color == color || root->color == color)) {
                color++;
            }
            // Color the child with the chosen color
            child->color = color;
            // Update the maximum color used
            if (color > maxColor) {
                maxColor = color;
            }
            // Recursively color the subtree rooted at the child
            maxColor = colorTree(child, colors);
        }
    }

    return maxColor;
}

int main() {
    int N;
    scanf("%d", &N);

    // Create an array of nodes
    Node *nodes[MAX_N];
    for (int i = 0; i < N; i++) {
        nodes[i] = createNode(i + 1);
    }

    // Read the edges and connect the nodes
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(nodes[a - 1], nodes[b - 1]);
    }

    // Choose an arbitrary node as the root of the tree
    Node *root = nodes[0];

    // Allocate memory for the colors array
    int *colors = (int *)malloc(sizeof(int) * (N - 1));

    // Color the tree and get the maximum color used
    int K = colorTree(root, colors);

    // Print the number of colors used
    printf("%d\n", K);

    // Print the colors of the edges
    for (int i = 0; i < N - 1; i++) {
        // Find the edge that connects node i + 1 to its parent
        Node *node1 = nodes[i];
        Node *node2 = node1->parent;
        if (node2 == NULL) {
            // Find the first child node of node i + 1
            node2 = node1->children[0];
        }
        // Determine the color of the edge
        int color = (node1->color == node2->color) ? node1->color : node2->color;
        // Print the color of the edge
        printf("%d\n", color);
    }

    // Free the allocated memory
    free(colors);
    for (int i = 0; i < N; i++) {
        free(nodes[i]);
    }

    return 0;
}