#include <stdio.h>
#include <stdlib.h>

#define MAX_N 60

int main() {
  int N;
  int a[MAX_N];
  int dp[MAX_N][MAX_N]; // dp[i][j]: maximum value obtainable using subsequence from i to j (inclusive)
  int seq[MAX_N]; // stores the optimal sequence
  int k = 0; // length of the optimal sequence

  // Input
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Initialize DP table
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      dp[i][j] = 1; // initial value: x0 = 1
    }
  }

  // Calculate DP values
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (i == j) {
        dp[i][j] = a[i]; // base case: single element
      } else {
        dp[i][j] = dp[i][j - 1] * a[j]; // maximize by multiplying with the current element
      }
    }
  }

  // Find the optimal sequence
  int max_value = 1; // initial value: no elements in the sequence
  int max_index = -1; // index of the last element in the optimal sequence
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      if (dp[i][j] > max_value) {
        max_value = dp[i][j];
        max_index = j;
        k = j - i + 1; // length of the optimal sequence
      }
    }
  }

  // Reconstruct the optimal sequence
  int index = max_index;
  for (int i = k - 1; i >= 0; i--) {
    seq[i] = index + 1; // store the index (1-based)
    index--;
  }

  // Output
  printf("%d\n", k);
  for (int i = 0; i < k; i++) {
    printf("%d\n", seq[i]);
  }

  return 0;
}