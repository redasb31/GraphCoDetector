#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct Node {
    int id;
    int left;
    int right;
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
    char type[20];
};

// Function to create a new node
struct Node* newNode(int id, int left, int right) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->id = id;
    node->left = left;
    node->right = right;
    node->parent = -1;
    node->sibling = -1;
    node->degree = 0;
    node->depth = 0;
    node->height = 0;
    strcpy(node->type, "leaf"); 
    return node;
}

// Function to calculate the height of a node
int height(struct Node* node, struct Node* tree[], int n) {
    if (node->left == -1 && node->right == -1) {
        return 0;
    }
    
    int leftHeight = 0, rightHeight = 0;
    if (node->left != -1) {
        leftHeight = height(tree[node->left], tree, n) + 1;
    }
    if (node->right != -1) {
        rightHeight = height(tree[node->right], tree, n) + 1;
    }
    return (leftHeight > rightHeight) ? leftHeight : rightHeight;
}

// Function to print the information of a node
void printNode(struct Node* node) {
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", 
           node->id, node->parent, node->sibling, node->degree, node->depth, node->height, node->type);
}

// Function to build the binary tree from input
void buildTree(struct Node* tree[], int n) {
    for (int i = 0; i < n; i++) {
        int id, left, right;
        scanf("%d %d %d", &id, &left, &right);

        tree[id] = newNode(id, left, right);

        // Set parent and sibling information
        if (i != 0) {
            int parent = (tree[i]->id % 2 == 0) ? (tree[i]->id - 1) / 2 : (tree[i]->id - 2) / 2;
            tree[i]->parent = parent;
            if (tree[parent]->left == i) {
                if (tree[parent]->right != -1) {
                    tree[i]->sibling = tree[parent]->right;
                    tree[tree[parent]->right]->sibling = i; 
                }
            } else if (tree[parent]->right == i) {
                if (tree[parent]->left != -1) {
                    tree[i]->sibling = tree[parent]->left;
                    tree[tree[parent]->left]->sibling = i; 
                }
            }
        }
        
        // Update degree and type
        if (left != -1) {
            tree[i]->degree++;
            if (strcmp(tree[i]->type, "leaf") == 0) {
                strcpy(tree[i]->type, "internal node");
            }
        }
        if (right != -1) {
            tree[i]->degree++;
            if (strcmp(tree[i]->type, "leaf") == 0) {
                strcpy(tree[i]->type, "internal node");
            }
        }
    }
    
    // Set depth of each node
    for (int i = 1; i < n; i++) {
        tree[i]->depth = tree[tree[i]->parent]->depth + 1;
    }

    // Calculate height of each node
    for (int i = 0; i < n; i++) {
        tree[i]->height = height(tree[i], tree, n);
    }
    
    // Update root node type
    if (tree[0]->degree > 0) {
        strcpy(tree[0]->type, "root");
    } else {
        strcpy(tree[0]->type, "root");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* tree[n];
    
    buildTree(tree, n);

    // Print the information of each node
    for (int i = 0; i < n; i++) {
        printNode(tree[i]);
    }
    
    for (int i = 0; i < n; i++) {
        free(tree[i]);
    }
    return 0;
}