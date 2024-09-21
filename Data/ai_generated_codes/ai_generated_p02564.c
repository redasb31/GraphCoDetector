#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500000
#define MAX_M 500000

int N, M;
int a[MAX_M], b[MAX_M];

// Adjacency list representation of the graph
int adj[MAX_N][MAX_N];

// Stack for Depth First Search (DFS)
int stack[MAX_N];
int top = -1;

// Visited array for DFS
int visited[MAX_N];

// Array to store the finishing times of nodes in DFS
int finish_time[MAX_N];

// Array to store the component number of each node
int component[MAX_N];

// Function to push an element onto the stack
void push(int x) {
  stack[++top] = x;
}

// Function to pop an element from the stack
int pop() {
  return stack[top--];
}

// Depth First Search (DFS) algorithm
void dfs(int u) {
  visited[u] = 1;
  for (int v = 0; v < N; v++) {
    if (adj[u][v] && !visited[v]) {
      dfs(v);
    }
  }
  push(u);
}

// Depth First Search (DFS) algorithm for finding strongly connected components
void dfs_scc(int u, int component_number) {
  visited[u] = 1;
  component[u] = component_number;
  for (int v = 0; v < N; v++) {
    if (adj[u][v] && !visited[v]) {
      dfs_scc(v, component_number);
    }
  }
}

// Function to find strongly connected components
void find_scc() {
  // Initialize visited array
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
  }

  // Perform DFS on all unvisited nodes
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  // Initialize visited array again
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
  }

  // Count the number of strongly connected components
  int component_number = 0;

  // Perform DFS on nodes in reverse order of finishing times
  while (top != -1) {
    int u = pop();
    if (!visited[u]) {
      component_number++;
      dfs_scc(u, component_number);
    }
  }

  // Print the number of strongly connected components
  printf("%d\n", component_number);

  // Print the strongly connected components in topological order
  for (int i = 1; i <= component_number; i++) {
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (component[j] == i) {
        count++;
      }
    }
    printf("%d ", count);
    for (int j = 0; j < N; j++) {
      if (component[j] == i) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

int main() {
  // Read the input
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &a[i], &b[i]);
    // Add the edge to the adjacency list
    adj[a[i]][b[i]] = 1;
  }

  // Find the strongly connected components
  find_scc();

  return 0;
}