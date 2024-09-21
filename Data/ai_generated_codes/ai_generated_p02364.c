#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src;
    int dest;
    int weight;
};

// Structure to represent a set
struct Set {
    int parent;
    int rank;
};

// Function to create a set with a single element
struct Set* createSet(int n) {
    struct Set* set = (struct Set*)malloc(sizeof(struct Set));
    set->parent = n;
    set->rank = 0;
    return set;
}

// Function to find the root of the set containing a given element
int find(struct Set* sets, int n) {
    if (sets[n].parent != n) {
        sets[n].parent = find(sets, sets[n].parent);
    }
    return sets[n].parent;
}

// Function to perform union of two sets
void unionSets(struct Set* sets, int u, int v) {
    int rootU = find(sets, u);
    int rootV = find(sets, v);

    if (sets[rootU].rank < sets[rootV].rank) {
        sets[rootU].parent = rootV;
    } else if (sets[rootU].rank > sets[rootV].rank) {
        sets[rootV].parent = rootU;
    } else {
        sets[rootV].parent = rootU;
        sets[rootU].rank++;
    }
}

// Function to compare two edges based on their weights
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
int findMST(struct Edge* edges, int numEdges, int numVertices) {
    // Sort edges in ascending order of weights
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    // Create sets for each vertex
    struct Set* sets = (struct Set*)malloc(numVertices * sizeof(struct Set));
    for (int i = 0; i < numVertices; i++) {
        sets[i] = *createSet(i);
    }

    // Initialize sum of MST edge weights
    int mstWeight = 0;

    // Iterate through sorted edges
    int i = 0;
    while (i < numEdges) {
        // Get the current edge
        struct Edge currentEdge = edges[i];

        // Find the sets containing the source and destination vertices
        int srcRoot = find(sets, currentEdge.src);
        int destRoot = find(sets, currentEdge.dest);

        // If the sets are different, add the edge to the MST and union the sets
        if (srcRoot != destRoot) {
            mstWeight += currentEdge.weight;
            unionSets(sets, srcRoot, destRoot);
        }

        // Move to the next edge
        i++;
    }

    // Free allocated memory
    free(sets);

    // Return the total weight of the MST
    return mstWeight;
}

int main() {
    int numVertices, numEdges;

    // Read the number of vertices and edges from input
    scanf("%d %d", &numVertices, &numEdges);

    // Create an array to store edges
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));

    // Read the edges and their weights from input
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Calculate and print the weight of the Minimum Spanning Tree
    int mstWeight = findMST(edges, numEdges, numVertices);
    printf("%d\n", mstWeight);

    // Free allocated memory
    free(edges);

    return 0;
}