#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10000
#define MAX_E 30000

// Structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent a graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since it's a directed graph, there's no need to add the reverse edge
}

// Function to perform Depth First Search (DFS)
void DFS(struct Graph* graph, int u, int* visited, int* stack) {
    visited[u] = 1;

    // Traverse the adjacency list of the current node
    struct AdjListNode* adj = graph->array[u].head;
    while (adj) {
        if (!visited[adj->dest]) {
            DFS(graph, adj->dest, visited, stack);
        }
        adj = adj->next;
    }

    // Push the node to the stack after visiting all its adjacent nodes
    stack[u] = 1;
}

// Function to perform Depth First Search (DFS) for the transpose graph
void DFSUtil(struct Graph* graph, int u, int* visited) {
    visited[u] = 1;

    // Traverse the adjacency list of the current node
    struct AdjListNode* adj = graph->array[u].head;
    while (adj) {
        if (!visited[adj->dest]) {
            DFSUtil(graph, adj->dest, visited);
        }
        adj = adj->next;
    }
}

// Function to find strongly connected components (SCCs) using Kosaraju's algorithm
int* getSCCs(struct Graph* graph, int V) {
    // 1. Perform DFS on the original graph to get a stack of nodes in reverse postorder
    int* stack = (int*)malloc(V * sizeof(int));
    int* visited = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i) {
        visited[i] = 0;
        stack[i] = 0;
    }

    // Perform DFS on each unvisited node
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack);
        }
    }

    // 2. Create the transpose graph by reversing the directions of all edges
    struct Graph* transposeGraph = createGraph(V);
    for (int i = 0; i < V; ++i) {
        struct AdjListNode* adj = graph->array[i].head;
        while (adj) {
            addEdge(transposeGraph, adj->dest, i);
            adj = adj->next;
        }
    }

    // 3. Perform DFS on the transpose graph, starting from the nodes in the stack (in reverse postorder)
    for (int i = 0; i < V; ++i) {
        visited[i] = 0;
    }

    int* SCCs = (int*)malloc(V * sizeof(int)); // Array to store the SCC IDs of each node
    int SCCCount = 0; // Counter for the number of SCCs

    // Iterate through the stack in reverse order
    for (int i = V - 1; i >= 0; --i) {
        if (!visited[stack[i]]) {
            DFSUtil(transposeGraph, stack[i], visited);
            SCCCount++;
            // Assign the same SCC ID to all nodes reachable from the current node in the DFS traversal
            for (int j = 0; j < V; ++j) {
                if (visited[j]) {
                    SCCs[j] = SCCCount;
                }
            }
        }
    }

    // Free memory allocated for the transpose graph
    free(transposeGraph->array);
    free(transposeGraph);

    // Free memory allocated for the stack and visited arrays
    free(stack);
    free(visited);

    return SCCs;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    // Read edges from input
    int src, dest;
    for (int i = 0; i < E; ++i) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Calculate strongly connected components
    int* SCCs = getSCCs(graph, V);

    // Read queries from input
    int Q;
    scanf("%d", &Q);

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Check if the nodes belong to the same SCC
        if (SCCs[u] == SCCs[v]) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    // Free memory allocated for the graph and SCCs array
    free(graph->array);
    free(graph);
    free(SCCs);

    return 0;
}