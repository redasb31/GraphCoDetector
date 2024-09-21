#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

int N;
int P[MAX_N + 1];
int V[MAX_N + 1];
int subtree_size[MAX_N + 1];
int dp[MAX_N + 1][2]; // dp[i][j] -> minimum inversions for subtree rooted at i with j ones in the left side

int dfs(int u) {
  subtree_size[u] = 1;
  dp[u][0] = dp[u][1] = 0;

  // Iterate over children
  for (int v = u + 1; v <= N; v++) {
    if (P[v] == u) {
      dfs(v);
      subtree_size[u] += subtree_size[v];
      // Update dp values based on child node's dp values
      dp[u][0] += dp[v][0] + subtree_size[v] * V[u];
      dp[u][1] += dp[v][1] + subtree_size[v] * (1 - V[u]);
      // Choose the best arrangement for the current subtree
      dp[u][0] = (dp[u][0] < dp[u][1]) ? dp[u][0] : dp[u][1];
    }
  }

  return dp[u][0];
}

int main() {
  scanf("%d", &N);
  for (int i = 2; i <= N; i++) {
    scanf("%d", &P[i]);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%d", &V[i]);
  }

  // Calculate the minimum inversions using DFS
  printf("%d\n", dfs(1));

  return 0;
}