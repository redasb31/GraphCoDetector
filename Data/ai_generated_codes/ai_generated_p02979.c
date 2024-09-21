#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of possible sets
long long count_sets(int N, int K, long long M) {
  // Initialize the dp table
  long long dp[N + 1][K + 1];
  memset(dp, 0, sizeof(dp));

  // Base case: For each value of K, the number of possible sets with no numbers is 1
  for (int i = 0; i <= K; i++) {
    dp[0][i] = 1;
  }

  // Iterate over each number from 1 to N
  for (int i = 1; i <= N; i++) {
    // Iterate over each possible value of K
    for (int j = 0; j <= K; j++) {
      // Calculate the number of sets for this number and value of K
      dp[i][j] = (dp[i - 1][j] + (j == 0 ? 0 : dp[i - 1][j - 1]) + (j == K ? 0 : dp[i - 1][j + 1])) % M;
    }
  }

  // Return the number of possible sets for the given N and K
  return dp[N][K];
}

int main() {
  int N, K;
  long long M;

  // Read the input
  scanf("%d %d %lld", &N, &K, &M);

  // Calculate and print the number of possible sets
  printf("%lld\n", count_sets(N, K, M));

  return 0;
}