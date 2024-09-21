#include <stdio.h>
#include <limits.h>

#define MAX_N 16

int main() {
  int N;
  int a[MAX_N][MAX_N];
  int dp[1 << MAX_N]; // dp[S] stores the maximum score for grouping rabbits with indices in set S
  
  // Read input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  // Initialize dp
  for (int i = 0; i < (1 << N); i++) {
    dp[i] = INT_MIN;
  }
  dp[0] = 0;

  // Iterate over all possible subsets of rabbits
  for (int S = 1; S < (1 << N); S++) {
    // Find a rabbit j that is not included in the current subset
    for (int j = 0; j < N; j++) {
      if ((S & (1 << j)) == 0) {
        // Calculate the score if we add rabbit j to the current subset
        int score = dp[S ^ (1 << j)];
        for (int k = 0; k < N; k++) {
          if ((S & (1 << k)) != 0) {
            score += a[j][k];
          }
        }

        // Update dp[S] with the maximum score
        dp[S] = (dp[S] > score) ? dp[S] : score;
      }
    }
  }

  // Output the maximum score
  printf("%d\n", dp[(1 << N) - 1]);

  return 0;
}