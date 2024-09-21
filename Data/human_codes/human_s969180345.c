#include <stdio.h>
typedef long long int64;
int A = 0, G = 1, C = 2, T = 3;
int main(int argc, const char *argv[])
{
  int n, MOD = 1000000007;
  scanf("%d", &n);
  int64 dp[n+1][4][4][4];
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      for (int l = 0; l < 4; l++) {
        dp[3][j][k][l] = 0;
        if ( j == A && k == C && l == G ) continue;
        if ( j == A && k == G && l == C ) continue;
        if ( j == G && k == A && l == C ) continue;
        dp[3][j][k][l] = 1;
      }
    }
  }

  for (int i = 4; i <= n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
          dp[i][j][k][l] = 0;
          if ( j == A && k == C && l == G ) continue;
          if ( j == A && k == G && l == C ) continue;
          if ( j == G && k == A && l == C ) continue;
          for (int m = 0; m < 4; m++) {
            // AG?C
            if ( m == A && j == G && l == C ) continue;
            // A?GC
            if ( m == A && k == G && l == C ) continue;
            dp[i][j][k][l] += dp[i-1][m][j][k] % MOD;
          }
        }
      }
    }
  }

  int64 sum = 0;
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      for (int l = 0; l < 4; l++) {
        sum += dp[n][j][k][l];
      }
    }
  }
  printf("%lld\n", sum % MOD);
  return 0;
}