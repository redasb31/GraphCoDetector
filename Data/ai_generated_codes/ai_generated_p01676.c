#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500
#define MAX_M 3000

// Structure to represent a node in the graph
typedef struct Node {
    int id;
    int in_degree;
    int out_degree;
    int *in_edges;
    int *out_edges;
} Node;

// Structure to represent an edge in the graph
typedef struct Edge {
    int from;
    int to;
} Edge;

// Function to create a new node
Node *create_node(int id) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->id = id;
    node->in_degree = 0;
    node->out_degree = 0;
    node->in_edges = NULL;
    node->out_edges = NULL;
    return node;
}

// Function to create a new edge
Edge *create_edge(int from, int to) {
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->from = from;
    edge->to = to;
    return edge;
}

// Function to add an edge to the graph
void add_edge(Node *nodes[], Edge *edge) {
    // Increase out-degree of the source node
    nodes[edge->from]->out_degree++;
    // Increase in-degree of the destination node
    nodes[edge->to]->in_degree++;
    // Allocate memory for the new in/out edge arrays
    nodes[edge->from]->out_edges = (int *)realloc(nodes[edge->from]->out_edges, sizeof(int) * nodes[edge->from]->out_degree);
    nodes[edge->to]->in_edges = (int *)realloc(nodes[edge->to]->in_edges, sizeof(int) * nodes[edge->to]->in_degree);
    // Add the edge to the arrays
    nodes[edge->from]->out_edges[nodes[edge->from]->out_degree - 1] = edge->to;
    nodes[edge->to]->in_edges[nodes[edge->to]->in_degree - 1] = edge->from;
}

// Function to calculate the minimum number of edges to keep
int calculate_min_edges(Node *nodes[], int N) {
    int min_edges = 0;
    // Iterate over all nodes
    for (int i = 0; i < N; i++) {
        // Choose the minimum between in-degree and out-degree for each node
        min_edges += (nodes[i]->in_degree < nodes[i]->out_degree) ? nodes[i]->in_degree : nodes[i]->out_degree;
    }
    // Return the total number of minimum edges
    return min_edges;
}

int main() {
    int N, M;
    // Read the number of nodes and edges
    while (scanf("%d %d", &N, &M) != EOF) {
        // Create an array of nodes
        Node *nodes[MAX_N];
        // Initialize the nodes
        for (int i = 0; i < N; i++) {
            nodes[i] = create_node(i + 1);
        }
        // Read the edges
        for (int i = 0; i < M; i++) {
            int s, t;
            scanf("%d %d", &s, &t);
            // Create an edge
            Edge *edge = create_edge(s - 1, t - 1);
            // Add the edge to the graph
            add_edge(nodes, edge);
        }
        // Calculate the minimum number of edges to keep
        int min_edges = calculate_min_edges(nodes, N);
        // Print the result
        printf("%d\n", min_edges);
        // Free the allocated memory
        for (int i = 0; i < N; i++) {
            free(nodes[i]->in_edges);
            free(nodes[i]->out_edges);
            free(nodes[i]);
        }
    }
    return 0;
}