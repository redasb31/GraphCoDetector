#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

typedef struct {
  int to;
  struct Edge *next;
} Edge;

typedef struct {
  Edge *head;
} AdjList;

AdjList adj[MAX_N + 1];
int n, m;

// Function to add an edge to the adjacency list
void add_edge(int u, int v) {
  Edge *new_edge = (Edge *)malloc(sizeof(Edge));
  new_edge->to = v;
  new_edge->next = adj[u].head;
  adj[u].head = new_edge;
}

// Function to perform Depth-First Search (DFS)
int dfs(int u, int parent, int color) {
  int count = 1; // Number of ways to paint the subtree rooted at u
  Edge *curr = adj[u].head;
  while (curr != NULL) {
    if (curr->to != parent) {
      int subtree_count = dfs(curr->to, u, !color);
      count = (count * subtree_count) % m; // Multiply counts for subtrees
    }
    curr = curr->next;
  }
  return count;
}

int main() {
  scanf("%d %d", &n, &m);
  
  // Initialize adjacency list
  for (int i = 1; i <= n; i++) {
    adj[i].head = NULL;
  }

  // Read edges and add them to the adjacency list
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }

  // For each vertex, calculate the number of ways to paint the tree
  for (int i = 1; i <= n; i++) {
    // Calculate the number of ways to paint the subtree rooted at i
    int count = dfs(i, 0, 1);
    printf("%d\n", count);
  }

  return 0;
}