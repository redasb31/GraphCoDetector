#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent an edge in the tree
typedef struct Edge {
  int u;
  int v;
  int w;
} Edge;

// Structure to represent a node in the tree
typedef struct Node {
  int id;
  int color; // 0: white, 1: black
  int parent;
  int depth;
  Edge *edges;
  int num_edges;
} Node;

// Function to create a new node
Node *create_node(int id) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->id = id;
  node->color = -1; // Initially uncolored
  node->parent = -1;
  node->depth = 0;
  node->edges = NULL;
  node->num_edges = 0;
  return node;
}

// Function to add an edge to a node
void add_edge(Node *node, int u, int v, int w) {
  node->num_edges++;
  node->edges = (Edge *)realloc(node->edges, node->num_edges * sizeof(Edge));
  node->edges[node->num_edges - 1].u = u;
  node->edges[node->num_edges - 1].v = v;
  node->edges[node->num_edges - 1].w = w;
}

// Function to perform depth-first search (DFS) on the tree
void dfs(Node *nodes, int n, int current, int parent, int depth) {
  nodes[current].parent = parent;
  nodes[current].depth = depth;
  
  // Color the current node based on its depth
  if (depth % 2 == 0) {
    nodes[current].color = 0; // White
  } else {
    nodes[current].color = 1; // Black
  }
  
  // Recursively explore the children of the current node
  for (int i = 0; i < nodes[current].num_edges; i++) {
    Edge *edge = &nodes[current].edges[i];
    if (edge->v != parent) {
      dfs(nodes, n, edge->v, current, depth + edge->w);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  // Create an array of nodes
  Node *nodes = (Node *)malloc(n * sizeof(Node));
  for (int i = 0; i < n; i++) {
    nodes[i] = *create_node(i + 1);
  }

  // Read the edges of the tree
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    add_edge(&nodes[u - 1], u, v, w);
    add_edge(&nodes[v - 1], v, u, w);
  }

  // Perform DFS starting from node 1 (root)
  dfs(nodes, n, 0, -1, 0);

  // Print the coloring of the vertices
  for (int i = 0; i < n; i++) {
    printf("%d\n", nodes[i].color);
  }

  // Free the allocated memory
  free(nodes);

  return 0;
}