#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 200000
#define INF 1000000000

int N;
int a[MAX_N];
int u[MAX_N], v[MAX_N];
int dp[MAX_N];
int parent[MAX_N];

int dfs(int cur, int par) {
  parent[cur] = par;
  for (int i = 0; i < N; i++) {
    if (u[i] == cur && v[i] != par) {
      dfs(v[i], cur);
    } else if (v[i] == cur && u[i] != par) {
      dfs(u[i], cur);
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &u[i], &v[i]);
  }

  // Build the tree using DFS
  dfs(0, -1);

  // Calculate the length of the longest increasing subsequence
  for (int k = 1; k < N; k++) {
    int cur = k;
    dp[cur] = 1;
    int max = 1;
    while (parent[cur] != -1) {
      if (a[parent[cur]] < a[cur]) {
        dp[cur] = dp[parent[cur]] + 1;
        max = dp[cur];
      }
      cur = parent[cur];
    }
    printf("%d\n", max);
  }

  return 0;
}