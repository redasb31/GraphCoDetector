#include <stdio.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 1000

// Structure for representing an edge in the flow network
struct Edge {
  int to;  // Destination vertex
  int cap;  // Capacity of the edge
  int flow; // Current flow on the edge
  int rev;  // Index of the reverse edge
};

// Structure for representing the flow network
struct Graph {
  int V;   // Number of vertices
  int E;   // Number of edges
  struct Edge edges[MAX_E * 2]; // Array of edges
  int head[MAX_V]; // Adjacency list representation
  int level[MAX_V]; // Level of each vertex for BFS
};

// Function to add an edge to the graph
void add_edge(struct Graph* graph, int from, int to, int cap) {
  // Add a forward edge
  graph->edges[graph->E].to = to;
  graph->edges[graph->E].cap = cap;
  graph->edges[graph->E].flow = 0;
  graph->edges[graph->E].rev = graph->E + 1;
  graph->edges[graph->E++] = graph->edges[graph->E - 1];

  // Add a reverse edge
  graph->edges[graph->E].to = from;
  graph->edges[graph->E].cap = 0;
  graph->edges[graph->E].flow = 0;
  graph->edges[graph->E].rev = graph->E - 1;
  graph->edges[graph->E++] = graph->edges[graph->E - 1];
}

// Function to initialize the graph
void init_graph(struct Graph* graph, int V, int E) {
  graph->V = V;
  graph->E = 0;
  for (int i = 0; i < V; i++) {
    graph->head[i] = -1;
  }
}

// Function to perform Breadth-First Search (BFS)
int bfs(struct Graph* graph, int s, int t) {
  for (int i = 0; i < graph->V; i++) {
    graph->level[i] = -1;
  }
  graph->level[s] = 0;

  // Queue for BFS
  int queue[MAX_V];
  int front = 0, rear = 0;
  queue[rear++] = s;

  while (front < rear) {
    int u = queue[front++];
    for (int i = graph->head[u]; i != -1; i = graph->edges[i].rev) {
      int v = graph->edges[i].to;
      if (graph->level[v] < 0 && graph->edges[i].cap > graph->edges[i].flow) {
        graph->level[v] = graph->level[u] + 1;
        queue[rear++] = v;
      }
    }
  }
  return graph->level[t] != -1;
}

// Function to find a path from source to sink using DFS
int dfs(struct Graph* graph, int u, int t, int f) {
  if (u == t) {
    return f;
  }

  for (int i = graph->head[u]; i != -1; i = graph->edges[i].rev) {
    int v = graph->edges[i].to;
    if (graph->level[v] == graph->level[u] + 1 &&
        graph->edges[i].cap > graph->edges[i].flow) {
      int df = dfs(graph, v, t,
                   f < graph->edges[i].cap - graph->edges[i].flow ?
                   f : graph->edges[i].cap - graph->edges[i].flow);
      if (df > 0) {
        graph->edges[i].flow += df;
        graph->edges[graph->edges[i].rev].flow -= df;
        return df;
      }
    }
  }
  return 0;
}

// Function to compute the maximum flow using Ford-Fulkerson algorithm
int max_flow(struct Graph* graph, int s, int t) {
  int flow = 0;
  while (bfs(graph, s, t)) {
    int df;
    do {
      df = dfs(graph, s, t, INT_MAX);
      flow += df;
    } while (df > 0);
  }
  return flow;
}

int main() {
  int V, E;
  scanf("%d %d", &V, &E);

  struct Graph graph;
  init_graph(&graph, V, E);

  // Read the edges from input
  for (int i = 0; i < E; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    add_edge(&graph, u, v, c);
  }

  // Calculate and print the maximum flow
  printf("%d\n", max_flow(&graph, 0, V - 1));

  return 0;
}