#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
struct Edge {
    int src; // Source vertex
    int dest; // Destination vertex
    int weight; // Weight of the edge
};

// Structure to represent a set
struct Set {
    int parent; // Parent of the set
    int rank; // Rank of the set
};

// Function to find the set of a given vertex
int find(struct Set* sets, int vertex) {
    if (sets[vertex].parent != vertex) {
        sets[vertex].parent = find(sets, sets[vertex].parent); // Path compression
    }
    return sets[vertex].parent;
}

// Function to perform union of two sets
void unionSet(struct Set* sets, int vertex1, int vertex2) {
    int root1 = find(sets, vertex1);
    int root2 = find(sets, vertex2);

    // Union by rank
    if (sets[root1].rank < sets[root2].rank) {
        sets[root1].parent = root2;
    } else if (sets[root1].rank > sets[root2].rank) {
        sets[root2].parent = root1;
    } else {
        sets[root1].parent = root2;
        sets[root2].rank++;
    }
}

// Function to compare edges based on their weights
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
int kruskalMST(int graph[][MAX_VERTICES], int numVertices) {
    // Create an array of edges to store all edges of the graph
    struct Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeCount = 0;
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != -1) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges in ascending order of weight
    qsort(edges, edgeCount, sizeof(struct Edge), compareEdges);

    // Create a set for each vertex
    struct Set sets[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }

    // Initialize total weight of MST to 0
    int mstWeight = 0;

    // Iterate over sorted edges
    for (int i = 0; i < edgeCount; i++) {
        // Find sets of the source and destination vertices
        int srcSet = find(sets, edges[i].src);
        int destSet = find(sets, edges[i].dest);

        // If source and destination vertices are in different sets, add the edge to MST and perform union
        if (srcSet != destSet) {
            mstWeight += edges[i].weight;
            unionSet(sets, srcSet, destSet);
        }
    }

    return mstWeight;
}

int main() {
    int numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Read input
    scanf("%d", &numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Calculate and print the total weight of the MST
    int mstWeight = kruskalMST(graph, numVertices);
    printf("%d\n", mstWeight);

    return 0;
}