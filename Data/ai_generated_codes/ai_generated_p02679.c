#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct {
  long long a, b;
} sardine;

// Function to calculate the number of ways to choose sardines
long long count_ways(sardine *sardines, int n) {
  // Create an adjacency matrix to represent bad terms relationship
  int **adj_matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    adj_matrix[i] = (int *)malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      adj_matrix[i][j] = 0;
    }
  }

  // Populate the adjacency matrix
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (sardines[i].a * sardines[j].a + sardines[i].b * sardines[j].b == 0) {
        adj_matrix[i][j] = 1;
        adj_matrix[j][i] = 1; // Undirected graph
      }
    }
  }

  // Use dynamic programming to count the number of ways
  long long dp[n + 1];
  dp[0] = 1; // Empty set is always valid
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++) {
      if (adj_matrix[j][i - 1] == 0) { // If sardines are not on bad terms
        dp[i] = (dp[i] + dp[j]) % MOD;
      }
    }
    dp[i] = (dp[i] + 1) % MOD; // Including the current sardine
  }

  // Free allocated memory
  for (int i = 0; i < n; i++) {
    free(adj_matrix[i]);
  }
  free(adj_matrix);

  return dp[n];
}

int main() {
  int n;
  scanf("%d", &n);

  sardine *sardines = (sardine *)malloc(n * sizeof(sardine));

  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &sardines[i].a, &sardines[i].b);
  }

  long long ways = count_ways(sardines, n);

  printf("%lld\n", ways);

  free(sardines);

  return 0;
}