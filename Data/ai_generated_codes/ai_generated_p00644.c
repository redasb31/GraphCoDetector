#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 10000

// Structure to represent an edge in the graph
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// Structure to represent a node in the graph
typedef struct Node {
    int id;
    int distance;
    int num_paths;
    int visited;
} Node;

// Function to initialize the graph with nodes and edges
void initGraph(Node graph[], int n, Edge edges[], int m) {
    for (int i = 0; i < n; i++) {
        graph[i].id = i;
        graph[i].distance = INT_MAX; // Initialize distance to infinity
        graph[i].num_paths = 0;
        graph[i].visited = 0;
    }
}

// Function to find the shortest path from source to destination using Dijkstra's algorithm
void dijkstra(Node graph[], int n, Edge edges[], int m, int src, int dest) {
    // Initialize the source node
    graph[src].distance = 0;
    graph[src].num_paths = 1;

    // Create a priority queue to store nodes based on their distance
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = src;

    while (front < rear) {
        int u = queue[front++];

        // If the destination is reached, stop the algorithm
        if (u == dest) {
            return;
        }

        // Mark the current node as visited
        graph[u].visited = 1;

        // Iterate over all edges connected to the current node
        for (int i = 0; i < m; i++) {
            if (edges[i].src == u && !graph[edges[i].dest].visited) {
                // Calculate the new distance to the neighbor
                int new_distance = graph[u].distance + edges[i].weight;

                // Update the distance and number of paths if a shorter path is found
                if (new_distance < graph[edges[i].dest].distance) {
                    graph[edges[i].dest].distance = new_distance;
                    graph[edges[i].dest].num_paths = graph[u].num_paths;
                    queue[rear++] = edges[i].dest;
                } else if (new_distance == graph[edges[i].dest].distance) {
                    // Increment the number of paths if multiple shortest paths are found
                    graph[edges[i].dest].num_paths += graph[u].num_paths;
                    queue[rear++] = edges[i].dest;
                }
            }
        }
    }
}

int main() {
    int n, m, p;

    // Read input until the end of file
    while (scanf("%d %d %d", &n, &m, &p) != EOF) {
        // If all values are 0, break the loop
        if (n == 0 && m == 0 && p == 0) {
            break;
        }

        Node graph[MAX_NODES];
        Edge edges[MAX_EDGES];
        int c[MAX_NODES];

        // Initialize the graph and read edges
        initGraph(graph, n, edges, m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
        }

        // Read the positions of the children
        for (int i = 0; i < p; i++) {
            scanf("%d", &c[i]);
        }

        // Calculate the shortest path from the source to the destination
        dijkstra(graph, n, edges, m, 0, n - 1);

        // Calculate the probability for each child to see Santa
        for (int i = 0; i < p; i++) {
            if (graph[c[i]].num_paths > 0) {
                // Probability is the number of paths passing through the child's node divided by the total number of paths
                printf("%.9f ", (double) graph[c[i]].num_paths / graph[n - 1].num_paths);
            } else {
                // Probability is 0 if Santa does not pass through the child's node
                printf("0.000000000 ");
            }
        }

        // Print a blank line after each dataset
        printf("\n");
    }

    return 0;
}