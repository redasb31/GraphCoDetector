#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
typedef struct Node {
  int value;
  int weight;
  struct Node *left;
  struct Node *right;
} Node;

// Function to create a new node
Node* newNode(int value, int weight) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->weight = weight;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to build the binary tree
Node* buildTree(int n, int V[], int W[]) {
  // Create the root node
  Node* root = newNode(V[0], W[0]);

  // Create the remaining nodes
  for (int i = 1; i < n; i++) {
    // Determine the parent node
    int parentIndex = i / 2;
    Node* parent = NULL;
    if (parentIndex == 0) {
      parent = root;
    } else {
      parent = buildTree(n, V, W);
    }

    // Create the new node and attach it to the parent
    Node* node = newNode(V[i], W[i]);
    if (i % 2 == 0) {
      parent->right = node;
    } else {
      parent->left = node;
    }
  }

  return root;
}

// Function to perform a query
int query(Node* root, int v, int L) {
  // Initialize the maximum value
  int maxValue = 0;

  // Traverse the path from the target vertex to the root
  while (v > 0) {
    // Add the value of the current vertex if its weight is within the limit
    if (L >= root->weight) {
      maxValue += root->value;
      L -= root->weight;
    }

    // Move to the parent vertex
    v /= 2;
    root = (v > 0) ? (v % 2 == 0) ? root->right : root->left : root;
  }

  return maxValue;
}

int main() {
  // Read the number of vertices
  int N;
  scanf("%d", &N);

  // Read the values and weights of the items
  int V[N], W[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &V[i], &W[i]);
  }

  // Build the binary tree
  Node* root = buildTree(N, V, W);

  // Read the number of queries
  int Q;
  scanf("%d", &Q);

  // Process the queries
  for (int i = 0; i < Q; i++) {
    // Read the query parameters
    int v, L;
    scanf("%d %d", &v, &L);

    // Perform the query and print the result
    printf("%d\n", query(root, v, L));
  }

  return 0;
}