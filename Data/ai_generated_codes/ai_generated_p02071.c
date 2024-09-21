#include <stdio.h>
#include <stdlib.h>

// Structure to represent a trading rule
typedef struct {
  int A;  // Item A
  int B;  // Item B
  int x;  // Exchange ratio
} Rule;

// Function to check if a given rule set contains a bug
int check_bug(Rule *rules, int M, int N) {
  // Create a 2D array to represent the graph of trading rules
  int graph[N + 1][N + 1];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      graph[i][j] = 0;
    }
  }

  // Populate the graph with trading rules
  for (int i = 0; i < M; i++) {
    graph[rules[i].A][rules[i].B] = rules[i].x;
    graph[rules[i].B][rules[i].A] = 1; // Reciprocal rule
  }

  // Perform depth-first search (DFS) to check for cycles
  int visited[N + 1] = {0};
  int stack[N + 1] = {0};
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      if (dfs(graph, visited, stack, i, N)) {
        return 1; // Bug found
      }
    }
  }

  return 0; // No bug found
}

// Depth-first search (DFS) function to detect cycles
int dfs(int graph[][N + 1], int visited[], int stack[], int node, int N) {
  visited[node] = 1;
  stack[node] = 1;

  for (int i = 1; i <= N; i++) {
    if (graph[node][i] != 0) {
      if (!visited[i] && dfs(graph, visited, stack, i, N)) {
        return 1; // Cycle found
      } else if (stack[i]) {
        return 1; // Cycle found
      }
    }
  }

  stack[node] = 0;
  return 0;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  Rule *rules = (Rule *)malloc(M * sizeof(Rule));
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &rules[i].A, &rules[i].B, &rules[i].x);
  }

  if (check_bug(rules, M, N)) {
    printf("No\n");
  } else {
    printf("Yes\n");
  }

  free(rules);
  return 0;
}