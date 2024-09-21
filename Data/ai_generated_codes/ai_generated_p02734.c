// This code implements a dynamic programming solution for the problem, calculating f(L, R) for all pairs (L, R).

#include <stdio.h>

#define MOD 998244353

int main() {
  int N, S;
  scanf("%d %d", &N, &S);

  // Array to store the input sequence
  int A[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // DP table to store the number of ways to achieve a sum 's' using elements from index 'i' to 'j'
  long long dp[N + 1][S + 1];
  // Initialize DP table with 0s
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] = 0;
    }
  }
  // Base case: If the sum is 0, there is one way to achieve it (by not taking any elements)
  for (int i = 0; i <= N; i++) {
    dp[i][0] = 1;
  }

  // Fill the DP table using a bottom-up approach
  for (int i = N - 1; i >= 0; i--) {
    for (int s = 1; s <= S; s++) {
      // Take the current element
      if (s >= A[i]) {
        dp[i][s] = (dp[i + 1][s] + dp[i + 1][s - A[i]]) % MOD;
      } else {
        // Don't take the current element
        dp[i][s] = dp[i + 1][s];
      }
    }
  }

  // Calculate the sum of f(L, R) over all pairs (L, R)
  long long sum = 0;
  for (int L = 1; L <= N; L++) {
    for (int R = L; R <= N; R++) {
      // f(L, R) is the difference between the number of ways to achieve the sum 'S' using elements from index 'L' to 'N' and the number of ways using elements from index 'R+1' to 'N'
      sum = (sum + dp[L - 1][S] - dp[R][S] + MOD) % MOD;
    }
  }

  printf("%lld\n", sum);
  return 0;
}