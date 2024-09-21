#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define MAXM 100000

// Structure for a node in the tree
typedef struct Node {
  int id;
  int color;
  int parent;
  int size;
  int subtree_count[MAXN + 1]; // Count of vertices of each color in the subtree rooted at this node
  struct Node* children[MAXN + 1];
} Node;

// Function to create a new node
Node* createNode(int id, int color) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->id = id;
  newNode->color = color;
  newNode->parent = -1;
  newNode->size = 1;
  for (int i = 0; i <= MAXN; i++) {
    newNode->subtree_count[i] = 0;
  }
  for (int i = 0; i <= MAXN; i++) {
    newNode->children[i] = NULL;
  }
  return newNode;
}

// Function to add a child to a node
void addChild(Node* parent, Node* child) {
  parent->children[child->color] = child;
  child->parent = parent->id;
  parent->size += child->size;
  for (int i = 0; i <= MAXN; i++) {
    parent->subtree_count[i] += child->subtree_count[i];
  }
}

// Function to update the color of a node
void updateColor(Node* node, int newColor) {
  if (node->parent != -1) {
    Node* parent = nodes[node->parent];
    parent->subtree_count[node->color]--;
    parent->subtree_count[newColor]++;
  }
  node->color = newColor;
}

// Function to calculate the number of edges in the minimum connected subgraph
int calculateEdges(Node* node, int color) {
  int total_vertices = 0;
  int edges = 0;

  // Recursive function to traverse the subtree and calculate the number of edges
  if (node->color == color) {
    total_vertices++;
  }
  for (int i = 0; i <= MAXN; i++) {
    if (node->children[i] != NULL) {
      int subtree_edges = calculateEdges(node->children[i], color);
      edges += subtree_edges;
      total_vertices += node->children[i]->size;
    }
  }

  // Return the number of edges
  if (total_vertices > 0) {
    return total_vertices - 1;
  } else {
    return -1;
  }
}

// Global array to store the nodes
Node* nodes[MAXN + 1];

int main() {
  int n, m;
  int a, b, color;

  // Input the number of vertices and edges
  scanf("%d", &n);

  // Create nodes for the tree
  for (int i = 1; i <= n; i++) {
    nodes[i] = createNode(i, 0);
  }

  // Input the edges
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    addChild(nodes[a], nodes[b]);
  }

  // Input the initial colors of the vertices
  for (int i = 1; i <= n; i++) {
    scanf("%d", &color);
    nodes[i]->color = color;
    nodes[i]->subtree_count[color]++;
  }

  // Input the number of commands
  scanf("%d", &m);

  // Process the commands
  char command[2];
  int x, y;
  for (int i = 0; i < m; i++) {
    scanf("%s", command);
    if (command[0] == 'U') {
      scanf("%d %d", &x, &y);
      updateColor(nodes[x], y);
    } else if (command[0] == 'Q') {
      scanf("%d", &y);
      printf("%d\n", calculateEdges(nodes[1], y));
    }
  }

  // Free the allocated memory
  for (int i = 1; i <= n; i++) {
    free(nodes[i]);
  }

  return 0;
}