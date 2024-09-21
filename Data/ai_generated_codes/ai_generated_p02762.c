#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 100000
#define MAX_K 100000

// Structure to represent a friendship
typedef struct {
  int a;
  int b;
} Friendship;

// Structure to represent a blockship
typedef struct {
  int c;
  int d;
} Blockship;

// Function to perform Depth First Search (DFS) to find connected components
void dfs(int **graph, int *visited, int current, int *count) {
  visited[current] = 1;
  (*count)++;
  for (int i = 1; i <= MAX_N; i++) {
    if (graph[current][i] && !visited[i]) {
      dfs(graph, visited, i, count);
    }
  }
}

int main() {
  int n, m, k;
  // Read input values
  scanf("%d %d %d", &n, &m, &k);

  // Create arrays to store friendships and blockships
  Friendship *friendships = (Friendship *)malloc(sizeof(Friendship) * MAX_M);
  Blockship *blockships = (Blockship *)malloc(sizeof(Blockship) * MAX_K);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &friendships[i].a, &friendships[i].b);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &blockships[i].c, &blockships[i].d);
  }

  // Create an adjacency matrix to represent friendships
  int **graph = (int **)malloc(sizeof(int *) * (MAX_N + 1));
  for (int i = 0; i <= MAX_N; i++) {
    graph[i] = (int *)calloc(MAX_N + 1, sizeof(int));
  }
  for (int i = 0; i < m; i++) {
    graph[friendships[i].a][friendships[i].b] = 1;
    graph[friendships[i].b][friendships[i].a] = 1;
  }

  // Find friend candidates for each user
  int *friend_candidates = (int *)calloc(n + 1, sizeof(int));
  for (int i = 1; i <= n; i++) {
    // Check for each user j if they are a friend candidate for user i
    for (int j = 1; j <= n; j++) {
      if (i != j && !graph[i][j]) {
        // Check if there is no blockship between user i and j
        int is_blocked = 0;
        for (int k = 0; k < k; k++) {
          if ((blockships[k].c == i && blockships[k].d == j) ||
              (blockships[k].c == j && blockships[k].d == i)) {
            is_blocked = 1;
            break;
          }
        }
        if (!is_blocked) {
          // Perform DFS to check if user j is connected to user i
          int *visited = (int *)calloc(n + 1, sizeof(int));
          int count = 0;
          dfs(graph, visited, i, &count);
          if (visited[j]) {
            friend_candidates[i]++;
          }
          free(visited);
        }
      }
    }
  }

  // Print the number of friend candidates for each user
  for (int i = 1; i <= n; i++) {
    printf("%d ", friend_candidates[i]);
  }
  printf("\n");

  // Free allocated memory
  free(graph);
  free(friendships);
  free(blockships);
  free(friend_candidates);
  return 0;
}