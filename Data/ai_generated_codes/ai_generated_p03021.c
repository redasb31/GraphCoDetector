#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 2000

// Structure for a node in the tree
typedef struct Node {
    int id;
    int parent;
    int pieces;
    int depth;
    int children_count;
    struct Node* children[MAX_N];
} Node;

// Function to create a new node
Node* createNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->parent = -1;
    node->pieces = 0;
    node->depth = 0;
    node->children_count = 0;
    memset(node->children, 0, sizeof(node->children));
    return node;
}

// Function to add a child to a node
void addChild(Node* parent, Node* child) {
    parent->children[parent->children_count++] = child;
    child->parent = parent->id;
}

// Function to build the tree from the given input
Node* buildTree(int n, int* a, int* b, char* s) {
    // Create an array of nodes
    Node* nodes[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        nodes[i] = createNode(i);
    }

    // Set the number of pieces on each node
    for (int i = 0; i < n; i++) {
        nodes[i + 1]->pieces = s[i] - '0';
    }

    // Add edges to the tree
    for (int i = 0; i < n - 1; i++) {
        addChild(nodes[a[i]], nodes[b[i]]);
        addChild(nodes[b[i]], nodes[a[i]]);
    }

    // Find the root of the tree (the node with no parent)
    Node* root = NULL;
    for (int i = 1; i <= n; i++) {
        if (nodes[i]->parent == -1) {
            root = nodes[i];
            break;
        }
    }

    // Calculate the depth of each node
    int depth = 0;
    calculateDepth(root, depth);

    // Return the root of the tree
    return root;
}

// Function to calculate the depth of each node
void calculateDepth(Node* node, int depth) {
    node->depth = depth;
    for (int i = 0; i < node->children_count; i++) {
        calculateDepth(node->children[i], depth + 1);
    }
}

// Function to calculate the minimum number of operations
int calculateOperations(Node* root) {
    // Calculate the total number of pieces
    int totalPieces = 0;
    for (int i = 1; i <= MAX_N; i++) {
        totalPieces += root->pieces;
    }

    // If there is only one piece, no operations are needed
    if (totalPieces == 1) {
        return 0;
    }

    // If there are no pieces, it's impossible to gather them
    if (totalPieces == 0) {
        return -1;
    }

    // Calculate the number of pieces on each subtree
    calculateSubtreePieces(root);

    // Find the node with the maximum number of pieces
    Node* maxNode = findMaxPiecesNode(root);

    // Calculate the number of operations required
    int operations = 0;
    for (int i = 0; i < maxNode->children_count; i++) {
        operations += maxNode->children[i]->pieces;
    }

    // Return the number of operations
    return operations;
}

// Function to calculate the number of pieces on each subtree
void calculateSubtreePieces(Node* node) {
    for (int i = 0; i < node->children_count; i++) {
        calculateSubtreePieces(node->children[i]);
        node->pieces += node->children[i]->pieces;
    }
}

// Function to find the node with the maximum number of pieces
Node* findMaxPiecesNode(Node* node) {
    Node* maxNode = node;
    for (int i = 0; i < node->children_count; i++) {
        Node* childMaxNode = findMaxPiecesNode(node->children[i]);
        if (childMaxNode->pieces > maxNode->pieces) {
            maxNode = childMaxNode;
        }
    }
    return maxNode;
}

int main() {
    // Read the input
    int n;
    scanf("%d", &n);
    char s[MAX_N + 1];
    scanf("%s", s);
    int a[MAX_N], b[MAX_N];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }

    // Build the tree
    Node* root = buildTree(n, a, b, s);

    // Calculate the minimum number of operations
    int operations = calculateOperations(root);

    // Print the output
    printf("%d\n", operations);

    return 0;
}