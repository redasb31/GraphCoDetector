#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_M 200000

typedef struct {
  int L;
  int R;
  int D;
} Info;

int main() {
  // Input
  int N, M;
  scanf("%d %d", &N, &M);

  Info info[MAX_M];
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &info[i].L, &info[i].R, &info[i].D);
  }

  // Create a graph to represent the relationships between people
  int graph[MAX_N + 1][MAX_N + 1] = {0};
  for (int i = 0; i < M; i++) {
    graph[info[i].L][info[i].R] = info[i].D;
  }

  // Use Bellman-Ford algorithm to detect negative cycles
  int dist[MAX_N + 1];
  for (int i = 1; i <= N; i++) {
    dist[i] = 0;
  }

  // Relax edges for N-1 times
  for (int k = 1; k <= N - 1; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (graph[i][j] != 0 && dist[j] > dist[i] + graph[i][j]) {
          dist[j] = dist[i] + graph[i][j];
        }
      }
    }
  }

  // Check for negative cycles
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (graph[i][j] != 0 && dist[j] > dist[i] + graph[i][j]) {
        printf("No\n");
        return 0;
      }
    }
  }

  // If no negative cycles are found, a consistent set of values exists
  printf("Yes\n");

  return 0;
}