#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent an edge in the graph
struct Edge {
    int src;
    int dest;
    int weight;
};

// Structure to represent a node in the priority queue
struct Node {
    int vertex;
    int distance;
};

// Function to compare two nodes for priority queue
int compare(const void *a, const void *b) {
    struct Node *node1 = (struct Node *)a;
    struct Node *node2 = (struct Node *)b;
    return node1->distance - node2->distance;
}

// Function to perform Dijkstra's algorithm
int dijkstra(struct Edge *graph, int num_edges, int N) {
    // Initialize distances to infinity
    int distances[MAX_N + 1];
    for (int i = 1; i <= N; i++) {
        distances[i] = INT_MAX;
    }

    // Priority queue to store nodes and their distances
    struct Node *queue = malloc((N + 1) * sizeof(struct Node));
    int queue_size = 0;

    // Start from vertex 1
    distances[1] = 0;
    queue[queue_size++] = (struct Node) { .vertex = 1, .distance = 0 };

    // While the priority queue is not empty
    while (queue_size > 0) {
        // Get the node with the minimum distance
        struct Node current = queue[0];
        queue[0] = queue[queue_size - 1];
        queue_size--;
        qsort(queue, queue_size, sizeof(struct Node), compare);

        // If the current node is the destination node, return its distance
        if (current.vertex == N) {
            free(queue);
            return current.distance;
        }

        // Iterate over all edges connected to the current node
        for (int i = 0; i < num_edges; i++) {
            if (graph[i].src == current.vertex) {
                // Calculate the distance to the adjacent node
                int new_distance = current.distance + graph[i].weight;

                // If the new distance is less than the current distance, update it
                if (new_distance < distances[graph[i].dest]) {
                    distances[graph[i].dest] = new_distance;

                    // Add the adjacent node to the priority queue
                    queue[queue_size++] = (struct Node) { .vertex = graph[i].dest, .distance = new_distance };
                    qsort(queue, queue_size, sizeof(struct Node), compare);
                }
            }
        }
    }

    // If no path is found, return -1
    free(queue);
    return -1;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Allocate memory for the graph
    struct Edge *graph = malloc(MAX_M * sizeof(struct Edge));
    int num_edges = 0;

    // Read the edges from input
    for (int i = 0; i < M; i++) {
        int L, R, C;
        scanf("%d %d %d", &L, &R, &C);

        // Add edges for all pairs of vertices within the range
        for (int s = L; s < R; s++) {
            for (int t = s + 1; t <= R; t++) {
                graph[num_edges++] = (struct Edge) { .src = s, .dest = t, .weight = C };
            }
        }
    }

    // Perform Dijkstra's algorithm and print the shortest path distance
    int shortest_path = dijkstra(graph, num_edges, N);
    printf("%d\n", shortest_path);

    // Free allocated memory
    free(graph);

    return 0;
}