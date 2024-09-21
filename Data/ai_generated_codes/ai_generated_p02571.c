#include <stdio.h>
#include <string.h>

int main() {
  char S[1001], T[1001];
  scanf("%s", S);
  scanf("%s", T);

  int lenS = strlen(S);
  int lenT = strlen(T);

  // Initialize a 2D array to store the minimum changes needed to match T up to index j
  // in S up to index i.
  int dp[lenS + 1][lenT + 1];
  for (int i = 0; i <= lenS; i++) {
    for (int j = 0; j <= lenT; j++) {
      dp[i][j] = 0;
    }
  }

  // Iterate through each character of S and T.
  for (int i = 1; i <= lenS; i++) {
    for (int j = 1; j <= lenT; j++) {
      // If the characters match, the minimum changes needed is the same as the previous
      // position.
      if (S[i - 1] == T[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // If the characters don't match, we need to change one character. So, we
        // choose the minimum changes from the previous position in S or the previous
        // position in T.
        dp[i][j] = 1 + (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
      }
    }
  }

  // The minimum number of changes needed is stored in the last element of the dp
  // array.
  printf("%d\n", dp[lenS][lenT]);

  return 0;
}