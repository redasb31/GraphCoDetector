#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000

typedef struct {
  int a, b;
} Vertex;

typedef struct {
  int u, v;
} Edge;

int N, M;
Vertex vertices[MAX_N + 1];
Edge edges[MAX_M + 1];
int graph[MAX_N + 1][MAX_N + 1];

// Function to find the minimum initial amount of money
int find_min_money(int start_vertex) {
  // Initialize the amount of money required for each vertex to 0
  int money[MAX_N + 1] = {0};
  // Initialize the visited array to 0
  int visited[MAX_N + 1] = {0};
  // Initialize the amount of money in pocket to the initial amount
  int current_money = vertices[start_vertex].a;
  // Initialize the queue for BFS
  int queue[MAX_N + 1];
  int front = 0, rear = 0;

  // Push the starting vertex to the queue
  queue[rear++] = start_vertex;
  // Mark the starting vertex as visited
  visited[start_vertex] = 1;

  // Perform BFS
  while (front < rear) {
    int current_vertex = queue[front++];
    // Donate to the current vertex
    current_money -= vertices[current_vertex].b;
    // Check if the amount of money is negative, then return -1
    if (current_money < 0) {
      return -1;
    }
    // Check if the donation is successful, then mark the vertex as visited
    if (!visited[current_vertex]) {
      visited[current_vertex] = 1;
    }

    // Iterate over the adjacent vertices
    for (int i = 1; i <= N; i++) {
      // Check if the vertex is connected to the current vertex and is not visited
      if (graph[current_vertex][i] && !visited[i]) {
        // Check if the amount of money is sufficient to move to the vertex
        if (current_money >= vertices[i].a) {
          // Update the amount of money required to visit the vertex
          money[i] = current_money;
          // Push the vertex to the queue
          queue[rear++] = i;
        } else {
          // Update the amount of money required to visit the vertex
          money[i] = vertices[i].a;
        }
      }
    }
  }
  // Check if all vertices are visited
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      return -1;
    }
  }
  // Find the maximum amount of money required
  int max_money = 0;
  for (int i = 1; i <= N; i++) {
    max_money = (money[i] > max_money) ? money[i] : max_money;
  }
  // Return the maximum amount of money required
  return max_money;
}

int main() {
  // Read input
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &vertices[i].a, &vertices[i].b);
  }
  for (int i = 1; i <= M; i++) {
    scanf("%d %d", &edges[i].u, &edges[i].v);
    // Update the graph adjacency matrix
    graph[edges[i].u][edges[i].v] = graph[edges[i].v][edges[i].u] = 1;
  }

  // Find the minimum amount of money required to win the game
  int min_money = 1e9;
  for (int i = 1; i <= N; i++) {
    int money = find_min_money(i);
    if (money != -1 && money < min_money) {
      min_money = money;
    }
  }

  // Print the output
  if (min_money == 1e9) {
    printf("-1\n");
  } else {
    printf("%d\n", min_money);
  }

  return 0;
}