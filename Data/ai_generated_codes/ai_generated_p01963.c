#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the number of ways to separate the string
long long separateString(char *t, char **s, int n, int len) {
  // Create a dp array to store the number of ways to separate the string up to index i
  long long dp[len + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1; // Base case: Empty string can be separated in 1 way

  // Iterate over the string
  for (int i = 1; i <= len; i++) {
    // Iterate over the set of strings
    for (int j = 0; j < n; j++) {
      // If the current string is a prefix of the substring from index i
      if (strncmp(t + i - strlen(s[j]), s[j], strlen(s[j])) == 0) {
        // Add the number of ways to separate the substring up to index i - length of s[j] to the current dp value
        dp[i] = (dp[i] + dp[i - strlen(s[j])]) % MOD;
      }
    }
  }

  // Return the number of ways to separate the entire string
  return dp[len];
}

int main() {
  int n, len;
  scanf("%d", &n);

  // Allocate memory for the set of strings
  char **s = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(100001 * sizeof(char));
    scanf("%s", s[i]);
  }

  // Read the string to be separated
  char t[100001];
  scanf("%s", t);
  len = strlen(t);

  // Calculate the number of ways to separate the string
  long long result = separateString(t, s, n, len);

  // Print the result
  printf("%lld\n", result);

  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(s[i]);
  }
  free(s);

  return 0;
}