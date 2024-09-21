#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 200
#define MAX_EDGES 2000

// Structure to represent an edge
typedef struct Edge {
    int v;  // Destination node
    int d;  // Initial length
    int c;  // Cost per unit extension
    struct Edge *next;
} Edge;

// Structure to represent a node
typedef struct Node {
    Edge *head; // Head of the adjacency list
} Node;

// Function to create a new edge
Edge* createEdge(int v, int d, int c) {
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->v = v;
    newEdge->d = d;
    newEdge->c = c;
    newEdge->next = NULL;
    return newEdge;
}

// Function to add an edge to the adjacency list
void addEdge(Node *graph, int u, int v, int d, int c) {
    Edge *newEdge = createEdge(v, d, c);
    newEdge->next = graph[u].head;
    graph[u].head = newEdge;
}

// Function to find the shortest path using Dijkstra's algorithm
double dijkstra(Node *graph, int s, int t, int P) {
    int dist[MAX_NODES]; // Distance from source to each node
    int visited[MAX_NODES]; // Flag to track visited nodes
    double cost[MAX_NODES]; // Cost incurred to reach each node
    int parent[MAX_NODES]; // Parent node in the shortest path

    // Initialize distances, costs, and parent
    for (int i = 1; i <= MAX_NODES; ++i) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        cost[i] = INT_MAX;
        parent[i] = -1;
    }

    // Set initial distance and cost for source node
    dist[s] = 0;
    cost[s] = 0;

    // Priority queue for nodes to be visited
    int minDistance, minNode = s;

    while (visited[t] == 0) {
        // Find node with minimum distance
        minDistance = INT_MAX;
        for (int i = 1; i <= MAX_NODES; ++i) {
            if (!visited[i] && dist[i] < minDistance) {
                minDistance = dist[i];
                minNode = i;
            }
        }

        // Mark current node as visited
        visited[minNode] = 1;

        // Update distances for adjacent nodes
        Edge *currEdge = graph[minNode].head;
        while (currEdge != NULL) {
            int v = currEdge->v;
            int d = currEdge->d;
            int c = currEdge->c;
            
            // Check if extending the edge is within cost limit
            if (cost[minNode] + c * (dist[v] - d) <= P && dist[v] > dist[minNode] + d) {
                // Update distance, cost, and parent
                dist[v] = dist[minNode] + d;
                cost[v] = cost[minNode] + c * (dist[v] - d);
                parent[v] = minNode;
            }

            currEdge = currEdge->next;
        }
    }

    return dist[t];
}

int main() {
    int N, M, P, s, t;
    Node graph[MAX_NODES];
    int v, u, d, c;

    // Read input
    scanf("%d %d %d %d %d", &N, &M, &P, &s, &t);
    
    // Initialize adjacency list
    for (int i = 1; i <= N; ++i) {
        graph[i].head = NULL;
    }

    // Read edges and add to the graph
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d %d", &v, &u, &d, &c);
        addEdge(graph, v, u, d, c);
    }

    // Find the longest shortest path
    double max_length = dijkstra(graph, s, t, P);

    // Print the result
    printf("%.6lf\n", max_length);

    return 0;
}