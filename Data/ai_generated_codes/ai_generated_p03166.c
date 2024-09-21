#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

// Structure to represent a node in the graph
typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

// Structure to represent the adjacency list of the graph
typedef struct AdjacencyList {
    Node *head;
} AdjacencyList;

// Function to create a new node
Node* createNode(int vertex) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(AdjacencyList *graph, int src, int dest) {
    // Create a new node for the destination vertex
    Node *newNode = createNode(dest);

    // Add the new node to the head of the adjacency list for the source vertex
    newNode->next = graph[src].head;
    graph[src].head = newNode;
}

// Function to perform topological sort using Kahn's algorithm
int* topologicalSort(AdjacencyList *graph, int N) {
    // Create an array to store the in-degree of each vertex
    int *inDegree = (int*)calloc(N + 1, sizeof(int));

    // Calculate the in-degree of each vertex
    for (int i = 1; i <= N; i++) {
        Node *current = graph[i].head;
        while (current != NULL) {
            inDegree[current->vertex]++;
            current = current->next;
        }
    }

    // Create a queue to store the vertices with in-degree 0
    int *queue = (int*)malloc((N + 1) * sizeof(int));
    int front = 0, rear = 0;

    // Add all vertices with in-degree 0 to the queue
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Create an array to store the topological order
    int *topologicalOrder = (int*)malloc(N * sizeof(int));
    int count = 0;

    // Perform topological sort
    while (front < rear) {
        int u = queue[front++];

        // Add the current vertex to the topological order
        topologicalOrder[count++] = u;

        // Decrement the in-degree of all adjacent vertices
        Node *current = graph[u].head;
        while (current != NULL) {
            if (--inDegree[current->vertex] == 0) {
                queue[rear++] = current->vertex;
            }
            current = current->next;
        }
    }

    // Check if all vertices were visited, indicating a DAG
    if (count != N) {
        free(inDegree);
        free(queue);
        free(topologicalOrder);
        return NULL;
    }

    // Free the in-degree array and queue
    free(inDegree);
    free(queue);

    return topologicalOrder;
}

// Function to find the longest path in a DAG using topological sort
int longestPath(AdjacencyList *graph, int N) {
    // Perform topological sort
    int *topologicalOrder = topologicalSort(graph, N);

    // If the graph is not a DAG, return -1
    if (topologicalOrder == NULL) {
        return -1;
    }

    // Create an array to store the length of the longest path ending at each vertex
    int *distances = (int*)calloc(N + 1, sizeof(int));

    // Initialize the distance of the first vertex in the topological order to 0
    distances[topologicalOrder[0]] = 0;

    // Iterate through the topological order
    for (int i = 1; i < N; i++) {
        int u = topologicalOrder[i];

        // Iterate through the adjacent vertices of the current vertex
        Node *current = graph[u].head;
        while (current != NULL) {
            int v = current->vertex;

            // Update the distance of the current vertex if the path through the adjacent vertex is longer
            if (distances[v] < distances[u] + 1) {
                distances[v] = distances[u] + 1;
            }

            current = current->next;
        }
    }

    // Find the maximum distance among all vertices
    int maxLength = 0;
    for (int i = 1; i <= N; i++) {
        if (distances[i] > maxLength) {
            maxLength = distances[i];
        }
    }

    // Free the topological order and distances arrays
    free(topologicalOrder);
    free(distances);

    return maxLength;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Create an adjacency list to represent the graph
    AdjacencyList *graph = (AdjacencyList*)malloc((N + 1) * sizeof(AdjacencyList));
    for (int i = 1; i <= N; i++) {
        graph[i].head = NULL;
    }

    // Read the edges of the graph
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(graph, x, y);
    }

    // Find the length of the longest path in the DAG
    int maxLength = longestPath(graph, N);

    // Print the length of the longest path
    printf("%d\n", maxLength);

    // Free the memory allocated for the graph
    for (int i = 1; i <= N; i++) {
        Node *current = graph[i].head;
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}