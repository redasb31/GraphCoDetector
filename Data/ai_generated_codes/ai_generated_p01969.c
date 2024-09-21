#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_H 50
#define MAX_W 50

// Structure to represent a vertex
typedef struct Vertex {
    int row;
    int col;
    char label;
    int visited;
    int distance;
} Vertex;

// Structure to represent an edge
typedef struct Edge {
    Vertex* source;
    Vertex* destination;
} Edge;

// Function to create a new vertex
Vertex* createVertex(int row, int col, char label) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->row = row;
    vertex->col = col;
    vertex->label = label;
    vertex->visited = 0;
    vertex->distance = -1; // Initialize distance to -1 (not visited)
    return vertex;
}

// Function to create a new edge
Edge* createEdge(Vertex* source, Vertex* destination) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->source = source;
    edge->destination = destination;
    return edge;
}

// Function to find a vertex based on its label
Vertex* findVertex(Vertex** vertices, int numVertices, char label) {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i]->label == label) {
            return vertices[i];
        }
    }
    return NULL;
}

// Function to add an edge to the graph
void addEdge(Vertex** vertices, int numVertices, char sourceLabel, char destinationLabel) {
    Vertex* source = findVertex(vertices, numVertices, sourceLabel);
    Vertex* destination = findVertex(vertices, numVertices, destinationLabel);
    if (source && destination) {
        Edge* edge = createEdge(source, destination);
        // Add the edge to the graph (implementation specific)
        // You might have a list of edges or use an adjacency list
    }
}

// Function to perform Breadth-First Search (BFS)
int bfs(Vertex** vertices, int numVertices, Vertex* startVertex, Vertex* endVertex) {
    // Initialize queue
    Vertex** queue = (Vertex**)malloc(sizeof(Vertex*) * numVertices);
    int front = 0;
    int rear = 0;

    // Initialize the start vertex
    startVertex->visited = 1;
    startVertex->distance = 0;
    queue[rear++] = startVertex;

    while (front < rear) {
        Vertex* currentVertex = queue[front++];

        // Check if the current vertex is the end vertex
        if (currentVertex == endVertex) {
            return endVertex->distance; // Shortest path found
        }

        // Explore neighbors
        // Implementation specific: Get neighbors based on edges or adjacency list
        // ...

        // For each neighbor (adjacent vertex):
        // 1. If neighbor is not visited, mark it as visited and add it to the queue
        // 2. Set the neighbor's distance to currentVertex->distance + 1
    }

    // End vertex not found (disconnected)
    return -1;
}

int main() {
    int H, W;
    char s, t;
    scanf("%d %d %c %c\n", &H, &W, &s, &t);

    // Create a 2D array to store the ASCII art
    char aa[MAX_H][MAX_W];
    for (int i = 0; i < H; i++) {
        scanf("%s\n", aa[i]);
    }

    // Create vertices
    Vertex* vertices[MAX_H * MAX_W];
    int numVertices = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (aa[i][j] >= 'A' && aa[i][j] <= 'Z') {
                vertices[numVertices++] = createVertex(i, j, aa[i][j]);
            }
        }
    }

    // Add edges based on ASCII art
    // Implementation specific: Scan the AA to identify edge connections
    // ...

    // Find the start and end vertices
    Vertex* startVertex = findVertex(vertices, numVertices, s);
    Vertex* endVertex = findVertex(vertices, numVertices, t);

    // Perform BFS
    int shortestPathLength = bfs(vertices, numVertices, startVertex, endVertex);

    printf("%d\n", shortestPathLength);

    // Free allocated memory
    for (int i = 0; i < numVertices; i++) {
        free(vertices[i]);
    }

    return 0;
}