#include <stdio.h>
#include <string.h>

int main() {
  char S[200001]; // String to store the state of the pieces
  scanf("%s", S); // Input the string

  int N = strlen(S); // Length of the string
  int count = 0; // Initialize the count of operations

  // Iterate through the string, checking for adjacent pieces with different colors
  for (int i = 0; i < N - 1; i++) {
    // If a black piece is followed by a white piece, increment the count
    if (S[i] == 'B' && S[i + 1] == 'W') {
      count++;
      // Flip the colors of the two pieces
      S[i] = 'W';
      S[i + 1] = 'B';
    }
  }

  printf("%d\n", count); // Print the maximum number of operations

  return 0;
}