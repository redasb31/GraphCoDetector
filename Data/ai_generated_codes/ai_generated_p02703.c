#include <stdio.h>
#include <limits.h>

#define INF (1LL << 60)

// Function to find the minimum time required to travel from City 1 to City t
long long min_time(int N, int M, long long S, int U[], int V[], int A[], int B[], long long C[], long long D[], int t) {
  // Create a 2D array to store the shortest path distances from City 1 to all other cities
  long long dp[N + 1][2];
  for (int i = 1; i <= N; i++) {
    dp[i][0] = INF; // Initialize all distances to infinity
    dp[i][1] = INF; // Initialize all distances to infinity
  }
  dp[1][0] = 0; // The distance from City 1 to itself is 0
  dp[1][1] = S; // The initial silver coins available

  // Iterate over all railroads
  for (int i = 0; i < M; i++) {
    // If the current railroad connects City 1 and City t
    if (U[i] == 1 && V[i] == t) {
      // Update the shortest path distance from City 1 to City t if the current distance is shorter
      dp[t][0] = B[i];
      dp[t][1] = S - A[i];
    }
  }

  // Iterate over all cities
  for (int i = 2; i <= N; i++) {
    // Iterate over all railroads
    for (int j = 0; j < M; j++) {
      // If the current railroad connects City 1 and City i
      if (U[j] == 1 && V[j] == i) {
        // Update the shortest path distance from City 1 to City i if the current distance is shorter
        dp[i][0] = B[j];
        dp[i][1] = S - A[j];
      } else if (U[j] == i && V[j] == 1) {
        // Update the shortest path distance from City 1 to City i if the current distance is shorter
        dp[i][0] = B[j];
        dp[i][1] = S - A[j];
      }
    }

    // Iterate over all cities
    for (int k = 1; k <= N; k++) {
      // If the current railroad connects City i and City k
      for (int j = 0; j < M; j++) {
        if ((U[j] == i && V[j] == k) || (U[j] == k && V[j] == i)) {
          // Update the shortest path distance from City 1 to City k if the current distance is shorter
          dp[k][0] = (dp[k][0] > dp[i][0] + B[j]) ? dp[i][0] + B[j] : dp[k][0];
          dp[k][1] = (dp[k][1] > dp[i][1] - A[j]) ? dp[i][1] - A[j] : dp[k][1];
        }
      }

      // If the current city is not City 1 and the shortest path distance from City 1 to the current city is not infinity
      if (i != 1 && dp[i][0] != INF) {
        // Update the shortest path distance from City 1 to the current city if the current distance is shorter
        dp[i][0] = (dp[i][0] > dp[i][0] + D[i] * (C[i] - dp[i][1]) + B[i]) ? dp[i][0] + D[i] * (C[i] - dp[i][1]) + B[i] : dp[i][0];
        dp[i][1] = (dp[i][1] > dp[i][1] + C[i] - dp[i][1]) ? dp[i][1] + C[i] - dp[i][1] : dp[i][1];
      }
    }
  }
  // Return the shortest path distance from City 1 to City t
  return dp[t][0];
}

int main() {
  int N, M;
  long long S;
  scanf("%d %d %lld", &N, &M, &S);

  int U[M], V[M], A[M], B[M];
  long long C[N + 1], D[N + 1];

  // Read input
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d %d", &U[i], &V[i], &A[i], &B[i]);
  }
  for (int i = 1; i <= N; i++) {
    scanf("%lld %lld", &C[i], &D[i]);
  }

  // Print the minimum time required to travel from City 1 to each city
  for (int t = 2; t <= N; t++) {
    printf("%lld\n", min_time(N, M, S, U, V, A, B, C, D, t));
  }

  return 0;
}