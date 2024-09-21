#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum sum of the last two cards
int minSum(int N, int A[]) {
  // Create a 2D array to store the minimum sum for each pair of cards
  int dp[N][N];

  // Initialize the dp array with INT_MAX
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = INT_MAX;
    }
  }

  // Base case: when there are only two cards left
  for (int i = 0; i < N - 1; i++) {
    dp[i][i + 1] = A[i] + A[i + 1];
  }

  // Iterate through the array to calculate the minimum sum for each pair
  for (int len = 3; len <= N; len++) {
    for (int i = 0; i <= N - len; i++) {
      int j = i + len - 1;
      // Calculate the minimum sum by considering all possible middle cards
      for (int k = i + 1; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + A[k]);
      }
    }
  }

  // Return the minimum sum of the last two cards
  return dp[0][N - 1];
}

// Main function
int main() {
  // Input the number of cards
  int N;
  scanf("%d", &N);

  // Input the integers written on the cards
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate and output the minimum sum
  printf("%d\n", minSum(N, A));

  return 0;
}