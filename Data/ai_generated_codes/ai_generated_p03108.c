#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bridge
typedef struct Bridge {
    int a, b;
} Bridge;

// Structure to represent a disjoint set
typedef struct DisjointSet {
    int *parent;
    int *rank;
    int n;
} DisjointSet;

// Function to create a new disjoint set
DisjointSet *createDisjointSet(int n) {
    DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
    ds->parent = (int *)malloc(n * sizeof(int));
    ds->rank = (int *)malloc(n * sizeof(int));
    ds->n = n;
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

// Function to find the parent of a node in the disjoint set
int find(DisjointSet *ds, int u) {
    if (ds->parent[u] != u) {
        ds->parent[u] = find(ds, ds->parent[u]);
    }
    return ds->parent[u];
}

// Function to union two sets in the disjoint set
void unionSet(DisjointSet *ds, int u, int v) {
    int uRoot = find(ds, u);
    int vRoot = find(ds, v);
    if (uRoot == vRoot) {
        return;
    }
    if (ds->rank[uRoot] < ds->rank[vRoot]) {
        ds->parent[uRoot] = vRoot;
    } else if (ds->rank[uRoot] > ds->rank[vRoot]) {
        ds->parent[vRoot] = uRoot;
    } else {
        ds->parent[vRoot] = uRoot;
        ds->rank[uRoot]++;
    }
}

// Function to calculate the inconvenience after a bridge collapse
long long calculateInconvenience(DisjointSet *ds, int n) {
    long long inconvenience = 0;
    // Iterate over all pairs of islands
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // Check if the islands are connected
            if (find(ds, i) != find(ds, j)) {
                inconvenience++;
            }
        }
    }
    return inconvenience;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create an array to store the bridges
    Bridge *bridges = (Bridge *)malloc(m * sizeof(Bridge));

    // Read the input
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &bridges[i].a, &bridges[i].b);
    }

    // Create a disjoint set
    DisjointSet *ds = createDisjointSet(n + 1);

    // Initialize the disjoint set with all bridges connected
    for (int i = 0; i < m; i++) {
        unionSet(ds, bridges[i].a, bridges[i].b);
    }

    // Calculate the inconvenience after each bridge collapse
    for (int i = 0; i < m; i++) {
        // Collapse the bridge
        unionSet(ds, bridges[i].a, bridges[i].b);

        // Calculate the inconvenience
        long long inconvenience = calculateInconvenience(ds, n);

        // Print the inconvenience
        printf("%lld\n", inconvenience);
    }

    // Free the allocated memory
    free(bridges);
    free(ds->parent);
    free(ds->rank);
    free(ds);

    return 0;
}