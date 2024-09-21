#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CELLS 100

typedef struct {
    double x, y, z, r;
} Cell;

double distance(Cell a, Cell b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Check if two cells are touching or overlapping
int areConnected(Cell a, Cell b) {
    double dist = distance(a, b);
    return (dist <= a.r + b.r);
}

// Find the shortest distance between two cells, considering their radii
double shortestDistance(Cell a, Cell b) {
    double dist = distance(a, b);
    return dist - a.r - b.r; 
}

// Function to find the shortest path using Kruskal's algorithm
double findShortestPath(Cell cells[], int n) {
    int i, j, k;
    int parent[MAX_CELLS];
    double edge[MAX_CELLS][MAX_CELLS];
    double totalLength = 0.0;

    // Initialize edge weights and parent array
    for (i = 0; i < n; i++) {
        parent[i] = i;
        for (j = 0; j < n; j++) {
            edge[i][j] = (i == j) ? 0.0 : shortestDistance(cells[i], cells[j]);
        }
    }

    // Find the shortest edges using Kruskal's algorithm
    for (k = 0; k < n - 1; k++) {
        double minWeight = INFINITY;
        int u = -1, v = -1;

        // Find the edge with minimum weight
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (edge[i][j] < minWeight) {
                    minWeight = edge[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Check for cycles using find and union operations
        int rootU = parent[u];
        int rootV = parent[v];
        while (parent[rootU] != rootU) {
            rootU = parent[rootU];
        }
        while (parent[rootV] != rootV) {
            rootV = parent[rootV];
        }

        // Connect the cells if they are not already connected
        if (rootU != rootV) {
            parent[rootU] = rootV; // Union the sets
            totalLength += minWeight; 
            edge[u][v] = edge[v][u] = INFINITY; // Mark the edge as used
        }
    }

    return totalLength;
}

int main() {
    int n;
    Cell cells[MAX_CELLS];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        // Read cell data
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &cells[i].x, &cells[i].y, &cells[i].z, &cells[i].r);
        }

        // Check for initial connections
        int connected = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (areConnected(cells[i], cells[j])) {
                    connected = 1;
                    break;
                }
            }
        }

        // Calculate the shortest path length
        double shortestLength = (connected) ? 0.000 : findShortestPath(cells, n);
        printf("%.3lf\n", shortestLength);
    }

    return 0;
}