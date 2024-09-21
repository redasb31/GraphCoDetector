#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node *root = NULL; // Root of the BST

// Function to create a new node
Node *newNode(int key) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = node->parent = NULL;
    return node;
}

// Function to insert a node into the BST
void insert(int key) {
    Node *node = newNode(key);
    Node *y = NULL;
    Node *x = root;

    while (x != NULL) {
        y = x;
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == NULL) {
        root = node;
    } else if (key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
}

// Function to find a node in the BST
Node *find(int key) {
    Node *x = root;
    while (x != NULL && key != x->key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}

// Function to find the minimum node in a subtree
Node *treeMinimum(Node *x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

// Function to find the successor of a node
Node *successor(Node *x) {
    if (x->right != NULL) {
        return treeMinimum(x->right);
    }
    Node *y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

// Function to delete a node from the BST
void delete(int key) {
    Node *z = find(key);
    if (z == NULL) {
        return; // Key not found
    }

    if (z->left == NULL) { // Case 1: z has no left child
        transplant(z, z->right);
    } else if (z->right == NULL) { // Case 2: z has no right child
        transplant(z, z->left);
    } else { // Case 3: z has two children
        Node *y = successor(z);
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    free(z);
}

// Function to transplant a node (replace one node with another)
void transplant(Node *u, Node *v) {
    if (u->parent == NULL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

// Function to print the keys in inorder traversal
void inorderTreeWalk(Node *x) {
    if (x != NULL) {
        inorderTreeWalk(x->left);
        printf(" %d", x->key);
        inorderTreeWalk(x->right);
    }
}

// Function to print the keys in preorder traversal
void preorderTreeWalk(Node *x) {
    if (x != NULL) {
        printf(" %d", x->key);
        preorderTreeWalk(x->left);
        preorderTreeWalk(x->right);
    }
}

int main() {
    int m, key;
    char operation[10];

    scanf("%d", &m);

    while (m--) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "insert") == 0) {
            insert(key);
        } else if (strcmp(operation, "find") == 0) {
            Node *node = find(key);
            if (node != NULL) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (strcmp(operation, "delete") == 0) {
            delete(key);
        } else if (strcmp(operation, "print") == 0) {
            printf(" ");
            inorderTreeWalk(root);
            printf("\n ");
            preorderTreeWalk(root);
            printf("\n");
        }
    }

    return 0;
}