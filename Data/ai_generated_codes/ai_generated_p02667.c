#include <stdio.h>
#include <string.h>

int main() {
  // Input the string T
  char T[200001];
  scanf("%s", T);

  // Calculate the length of T
  int n = strlen(T);

  // Initialize x to 0
  int x = 0;

  // Iterate over the characters of T
  for (int i = 0; i < n; i++) {
    // If the current character is 1, add the sum of the digits in odd positions of T up to the current position to x
    if (T[i] == '1') {
      // Calculate the sum of digits in odd positions
      int sum = 0;
      for (int j = 0; j <= i; j += 2) {
        sum += T[j] - '0';
      }
      // Add the sum to x
      x += sum;
    }
  }

  // Print the maximum possible value of x
  printf("%d\n", x);

  return 0;
}