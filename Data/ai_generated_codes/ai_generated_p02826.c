#include <stdio.h>

#define MOD 998244353

int main() {
  int n, m;

  // Read input
  scanf("%d %d", &n, &m);

  // Initialize dp array
  long long dp[5001] = {0}; 
  dp[0] = 1; // Base case:  0 problems have only 1 way to assign scores

  // Iterate over problem numbers
  for (int i = 1; i <= n; i++) {
    // Iterate over possible scores for the current problem
    for (int j = i; j >= 1; j--) {
      // Sum up valid score combinations
      dp[i] = (dp[i] + dp[j - 1]) % MOD;
    }
  }

  // Output the result
  printf("%lld\n", dp[n]);

  return 0;
}