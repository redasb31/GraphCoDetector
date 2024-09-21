#include <stdio.h>
#include <string.h>

// Function to find the length of the longest common subsequence (LCS)
int lcs(char *X, char *Y, int m, int n) {
  // Create a 2D array to store the lengths of LCS for all subproblems
  int dp[m + 1][n + 1];

  // Initialize the first row and column to 0s
  for (int i = 0; i <= m; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = 0;
  }

  // Fill the dp array using dynamic programming approach
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i - 1] == Y[j - 1]) {
        // If characters match, add 1 to the length of LCS from previous subproblem
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        // If characters don't match, take the maximum length from previous subproblems
        dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }

  // The length of LCS is stored in the bottom-right corner of the dp array
  return dp[m][n];
}

int main() {
  int q; // Number of datasets
  scanf("%d", &q);

  // Iterate through each dataset
  for (int i = 0; i < q; i++) {
    // Read the two sequences X and Y
    char X[1001], Y[1001];
    scanf("%s %s", X, Y);
    int m = strlen(X); // Length of sequence X
    int n = strlen(Y); // Length of sequence Y

    // Calculate and print the length of LCS for the current dataset
    int length = lcs(X, Y, m, n);
    printf("%d\n", length);
  }

  return 0;
}