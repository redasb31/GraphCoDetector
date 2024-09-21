#include <stdio.h>
#include <string.h>

int main() {
  char s[100001]; // String to store tile colors
  scanf("%s", s); // Read the string from the input
  int n = strlen(s); // Get the length of the string

  int count = 0; // Initialize a counter to track the number of tiles to be repainted
  for (int i = 0; i < n - 1; i++) { // Iterate through the string, except for the last tile
    if (s[i] == s[i + 1]) { // If two adjacent tiles have the same color
      count++; // Increment the counter
    }
  }
  printf("%d\n", count); // Print the minimum number of tiles to be repainted
  return 0;
}