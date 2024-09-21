#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_A 16

typedef struct Edge {
  int to;
  int cost;
} Edge;

typedef struct Node {
  int num;
  int depth;
  Edge* edges;
  int edge_count;
} Node;

Node nodes[MAX_N];
int edge_count = 0;

// Function to add an edge to the graph
void add_edge(int from, int to, int cost) {
  nodes[from].edges[nodes[from].edge_count].to = to;
  nodes[from].edges[nodes[from].edge_count].cost = cost;
  nodes[from].edge_count++;
}

// Function to perform Depth First Search (DFS) to calculate the depth of each node
void dfs(int node, int depth, int parent) {
  nodes[node].depth = depth;
  for (int i = 0; i < nodes[node].edge_count; i++) {
    if (nodes[node].edges[i].to != parent) {
      dfs(nodes[node].edges[i].to, depth + 1, node);
    }
  }
}

// Function to calculate the minimum number of operations required
int calculate_operations(int root) {
  int operations = 0;
  int visited[MAX_N] = {0};
  int stack[MAX_N];
  int top = -1;
  stack[++top] = root;

  // Iterate through each node in the tree using DFS
  while (top >= 0) {
    int current = stack[top--];
    if (visited[current]) {
      continue;
    }
    visited[current] = 1;

    // Iterate through the edges of the current node
    for (int i = 0; i < nodes[current].edge_count; i++) {
      int next = nodes[current].edges[i].to;

      // If the edge has a non-zero cost
      if (nodes[current].edges[i].cost) {
        // Find the XOR of all edge costs in the path from the root to the current node
        int xor = 0;
        for (int j = 0; j <= top; j++) {
          xor ^= nodes[stack[j]].edges[i].cost;
        }
        // Add the XOR value to the count of operations
        operations += (xor != 0);

        // Add the next node to the stack if not visited
        if (!visited[next]) {
          stack[++top] = next;
        }
      }
    }
  }
  return operations;
}

int main() {
  int n, x, y, a;
  scanf("%d", &n);
  
  // Initialize the nodes array
  for (int i = 0; i < n; i++) {
    nodes[i].num = i;
    nodes[i].edge_count = 0;
    nodes[i].edges = malloc(sizeof(Edge) * (n - 1));
  }

  // Read the input graph
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d %d", &x, &y, &a);
    add_edge(x, y, a);
    add_edge(y, x, a);
  }

  // Perform DFS to calculate the depth of each node
  dfs(0, 0, -1);

  // Find the root node with the maximum depth
  int root = 0;
  for (int i = 1; i < n; i++) {
    if (nodes[i].depth > nodes[root].depth) {
      root = i;
    }
  }

  // Calculate the minimum number of operations required
  int operations = calculate_operations(root);

  // Print the result
  printf("%d\n", operations);

  return 0;
}