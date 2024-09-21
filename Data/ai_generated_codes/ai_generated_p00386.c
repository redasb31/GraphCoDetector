#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_Q 100000
#define MAX_W 10000

// Structure to represent a node in the graph
typedef struct Node {
    int city;
    int distance;
    struct Node *next;
} Node;

// Structure to represent the graph
typedef struct Graph {
    Node *adjList[MAX_N + 1];
    int numVertices;
} Graph;

// Function to create a new node
Node *newNode(int city, int distance) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->city = city;
    node->distance = distance;
    node->next = NULL;
    return node;
}

// Function to initialize the graph
Graph *initGraph(int numVertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    for (int i = 1; i <= numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v, int w) {
    Node *node = newNode(v, w);
    node->next = graph->adjList[u];
    graph->adjList[u] = node;

    // Since the graph is undirected, add the edge in both directions
    node = newNode(u, w);
    node->next = graph->adjList[v];
    graph->adjList[v] = node;
}

// Function to perform BFS traversal
void BFS(Graph *graph, int start, int *distances) {
    // Initialize distances to -1 (not visited)
    for (int i = 1; i <= graph->numVertices; i++) {
        distances[i] = -1;
    }

    // Create a queue for BFS
    Node **queue = (Node **)malloc(sizeof(Node *) * (graph->numVertices + 1));
    int front = 0, rear = 0;

    // Enqueue the starting node
    queue[rear++] = newNode(start, 0);
    distances[start] = 0;

    // Perform BFS
    while (front < rear) {
        Node *current = queue[front++];

        // Iterate over all adjacent nodes of the current node
        for (Node *neighbor = graph->adjList[current->city]; neighbor != NULL; neighbor = neighbor->next) {
            // If the neighbor is not visited, enqueue it
            if (distances[neighbor->city] == -1) {
                distances[neighbor->city] = current->distance + neighbor->distance;
                queue[rear++] = newNode(neighbor->city, distances[neighbor->city]);
            }
        }
        free(current);
    }

    free(queue);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    // Initialize the graph
    Graph *graph = initGraph(N);

    // Read road information
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    // Calculate distances from each city to all other cities
    int distances[MAX_N + 1][MAX_N + 1];
    for (int i = 1; i <= N; i++) {
        BFS(graph, i, distances[i]);
    }

    // Read theme information and calculate the cost for each theme
    for (int i = 0; i < Q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        // Find the minimum cost of reaching the meeting city from all three cities
        int minCost = MAX_W;
        for (int j = 1; j <= N; j++) {
            int cost = distances[a][j] + distances[b][j] + distances[c][j];
            minCost = (cost < minCost) ? cost : minCost;
        }

        printf("%d\n", minCost);
    }

    // Free allocated memory
    free(graph);

    return 0;
}