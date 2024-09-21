#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000
#define MAX_Q 200000

int N, Q;
int a[MAX_N], b[MAX_N];
int p[MAX_Q], x[MAX_Q];
int counter[MAX_N];
int parent[MAX_N];

// Function to find the parent of a given node
int find_parent(int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = find_parent(parent[node]);
}

// Function to perform the operations
void perform_operations() {
  for (int i = 0; i < Q; i++) {
    // Find the root of the subtree
    int root = find_parent(p[i]);
    // Increment the counters of all nodes in the subtree
    counter[root] += x[i];
  }
}

// Function to print the counter values
void print_counters() {
  for (int i = 1; i <= N; i++) {
    printf("%d ", counter[i]);
  }
  printf("\n");
}

int main() {
  // Read the input
  scanf("%d %d", &N, &Q);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &p[i], &x[i]);
  }

  // Initialize the parent array
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  // Build the tree using DSU
  for (int i = 0; i < N - 1; i++) {
    int parent_a = find_parent(a[i]);
    int parent_b = find_parent(b[i]);
    if (parent_a != parent_b) {
      parent[parent_b] = parent_a;
    }
  }

  // Perform the operations
  perform_operations();

  // Print the counter values
  print_counters();

  return 0;
}