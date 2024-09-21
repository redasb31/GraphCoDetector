#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAX_K 50

int N, K;
int A[MAX_N];
int dp[MAX_N][MAX_K];

// Recursive function to calculate the minimum boringness of a tournament
int min_boringness(int start, int end, int height) {
  // Base case: Only one contestant remains
  if (start == end) {
    return 0;
  }

  // If the minimum boringness for this subproblem has already been calculated
  if (dp[start][height] != -1) {
    return dp[start][height];
  }

  int min_boring = INT_MAX;

  // Iterate through all possible splitting points for the current tournament
  for (int i = start; i < end; i++) {
    // Calculate the boringness of the current split
    int boring = abs(A[i] - A[i + 1]);

    // Recursively calculate the minimum boringness of the left and right subtournaments
    int left_boring = min_boringness(start, i, height - 1);
    int right_boring = min_boringness(i + 1, end, height - 1);

    // Update the minimum boringness if the current split is better
    min_boring = min(min_boring, boring + left_boring + right_boring);
  }

  // Store the calculated minimum boringness in the DP table
  dp[start][height] = min_boring;

  return min_boring;
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize the DP table
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      dp[i][j] = -1;
    }
  }

  // Calculate the minimum boringness of the entire tournament
  int min_boringness_value = min_boringness(0, N - 1, K);

  printf("%d\n", min_boringness_value);

  return 0;
}