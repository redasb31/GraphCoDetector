#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007

// Structure to represent a node in the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structure to represent the adjacency list of the graph
typedef struct AdjList {
    Node* head;
} AdjList;

// Structure to represent the graph
typedef struct Graph {
    int V;  // Number of vertices
    AdjList* array; // Array of adjacency lists
} Graph;

// Function to create a new node
Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge from source vertex to destination vertex
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* new_node = newNode(dest);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    // Since the graph is directed, no need to add an edge from dest to src
}

// Function to perform BFS and check if the wrong BFS code will stop
int bfs(Graph* graph, int start) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = false;
    }

    int* current = (int*)malloc(graph->V * sizeof(int));
    int* found = (int*)malloc(graph->V * sizeof(int));
    int current_size = 0;
    int found_size = 0;

    current[0] = start;
    current_size = 1;
    visited[start - 1] = true;

    int iterations = 0;

    while (current_size > 0) {
        iterations++;
        found_size = 0;

        for (int i = 0; i < current_size; ++i) {
            int u = current[i];

            Node* temp = graph->array[u - 1].head;
            while (temp != NULL) {
                int v = temp->data;
                if (!visited[v - 1]) {
                    found[found_size++] = v;
                    visited[v - 1] = true;
                }
                temp = temp->next;
            }
        }

        // Check if there are no new nodes found, indicating an infinite loop
        if (found_size == 0) {
            free(visited);
            free(current);
            free(found);
            return -1; // Indicate infinite loop
        }

        // Update the current list for the next iteration
        current_size = found_size;
        for (int i = 0; i < current_size; ++i) {
            current[i] = found[i];
        }
    }

    free(visited);
    free(current);
    free(found);

    // Return the number of iterations
    return iterations % MOD; // Return the result modulo 10^9 + 7
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Graph* graph = createGraph(N);

    // Read the edges from input
    for (int i = 0; i < M; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Perform BFS and print the result
    int iterations = bfs(graph, 1);

    printf("%d\n", iterations);

    // Free memory
    free(graph->array);
    free(graph);

    return 0;
}