#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent an adjacency list
typedef struct AdjList {
    Node* head;
} AdjList;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

// Function to create a new node
Node* newNode(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

// Function to create a graph with n vertices
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->array = (AdjList*)malloc(n * sizeof(AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < n; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* newNode = newNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since it is an undirected graph, add an edge from dest to src also
    // newNode = newNode(src);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
}

// Function to perform Breadth First Search (BFS)
void BFS(Graph* graph, int startVertex) {
    // Initialize distance array to -1 (no path)
    int distance[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        distance[i] = -1;
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    // Mark the starting vertex as visited and set its distance to 0
    distance[startVertex - 1] = 0;
    queue[rear++] = startVertex;

    // Perform BFS
    while (front != rear) {
        int currentVertex = queue[front++];
        // Get adjacent vertices
        Node* adjacent = graph->array[currentVertex - 1].head;
        while (adjacent != NULL) {
            // If an adjacent vertex is not visited
            if (distance[adjacent->vertex - 1] == -1) {
                // Mark it as visited and set its distance
                distance[adjacent->vertex - 1] = distance[currentVertex - 1] + 1;
                // Add it to the queue
                queue[rear++] = adjacent->vertex;
            }
            adjacent = adjacent->next;
        }
    }

    // Print the distances from the starting vertex
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d %d\n", i + 1, distance[i]);
    }
}

int main() {
    // Read the number of vertices
    int n;
    scanf("%d", &n);

    // Create a graph
    Graph* graph = createGraph(n);

    // Read the edges from input
    for (int i = 0; i < n; i++) {
        int u, k;
        scanf("%d %d", &u, &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            addEdge(graph, u, v);
        }
    }

    // Perform BFS starting from vertex 1
    BFS(graph, 1);

    return 0;
}