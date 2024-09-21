#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Structure to represent a node in the tree
typedef struct Node {
    int parent;
    int count; // Number of marbles at this node
} Node;

// Function to calculate the number of marbles in the box for a given placement of marbles
int count_marbles(Node *tree, int n) {
    int box_count = 0; // Number of marbles in the box
    int *queue = malloc((n + 1) * sizeof(int)); // Queue for BFS
    int front = 0, rear = 0; // Queue indices
    int *visited = calloc((n + 1), sizeof(int)); // Array to track visited nodes

    // Iterate through each node and add it to the queue if it has marbles
    for (int i = 1; i <= n; i++) {
        if (tree[i].count > 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    // Perform BFS to simulate the marble movement
    while (front < rear) {
        int current = queue[front++];

        // Move marbles to parent node
        tree[tree[current].parent].count += tree[current].count;
        tree[current].count = 0;

        // If current node is the root, add marbles to the box
        if (tree[current].parent == 0) {
            box_count += tree[tree[current].parent].count;
            tree[tree[current].parent].count = 0;
        }

        // Add parent node to the queue if it has marbles and hasn't been visited
        if (tree[tree[current].parent].count > 0 && !visited[tree[current].parent]) {
            queue[rear++] = tree[current].parent;
            visited[tree[current].parent] = 1;
        }

        // Remove marbles if there are multiple at the parent node
        if (tree[tree[current].parent].count > 1) {
            tree[tree[current].parent].count = 0;
        }
    }

    free(queue);
    free(visited);

    return box_count;
}

// Function to calculate the total number of marbles in the box for all possible marble placements
int calculate_total_marbles(Node *tree, int n) {
    int total_marbles = 0; // Total number of marbles in the box

    // Iterate through all possible marble placements
    for (int i = 0; i < (1 << (n + 1)); i++) {
        // Initialize tree with marbles based on the current bitmask
        for (int j = 1; j <= n; j++) {
            tree[j].count = (i >> j) & 1;
        }

        // Calculate marbles in the box for the current placement
        total_marbles = (total_marbles + count_marbles(tree, n)) % MOD;
    }

    return total_marbles;
}

int main() {
    int n;
    scanf("%d", &n);

    // Create a tree array to store parent and marble count for each node
    Node *tree = malloc((n + 1) * sizeof(Node));

    // Read parent nodes from input
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tree[i].parent);
    }

    // Calculate the total number of marbles in the box for all possible placements
    int total_marbles = calculate_total_marbles(tree, n);

    // Print the result
    printf("%d\n", total_marbles);

    free(tree);

    return 0;
}