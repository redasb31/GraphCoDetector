#include <stdio.h>
#include <string.h>

int main() {
  char s[3001], t[3001];
  
  // Get the input strings s and t
  scanf("%s", s);
  scanf("%s", t);
  
  // Create a 2D array dp to store the lengths of the longest common subsequences
  int dp[3001][3001] = {0};
  
  // Iterate through the strings s and t to calculate the lengths of the longest common subsequences
  for (int i = 1; i <= strlen(s); i++) {
    for (int j = 1; j <= strlen(t); j++) {
      // If the characters at the current positions are the same, the length of the longest common subsequence is one more than the length of the longest common subsequence of the previous positions
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } 
      // Otherwise, the length of the longest common subsequence is the maximum of the lengths of the longest common subsequences of the previous positions
      else {
        dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
      }
    }
  }
  
  // Backtrack through the dp array to reconstruct the longest common subsequence
  int i = strlen(s), j = strlen(t), k = dp[i][j];
  char lcs[3001] = {0};
  while (k > 0) {
    // If the characters at the current positions are the same, add the character to the lcs string and move to the previous positions
    if (s[i - 1] == t[j - 1]) {
      lcs[k - 1] = s[i - 1];
      i--;
      j--;
      k--;
    }
    // Otherwise, move to the position with the larger length of the longest common subsequence
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  
  // Print the longest common subsequence
  printf("%s\n", lcs);
  
  return 0;
}