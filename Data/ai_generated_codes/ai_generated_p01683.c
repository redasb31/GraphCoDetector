#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an island
typedef struct {
    int p; // Parameter of the island
    int d; // Maximum degree of the island
    int visited; // Flag to indicate if the island has been visited
    int degree; // Current degree of the island
} Island;

// Function to find the minimum cost to rebuild bridges using Kruskal's algorithm
int minCost(Island* islands, int n) {
    // Sort the edges in ascending order of cost
    int cost = 0;
    int edges = 0;
    int i, j, k;

    // Create a priority queue to store the edges
    int* edge_cost = (int*)malloc(n * (n - 1) / 2 * sizeof(int));
    int* edge_u = (int*)malloc(n * (n - 1) / 2 * sizeof(int));
    int* edge_v = (int*)malloc(n * (n - 1) / 2 * sizeof(int));
    int edge_count = 0;

    // Add all edges to the priority queue
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            edge_cost[edge_count] = abs(islands[i].p - islands[j].p);
            edge_u[edge_count] = i;
            edge_v[edge_count] = j;
            edge_count++;
        }
    }

    // Sort the edges by cost
    for (i = 0; i < edge_count; i++) {
        for (j = i + 1; j < edge_count; j++) {
            if (edge_cost[i] > edge_cost[j]) {
                int temp = edge_cost[i];
                edge_cost[i] = edge_cost[j];
                edge_cost[j] = temp;
                temp = edge_u[i];
                edge_u[i] = edge_u[j];
                edge_u[j] = temp;
                temp = edge_v[i];
                edge_v[i] = edge_v[j];
                edge_v[j] = temp;
            }
        }
    }

    // Initialize the parent array for the disjoint set data structure
    int* parent = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Iterate over the sorted edges
    for (i = 0; i < edge_count; i++) {
        // Get the endpoints of the edge
        int u = edge_u[i];
        int v = edge_v[i];

        // Check if the endpoints are in the same connected component
        if (find(parent, u) != find(parent, v)) {
            // If not, add the edge to the MST
            cost += edge_cost[i];
            edges++;
            union_set(parent, u, v);
        }
    }

    // Free the memory allocated for the priority queue and the parent array
    free(edge_cost);
    free(edge_u);
    free(edge_v);
    free(parent);

    // Return the minimum cost if all islands are connected, otherwise return -1
    if (edges == n - 1) {
        return cost;
    } else {
        return -1;
    }
}

// Function to find the parent of a node in the disjoint set data structure
int find(int* parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// Function to union two sets in the disjoint set data structure
void union_set(int* parent, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu != pv) {
        parent[pu] = pv;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        // Create an array of islands
        Island* islands = (Island*)malloc(n * sizeof(Island));

        // Read the island parameters
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &islands[i].p, &islands[i].d);
            islands[i].visited = 0;
            islands[i].degree = 0;
        }

        // Calculate the minimum cost to rebuild bridges
        int min_cost = minCost(islands, n);

        // Print the minimum cost or -1 if it is impossible to rebuild bridges
        printf("%d\n", min_cost);

        // Free the memory allocated for the islands
        free(islands);
    }
    return 0;
}