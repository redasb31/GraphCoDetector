#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
  int N, M;
  char S[MAX_N + 1];
  scanf("%d %d\n", &N, &M);
  scanf("%s", S);

  // Initialize an array to store the shortest path lengths
  int dp[MAX_N + 1];
  memset(dp, -1, sizeof(dp));

  // Initialize the starting square with a path length of 0
  dp[0] = 0;

  // Dynamic programming to calculate the shortest path lengths
  for (int i = 0; i <= N; i++) {
    if (dp[i] != -1 && S[i] == '0') {
      for (int j = 1; j <= M; j++) {
        if (i + j <= N && (dp[i + j] == -1 || dp[i + j] > dp[i] + 1)) {
          // Update the shortest path length if a shorter path is found
          dp[i + j] = dp[i] + 1;
        }
      }
    }
  }

  // If the destination square cannot be reached, print -1
  if (dp[N] == -1) {
    printf("-1\n");
    return 0;
  }

  // Backtrack from the destination square to find the shortest path
  int current = N;
  int *path = malloc(sizeof(int) * (dp[N] + 1));
  int path_index = dp[N];

  // Store the path in reverse order
  while (current > 0) {
    for (int j = 1; j <= M; j++) {
      if (current - j >= 0 && dp[current - j] == dp[current] - 1) {
        path[path_index--] = j;
        current -= j;
        break;
      }
    }
  }

  // Print the shortest path in the correct order
  for (int i = path_index + 1; i < dp[N] + 1; i++) {
    printf("%d ", path[i]);
  }

  // Free allocated memory
  free(path);

  printf("\n");

  return 0;
}