#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

// Structure for an edge in the tree
typedef struct Edge {
    int to;
    struct Edge *next;
} Edge;

// Structure for a node in the tree
typedef struct Node {
    int color;
    Edge *edges;
    int visited;
} Node;

// Array of nodes
Node nodes[MAX_N + 1];

// Function to add an edge to the graph
void add_edge(int u, int v) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->to = v;
    new_edge->next = nodes[u].edges;
    nodes[u].edges = new_edge;

    new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->to = u;
    new_edge->next = nodes[v].edges;
    nodes[v].edges = new_edge;
}

// Function to count the number of simple paths that visit a vertex of a given color
int count_paths(int u, int color) {
    int count = 0;
    nodes[u].visited = 1;
    for (Edge *e = nodes[u].edges; e; e = e->next) {
        if (!nodes[e->to].visited) {
            if (nodes[e->to].color == color) {
                count += 1;
            }
            count += count_paths(e->to, color);
        }
    }
    nodes[u].visited = 0;
    return count;
}

int main() {
    int N;
    scanf("%d", &N);

    // Initialize colors of nodes
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nodes[i].color);
        nodes[i].edges = NULL;
        nodes[i].visited = 0;
    }

    // Read edges and add them to the graph
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add_edge(a, b);
    }

    // Count the number of simple paths for each color
    for (int k = 1; k <= N; k++) {
        // Call the count_paths function to count paths for each color k
        printf("%d\n", count_paths(1, k));
    }

    return 0;
}