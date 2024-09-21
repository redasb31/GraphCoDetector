#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 1000

// Structure to represent an edge in the graph
typedef struct Edge {
    int source;
    int target;
    int weight;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int num_vertices;
    int num_edges;
    Edge *edges;
} Graph;

// Function to create a new graph
Graph *create_graph(int num_vertices, int num_edges) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->edges = (Edge *)malloc(sizeof(Edge) * num_edges);
    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int source, int target, int weight) {
    graph->edges[graph->num_edges].source = source;
    graph->edges[graph->num_edges].target = target;
    graph->edges[graph->num_edges].weight = weight;
    graph->num_edges++;
}

// Function to find the minimum-cost arborescence using the Chu-Liu/Edmonds algorithm
int chu_liu_edmonds(Graph *graph, int root) {
    int num_vertices = graph->num_vertices;
    int num_edges = graph->num_edges;
    int *in_degree = (int *)calloc(num_vertices, sizeof(int)); // Array to store in-degrees of vertices
    int *parent = (int *)malloc(sizeof(int) * num_vertices); // Array to store parent vertices in the arborescence
    int *cost = (int *)malloc(sizeof(int) * num_vertices); // Array to store minimum costs to reach vertices from root
    int *cycle_head = (int *)malloc(sizeof(int) * num_vertices); // Array to store the head of the cycle each vertex belongs to
    int *cycle_weight = (int *)malloc(sizeof(int) * num_vertices); // Array to store the weight of the cycle each vertex belongs to

    // Initialize arrays
    for (int i = 0; i < num_vertices; i++) {
        parent[i] = -1;
        cost[i] = INT_MAX;
        cycle_head[i] = -1;
        cycle_weight[i] = 0;
    }

    // Step 1: Find the minimum incoming edge for each vertex
    for (int i = 0; i < num_edges; i++) {
        int source = graph->edges[i].source;
        int target = graph->edges[i].target;
        int weight = graph->edges[i].weight;

        if (weight < cost[target] && target != root) {
            cost[target] = weight;
            parent[target] = source;
        }
    }

    // Step 2: Identify cycles
    for (int i = 0; i < num_vertices; i++) {
        if (i != root && parent[i] != -1) {
            int current = i;
            int cycle_start = i;
            int cycle_sum = 0;

            while (cycle_head[current] == -1) {
                cycle_head[current] = cycle_start;
                cycle_sum += cost[current];
                current = parent[current];
            }

            if (current != cycle_start) {
                // Found a cycle
                cycle_weight[cycle_start] = cycle_sum - cost[current];
            }
        }
    }

    // Step 3: Contract cycles
    while (1) {
        int min_cycle_weight = INT_MAX;
        int cycle_head_to_contract = -1;

        // Find the cycle with the minimum weight
        for (int i = 0; i < num_vertices; i++) {
            if (cycle_head[i] != -1 && cycle_weight[i] < min_cycle_weight) {
                min_cycle_weight = cycle_weight[i];
                cycle_head_to_contract = cycle_head[i];
            }
        }

        // If no cycle found, break
        if (cycle_head_to_contract == -1) {
            break;
        }

        // Contract the cycle
        for (int i = 0; i < num_vertices; i++) {
            if (cycle_head[i] == cycle_head_to_contract) {
                parent[i] = cycle_head_to_contract;
                cost[i] = 0;
                cycle_head[i] = -1;
            }
        }

        // Update the edge weights
        for (int i = 0; i < num_edges; i++) {
            int source = graph->edges[i].source;
            int target = graph->edges[i].target;
            int weight = graph->edges[i].weight;

            if (cycle_head[source] == cycle_head_to_contract) {
                if (cycle_head[target] != cycle_head_to_contract) {
                    graph->edges[i].weight = weight - min_cycle_weight;
                } else {
                    graph->edges[i].weight = weight;
                }
            }
        }
    }

    // Step 4: Construct the arborescence
    int total_cost = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (i != root && parent[i] != -1) {
            total_cost += cost[i];
        }
    }

    // Free allocated memory
    free(in_degree);
    free(parent);
    free(cost);
    free(cycle_head);
    free(cycle_weight);

    return total_cost;
}

int main() {
    int num_vertices, num_edges, root;
    scanf("%d %d %d", &num_vertices, &num_edges, &root);

    Graph *graph = create_graph(num_vertices, num_edges);

    // Read the edges from input
    for (int i = 0; i < num_edges; i++) {
        int source, target, weight;
        scanf("%d %d %d", &source, &target, &weight);
        add_edge(graph, source, target, weight);
    }

    // Find the minimum-cost arborescence
    int min_cost = chu_liu_edmonds(graph, root);

    // Print the minimum cost
    printf("%d\n", min_cost);

    // Free allocated memory
    free(graph->edges);
    free(graph);

    return 0;
}