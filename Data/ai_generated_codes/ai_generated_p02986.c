#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_Q 100000

// Structure to represent an edge in the tree
struct Edge {
    int to; // Destination vertex
    int color; // Color of the edge
    int length; // Length of the edge
    struct Edge *next; // Pointer to the next edge in the adjacency list
};

// Structure to represent a vertex in the tree
struct Vertex {
    struct Edge *edges; // Pointer to the adjacency list of the vertex
};

// Global variables
struct Vertex tree[MAX_N + 1]; // Array of vertices
int N, Q; // Number of vertices and queries
int parent[MAX_N + 1]; // Parent vertex in the tree (used for LCA)
int depth[MAX_N + 1]; // Depth of each vertex (used for LCA)
int edge_color[MAX_N]; // Original color of each edge

// Function to add an edge to the adjacency list of a vertex
void add_edge(int from, int to, int color, int length) {
    struct Edge *new_edge = (struct Edge *)malloc(sizeof(struct Edge));
    new_edge->to = to;
    new_edge->color = color;
    new_edge->length = length;
    new_edge->next = tree[from].edges;
    tree[from].edges = new_edge;
}

// Function to perform Depth First Search (DFS) to compute parent and depth of each vertex
void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    struct Edge *curr = tree[u].edges;
    while (curr != NULL) {
        if (curr->to != p) {
            dfs(curr->to, u, d + 1);
        }
        curr = curr->next;
    }
}

// Function to find the Lowest Common Ancestor (LCA) of two vertices
int lca(int u, int v) {
    // Ensure u is the deeper vertex
    if (depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }
    // Go up the tree until u and v are at the same depth
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    // Traverse upwards from u and v until they meet
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

// Function to calculate the distance between two vertices
int distance(int u, int v, int color, int new_length) {
    // Find the LCA of u and v
    int lca_vertex = lca(u, v);
    // Calculate the distance from u to LCA
    int dist_u = 0;
    while (u != lca_vertex) {
        if (edge_color[u] == color) {
            dist_u += new_length;
        } else {
            dist_u += tree[u].edges->length;
        }
        u = parent[u];
    }
    // Calculate the distance from v to LCA
    int dist_v = 0;
    while (v != lca_vertex) {
        if (edge_color[v] == color) {
            dist_v += new_length;
        } else {
            dist_v += tree[v].edges->length;
        }
        v = parent[v];
    }
    // Return the total distance
    return dist_u + dist_v;
}

int main() {
    // Read input
    scanf("%d %d", &N, &Q);
    for (int i = 1; i < N; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        add_edge(a, b, c, d);
        add_edge(b, a, c, d);
        edge_color[i] = c;
    }
    // Perform DFS to compute parent and depth
    dfs(1, 0, 0);
    // Process queries
    for (int i = 1; i <= Q; i++) {
        int x, y, u, v;
        scanf("%d %d %d %d", &x, &y, &u, &v);
        // Calculate and print the distance
        printf("%d\n", distance(u, v, x, y));
    }
    return 0;
}