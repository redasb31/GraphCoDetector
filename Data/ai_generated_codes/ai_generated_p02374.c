#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_Q 200000

// Structure to represent a node in the tree
typedef struct Node {
  int id; // Node ID
  int num_children; // Number of children
  int *children; // Array to store the IDs of children
  int edge_weight; // Weight of the edge connecting this node to its parent
} Node;

// Function to initialize a node
Node *initNode(int id, int num_children, int *children) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->id = id;
  node->num_children = num_children;
  node->children = children;
  node->edge_weight = 0;
  return node;
}

// Function to add weight to an edge
void add(Node *tree[], int v, int w) {
  tree[v]->edge_weight += w;
}

// Function to get the sum of weights from root to a node
int getSum(Node *tree[], int u) {
  int sum = 0;
  while (u != 0) {
    sum += tree[u]->edge_weight;
    u = tree[u]->children[0]; // Move to the parent node
  }
  return sum;
}

int main() {
  int n, q; // Number of nodes and queries
  scanf("%d", &n);

  // Initialize the tree
  Node *tree[MAX_N];
  for (int i = 0; i < n; i++) {
    int num_children;
    scanf("%d", &num_children);
    int *children = (int *)malloc(sizeof(int) * num_children);
    for (int j = 0; j < num_children; j++) {
      scanf("%d", &children[j]);
    }
    tree[i] = initNode(i, num_children, children);
  }

  // Read the number of queries
  scanf("%d", &q);

  // Process the queries
  for (int i = 0; i < q; i++) {
    int query_type, v, w;
    scanf("%d", &query_type);

    if (query_type == 0) {
      // Add weight to an edge
      scanf("%d %d", &v, &w);
      add(tree, v, w);
    } else {
      // Get the sum of weights from root to a node
      scanf("%d", &v);
      printf("%d\n", getSum(tree, v));
    }
  }

  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(tree[i]->children);
    free(tree[i]);
  }

  return 0;
}