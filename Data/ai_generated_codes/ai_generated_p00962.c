#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct Edge {
    int to;
    int cost;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Edge *edges[MAX_N + 1];
    int num_edges;
} Graph;

// Initialize a graph
Graph *init_graph() {
    Graph *graph = malloc(sizeof(Graph));
    graph->num_edges = 0;
    for (int i = 1; i <= MAX_N; i++) {
        graph->edges[i] = NULL;
    }
    return graph;
}

// Add an edge to the graph
void add_edge(Graph *graph, int from, int to, int cost) {
    Edge *new_edge = malloc(sizeof(Edge));
    new_edge->to = to;
    new_edge->cost = cost;
    new_edge->next = graph->edges[from];
    graph->edges[from] = new_edge;
    graph->num_edges++;
}

// Dijkstra's algorithm for finding the shortest path
int dijkstra(Graph *graph, int start, int end) {
    int distances[MAX_N + 1];
    int visited[MAX_N + 1];
    for (int i = 1; i <= MAX_N; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[start] = 0;
    
    for (int i = 0; i < MAX_N; i++) {
        int min_distance = INT_MAX;
        int min_vertex = -1;
        for (int j = 1; j <= MAX_N; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_vertex = j;
            }
        }
        if (min_vertex == -1) {
            break;
        }
        visited[min_vertex] = 1;
        
        Edge *edge = graph->edges[min_vertex];
        while (edge != NULL) {
            if (distances[min_vertex] + edge->cost < distances[edge->to]) {
                distances[edge->to] = distances[min_vertex] + edge->cost;
            }
            edge = edge->next;
        }
    }
    return distances[end];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Initialize the graph
    Graph *graph = init_graph();
    Graph *reversed_graph = init_graph();

    // Read the edges and add them to the graph
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(graph, a, b, c);
        add_edge(reversed_graph, b, a, c); // Add the reversed edge for the reversed graph
    }

    // Calculate the shortest distance before the social experiment
    int original_distance = dijkstra(graph, 1, 2);

    // Iterate over each day and calculate the shortest distance
    for (int i = 1; i <= m; i++) {
        int reversed_distance = dijkstra(reversed_graph, 1, 2);

        if (reversed_distance < original_distance) {
            printf("HAPPY\n");
        } else if (reversed_distance == original_distance) {
            printf("SOSO\n");
        } else {
            printf("SAD\n");
        }

        // Reverse the edge for the next day
        Edge *edge = graph->edges[i];
        while (edge != NULL) {
            if (edge->to == i) {
                break;
            }
            edge = edge->next;
        }
        if (edge != NULL) {
            graph->edges[edge->to] = edge->next;
            add_edge(graph, i, edge->to, edge->cost);
        }
        edge = reversed_graph->edges[i];
        while (edge != NULL) {
            if (edge->to == i) {
                break;
            }
            edge = edge->next;
        }
        if (edge != NULL) {
            reversed_graph->edges[edge->to] = edge->next;
            add_edge(reversed_graph, i, edge->to, edge->cost);
        }
    }

    free(graph);
    free(reversed_graph);

    return 0;
}