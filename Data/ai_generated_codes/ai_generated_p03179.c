#include <stdio.h>
#include <string.h>

#define MOD 1000000007

long long dp[3001][3001]; // dp[i][j] stores the number of permutations of (1, 2, ..., i) that satisfy the condition and end with j

int main() {
  int n;
  char s[3001];

  scanf("%d", &n);
  scanf("%s", s);

  // Base case: dp[1][1] = 1, as there is only one permutation for the first element
  dp[1][1] = 1;

  // Iterate over the length of the permutation
  for (int i = 2; i <= n; i++) {
    // Iterate over the possible ending elements of the permutation
    for (int j = 1; j <= i; j++) {
      // If the previous character in the string is '<', the current element must be greater than the previous element
      if (s[i - 2] == '<') {
        // Add the number of permutations ending with j - 1
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      }
      // If the previous character in the string is '>', the current element must be smaller than the previous element
      if (s[i - 2] == '>') {
        // Add the number of permutations ending with j + 1
        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
      }
    }
  }

  // Sum up the number of permutations ending with all possible elements
  long long result = 0;
  for (int i = 1; i <= n; i++) {
    result = (result + dp[n][i]) % MOD;
  }

  printf("%lld\n", result);

  return 0;
}