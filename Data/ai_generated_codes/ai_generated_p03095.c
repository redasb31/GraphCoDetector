#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
  int n;
  char s[100001];

  // Read the input string length and the string itself.
  scanf("%d\n", &n);
  scanf("%s", s);

  // Initialize dp array.
  long long dp[100001][26] = {0}; 

  // Base case: For the first character, there's only one subsequence.
  dp[0][s[0] - 'a'] = 1;

  // Iterate over the string.
  for (int i = 1; i < n; i++) {
    // For each character, copy the previous state.
    for (int j = 0; j < 26; j++) {
      dp[i][j] = dp[i - 1][j];
    }

    // Add the subsequences ending with the current character.
    dp[i][s[i] - 'a'] = (dp[i][s[i] - 'a'] + dp[i - 1][s[i] - 'a'] + 1) % MOD; 
  }

  // Sum up the subsequences ending with all characters.
  long long count = 0;
  for (int i = 0; i < 26; i++) {
    count = (count + dp[n - 1][i]) % MOD;
  }

  // Print the final count.
  printf("%lld\n", count);

  return 0;
}