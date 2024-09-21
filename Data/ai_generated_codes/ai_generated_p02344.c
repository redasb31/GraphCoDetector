#include <stdio.h>
#include <stdlib.h>

// Structure for representing a node in the union-find tree
typedef struct Node {
    int parent;
    int rank;
    int value; // To store the difference from the root
} Node;

// Function to initialize the union-find tree with n nodes
Node* init_uf(int n) {
    Node* nodes = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
        nodes[i].value = 0; // Initial value is 0
    }
    return nodes;
}

// Function to find the root of the tree containing node x
int find_root(Node* nodes, int x) {
    if (nodes[x].parent != x) {
        int root = find_root(nodes, nodes[x].parent);
        // Path compression: Update the parent of x to the root
        nodes[x].parent = root;
        // Update the value of x based on the path compression
        nodes[x].value += nodes[nodes[x].parent].value; 
    }
    return nodes[x].parent;
}

// Function to perform union operation with weighted union
void union_set(Node* nodes, int x, int y, int z) {
    int root_x = find_root(nodes, x);
    int root_y = find_root(nodes, y);

    // If both nodes are already in the same set, do nothing
    if (root_x == root_y) {
        return;
    }

    // Attach the smaller tree to the larger tree
    if (nodes[root_x].rank < nodes[root_y].rank) {
        nodes[root_x].parent = root_y;
        // Update the value of the smaller tree
        nodes[root_x].value += (z + nodes[root_y].value) - nodes[root_x].value; 
    } else if (nodes[root_x].rank > nodes[root_y].rank) {
        nodes[root_y].parent = root_x;
        // Update the value of the smaller tree
        nodes[root_y].value += (-z + nodes[root_x].value) - nodes[root_y].value;
    } else {
        // If the ranks are equal, increase the rank of the larger tree
        nodes[root_y].parent = root_x;
        nodes[root_x].rank++;
        // Update the value of the smaller tree
        nodes[root_y].value += (-z + nodes[root_x].value) - nodes[root_y].value;
    }
}

// Function to calculate the difference between a_x and a_y
int diff(Node* nodes, int x, int y) {
    int root_x = find_root(nodes, x);
    int root_y = find_root(nodes, y);

    // If both nodes are in the same set, return the difference
    if (root_x == root_y) {
        return nodes[y].value - nodes[x].value;
    } else {
        return -1; // Or you can return a value indicating error
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Node* nodes = init_uf(n);

    for (int i = 0; i < q; i++) {
        int type, x, y, z;
        scanf("%d %d %d", &type, &x, &y);

        if (type == 0) {
            scanf("%d", &z);
            union_set(nodes, x, y, z);
        } else if (type == 1) {
            int result = diff(nodes, x, y);
            if (result != -1) {
                printf("%d\n", result);
            } else {
                printf("?\n"); // Or handle the error in a different way
            }
        }
    }

    free(nodes);
    return 0;
}