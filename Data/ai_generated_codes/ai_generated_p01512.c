#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the tree
typedef struct Node {
    int data;
    int parent;
    int depth; // Depth of the node in the tree
    int block; // Block number where the node is allocated
    struct Node* children;
    int num_children;
} Node;

// Function to create a new node
Node* createNode(int data, int parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->parent = parent;
    newNode->depth = 0; // Initialize depth to 0
    newNode->block = -1; // Initialize block to -1
    newNode->children = NULL;
    newNode->num_children = 0;
    return newNode;
}

// Function to add a child to a node
void addChild(Node* parent, Node* child) {
    parent->children = (Node*)realloc(parent->children, (parent->num_children + 1) * sizeof(Node));
    parent->children[parent->num_children] = *child;
    parent->num_children++;
}

// Function to calculate the depth of each node in the tree
void calculateDepth(Node* root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root->num_children; i++) {
        root->children[i].depth = root->depth + 1;
        calculateDepth(&root->children[i]);
    }
}

// Function to perform the allocation of nodes to blocks
void allocateBlocks(Node* root, int B) {
    if (root == NULL) {
        return;
    }

    // Allocate the root node to block 0
    root->block = 0;

    // Allocate children recursively
    for (int i = 0; i < root->num_children; i++) {
        // Allocate children to the same block as the parent if possible
        if (root->children[i].depth % B == root->depth % B) {
            root->children[i].block = root->block;
        } else {
            // Otherwise, allocate to a new block
            root->children[i].block = root->block + 1;
        }
        allocateBlocks(&root->children[i], B);
    }
}

// Function to calculate the cost of allocation for a given tree
int calculateCost(Node* root) {
    int maxCost = 0;

    if (root == NULL) {
        return 0;
    }

    // Calculate the cost for each child recursively
    for (int i = 0; i < root->num_children; i++) {
        int childCost = calculateCost(&root->children[i]);

        // If the child is in a different block, the cost is increased by 1
        if (root->children[i].block != root->block) {
            childCost++;
        }

        // Update the maximum cost
        maxCost = (childCost > maxCost) ? childCost : maxCost;
    }

    return maxCost;
}

int main() {
    int N, B, caseNum = 1;

    while (1) {
        scanf("%d %d", &N, &B);

        // End of input
        if (N == 0 && B == 0) {
            break;
        }

        // Create the tree
        Node* root = createNode(1, 0);
        Node* nodes = (Node*)malloc(N * sizeof(Node));
        nodes[0] = *root;

        // Read the parent information
        for (int i = 1; i < N; i++) {
            int parent;
            scanf("%d", &parent);

            nodes[i] = *createNode(i + 1, parent);
            addChild(&nodes[parent - 1], &nodes[i]);
        }

        // Calculate the depth of each node
        calculateDepth(root);

        // Print the case number
        printf("Case %d:\n", caseNum);

        // Allocate the nodes to blocks
        allocateBlocks(root, B);

        // Calculate and print the cost for each node as the root
        for (int i = 0; i < N; i++) {
            nodes[i].block = 0; // Set the current node as the root
            allocateBlocks(&nodes[i], B);
            int cost = calculateCost(&nodes[i]);
            printf("%d\n", cost);
        }

        // Free memory
        free(nodes);
        free(root);

        caseNum++;
    }

    return 0;
}