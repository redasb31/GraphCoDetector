#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

// Structure to represent a node in the tree
typedef struct Node {
    int id;
    int parent;
    int child_count;
    struct Node *children[MAX_N];
} Node;

// Function to create a new node
Node* createNode(int id) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->id = id;
    node->parent = -1;
    node->child_count = 0;
    for (int i = 0; i < MAX_N; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to add a child to a node
void addChild(Node *parent, Node *child) {
    parent->children[parent->child_count++] = child;
    child->parent = parent->id;
}

// Function to find the winner of the game
char findWinner(Node *root, int isTakahashiTurn) {
    // Base case: If the tree has only one node, the player whose turn it is wins
    if (root->child_count == 0) {
        return isTakahashiTurn ? 'F' : 'S';
    }

    // Find the child with the maximum number of coins
    int maxCoins = 0, maxChild = -1;
    for (int i = 0; i < root->child_count; i++) {
        if (root->children[i]->child_count > maxCoins) {
            maxCoins = root->children[i]->child_count;
            maxChild = i;
        }
    }

    // Remove the coin from the root node
    root->child_count--;

    // Recursively call the function for the child with the maximum coins
    char winner = findWinner(root->children[maxChild], !isTakahashiTurn);

    // Add the removed coin back to the root node (for backtracking)
    root->child_count++;

    // Return the winner
    return winner;
}

int main() {
    int N;
    scanf("%d", &N);

    // Create the tree
    Node *nodes[MAX_N];
    for (int i = 0; i < N; i++) {
        nodes[i] = createNode(i + 1);
    }

    // Read the edges of the tree
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addChild(nodes[a - 1], nodes[b - 1]);
        addChild(nodes[b - 1], nodes[a - 1]);
    }

    // Find the winner of the game
    char winner = findWinner(nodes[0], 1);

    // Print the winner
    printf("%c\n", winner);

    return 0;
}