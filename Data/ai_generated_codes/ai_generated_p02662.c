#include <stdio.h>

#define MOD 998244353

int main() {
  int N, S;
  scanf("%d %d", &N, &S);

  int A[3001];
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  // dp[i][j] represents the number of subsets of {1, 2, ..., i} with sum j.
  int dp[3001][3001] = {0};

  // Initialize dp[0][0] to 1 as the empty subset has sum 0.
  dp[0][0] = 1;

  // Iterate over each element of the array.
  for (int i = 1; i <= N; i++) {
    // Iterate over all possible sums.
    for (int j = 0; j <= S; j++) {
      // Without including the current element.
      dp[i][j] = dp[i - 1][j];
      // Including the current element if its sum is less than or equal to S.
      if (j >= A[i]) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i]]) % MOD;
      }
    }
  }

  // Sum of f(T) over all subsets.
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    // Add the number of subsets with sum S for each element i.
    sum = (sum + dp[N][S]) % MOD;
  }

  printf("%d\n", sum);
  return 0;
}