#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_N 100
#define MAX_M 1000
#define INF INT_MAX

// Edge structure
typedef struct Edge {
    int to;  // Destination vertex
    int cap; // Capacity
    int cost; // Cost
    int flow; // Flow
    int next; // Next edge in the adjacency list
} Edge;

// Graph structure
typedef struct Graph {
    Edge edges[MAX_M * 2]; // Array of edges
    int head[MAX_N];       // Head of the adjacency list for each vertex
    int edge_cnt;          // Number of edges
} Graph;

// Initialize the graph
void init_graph(Graph* graph) {
    graph->edge_cnt = 0;
    for (int i = 0; i < MAX_N; i++) {
        graph->head[i] = -1;
    }
}

// Add an edge to the graph
void add_edge(Graph* graph, int from, int to, int cap, int cost) {
    graph->edges[graph->edge_cnt].to = to;
    graph->edges[graph->edge_cnt].cap = cap;
    graph->edges[graph->edge_cnt].cost = cost;
    graph->edges[graph->edge_cnt].flow = 0;
    graph->edges[graph->edge_cnt].next = graph->head[from];
    graph->head[from] = graph->edge_cnt++;

    // Add the reverse edge (for the residual graph)
    graph->edges[graph->edge_cnt].to = from;
    graph->edges[graph->edge_cnt].cap = 0; // Reverse edge capacity is 0
    graph->edges[graph->edge_cnt].cost = -cost; // Reverse edge cost is negative
    graph->edges[graph->edge_cnt].flow = 0;
    graph->edges[graph->edge_cnt].next = graph->head[to];
    graph->head[to] = graph->edge_cnt++;
}

// Bellman-Ford algorithm for finding shortest paths with potential
int bellman_ford(Graph* graph, int s, int t, int* dist, int* potential) {
    // Initialize distance and potential
    for (int i = 0; i < MAX_N; i++) {
        dist[i] = INF;
        potential[i] = 0;
    }
    dist[s] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < MAX_N - 1; i++) {
        for (int u = 0; u < MAX_N; u++) {
            for (int e = graph->head[u]; e != -1; e = graph->edges[e].next) {
                int v = graph->edges[e].to;
                int cap = graph->edges[e].cap - graph->edges[e].flow;
                int cost = graph->edges[e].cost;
                if (cap > 0 && dist[u] + cost + potential[u] - potential[v] < dist[v]) {
                    dist[v] = dist[u] + cost + potential[u] - potential[v];
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < MAX_N; u++) {
        for (int e = graph->head[u]; e != -1; e = graph->edges[e].next) {
            int v = graph->edges[e].to;
            int cap = graph->edges[e].cap - graph->edges[e].flow;
            int cost = graph->edges[e].cost;
            if (cap > 0 && dist[u] + cost + potential[u] - potential[v] < dist[v]) {
                return 0; // Negative cycle detected
            }
        }
    }

    // Update potential
    for (int i = 0; i < MAX_N; i++) {
        potential[i] += dist[i];
    }
    return 1; // No negative cycle
}

// Minimum cost flow algorithm (using Bellman-Ford with potential)
int min_cost_flow(Graph* graph, int s, int t, int max_flow) {
    int dist[MAX_N], potential[MAX_N];
    int flow = 0;
    int cost = 0;

    while (flow < max_flow) {
        // Find shortest path using Bellman-Ford with potential
        if (!bellman_ford(graph, s, t, dist, potential)) {
            break; // Negative cycle detected, stop
        }

        // Find bottleneck capacity
        int bottleneck = INF;
        int prev[MAX_N];
        prev[t] = -1;
        for (int u = 0; u < MAX_N; u++) {
            for (int e = graph->head[u]; e != -1; e = graph->edges[e].next) {
                int v = graph->edges[e].to;
                int cap = graph->edges[e].cap - graph->edges[e].flow;
                if (cap > 0 && dist[u] + graph->edges[e].cost + potential[u] - potential[v] == dist[v] && cap < bottleneck) {
                    bottleneck = cap;
                    prev[v] = e;
                }
            }
        }

        // Augment flow along the path
        if (bottleneck == INF) {
            break; // No augmenting path found, stop
        }
        flow += bottleneck;
        cost += bottleneck * dist[t];

        // Update flow along the path
        int u = t;
        while (u != s) {
            int e = prev[u];
            graph->edges[e].flow += bottleneck;
            graph->edges[e ^ 1].flow -= bottleneck;
            u = graph->edges[e].to;
        }
    }

    return cost;
}

int main() {
    int N, M, s, t;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &s, &t);

    Graph graph;
    init_graph(&graph);

    // Read edges and add them to the graph
    for (int i = 0; i < M; i++) {
        int a, b, u, c;
        scanf("%d %d %d %d", &a, &b, &u, &c);
        add_edge(&graph, a - 1, b - 1, u, c); // Adjust vertex indices to 0-based
    }

    // Find the maximum flow
    int max_flow = min_cost_flow(&graph, s - 1, t - 1, INF); // Adjust source and sink indices to 0-based

    // Find the minimum cost flow with the maximum flow
    int min_cost = min_cost_flow(&graph, s - 1, t - 1, max_flow);

    // Calculate the balanced function
    int numerator = min_cost * min_cost + (max_flow - min_cost) * (max_flow - min_cost);
    int denominator = 1;

    // Find the greatest common divisor (GCD)
    while (numerator % denominator != 0) {
        int temp = numerator % denominator;
        numerator = denominator;
        denominator = temp;
    }

    printf("%d/%d\n", numerator, denominator);

    return 0;
}