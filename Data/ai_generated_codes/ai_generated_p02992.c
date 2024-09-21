#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of sequences modulo MOD
long long countSequences(int N, int K) {
  // Create a DP table to store the number of sequences ending at each number
  long long dp[N + 1];
  // Initialize base case: for length 1, all numbers are valid
  for (int i = 1; i <= N; i++) {
    dp[i] = 1;
  }

  // Iterate through lengths from 2 to K
  for (int len = 2; len <= K; len++) {
    // Create a temporary array to store intermediate results
    long long temp[N + 1];
    // Initialize the temporary array
    for (int i = 1; i <= N; i++) {
      temp[i] = 0;
    }

    // Iterate through possible ending numbers
    for (int i = 1; i <= N; i++) {
      // Iterate through possible preceding numbers
      for (int j = 1; j <= N; j++) {
        // Check if the product is at most N
        if (i * j <= N) {
          // Add the count of sequences ending at j to the count of sequences ending at i
          temp[i] = (temp[i] + dp[j]) % MOD;
        }
      }
    }

    // Update the DP table with the results from the temporary array
    for (int i = 1; i <= N; i++) {
      dp[i] = temp[i];
    }
  }

  // Sum up the counts of sequences ending at all numbers to get the total count
  long long total = 0;
  for (int i = 1; i <= N; i++) {
    total = (total + dp[i]) % MOD;
  }

  // Return the total count
  return total;
}

int main() {
  int N, K;

  // Read the input values
  scanf("%d %d", &N, &K);

  // Calculate and print the number of sequences
  printf("%lld\n", countSequences(N, K));

  return 0;
}