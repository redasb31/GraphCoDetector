#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the tree
typedef struct Node {
    int id;
    int parent;
    int depth;
    int degree;
    int* children;
    struct Node* left_child;
    struct Node* right_sibling;
} Node;

// Function to create a new node
Node* createNode(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->parent = -1; // Initialize parent to -1 for the root
    node->depth = 0;
    node->degree = 0;
    node->children = NULL;
    node->left_child = NULL;
    node->right_sibling = NULL;
    return node;
}

// Function to insert a child to a node
void insertChild(Node* parent, int child_id) {
    // Create a new node for the child
    Node* child = createNode(child_id);
    child->parent = parent->id;
    child->depth = parent->depth + 1;

    // If the parent has no children, make the child the leftmost child
    if (parent->left_child == NULL) {
        parent->left_child = child;
    } else {
        // Find the rightmost sibling and add the child as its right sibling
        Node* sibling = parent->left_child;
        while (sibling->right_sibling != NULL) {
            sibling = sibling->right_sibling;
        }
        sibling->right_sibling = child;
    }

    // Update the parent's degree and children array
    parent->degree++;
    parent->children = (int*)realloc(parent->children, sizeof(int) * parent->degree);
    parent->children[parent->degree - 1] = child_id;
}

// Function to print the information of a node
void printNodeInfo(Node* node) {
    printf("node %d: parent = %d, depth = %d, ", node->id, node->parent, node->depth);

    // Determine the node type
    if (node->parent == -1) {
        printf("root, ");
    } else if (node->degree == 0) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }

    // Print the children of the node
    printf("[");
    for (int i = 0; i < node->degree; i++) {
        printf("%d", node->children[i]);
        if (i < node->degree - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to perform a depth-first traversal of the tree
void dfs(Node* root) {
    if (root == NULL) {
        return;
    }

    // Print the information of the current node
    printNodeInfo(root);

    // Recursively traverse the left subtree
    dfs(root->left_child);

    // Recursively traverse the right subtree
    dfs(root->right_sibling);
}

int main() {
    int n;
    scanf("%d", &n);

    // Create an array of nodes
    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(i);
    }

    // Read the tree information from the input
    for (int i = 0; i < n; i++) {
        int id, degree;
        scanf("%d %d", &id, &degree);
        nodes[id]->degree = degree;
        nodes[id]->children = (int*)malloc(sizeof(int) * degree);

        for (int j = 0; j < degree; j++) {
            int child_id;
            scanf("%d", &child_id);
            insertChild(nodes[id], child_id);
        }
    }

    // Perform a depth-first traversal to print the information of all nodes
    dfs(nodes[0]); // Start from the root node

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(nodes[i]->children);
        free(nodes[i]);
    }

    return 0;
}