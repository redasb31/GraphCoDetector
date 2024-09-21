#include <stdio.h>
#include <stdlib.h>

int main() {
  // Input
  int N, K;
  scanf("%d %d", &N, &K);

  int *A = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // DP table: dp[i] stores the maximum length of a subsequence ending at A[i]
  int *dp = (int *)malloc(sizeof(int) * N);
  dp[0] = 1;

  // Initialize the first element of the DP table
  int max_length = 1;

  // Calculate the maximum length of a subsequence ending at each element
  for (int i = 1; i < N; i++) {
    // Initialize the maximum length of a subsequence ending at A[i] to 1
    dp[i] = 1;

    // Iterate over all previous elements
    for (int j = 0; j < i; j++) {
      // If the absolute difference between A[i] and A[j] is at most K,
      // and the length of the subsequence ending at A[j] plus 1 is greater than the current maximum length ending at A[i]
      if (abs(A[i] - A[j]) <= K && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }

    // Update the overall maximum length
    if (dp[i] > max_length) {
      max_length = dp[i];
    }
  }

  // Print the maximum length
  printf("%d\n", max_length);

  // Free allocated memory
  free(A);
  free(dp);

  return 0;
}