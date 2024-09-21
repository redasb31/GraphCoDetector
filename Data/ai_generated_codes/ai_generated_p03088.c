#include <stdio.h>

#define MOD 1000000007

// Function to calculate the number of valid strings of length n
long long countStrings(int n) {
  // dp[i][j] stores the number of valid strings of length i ending with the substring j
  long long dp[n + 1][3] = {0};

  // Base cases for strings of length 1 and 2
  dp[1][0] = 4; // Any of the four characters can be used
  dp[2][0] = 16; // All combinations of two characters are valid
  dp[2][1] = 3; // Only "AG" is valid as a substring
  dp[2][2] = 0; // "AGC" is not valid

  // Iterate through string lengths from 3 to n
  for (int i = 3; i <= n; i++) {
    // For each possible ending substring:
    // 0: No substring
    // 1: Ending with "AG"
    // 2: Ending with "AGC"
    for (int j = 0; j <= 2; j++) {
      // Calculate the number of valid strings for the current length
      dp[i][j] = 0;

      // If the substring is "AGC" (not valid), then there are no valid strings
      if (j == 2) {
        continue;
      }

      // If the substring is "AG", then we can add any character except "C" to the end
      if (j == 1) {
        dp[i][j] = (dp[i - 1][0] * 3) % MOD;
      }

      // If the substring is empty, then we can add any character to the end
      if (j == 0) {
        // Add valid combinations from previous lengths
        dp[i][j] = ((dp[i - 1][0] * 4) % MOD + (dp[i - 1][1] * 3) % MOD) % MOD;

        // Check if adding "A" or "G" creates a substring of "AG"
        if (i >= 3) {
          dp[i][1] = (dp[i][1] + dp[i - 2][0]) % MOD;
        }

        // Check if adding "A" and "G" consecutively creates a substring of "AGC"
        if (i >= 4) {
          dp[i][2] = (dp[i][2] + dp[i - 3][0]) % MOD;
        }
      }
    }
  }

  // Return the total number of valid strings of length n
  return (dp[n][0] + dp[n][1]) % MOD;
}

int main() {
  int n;
  scanf("%d", &n);

  long long result = countStrings(n);
  printf("%lld\n", result);

  return 0;
}