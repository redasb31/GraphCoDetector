#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100000
#define MAX_EDGES 100000

// Structure to represent an edge in the graph
struct Edge {
    int source;
    int target;
};

// Structure to represent a graph
struct Graph {
    int numVertices;
    int numEdges;
    struct Edge *edges;
    int *adjList[MAX_VERTICES];
    int *visited;
    int *discoveryTime;
    int *low;
    int *parent;
    int time;
    int *articulationPoints;
    int numArticulationPoints;
};

// Function to create a new graph
struct Graph *createGraph(int numVertices, int numEdges) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->edges = (struct Edge *)malloc(sizeof(struct Edge) * numEdges);
    graph->visited = (int *)calloc(numVertices, sizeof(int));
    graph->discoveryTime = (int *)calloc(numVertices, sizeof(int));
    graph->low = (int *)calloc(numVertices, sizeof(int));
    graph->parent = (int *)calloc(numVertices, sizeof(int));
    graph->articulationPoints = (int *)calloc(numVertices, sizeof(int));
    graph->numArticulationPoints = 0;
    graph->time = 0;

    // Initialize adjacency list
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int source, int target) {
    graph->edges[graph->numEdges].source = source;
    graph->edges[graph->numEdges].target = target;
    graph->numEdges++;

    // Add edge to adjacency list
    graph->adjList[source] = (int *)realloc(graph->adjList[source],
                                       (graph->adjList[source] != NULL ?
                                        sizeof(int) * (graph->numEdges + 1) :
                                        sizeof(int) * (graph->numEdges)));
    graph->adjList[source][graph->numEdges - 1] = target;

    // Since it's an undirected graph, add the reverse edge too
    graph->adjList[target] = (int *)realloc(graph->adjList[target],
                                       (graph->adjList[target] != NULL ?
                                        sizeof(int) * (graph->numEdges + 1) :
                                        sizeof(int) * (graph->numEdges)));
    graph->adjList[target][graph->numEdges - 1] = source;
}

// Depth First Search (DFS) to find articulation points
void dfs(struct Graph *graph, int u) {
    graph->visited[u] = 1;
    graph->discoveryTime[u] = graph->low[u] = ++graph->time;
    int children = 0; // Count of children of the current vertex

    for (int i = 0; graph->adjList[u][i] != 0; i++) {
        int v = graph->adjList[u][i];

        if (!graph->visited[v]) {
            children++;
            graph->parent[v] = u;
            dfs(graph, v);
            graph->low[u] = (graph->low[u] < graph->low[v]) ?
                           graph->low[u] : graph->low[v];

            // If u is not the root and its discovery time is less than or equal to its low value
            // then it is an articulation point
            if (graph->parent[u] != -1 && graph->discoveryTime[u] <= graph->low[v]) {
                graph->articulationPoints[graph->numArticulationPoints++] = u;
            }
        } else if (v != graph->parent[u]) {
            // Back edge found
            graph->low[u] = (graph->low[u] < graph->discoveryTime[v]) ?
                           graph->low[u] : graph->discoveryTime[v];
        }
    }

    // If the root has more than one child, it is also an articulation point
    if (graph->parent[u] == -1 && children > 1) {
        graph->articulationPoints[graph->numArticulationPoints++] = u;
    }
}

// Function to find articulation points in the graph
void findArticulationPoints(struct Graph *graph) {
    // Set parent of the root vertex to -1
    graph->parent[0] = -1;

    // Perform DFS from each unvisited vertex
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            dfs(graph, i);
        }
    }
}

// Function to print the articulation points
void printArticulationPoints(struct Graph *graph) {
    for (int i = 0; i < graph->numArticulationPoints; i++) {
        printf("%d\n", graph->articulationPoints[i]);
    }
}

int main() {
    int numVertices, numEdges;
    scanf("%d %d", &numVertices, &numEdges);

    struct Graph *graph = createGraph(numVertices, numEdges);

    // Read edges from input
    for (int i = 0; i < numEdges; i++) {
        int source, target;
        scanf("%d %d", &source, &target);
        addEdge(graph, source, target);
    }

    // Find articulation points
    findArticulationPoints(graph);

    // Print articulation points
    printArticulationPoints(graph);

    // Free memory
    free(graph->edges);
    free(graph->visited);
    free(graph->discoveryTime);
    free(graph->low);
    free(graph->parent);
    free(graph->articulationPoints);
    free(graph);

    return 0;
}