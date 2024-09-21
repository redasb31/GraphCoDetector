#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure for representing a node in the tree
typedef struct Node {
    int parent;
    int children_count;
    int *children;
} Node;

// Function to create a new node
Node *create_node(int parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->parent = parent;
    node->children_count = 0;
    node->children = NULL;
    return node;
}

// Function to add a child to a node
void add_child(Node *node, int child) {
    node->children_count++;
    node->children = (int *)realloc(node->children, node->children_count * sizeof(int));
    node->children[node->children_count - 1] = child;
}

// Function to perform breadth-first search (BFS)
int bfs(Node *tree, int n) {
    int *visited = (int *)calloc(n + 1, sizeof(int)); // Array to track visited nodes
    int *queue = (int *)malloc((n + 1) * sizeof(int)); // Queue for BFS
    int front = 0, rear = 0;
    int total_distance = 0;

    // Add the root node to the queue
    queue[rear++] = 1;
    visited[1] = 1;

    // BFS traversal
    while (front < rear) {
        int current = queue[front++];

        // Iterate over the children of the current node
        for (int i = 0; i < tree[current].children_count; i++) {
            int child = tree[current].children[i];

            // If the child is not visited, add it to the queue
            if (!visited[child]) {
                visited[child] = 1;
                total_distance += 2; // Add 2 to the total distance (distance between current and child + distance between child and its parent)
                queue[rear++] = child;
            }
        }
    }

    free(visited);
    free(queue);

    return total_distance;
}

int main() {
    int n;
    scanf("%d", &n);

    // Create an array of nodes for the tree
    Node *tree = (Node *)malloc((n + 1) * sizeof(Node));

    // Initialize the nodes with their parents
    for (int i = 1; i <= n; i++) {
        tree[i] = *create_node(0);
    }

    // Read the parent information from the input
    for (int i = 2; i <= n; i++) {
        int parent;
        scanf("%d", &parent);
        tree[i].parent = parent;
        add_child(&tree[parent], i); // Add the child to its parent
    }

    // Perform BFS and print the total distance
    int distance = bfs(tree, n);
    printf("%d\n", distance);

    // Free allocated memory
    free(tree);
    return 0;
}