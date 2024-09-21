#include <stdio.h>
#include <string.h>

int main() {
  // Declare variables
  int N; // Length of the string
  char S[51]; // String to store input
  int count = 0; // Counter for occurrences of "ABC"

  // Get input
  scanf("%d\n", &N);
  scanf("%s", S);

  // Iterate through the string, checking for "ABC"
  for (int i = 0; i <= N - 3; i++) {
    // Check if the current substring is "ABC"
    if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
      count++; // Increment the counter if found
    }
  }

  // Print the result
  printf("%d\n", count);

  return 0;
}