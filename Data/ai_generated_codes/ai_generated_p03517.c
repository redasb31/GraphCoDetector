#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure for an edge
typedef struct Edge {
    int u, v, w;
} Edge;

// Structure for a disjoint set union (DSU)
typedef struct DSU {
    int parent[MAX_N + 1];
    int rank[MAX_N + 1];
} DSU;

// Initialize the DSU
void initDSU(DSU *dsu, int n) {
    for (int i = 1; i <= n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
}

// Find the root of the set containing the element
int find(DSU *dsu, int u) {
    if (dsu->parent[u] != u) {
        dsu->parent[u] = find(dsu, dsu->parent[u]);
    }
    return dsu->parent[u];
}

// Union two sets
void unionSets(DSU *dsu, int u, int v) {
    int rootU = find(dsu, u);
    int rootV = find(dsu, v);

    if (rootU == rootV) {
        return;
    }

    if (dsu->rank[rootU] < dsu->rank[rootV]) {
        dsu->parent[rootU] = rootV;
    } else if (dsu->rank[rootU] > dsu->rank[rootV]) {
        dsu->parent[rootV] = rootU;
    } else {
        dsu->parent[rootV] = rootU;
        dsu->rank[rootU]++;
    }
}

// Compare two edges based on their weights
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->w - edgeB->w;
}

// Kruskal's algorithm to find the minimum spanning tree
long long kruskalMST(Edge edges[], int m, DSU *dsu) {
    // Sort edges in ascending order of weight
    qsort(edges, m, sizeof(Edge), compareEdges);

    long long mstWeight = 0;
    int edgeCount = 0;

    // Iterate over all edges
    for (int i = 0; i < m && edgeCount < dsu->parent[1] - 1; i++) {
        // If the two vertices connected by the edge are in different sets
        if (find(dsu, edges[i].u) != find(dsu, edges[i].v)) {
            // Add the edge to the MST
            mstWeight += edges[i].w;
            unionSets(dsu, edges[i].u, edges[i].v);
            edgeCount++;
        }
    }

    // Return the weight of the MST
    return (edgeCount == dsu->parent[1] - 1) ? mstWeight : -1;
}

int main() {
    int n, m, k;
    int c[MAX_N + 1];
    Edge edges[MAX_M];
    DSU dsu;

    // Read input
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize DSU
    initDSU(&dsu, k);

    // Create the graph G' based on the colors
    for (int i = 0; i < m; i++) {
        // If both vertices are colored
        if (c[edges[i].u] != 0 && c[edges[i].v] != 0) {
            // Add an edge between the corresponding colors in G'
            unionSets(&dsu, c[edges[i].u], c[edges[i].v]);
        }
    }

    // Find the minimum spanning tree of G'
    long long minMSTWeight = kruskalMST(edges, m, &dsu);

    // Print the result
    printf("%lld\n", minMSTWeight);

    return 0;
}