#include <stdio.h>
#include <string.h>

#define MOD 998244353

// Function to calculate the number of possible strings
long long countStrings(char *S) {
  int n = strlen(S);
  long long dp[n + 1][3]; // dp[i][j] represents the number of strings with prefix S[0:i-1] and the last character being j
  memset(dp, 0, sizeof(dp));

  // Base case: Empty string can have all 3 characters as last character
  dp[0][0] = dp[0][1] = dp[0][2] = 1;

  // Iterate through the string
  for (int i = 1; i <= n; ++i) {
    // Iterate through all possible last characters
    for (int j = 0; j < 3; ++j) {
      // Iterate through the previous character
      for (int k = 0; k < 3; ++k) {
        // If the current character and the previous character are different, 
        // we can use the previous string with the last character k to build a new string
        if (k != j) {
          dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
      }
    }
  }

  // Sum up all possible strings with last character being any of a, b, or c
  long long total = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
  return total;
}

int main() {
  char S[200001];
  scanf("%s", S);

  long long result = countStrings(S);
  printf("%lld\n", result);

  return 0;
}