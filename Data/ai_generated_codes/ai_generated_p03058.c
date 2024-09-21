#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2000
#define MAX_M 2000

// Structure for an edge
typedef struct Edge {
    int u;
    int v;
} Edge;

// Structure for a graph
typedef struct Graph {
    int V;  // Number of vertices
    int E;  // Number of edges
    Edge *edge; // Array of edges
} Graph;

// Structure for a tree
typedef struct Tree {
    int V;  // Number of vertices
    int E;  // Number of edges
    Edge *edge; // Array of edges
} Tree;

// Function to create a graph
Graph* createGraph(int V, int E) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(sizeof(Edge) * E);
    return graph;
}

// Function to create a tree
Tree* createTree(int V, int E) {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->V = V;
    tree->E = E;
    tree->edge = (Edge*)malloc(sizeof(Edge) * E);
    return tree;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int u, int v) {
    graph->edge[graph->E].u = u;
    graph->edge[graph->E].v = v;
    graph->E++;
}

// Function to add an edge to the tree
void addEdgeTree(Tree *tree, int u, int v) {
    tree->edge[tree->E].u = u;
    tree->edge[tree->E].v = v;
    tree->E++;
}

// Function to check if an edge exists in the graph
int isEdgePresent(Graph *graph, int u, int v) {
    for (int i = 0; i < graph->E; i++) {
        if ((graph->edge[i].u == u && graph->edge[i].v == v) ||
            (graph->edge[i].u == v && graph->edge[i].v == u)) {
            return 1;
        }
    }
    return 0;
}

// Function to find the parent of a node in the tree using Depth First Search (DFS)
int findParent(Tree *tree, int node, int parent) {
    for (int i = 0; i < tree->E; i++) {
        if (tree->edge[i].u == node && tree->edge[i].v != parent) {
            return tree->edge[i].v;
        } else if (tree->edge[i].v == node && tree->edge[i].u != parent) {
            return tree->edge[i].u;
        }
    }
    return -1;
}

// Function to check if there is a simple path in the tree containing three given nodes
int hasSimplePath(Tree *tree, int a, int b, int c) {
    // Check if all three nodes are distinct
    if (a == b || a == c || b == c) {
        return 0;
    }

    // Find the parent of each node
    int parentA = findParent(tree, a, -1);
    int parentB = findParent(tree, b, -1);
    int parentC = findParent(tree, c, -1);

    // Check if any two nodes are directly connected
    if (parentA == b || parentA == c || 
        parentB == a || parentB == c ||
        parentC == a || parentC == b) {
        return 1;
    }

    // Find the Least Common Ancestor (LCA) of the three nodes
    // The LCA is the highest node that is an ancestor of all three nodes
    int lca = -1;
    while (parentA != -1) {
        if (parentA == parentB || parentA == parentC) {
            lca = parentA;
            break;
        }
        parentA = findParent(tree, parentA, -1);
    }

    // If LCA is found, there is a simple path
    return (lca != -1);
}

// Function to add edges to the graph based on the given operation
void addEdges(Graph *graph, Tree *tree) {
    for (int a = 1; a <= graph->V; a++) {
        for (int b = 1; b <= graph->V; b++) {
            for (int c = 1; c <= graph->V; c++) {
                // Check if edges (a, b) and (b, c) exist in the graph
                if (isEdgePresent(graph, a, b) && isEdgePresent(graph, b, c) &&
                    !isEdgePresent(graph, a, c)) {
                    // Check if there is a simple path in the tree containing a, b, and c
                    if (hasSimplePath(tree, a, b, c)) {
                        // Add edge (a, c) to the graph
                        addEdge(graph, a, c);
                    }
                }
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Create the tree
    Tree *tree = createTree(N, N - 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdgeTree(tree, a, b);
    }

    // Create the graph
    Graph *graph = createGraph(N, M);
    for (int i = 0; i < M; i++) {
        int c, d;
        scanf("%d %d", &c, &d);
        addEdge(graph, c, d);
    }

    // Add edges to the graph based on the given operation
    addEdges(graph, tree);

    // Print the number of edges in the final graph
    printf("%d\n", graph->E);

    // Free allocated memory
    free(graph->edge);
    free(graph);
    free(tree->edge);
    free(tree);

    return 0;
}