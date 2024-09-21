#include <stdio.h>
#include <string.h>

// Function to calculate the edit distance (Levenshtein distance)
int editDistance(char *s1, char *s2, int m, int n) {
  // Create a 2D array to store the edit distances
  int dp[m + 1][n + 1];

  // Initialize the first row and column of the array
  for (int i = 0; i <= m; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = j;
  }

  // Calculate the edit distance for each character pair
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      // If the characters are the same, the edit distance is the same as the previous diagonal cell
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // Otherwise, the edit distance is the minimum of the following three operations:
        // 1. Insertion: Add the character from s2 to s1
        // 2. Deletion: Remove the character from s1
        // 3. Substitution: Replace the character in s1 with the character from s2
        dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
      }
    }
  }

  // Return the edit distance stored in the bottom-right cell of the array
  return dp[m][n];
}

// Helper function to find the minimum of three numbers
int min(int a, int b, int c) {
  return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int main() {
  char s1[1001], s2[1001];

  // Input the two words
  scanf("%s", s1);
  scanf("%s", s2);

  // Calculate the edit distance
  int m = strlen(s1);
  int n = strlen(s2);
  int distance = editDistance(s1, s2, m, n);

  // Print the edit distance
  printf("%d\n", distance);

  return 0;
}