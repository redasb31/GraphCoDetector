#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

typedef struct {
  int parent;
  int degree;
  int color;
  int is_leaf;
} Vertex;

typedef struct {
  int to;
  struct Edge* next;
} Edge;

Vertex vertices[MAX_N];
Edge* adj[MAX_N];

// Function to add an edge to the adjacency list
void add_edge(int u, int v) {
  Edge* new_edge = (Edge*)malloc(sizeof(Edge));
  new_edge->to = v;
  new_edge->next = adj[u];
  adj[u] = new_edge;
}

// Function to perform a depth-first search to calculate degrees and parent nodes
void dfs(int u, int parent) {
  vertices[u].parent = parent;
  vertices[u].degree = 0;

  Edge* cur = adj[u];
  while (cur != NULL) {
    int v = cur->to;
    if (v != parent) {
      vertices[u].degree++;
      dfs(v, u);
    }
    cur = cur->next;
  }
}

// Function to check if two rooted trees are isomorphic
int is_isomorphic(int u, int v) {
  if (vertices[u].degree != vertices[v].degree) {
    return 0;
  }

  Edge* cur_u = adj[u];
  Edge* cur_v = adj[v];

  while (cur_u != NULL && cur_v != NULL) {
    if (vertices[cur_u->to].color != vertices[cur_v->to].color) {
      return 0;
    }
    cur_u = cur_u->next;
    cur_v = cur_v->next;
  }

  return (cur_u == NULL && cur_v == NULL);
}

// Function to calculate the minimum colorfulness and number of leaves
void calculate_colorfulness(int n) {
  int colorfulness = 1;
  int leaves = 0;

  // Initially assign all vertices to color 1
  for (int i = 1; i <= n; i++) {
    vertices[i].color = 1;
    if (vertices[i].degree == 1) {
      leaves++;
    }
  }

  // Iterate through all colors
  while (1) {
    int valid = 1;

    // Check if all vertices with the same color have isomorphic rooted trees
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (vertices[i].color == vertices[j].color && !is_isomorphic(i, j)) {
          valid = 0;
          break;
        }
      }
      if (!valid) {
        break;
      }
    }

    // If all vertices with the same color have isomorphic rooted trees, increment the colorfulness and assign new colors
    if (valid) {
      colorfulness++;
      for (int i = 1; i <= n; i++) {
        if (vertices[i].color == colorfulness - 1) {
          vertices[i].color = colorfulness;
          if (vertices[i].degree == 1) {
            leaves++;
          }
        }
      }
    } else {
      break;
    }
  }

  printf("%d %d\n", colorfulness, leaves);
}

int main() {
  int n;
  scanf("%d", &n);

  // Read the edges of the tree
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    add_edge(a, b);
    add_edge(b, a);
  }

  // Perform depth-first search to calculate degrees and parent nodes
  dfs(1, 0);

  // Calculate the minimum colorfulness and number of leaves
  calculate_colorfulness(n);

  return 0;
}