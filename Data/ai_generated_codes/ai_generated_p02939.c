#include <stdio.h>
#include <string.h>

int main() {
  char S[200001]; // Maximum string length
  scanf("%s", S);
  int len = strlen(S);
  
  // Initialize K to 1
  int K = 1;
  // Iterate through the string
  for (int i = 1; i < len; i++) {
    // Check if the current character is different from the previous one
    if (S[i] != S[i - 1]) {
      // If different, increment K
      K++;
    }
  }
  // Print the maximum K
  printf("%d\n", K);
  return 0;
}