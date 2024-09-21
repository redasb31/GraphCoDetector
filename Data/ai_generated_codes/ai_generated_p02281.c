#include <stdio.h>

// Structure to represent a node in the binary tree
struct Node {
    int id;
    int left;
    int right;
};

// Function to perform preorder traversal
void preorder(struct Node *tree, int n) {
    // If the current node is not empty
    if (tree->id != -1) {
        // Print the ID of the current node
        printf(" %d", tree->id);
        // Recursively traverse the left subtree
        if (tree->left != -1) {
            preorder(&tree[tree->left], n);
        }
        // Recursively traverse the right subtree
        if (tree->right != -1) {
            preorder(&tree[tree->right], n);
        }
    }
}

// Function to perform inorder traversal
void inorder(struct Node *tree, int n) {
    // If the current node is not empty
    if (tree->id != -1) {
        // Recursively traverse the left subtree
        if (tree->left != -1) {
            inorder(&tree[tree->left], n);
        }
        // Print the ID of the current node
        printf(" %d", tree->id);
        // Recursively traverse the right subtree
        if (tree->right != -1) {
            inorder(&tree[tree->right], n);
        }
    }
}

// Function to perform postorder traversal
void postorder(struct Node *tree, int n) {
    // If the current node is not empty
    if (tree->id != -1) {
        // Recursively traverse the left subtree
        if (tree->left != -1) {
            postorder(&tree[tree->left], n);
        }
        // Recursively traverse the right subtree
        if (tree->right != -1) {
            postorder(&tree[tree->right], n);
        }
        // Print the ID of the current node
        printf(" %d", tree->id);
    }
}

int main() {
    int n; // Number of nodes
    // Read the number of nodes
    scanf("%d", &n);

    // Declare an array to store the nodes of the tree
    struct Node tree[n];

    // Read the information of each node
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &tree[i].id, &tree[i].left, &tree[i].right);
    }

    // Print "Preorder"
    printf("Preorder\n");
    // Perform preorder traversal
    preorder(&tree[0], n);
    printf("\n");

    // Print "Inorder"
    printf("Inorder\n");
    // Perform inorder traversal
    inorder(&tree[0], n);
    printf("\n");

    // Print "Postorder"
    printf("Postorder\n");
    // Perform postorder traversal
    postorder(&tree[0], n);
    printf("\n");

    return 0;
}