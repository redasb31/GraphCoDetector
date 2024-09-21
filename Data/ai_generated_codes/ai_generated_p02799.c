#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000
#define MAX_M 200000

// Structure to represent a graph edge
struct Edge {
  int u, v;
  int weight;
};

// Structure to represent a graph node
struct Node {
  int id;
  int color; // 0: white, 1: black
  int minDistance;
  int visited;
};

// Function to initialize the graph
void initGraph(struct Node* nodes, int n, struct Edge* edges, int m) {
  for (int i = 0; i < n; i++) {
    nodes[i].id = i + 1;
    nodes[i].color = -1; // Unassigned initially
    nodes[i].minDistance = INT_MAX;
    nodes[i].visited = 0;
  }

  for (int i = 0; i < m; i++) {
    edges[i].weight = -1; // Unassigned initially
  }
}

// Function to perform Depth First Search (DFS) to find the minimum distance to a vertex of a different color
void dfs(struct Node* nodes, int n, struct Edge* edges, int m, int current, int color, int distance) {
  // Mark the current node as visited
  nodes[current].visited = 1;

  // Update the minimum distance if it's less than the current minimum distance
  if (distance < nodes[current].minDistance) {
    nodes[current].minDistance = distance;
  }

  // Explore adjacent nodes
  for (int i = 0; i < m; i++) {
    if (edges[i].weight != -1) {
      if (edges[i].u == current + 1 && nodes[edges[i].v - 1].visited == 0) {
        // Explore the edge if the other end is not visited and has a different color
        if (nodes[edges[i].v - 1].color != color) {
          dfs(nodes, n, edges, m, edges[i].v - 1, color, distance + edges[i].weight);
        }
      } else if (edges[i].v == current + 1 && nodes[edges[i].u - 1].visited == 0) {
        if (nodes[edges[i].u - 1].color != color) {
          dfs(nodes, n, edges, m, edges[i].u - 1, color, distance + edges[i].weight);
        }
      }
    }
  }
}

// Function to assign colors and edge weights
int assignColorsAndWeights(struct Node* nodes, int n, struct Edge* edges, int m, int* d) {
  // Initialize graph
  initGraph(nodes, n, edges, m);

  // Find a node with the minimum distance, and use it as the starting node
  int minDistance = INT_MAX;
  int startNode = -1;
  for (int i = 0; i < n; i++) {
    if (d[i] < minDistance) {
      minDistance = d[i];
      startNode = i;
    }
  }

  // Assign color to the starting node
  nodes[startNode].color = 0;

  // Perform DFS to find the minimum distance to a vertex of a different color
  dfs(nodes, n, edges, m, startNode, 0, 0);

  // Assign colors and weights to the remaining nodes and edges
  for (int i = 0; i < n; i++) {
    // If a node is not assigned a color, assign it the opposite color of its neighbor
    if (nodes[i].color == -1) {
      for (int j = 0; j < m; j++) {
        if (edges[j].weight != -1) {
          if (edges[j].u == i + 1) {
            // Assign the opposite color to the neighbor
            nodes[i].color = 1 - nodes[edges[j].v - 1].color;
            // Assign weight to the edge
            edges[j].weight = nodes[i].minDistance;
          } else if (edges[j].v == i + 1) {
            nodes[i].color = 1 - nodes[edges[j].u - 1].color;
            edges[j].weight = nodes[i].minDistance;
          }
        }
      }
    }

    // Check if the minimum distance matches the given distance
    if (nodes[i].minDistance != d[i]) {
      // If it doesn't match, the conditions cannot be satisfied
      return -1;
    }
  }

  // Check if at least one node is assigned black and one is assigned white
  int whiteCount = 0;
  int blackCount = 0;
  for (int i = 0; i < n; i++) {
    if (nodes[i].color == 0) {
      whiteCount++;
    } else if (nodes[i].color == 1) {
      blackCount++;
    }
  }

  if (whiteCount == 0 || blackCount == 0) {
    return -1;
  }

  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int d[MAX_N];
  for (int i = 0; i < n; i++) {
    scanf("%d", &d[i]);
  }

  struct Edge edges[MAX_M];
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &edges[i].u, &edges[i].v);
  }

  struct Node nodes[MAX_N];

  // Assign colors and weights
  if (assignColorsAndWeights(nodes, n, edges, m, d) == -1) {
    printf("-1\n");
  } else {
    // Print the solution
    char colorString[MAX_N + 1];
    for (int i = 0; i < n; i++) {
      if (nodes[i].color == 0) {
        colorString[i] = 'W';
      } else {
        colorString[i] = 'B';
      }
    }
    colorString[n] = '\0';
    printf("%s\n", colorString);

    for (int i = 0; i < m; i++) {
      printf("%d\n", edges[i].weight);
    }
  }

  return 0;
}