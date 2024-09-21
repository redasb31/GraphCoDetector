#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the binary tree
typedef struct Node {
    int depth; // Depth of the node in the tree
    int medal; // Medal placed on the node (0 if no medal)
    struct Node *left;  // Left child
    struct Node *right; // Right child
} Node;

// Function to create a new node
Node *newNode(int depth) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->depth = depth;
    node->medal = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a perfect binary tree
Node *createBinaryTree(int depth) {
    if (depth == 0) {
        return newNode(0);
    }
    Node *root = newNode(0);
    root->left = createBinaryTree(depth - 1);
    root->right = createBinaryTree(depth - 1);
    return root;
}

// Function to find the best placement of a medal given its depth and the current state of the tree
int placeMedal(Node *root, int depth, int medal) {
    if (root == NULL) {
        return 0; // Empty node
    }

    // Check if the node itself is a valid placement
    if (root->depth == depth && root->medal == 0) {
        root->medal = medal;
        return 1; // Placement successful
    }

    // Recursively check the left and right subtrees
    if (placeMedal(root->left, depth, medal)) {
        return 1;
    }
    if (placeMedal(root->right, depth, medal)) {
        return 1;
    }

    // If the medal can't be placed, check if the placement of a medal on the current node would allow for the current medal to be placed
    if (root->medal != 0 && depth < root->depth && root->medal > medal) {
        // Remove the current medal and try placing the new medal
        int temp = root->medal;
        root->medal = medal;
        if (placeMedal(root, root->depth, temp)) {
            return 1;
        } else {
            // Reset the node's medal to the original value
            root->medal = temp;
        }
    }

    return 0; // No placement found
}

// Function to print the placement results
void printResults(Node *root, int n, int medals[]) {
    for (int i = 0; i < n; i++) {
        if (root->medal == medals[i]) {
            printf("Yes\n");
            root = root->left; // Move to the left subtree for the next medal
        } else {
            printf("No\n");
        }
    }
}

int main() {
    int n, depth, maxDepth = 0;
    scanf("%d", &n);

    // Allocate an array to store the medal values
    int *medals = (int *)malloc(sizeof(int) * n);
    if (medals == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Read the medal values from the input
    for (int i = 0; i < n; i++) {
        scanf("%d", &medals[i]);
        if (medals[i] > maxDepth) {
            maxDepth = medals[i]; // Keep track of the maximum depth
        }
    }

    // Create the binary tree with a depth equal to the maximum medal value
    Node *root = createBinaryTree(maxDepth);

    // Place the medals in the tree
    for (int i = 0; i < n; i++) {
        if (placeMedal(root, medals[i], medals[i])) {
            // Medal placed successfully
        } else {
            // Medal not placed, move to the next one
        }
    }

    // Print the results of the placement
    printResults(root, n, medals);

    // Free the memory allocated for the tree and medals array
    free(medals);
    // Free the tree (using a recursive function to free all nodes)
    // ... 

    return 0;
}