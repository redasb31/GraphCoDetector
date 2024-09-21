#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build the binary tree from preorder and inorder traversals
struct Node* buildTree(int pre[], int in[], int inStart, int inEnd, int preStart, int preEnd) {
    // Base case
    if (inStart > inEnd) {
        return NULL;
    }

    // Find the index of the root node in the inorder traversal
    int rootIndex;
    for (rootIndex = inStart; rootIndex <= inEnd; rootIndex++) {
        if (in[rootIndex] == pre[preStart]) {
            break;
        }
    }

    // Create the root node
    struct Node* root = newNode(pre[preStart]);

    // Recursively build the left and right subtrees
    root->left = buildTree(pre, in, inStart, rootIndex - 1, preStart + 1, preStart + (rootIndex - inStart));
    root->right = buildTree(pre, in, rootIndex + 1, inEnd, preStart + (rootIndex - inStart) + 1, preEnd);

    return root;
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        // Recursively traverse the left subtree
        postorderTraversal(root->left);
        // Recursively traverse the right subtree
        postorderTraversal(root->right);
        // Print the root node's data
        printf("%d ", root->data);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Input for preorder traversal
    int pre[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    // Input for inorder traversal
    int in[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    // Build the binary tree
    struct Node* root = buildTree(pre, in, 0, n - 1, 0, n - 1);

    // Perform postorder traversal and print the result
    postorderTraversal(root);

    printf("\n");

    return 0;
}