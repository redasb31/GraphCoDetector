#include <stdio.h>
#include <string.h>

// Function to calculate the number of distinct substrings
int countDistinctSubstrings(char *str) {
  int n = strlen(str);
  int count = 0; // Initialize count of distinct substrings
  
  // Iterate over all possible starting positions of substrings
  for (int i = 0; i < n; i++) {
    // Iterate over all possible lengths of substrings
    for (int j = i + 1; j <= n; j++) {
      // Check if the substring from i to j-1 is already counted
      int isDistinct = 1;
      for (int k = i; k < j - 1; k++) {
        if (strncmp(str + i, str + k + 1, j - k - 1) == 0) {
          isDistinct = 0;
          break;
        }
      }
      // Increment the count if the substring is distinct
      if (isDistinct) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  char str[500001]; // Declare a string to store the input
  
  // Read the string from the standard input
  scanf("%s", str); 
  
  // Calculate the number of distinct substrings
  int distinctSubstrings = countDistinctSubstrings(str); 
  
  // Print the result
  printf("%d\n", distinctSubstrings);
  
  return 0;
}