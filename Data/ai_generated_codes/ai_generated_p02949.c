#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 2500
#define MAX_M 5000

// Structure to represent a graph edge
typedef struct Edge {
    int to;
    int cost;
} Edge;

// Structure to represent a graph node
typedef struct Node {
    int num;
    int visited;
    int max_score;
    Edge *edges;
    int num_edges;
} Node;

// Function to create a new graph node
Node *create_node(int num) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->num = num;
    node->visited = 0;
    node->max_score = INT_MIN;
    node->edges = NULL;
    node->num_edges = 0;
    return node;
}

// Function to add a new edge to a node
void add_edge(Node *node, int to, int cost) {
    node->num_edges++;
    node->edges = (Edge *)realloc(node->edges, sizeof(Edge) * node->num_edges);
    node->edges[node->num_edges - 1].to = to;
    node->edges[node->num_edges - 1].cost = cost;
}

// Function to perform Depth First Search (DFS) on the graph
void dfs(Node *graph[], int n, int node_num, int current_score, int time, int p) {
    // Mark the current node as visited
    graph[node_num]->visited = 1;

    // Calculate the score after paying for the time spent
    int score = current_score - (time * p);

    // Check if the node is the destination node
    if (node_num == n) {
        // Update the maximum score if the current score is greater
        graph[node_num]->max_score = (score > graph[node_num]->max_score) ? score : graph[node_num]->max_score;
    } else {
        // Iterate through all the edges of the current node
        for (int i = 0; i < graph[node_num]->num_edges; i++) {
            int next_node = graph[node_num]->edges[i].to;

            // If the next node has not been visited
            if (!graph[next_node]->visited) {
                // Recursively call DFS on the next node
                dfs(graph, n, next_node, current_score + graph[node_num]->edges[i].cost, time + 1, p);
            }
        }
    }

    // Mark the current node as unvisited for backtracking
    graph[node_num]->visited = 0;
}

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);

    // Create an array of graph nodes
    Node *graph[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        graph[i] = create_node(i);
    }

    // Read the graph edges and their costs
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(graph[a], b, c);
    }

    // Perform DFS on the graph starting from node 1
    dfs(graph, n, 1, 0, 0, p);

    // Print the maximum score if it exists, otherwise print -1
    if (graph[n]->max_score != INT_MIN) {
        printf("%d\n", graph[n]->max_score);
    } else {
        printf("-1\n");
    }

    // Free the allocated memory
    for (int i = 1; i <= n; i++) {
        free(graph[i]->edges);
        free(graph[i]);
    }

    return 0;
}