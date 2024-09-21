#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_Q 200000

// Structure to represent a node in the tree
struct Node {
  int id;
  int num_children;
  int *children;
  int weight; // Stores the sum of weights on the path from the root to this node
};

// Function to create a new node
struct Node *newNode(int id, int num_children, int *children) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->id = id;
  node->num_children = num_children;
  node->children = children;
  node->weight = 0; // Initialize weight to 0
  return node;
}

// Function to add weight to all edges from the root to node v
void add(struct Node *tree, int v, int w) {
  while (v != 0) {
    tree[v].weight += w;
    v = tree[v].children[0]; // Move to the parent node
  }
}

// Function to get the sum of weights of all edges from the root to node u
int getSum(struct Node *tree, int u) {
  return tree[u].weight;
}

int main() {
  int n, q;

  // Read the number of nodes and queries
  scanf("%d", &n);
  scanf("%d", &q);

  // Create an array of nodes to represent the tree
  struct Node tree[MAX_N];

  // Read the tree information
  for (int i = 0; i < n; i++) {
    int num_children;
    scanf("%d", &num_children);
    int *children = (int *)malloc(sizeof(int) * num_children);
    for (int j = 0; j < num_children; j++) {
      scanf("%d", &children[j]);
    }
    tree[i] = *newNode(i, num_children, children);
  }

  // Process queries
  for (int i = 0; i < q; i++) {
    int query_type, u, w;
    scanf("%d", &query_type);

    // Add query
    if (query_type == 0) {
      scanf("%d %d", &u, &w);
      add(tree, u, w);
    } 
    // GetSum query
    else {
      scanf("%d", &u);
      printf("%d\n", getSum(tree, u));
    }
  }

  // Free memory
  for (int i = 0; i < n; i++) {
    free(tree[i].children);
  }

  return 0;
}