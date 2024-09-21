#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure for a node in the tree
typedef struct Node {
    int id; // ID of the node
    char label; // Label of the node ('(' or ')')
    int parent; // ID of the parent node
    int depth; // Depth of the node in the tree
    int num_balanced_descendants; // Number of balanced paths starting from this node
} Node;

// Structure for an edge in the tree
typedef struct Edge {
    int from;
    int to;
} Edge;

// Function to add an edge to the graph
void add_edge(Edge *edges, int from, int to) {
    edges[from - 1].from = from;
    edges[from - 1].to = to;
}

// Function to perform Depth First Search (DFS) to calculate the number of balanced paths
void dfs(Node *nodes, Edge *edges, int n, int current, int parent) {
    // Initialize the current node
    nodes[current - 1].id = current;
    nodes[current - 1].parent = parent;
    nodes[current - 1].depth = parent == -1 ? 0 : nodes[parent - 1].depth + 1;

    // Initialize the number of balanced paths starting from the current node
    nodes[current - 1].num_balanced_descendants = 0;

    // Iterate over the edges connected to the current node
    for (int i = current - 1; i < n; i++) {
        if (edges[i].from == current && edges[i].to != parent) {
            // Recursively call DFS on the neighbor node
            dfs(nodes, edges, n, edges[i].to, current);

            // Update the number of balanced paths starting from the current node
            if (nodes[edges[i].to - 1].label == '(') {
                nodes[current - 1].num_balanced_descendants += nodes[edges[i].to - 1].num_balanced_descendants + 1;
            } else if (nodes[edges[i].to - 1].label == ')' && nodes[edges[i].to - 1].depth - nodes[current - 1].depth == 1) {
                nodes[current - 1].num_balanced_descendants += nodes[edges[i].to - 1].num_balanced_descendants + 1;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Allocate memory for nodes and edges
    Node *nodes = malloc(n * sizeof(Node));
    Edge *edges = malloc((n - 1) * sizeof(Edge));

    // Read the labels of the nodes
    char labels[MAX_N];
    scanf("%s", labels);
    for (int i = 0; i < n; i++) {
        nodes[i].label = labels[i];
    }

    // Read the edges of the tree
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(edges, a, b);
        add_edge(edges, b, a);
    }

    // Perform DFS to calculate the number of balanced paths
    dfs(nodes, edges, n, 1, -1);

    // Calculate the total number of balanced paths
    long long count = 0;
    for (int i = 0; i < n; i++) {
        count += nodes[i].num_balanced_descendants;
    }

    // Print the result
    printf("%lld\n", count);

    // Free allocated memory
    free(nodes);
    free(edges);

    return 0;
}