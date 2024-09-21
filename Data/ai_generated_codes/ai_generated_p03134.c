#include <stdio.h>
#include <string.h>

#define MOD 998244353

// Function to calculate the number of possible sequences
long long countSequences(char *s) {
  int n = strlen(s);
  long long dp[n + 1][3][3]; // dp[i][j][k] represents the number of possible sequences up to the i-th Snuke, with j red balls and k blue balls in Takahashi's sequence

  // Initialize the DP array
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1; // Base case: empty sequence

  // Iterate over each Snuke
  for (int i = 0; i < n; i++) {
    // Iterate over the possible number of red balls in Takahashi's sequence
    for (int j = 0; j <= 2; j++) {
      // Iterate over the possible number of blue balls in Takahashi's sequence
      for (int k = 0; k <= 2; k++) {
        // Calculate the number of possible sequences for the current state
        if (s[i] == '0') {
          // Case 1: Snuke has two red balls
          dp[i + 1][(j + 2) % 3][k] = (dp[i + 1][(j + 2) % 3][k] + dp[i][j][k]) % MOD;
          dp[i + 1][(j + 1) % 3][k] = (dp[i + 1][(j + 1) % 3][k] + dp[i][j][k]) % MOD;
          dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
        } else if (s[i] == '1') {
          // Case 2: Snuke has one red and one blue ball
          dp[i + 1][(j + 1) % 3][(k + 1) % 3] = (dp[i + 1][(j + 1) % 3][(k + 1) % 3] + dp[i][j][k]) % MOD;
          dp[i + 1][(j + 1) % 3][k] = (dp[i + 1][(j + 1) % 3][k] + dp[i][j][k]) % MOD;
          dp[i + 1][j][(k + 1) % 3] = (dp[i + 1][j][(k + 1) % 3] + dp[i][j][k]) % MOD;
        } else {
          // Case 3: Snuke has two blue balls
          dp[i + 1][j][(k + 2) % 3] = (dp[i + 1][j][(k + 2) % 3] + dp[i][j][k]) % MOD;
          dp[i + 1][j][(k + 1) % 3] = (dp[i + 1][j][(k + 1) % 3] + dp[i][j][k]) % MOD;
          dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
        }
      }
    }
  }

  // Sum up the possible sequences at the end
  long long totalSequences = 0;
  for (int j = 0; j <= 2; j++) {
    for (int k = 0; k <= 2; k++) {
      totalSequences = (totalSequences + dp[n][j][k]) % MOD;
    }
  }

  return totalSequences;
}

int main() {
  char s[2001];

  // Read the input string
  scanf("%s", s);

  // Calculate and print the number of possible sequences
  printf("%lld\n", countSequences(s));

  return 0;
}