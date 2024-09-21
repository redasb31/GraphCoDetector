#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_M 200000

// Structure to represent an edge
typedef struct Edge {
    int from;
    int to;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int n;  // Number of vertices
    int m;  // Number of edges
    Edge* edges;  // Array of edges
} Graph;

// Structure to represent a node in the DFS tree
typedef struct Node {
    int id;  // Vertex ID
    int low;  // Lowest reachable vertex in the subtree
    int visited;  // Flag for visited status
    int onStack;  // Flag for on the stack status
    int parent;  // Parent node in the DFS tree
} Node;

// Stack for storing nodes during DFS
typedef struct Stack {
    int top;
    Node* data[MAX_N];
} Stack;

// Initialize a graph with given number of vertices and edges
Graph* initGraph(int n, int m) {
    Graph* graph = malloc(sizeof(Graph));
    graph->n = n;
    graph->m = m;
    graph->edges = malloc(sizeof(Edge) * m);
    return graph;
}

// Initialize a stack
Stack* initStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Push a node onto the stack
void push(Stack* stack, Node* node) {
    stack->data[++stack->top] = node;
}

// Pop a node from the stack
Node* pop(Stack* stack) {
    if (stack->top == -1) {
        return NULL;
    }
    return stack->data[stack->top--];
}

// Check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Depth-First Search (DFS) algorithm for finding strongly connected components
void dfs(Graph* graph, Node* nodes, int v, int* time, Stack* stack) {
    nodes[v].visited = 1;
    nodes[v].low = ++(*time);
    nodes[v].onStack = 1;
    push(stack, &nodes[v]);

    // Iterate over adjacent vertices
    for (int i = 0; i < graph->m; i++) {
        if (graph->edges[i].from == v) {
            int u = graph->edges[i].to;
            if (!nodes[u].visited) {
                nodes[u].parent = v;
                dfs(graph, nodes, u, time, stack);
                nodes[v].low = (nodes[v].low < nodes[u].low) ? nodes[v].low : nodes[u].low;
            } else if (nodes[u].onStack) {
                nodes[v].low = (nodes[v].low < nodes[u].low) ? nodes[v].low : nodes[u].low;
            }
        }
    }

    // Check if a strongly connected component is found
    if (nodes[v].low == nodes[v].id) {
        while (1) {
            Node* node = pop(stack);
            node->onStack = 0;
            if (node->id == v) {
                break;
            }
        }
    }
}

// Find strongly connected components in the graph
int findStronglyConnectedComponents(Graph* graph, Node* nodes) {
    int time = 0;
    Stack* stack = initStack();
    for (int i = 1; i <= graph->n; i++) {
        if (!nodes[i].visited) {
            dfs(graph, nodes, i, &time, stack);
        }
    }
    free(stack);
    return time;  // Time is the number of strongly connected components
}

// Revert the edge in the graph
void revertEdge(Graph* graph, int edgeIndex) {
    int temp = graph->edges[edgeIndex].from;
    graph->edges[edgeIndex].from = graph->edges[edgeIndex].to;
    graph->edges[edgeIndex].to = temp;
}

// Check if reverting the edge changes the number of strongly connected components
int isEdgeReversionChangingSCC(Graph* graph, Node* nodes, int edgeIndex) {
    int originalSCCCount = findStronglyConnectedComponents(graph, nodes);
    revertEdge(graph, edgeIndex);
    int newSCCCount = findStronglyConnectedComponents(graph, nodes);
    revertEdge(graph, edgeIndex);  // Revert the edge back to the original state
    return originalSCCCount != newSCCCount;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = initGraph(n, m);

    // Read edge information
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &graph->edges[i].from, &graph->edges[i].to);
    }

    Node* nodes = malloc(sizeof(Node) * (n + 1));
    for (int i = 1; i <= n; i++) {
        nodes[i].id = i;
        nodes[i].visited = 0;
        nodes[i].onStack = 0;
        nodes[i].parent = -1;
    }

    // Check the effect of reverting each edge
    for (int i = 0; i < m; i++) {
        if (isEdgeReversionChangingSCC(graph, nodes, i)) {
            printf("diff\n");
        } else {
            printf("same\n");
        }
    }

    free(nodes);
    free(graph->edges);
    free(graph);

    return 0;
}