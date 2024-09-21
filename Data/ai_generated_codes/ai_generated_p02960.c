#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of integers satisfying the condition
long long countIntegers(char *S) {
  int len = strlen(S);
  long long dp[len + 1][13] = {0}; // dp[i][j] stores the number of integers of length i with remainder j when divided by 13

  // Base case: empty string
  dp[0][0] = 1;

  // Iterate over each character in the string
  for (int i = 0; i < len; i++) {
    // Iterate over all possible remainders
    for (int j = 0; j < 13; j++) {
      // If the current character is a digit
      if (S[i] != '?') {
        int digit = S[i] - '0';
        int next_remainder = (10 * j + digit) % 13;
        dp[i + 1][next_remainder] = (dp[i + 1][next_remainder] + dp[i][j]) % MOD;
      } else { // If the current character is '?'
        // Iterate over all possible digits
        for (int digit = 0; digit <= 9; digit++) {
          int next_remainder = (10 * j + digit) % 13;
          dp[i + 1][next_remainder] = (dp[i + 1][next_remainder] + dp[i][j]) % MOD;
        }
      }
    }
  }

  // Return the number of integers with remainder 5
  return dp[len][5];
}

int main() {
  char S[100005];
  scanf("%s", S);

  long long result = countIntegers(S);
  printf("%lld\n", result);

  return 0;
}