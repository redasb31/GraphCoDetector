#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000
#define MAX_COST 10000

// Structure to represent an edge
typedef struct Edge {
    int u;
    int v;
    int cost;
} Edge;

// Structure to represent a node in the tree
typedef struct Node {
    int parent;
    int depth;
    int base;
    int visited;
    int num_bases;
} Node;

// Function to initialize the tree
void init_tree(Node *nodes, int n) {
    for (int i = 1; i <= n; i++) {
        nodes[i].parent = -1;
        nodes[i].depth = 0;
        nodes[i].base = 0;
        nodes[i].visited = 0;
        nodes[i].num_bases = 0;
    }
}

// Function to find the root of a tree
int find_root(Node *nodes, int n) {
    for (int i = 1; i <= n; i++) {
        if (nodes[i].parent == -1) {
            return i;
        }
    }
    return -1;
}

// Function to find the depth of a node
int find_depth(Node *nodes, int node) {
    int depth = 0;
    while (nodes[node].parent != -1) {
        depth++;
        node = nodes[node].parent;
    }
    return depth;
}

// Function to find the number of bases in a subtree
int count_bases(Node *nodes, int node) {
    int count = nodes[node].base;
    for (int i = 1; i <= MAX_NODES; i++) {
        if (nodes[i].parent == node) {
            count += count_bases(nodes, i);
        }
    }
    return count;
}

// Function to perform Depth First Search (DFS) from a given node
void dfs(Node *nodes, int node, Edge *edges, int n, int *cost, int k) {
    nodes[node].visited = 1;
    nodes[node].num_bases = count_bases(nodes, node);
    // If the current node has a base, check if we can split the tree
    if (nodes[node].base) {
        // Check if we have already split the tree enough times
        if (k == 0) {
            return;
        }
        // Find the minimum cost edge that can split the tree
        int min_cost = MAX_COST;
        int min_edge = -1;
        for (int i = 0; i < n - 1; i++) {
            // Check if the edge connects the current node to its parent
            if (edges[i].u == node && edges[i].v == nodes[node].parent ||
                edges[i].v == node && edges[i].u == nodes[node].parent) {
                // Check if the edge can split the tree
                if (nodes[node].num_bases - count_bases(nodes, edges[i].u) >= 1 &&
                    nodes[node].num_bases - count_bases(nodes, edges[i].v) >= 1) {
                    // Update the minimum cost and edge
                    if (edges[i].cost < min_cost) {
                        min_cost = edges[i].cost;
                        min_edge = i;
                    }
                }
            }
        }
        // If we found a valid edge to split the tree
        if (min_edge != -1) {
            // Update the cost
            *cost += min_cost;
            // Remove the edge by setting its cost to 0
            edges[min_edge].cost = 0;
            // Decrement the number of splits needed
            k--;
        }
    }
    // Recursively explore the children of the current node
    for (int i = 1; i <= n; i++) {
        if (nodes[i].parent == node && !nodes[i].visited) {
            dfs(nodes, i, edges, n, cost, k);
        }
    }
}

int main() {
    int n, t, k, case_num = 1;
    while (1) {
        scanf("%d %d %d", &n, &t, &k);
        // If the input is 0 0 0, break the loop
        if (n == 0 && t == 0 && k == 0) {
            break;
        }
        // Initialize the tree and edges
        Node nodes[MAX_NODES + 1];
        Edge edges[MAX_NODES];
        init_tree(nodes, n);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);
            // Set the parent of each node
            if (nodes[edges[i].u].parent == -1) {
                nodes[edges[i].u].parent = edges[i].v;
            } else {
                nodes[edges[i].v].parent = edges[i].u;
            }
        }
        // Read the list of nodes with bases
        for (int i = 0; i < t; i++) {
            int base_node;
            scanf("%d", &base_node);
            nodes[base_node].base = 1;
        }
        // Find the root of the tree
        int root = find_root(nodes, n);
        // Calculate the minimum destroying cost
        int cost = 0;
        dfs(nodes, root, edges, n, &cost, k);
        // Print the output
        printf("Case %d: %d\n", case_num, cost);
        case_num++;
    }
    return 0;
}