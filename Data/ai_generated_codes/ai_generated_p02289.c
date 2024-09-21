#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the priority queue
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node into the priority queue
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        root->left = insert(root->left, key);
    }
    return root;
}

// Function to find the node with the maximum key
struct Node* findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Function to extract the node with the maximum key
struct Node* extractMax(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* maxNode = findMax(root);
    // If the max node is the root, update the root
    if (maxNode == root) {
        if (root->left != NULL) {
            root = root->left;
        } else {
            root = NULL;
        }
    } else {
        // Find the parent of the max node
        struct Node* parent = root;
        while (parent->right != maxNode) {
            parent = parent->right;
        }
        // Remove the max node from the tree
        if (maxNode->left != NULL) {
            parent->right = maxNode->left;
        } else {
            parent->right = NULL;
        }
    }
    free(maxNode);
    return root;
}

int main() {
    struct Node* root = NULL;
    char operation[10];
    int key;
    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &key);
            root = insert(root, key);
        } else if (strcmp(operation, "extract") == 0) {
            if (root != NULL) {
                root = extractMax(root);
                printf("%d\n", key);
            }
        } else if (strcmp(operation, "end") == 0) {
            break;
        }
    }
    return 0;
}