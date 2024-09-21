#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define INF 1000000000

// Structure to represent an edge in the forest
typedef struct Edge {
    int u, v;
} Edge;

// Structure to represent a node in the disjoint set data structure
typedef struct Node {
    int parent;
    int rank;
} Node;

// Function to initialize the disjoint set data structure
void init_dsu(Node *nodes, int n) {
    for (int i = 0; i < n; i++) {
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }
}

// Function to find the root of the set containing a given node
int find_root(Node *nodes, int u) {
    if (nodes[u].parent != u) {
        nodes[u].parent = find_root(nodes, nodes[u].parent);
    }
    return nodes[u].parent;
}

// Function to merge two sets
void merge(Node *nodes, int u, int v) {
    int root_u = find_root(nodes, u);
    int root_v = find_root(nodes, v);

    if (root_u == root_v) {
        return;
    }

    if (nodes[root_u].rank < nodes[root_v].rank) {
        nodes[root_u].parent = root_v;
    } else if (nodes[root_u].rank > nodes[root_v].rank) {
        nodes[root_v].parent = root_u;
    } else {
        nodes[root_v].parent = root_u;
        nodes[root_u].rank++;
    }
}

// Function to find the minimum cost to connect the forest
int connect_forest(int n, int m, int *a, Edge *edges) {
    // Initialize disjoint set data structure
    Node *nodes = (Node *)malloc(sizeof(Node) * n);
    init_dsu(nodes, n);

    // Merge vertices connected by existing edges
    for (int i = 0; i < m; i++) {
        merge(nodes, edges[i].u, edges[i].v);
    }

    // Create a priority queue to store the edges in ascending order of cost
    // Since we do not have a priority queue in the C standard library, we can use a custom implementation or simply sort the edges
    // In this example, we will simply sort the edges
    Edge *sorted_edges = (Edge *)malloc(sizeof(Edge) * n);
    for (int i = 0; i < n; i++) {
        sorted_edges[i] = edges[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[sorted_edges[i].u] + a[sorted_edges[i].v] > a[sorted_edges[j].u] + a[sorted_edges[j].v]) {
                Edge temp = sorted_edges[i];
                sorted_edges[i] = sorted_edges[j];
                sorted_edges[j] = temp;
            }
        }
    }

    int total_cost = 0;
    int connected_components = n;
    int i = 0;

    // Connect the forest using the edges with minimum cost
    while (connected_components > 1 && i < n) {
        int u = sorted_edges[i].u;
        int v = sorted_edges[i].v;

        if (find_root(nodes, u) != find_root(nodes, v)) {
            total_cost += a[u] + a[v];
            merge(nodes, u, v);
            connected_components--;
        }

        i++;
    }

    // Free allocated memory
    free(nodes);
    free(sorted_edges);

    // Check if the forest is connected
    if (connected_components == 1) {
        return total_cost;
    } else {
        return INF;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Edge *edges = (Edge *)malloc(sizeof(Edge) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    int cost = connect_forest(n, m, a, edges);

    // Print the result
    if (cost == INF) {
        printf("Impossible\n");
    } else {
        printf("%d\n", cost);
    }

    // Free allocated memory
    free(a);
    free(edges);

    return 0;
}