#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 2000
#define MAX_EDGES 2000
#define MAX_DATA_SIZE 10000
#define MAX_DISTANCE 10000

// Structure for representing a node in the network
typedef struct Node {
  int data_size;
  int cached; // 1 if data is cached, 0 otherwise
  int parent; // Index of the parent node in the tree
  int distance_from_root;
} Node;

// Structure for representing an edge in the network
typedef struct Edge {
  int node1;
  int node2;
  int distance;
} Edge;

// Function to find the maximum delivery cost
int find_max_delivery_cost(Node *nodes, Edge *edges, int n, int m) {
  // Initialize the maximum cost to 0
  int max_cost = 0;

  // Iterate over all nodes
  for (int i = 0; i < n; i++) {
    // Find the farthest node from the current node
    int farthest_node = i;
    int max_distance = 0;
    for (int j = 0; j < n; j++) {
      if (nodes[j].cached == 0) {
        int distance = abs(nodes[i].distance_from_root - nodes[j].distance_from_root);
        if (distance > max_distance) {
          farthest_node = j;
          max_distance = distance;
        }
      }
    }

    // Calculate the delivery cost from the current node to the farthest node
    int delivery_cost = nodes[farthest_node].data_size * max_distance;

    // Update the maximum cost
    if (delivery_cost > max_cost) {
      max_cost = delivery_cost;
    }

    // Cache the data at the current node
    nodes[i].cached = 1;
  }

  return max_cost;
}

// Function to construct the tree from the given edges
void build_tree(Node *nodes, Edge *edges, int n) {
  // Initialize the root node
  nodes[0].parent = -1;
  nodes[0].distance_from_root = 0;

  // Traverse the edges and build the tree
  for (int i = 0; i < n - 1; i++) {
    int node1 = edges[i].node1 - 1;
    int node2 = edges[i].node2 - 1;

    // If either node is the root node, set the parent and distance of the other node
    if (nodes[node1].parent == -1) {
      nodes[node2].parent = node1;
      nodes[node2].distance_from_root = nodes[node1].distance_from_root + edges[i].distance;
    } else if (nodes[node2].parent == -1) {
      nodes[node1].parent = node2;
      nodes[node1].distance_from_root = nodes[node2].distance_from_root + edges[i].distance;
    }
  }
}

int main() {
  int n, m; // Number of nodes and deliveries
  Node nodes[MAX_NODES]; // Array of nodes
  Edge edges[MAX_EDGES]; // Array of edges

  // Read the input
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].distance);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &nodes[i].data_size);
    nodes[i].cached = 0;
  }

  // Build the tree from the edges
  build_tree(nodes, edges, n);

  // Find the maximum delivery cost
  int max_cost = find_max_delivery_cost(nodes, edges, n, m);

  // Print the output
  printf("%d\n", max_cost);

  return 0;
}