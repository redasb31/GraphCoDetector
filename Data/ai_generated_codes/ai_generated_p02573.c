#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

// Structure to represent a node in the disjoint set data structure
typedef struct Node {
    int parent;
    int rank;
} Node;

// Function to initialize the disjoint set data structure
void init_set(Node* set, int n) {
    for (int i = 1; i <= n; i++) {
        set[i].parent = i;
        set[i].rank = 0;
    }
}

// Function to find the root of the set containing the given node
int find(Node* set, int x) {
    if (set[x].parent != x) {
        set[x].parent = find(set, set[x].parent); // Path compression optimization
    }
    return set[x].parent;
}

// Function to merge the sets containing the given nodes
void union_set(Node* set, int x, int y) {
    int root_x = find(set, x);
    int root_y = find(set, y);

    if (root_x == root_y) {
        return; // Already in the same set
    }

    if (set[root_x].rank < set[root_y].rank) {
        set[root_x].parent = root_y;
    } else if (set[root_x].rank > set[root_y].rank) {
        set[root_y].parent = root_x;
    } else {
        set[root_y].parent = root_x;
        set[root_x].rank++;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* set = (Node*)malloc((n + 1) * sizeof(Node)); // Allocate memory for the disjoint set
    init_set(set, n); // Initialize the disjoint set

    // Read the friendship facts
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        union_set(set, a, b); // Merge the sets containing person a and b
    }

    // Count the number of disjoint sets
    int groups = 0;
    for (int i = 1; i <= n; i++) {
        if (set[i].parent == i) {
            groups++; // Each root node represents a separate group
        }
    }

    printf("%d\n", groups); // Print the number of groups
    free(set); // Free the allocated memory
    return 0;
}