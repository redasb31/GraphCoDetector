#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Structure to represent a node in the tree
typedef struct Node {
  int data;
  struct Node* parent;
  struct Node* children[MAX_N]; // Array to store children
  int num_children;
} Node;

// Function to create a new node
Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->parent = NULL;
  node->num_children = 0;
  for (int i = 0; i < MAX_N; i++) {
    node->children[i] = NULL;
  }
  return node;
}

// Function to insert a child node
void insertChild(Node* parent, Node* child) {
  parent->children[parent->num_children] = child;
  child->parent = parent;
  parent->num_children++;
}

// Function to calculate the depth of a node
int calculateDepth(Node* node) {
  if (node->parent == NULL) {
    return 0;
  }
  return calculateDepth(node->parent) + 1;
}

// Function to calculate the number of nodes at each depth
void calculateNodeCounts(Node* root, int* nodeCounts) {
  // Depth-first search traversal of the tree
  for (int i = 0; i < root->num_children; i++) {
    if (root->children[i] != NULL) {
      calculateNodeCounts(root->children[i], nodeCounts);
    }
  }
  nodeCounts[calculateDepth(root)]++; // Increment count for current depth
}

// Function to check if two subtrees are similar
int isSimilar(Node* subtree1, Node* subtree2) {
  // Calculate node counts for each subtree
  int subtree1Counts[MAX_N] = {0};
  int subtree2Counts[MAX_N] = {0};
  calculateNodeCounts(subtree1, subtree1Counts);
  calculateNodeCounts(subtree2, subtree2Counts);

  // Compare node counts at each depth
  for (int i = 0; i < MAX_N; i++) {
    if (subtree1Counts[i] != subtree2Counts[i]) {
      return 0; // Subtrees are not similar
    }
  }
  return 1; // Subtrees are similar
}

// Function to count the number of similar subtrees
int countSimilarSubtrees(Node* root) {
  int count = 0;
  for (int i = 1; i <= root->data; i++) { // Iterate over all nodes
    for (int j = i + 1; j <= root->data; j++) {
      if (isSimilar(root->children[i - 1], root->children[j - 1])) {
        count++; // Increment count if subtrees are similar
      }
    }
  }
  return count;
}

int main() {
  int N;
  scanf("%d", &N);

  // Create the root node
  Node* root = newNode(1);

  // Read input and construct the tree
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &a, &b);
    Node* parent = root->children[a - 1] != NULL ? root->children[a - 1] : newNode(a);
    Node* child = newNode(b);
    insertChild(parent, child);
    root->children[a - 1] = parent; // Update parent node
  }

  // Calculate and print the number of similar subtrees
  int count = countSimilarSubtrees(root);
  printf("%d\n", count);

  // Free allocated memory (optional)
  // ...

  return 0;
}