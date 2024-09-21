#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_N 50
#define MAX_S_LEN 20

// Structure to store string and its cost
typedef struct {
  char str[MAX_S_LEN + 1];
  int cost;
} String;

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the minimum cost of making a palindrome using the given strings
int min_palindrome_cost(String strings[], int n) {
  // Create a 2D array to store the minimum cost of making a palindrome
  // using strings from index i to j
  int dp[MAX_N + 1][MAX_N + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = INT_MAX;
    }
  }

  // Base case: an empty string is a palindrome with cost 0
  dp[0][0] = 0;

  // Iterate over all substrings
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      // Check if the substring from i to j is a palindrome
      if (is_palindrome(strings[i - 1].str + (j - i))) {
        // If it is a palindrome, update the minimum cost
        dp[i][j] = dp[i - 1][j - 1] + strings[i - 1].cost;
      }
      // Check if the substring from i to j can be made a palindrome
      // by concatenating with a palindrome from i to k
      for (int k = i; k < j; k++) {
        // Check if the substring from i to k is a palindrome
        if (is_palindrome(strings[i - 1].str + (k - i))) {
          // Check if the substring from k + 1 to j is a palindrome
          if (is_palindrome(strings[k].str + (j - k))) {
            // Update the minimum cost if necessary
            dp[i][j] = (dp[i][j] < dp[i][k] + dp[k + 1][j]) ? dp[i][j] : dp[i][k] + dp[k + 1][j];
          }
        }
      }
    }
  }

  // Return the minimum cost of making a palindrome
  return (dp[1][n] == INT_MAX) ? -1 : dp[1][n];
}

int main() {
  int n;
  scanf("%d", &n);

  String strings[MAX_N];
  for (int i = 0; i < n; i++) {
    scanf("%s %d", strings[i].str, &strings[i].cost);
  }

  int min_cost = min_palindrome_cost(strings, n);
  printf("%d\n", min_cost);

  return 0;
}