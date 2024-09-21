#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000
#define MAX_M 500000

// Structure to represent a graph node
typedef struct Node {
    int id;
    struct Node *next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    Node *adjList[MAX_N + 1];
} Graph;

// Function to create a new node
Node *newNode(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->next = NULL;
    return node;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest) {
    // Add edge from src to dest
    Node *newNode = newNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (undirected graph)
    newNode = newNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform Breadth-First Search (BFS)
int bfs(Graph *graph, int start, int *visited, int *grade, int A, int B, int C) {
    int queue[MAX_N + 1];
    int front = 0;
    int rear = 0;

    // Mark the starting node as visited
    visited[start] = 1;
    queue[rear++] = start;

    int communications = 0;
    int gradesReached = 0;

    while (front < rear) {
        int current = queue[front++];

        // Check if all grades have been reached
        if (gradesReached == 3) {
            break;
        }

        // Iterate through adjacent nodes
        Node *node = graph->adjList[current];
        while (node != NULL) {
            if (!visited[node->id]) {
                // Mark node as visited
                visited[node->id] = 1;
                queue[rear++] = node->id;

                // Check if a new grade has been reached
                if (grade[node->id] != grade[current] && gradesReached < 3) {
                    communications++;
                    gradesReached++;
                }
            }
            node = node->next;
        }
    }

    return communications;
}

// Function to find the minimum number of communications and the starting student
int findMinCommunications(Graph *graph, int A, int B, int C, int *grade, int *minCommunications, int *bestStart) {
    int visited[MAX_N + 1] = {0};
    int min = MAX_N;

    // Iterate through all students
    for (int i = 1; i <= A + B + C; i++) {
        // Reset visited array for each iteration
        for (int j = 1; j <= A + B + C; j++) {
            visited[j] = 0;
        }

        // Perform BFS from the current student
        int communications = bfs(graph, i, visited, grade, A, B, C);

        // Update minimum communications and best starting student
        if (communications < min) {
            min = communications;
            *bestStart = i;
        }
    }

    *minCommunications = min;
    return min;
}

int main() {
    int N, A, B, C, M;
    int a[MAX_N], b[MAX_N], c[MAX_N];
    int grade[MAX_N + 1];
    Graph graph;

    // Initialize the graph
    for (int i = 0; i <= MAX_N; i++) {
        graph.adjList[i] = NULL;
    }

    // Read input
    scanf("%d %d %d %d", &N, &A, &B, &C);
    for (int i = 0; i < A; i++) {
        scanf("%d", &a[i]);
        grade[a[i]] = 1; // First grade
    }
    for (int i = 0; i < B; i++) {
        scanf("%d", &b[i]);
        grade[b[i]] = 2; // Second grade
    }
    for (int i = 0; i < C; i++) {
        scanf("%d", &c[i]);
        grade[c[i]] = 3; // Third grade
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addEdge(&graph, x, y);
    }

    // Find minimum communications and best starting student
    int minCommunications = MAX_N;
    int bestStart = 0;
    findMinCommunications(&graph, A, B, C, grade, &minCommunications, &bestStart);

    // Output results
    printf("%d %d\n", minCommunications, bestStart);

    return 0;
}