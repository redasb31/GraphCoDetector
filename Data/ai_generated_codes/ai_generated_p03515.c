#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define INF 1000000000

typedef struct Edge {
  int to;
  int cost;
  struct Edge *next;
} Edge;

typedef struct Node {
  Edge *head;
} Node;

Node nodes[MAX_N + 1];
int n;
int parent[MAX_N + 1];
int min_cost[MAX_N + 1]; // stores the minimum cost of edge on the path from root to a node

// Function to add an edge to the graph
void add_edge(int from, int to, int cost) {
  Edge *new_edge = (Edge *)malloc(sizeof(Edge));
  new_edge->to = to;
  new_edge->cost = cost;
  new_edge->next = nodes[from].head;
  nodes[from].head = new_edge;
}

// Function to perform Depth First Search (DFS)
void dfs(int current, int prev, int cost) {
  parent[current] = prev;
  min_cost[current] = cost;
  for (Edge *e = nodes[current].head; e != NULL; e = e->next) {
    if (e->to != prev) {
      dfs(e->to, current, (cost < e->cost) ? cost : e->cost);
    }
  }
}

int main() {
  scanf("%d", &n);

  // Initialize the graph
  for (int i = 1; i <= n; i++) {
    nodes[i].head = NULL;
  }

  // Read the edges and construct the graph
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    add_edge(a, b, c);
    add_edge(b, a, c);
  }

  // Perform DFS to calculate the minimum cost on the path from root to each node
  dfs(1, 0, INF); // Assume vertex 1 as the root

  // Calculate niceness for each vertex
  for (int i = 1; i <= n; i++) {
    int niceness = 0;
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        niceness += min_cost[j]; // Add the minimum cost on the path from i to j
      }
    }
    printf("%d\n", niceness);
  }

  return 0;
}