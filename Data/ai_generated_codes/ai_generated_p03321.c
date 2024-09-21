#include <stdio.h>
#include <stdlib.h>

#define MAX_N 700
#define INF 1000000000

// Adjacency list representation of the graph
int graph[MAX_N + 1][MAX_N + 1];

// Function to perform Depth First Search (DFS)
void dfs(int node, int color, int* colors) {
  colors[node] = color;
  for (int i = 1; i <= MAX_N; i++) {
    if (graph[node][i] && colors[i] == 0) {
      dfs(i, color, colors);
    }
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  // Initialize the adjacency list
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      graph[i][j] = 0;
    }
  }

  // Read the edges and populate the adjacency list
  for (int i = 0; i < M; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    graph[A][B] = 1;
    graph[B][A] = 1;
  }

  // Initialize the colors array
  int colors[MAX_N + 1];
  for (int i = 1; i <= N; i++) {
    colors[i] = 0;
  }

  // Perform DFS to color the graph
  int color = 1;
  for (int i = 1; i <= N; i++) {
    if (colors[i] == 0) {
      dfs(i, color, colors);
      color++;
    }
  }

  // Check if the graph can be divided into two states
  int valid = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (graph[i][j] && colors[i] == colors[j]) {
        // If two connected nodes have the same color, it's invalid
        valid = 0;
        break;
      }
    }
    if (!valid) {
      break;
    }
  }

  if (!valid) {
    // If the graph cannot be divided, print -1
    printf("-1\n");
    return 0;
  }

  // Count the roads within the same state
  int count = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (graph[i][j] && colors[i] == colors[j]) {
        count++;
      }
    }
  }

  // Print the minimum number of roads within the same state
  printf("%d\n", count);
  return 0;
}