#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 200000

typedef struct Edge {
    int to;
    int cost;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Edge *edges[MAX_N + 1];
} Graph;

// Function to add an edge to the graph
void add_edge(Graph *graph, int from, int to, int cost) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->to = to;
    new_edge->cost = cost;
    new_edge->next = graph->edges[from];
    graph->edges[from] = new_edge;
}

// Function to perform a Depth-First Search (DFS) on the graph
int dfs(Graph *graph, int current, int target, int broken_edge, int cost, int *visited) {
    visited[current] = 1;
    if (current == target) {
        return cost;
    }

    int min_cost = INT_MAX;
    for (Edge *edge = graph->edges[current]; edge != NULL; edge = edge->next) {
        if (edge->to != broken_edge && !visited[edge->to]) {
            int new_cost = dfs(graph, edge->to, target, broken_edge, cost + edge->cost, visited);
            if (new_cost != INT_MAX) {
                min_cost = new_cost;
            }
        }
    }

    return min_cost;
}

// Function to find the minimum cost in the worst case scenario
int find_min_cost(Graph *graph, int start, int target, int n) {
    int min_cost = INT_MAX;
    int visited[MAX_N + 1] = {0};

    // Iterate over all edges to simulate the broken edge scenario
    for (int i = 1; i <= n; i++) {
        for (Edge *edge = graph->edges[i]; edge != NULL; edge = edge->next) {
            int cost = dfs(graph, start, target, edge->to, 0, visited);
            if (cost != INT_MAX) {
                min_cost = (min_cost > cost) ? cost : min_cost;
            }
            // Reset visited array for the next iteration
            for (int j = 1; j <= n; j++) {
                visited[j] = 0;
            }
        }
    }

    return (min_cost == INT_MAX) ? -1 : min_cost;
}

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);

    Graph graph;
    for (int i = 0; i <= n; i++) {
        graph.edges[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        add_edge(&graph, u, v, c);
        add_edge(&graph, v, u, c);
    }

    int min_cost = find_min_cost(&graph, s, t, n);
    printf("%d\n", min_cost);

    return 0;
}