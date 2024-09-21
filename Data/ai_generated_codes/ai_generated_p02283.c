#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = node->parent = NULL;
    return node;
}

// Function to insert a new node into the tree
void insert(struct Node** root, int key) {
    struct Node* z = newNode(key);
    struct Node* y = NULL; // parent of z
    struct Node* x = *root;

    // Traverse the tree to find the appropriate position
    while (x != NULL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    // Insert the new node
    z->parent = y;
    if (y == NULL) { // Tree is empty
        *root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf(" %d", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf(" %d", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    int m, key;
    char operation[10];
    struct Node* root = NULL;

    // Read the number of operations
    scanf("%d", &m);

    // Process each operation
    for (int i = 0; i < m; i++) {
        scanf("%s", operation);

        // Insert operation
        if (operation[0] == 'i') {
            scanf("%d", &key);
            insert(&root, key);
        }

        // Print operation
        else if (operation[0] == 'p') {
            printf("\n"); // Add a newline before printing the output
            printf("Inorder: ");
            inorderTraversal(root);
            printf("\nPreorder: ");
            preorderTraversal(root);
        }
    }

    return 0;
}