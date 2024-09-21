#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

// Structure to represent a vertex
typedef struct Vertex {
    int x;
    int y;
    int color;
} Vertex;

// Structure to represent an edge
typedef struct Edge {
    int u;
    int v;
} Edge;

// Function to check if two vertices are adjacent
int isAdjacent(Vertex *vertices, Edge *edges, int m, int u, int v) {
    for (int i = 0; i < m; i++) {
        if ((edges[i].u == u && edges[i].v == v) ||
            (edges[i].u == v && edges[i].v == u)) {
            return 1;
        }
    }
    return 0;
}

// Function to color the graph using a greedy algorithm
void colorGraph(Vertex *vertices, Edge *edges, int n, int m) {
    // Initialize all vertices to uncolored
    for (int i = 0; i < n; i++) {
        vertices[i].color = 0;
    }

    // Iterate through each vertex
    for (int i = 0; i < n; i++) {
        // Find the smallest available color
        int color = 1;
        while (1) {
            // Check if any adjacent vertex has this color
            int valid = 1;
            for (int j = 0; j < n; j++) {
                if (isAdjacent(vertices, edges, m, i, j) && vertices[j].color == color) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                break;
            }
            color++;
        }
        // Assign the color to the vertex
        vertices[i].color = color;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create arrays to store vertices and edges
    Vertex *vertices = (Vertex *)malloc(sizeof(Vertex) * n);
    Edge *edges = (Edge *)malloc(sizeof(Edge) * m);

    // Read vertex coordinates
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &vertices[i].x, &vertices[i].y);
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i].u, &edges[i].v);
    }

    // Color the graph
    colorGraph(vertices, edges, n, m);

    // Print the coloring
    for (int i = 0; i < n; i++) {
        printf("%d\n", vertices[i].color);
    }

    // Free allocated memory
    free(vertices);
    free(edges);

    return 0;
}