#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
  int to;
  long long weight;
} Edge;

typedef struct {
  int head;
  int size;
  Edge* edges;
} AdjList;

int n;
AdjList adj[MAX_N + 1];
long long s[MAX_N + 1];
long long dist[MAX_N + 1];

// Function to add an edge to the adjacency list
void addEdge(int from, int to, long long weight) {
  adj[from].edges[adj[from].size++] = (Edge){to, weight};
  adj[to].edges[adj[to].size++] = (Edge){from, weight};
}

// Function to calculate the distance from a given vertex to all other vertices using DFS
void dfs(int u, int p, long long d) {
  dist[u] = d;
  for (int i = 0; i < adj[u].size; i++) {
    int v = adj[u].edges[i].to;
    if (v != p) {
      dfs(v, u, d + adj[u].edges[i].weight);
    }
  }
}

int main() {
  scanf("%d", &n);

  // Initialize the adjacency list
  for (int i = 1; i <= n; i++) {
    adj[i].head = i;
    adj[i].size = 0;
    adj[i].edges = (Edge*)malloc(sizeof(Edge) * (n - 1));
  }

  // Read the edges and store them in the adjacency list
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    addEdge(a, b, 0); // Initially, the weight of each edge is 0
  }

  // Read the sum of shortest distances
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &s[i]);
  }

  // Calculate the distance from vertex 1 to all other vertices
  dfs(1, 0, 0);

  // Calculate the weight of each edge
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < adj[i].size; j++) {
      int v = adj[i].edges[j].to;
      if (v > i) {
        adj[i].edges[j].weight = s[v] - s[i] + dist[i] - dist[v];
        printf("%lld\n", adj[i].edges[j].weight);
      }
    }
  }

  // Free the memory allocated for the adjacency list
  for (int i = 1; i <= n; i++) {
    free(adj[i].edges);
  }

  return 0;
}