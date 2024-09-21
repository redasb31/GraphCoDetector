#include <stdio.h>
#include <string.h>

int main() {
  // N: length of the string S
  int N;
  // S: string containing the symbols
  char S[250001];

  // Read the input
  scanf("%d\n", &N);
  scanf("%s", S);

  // Initialize variables for counting the number of pairs
  long long pairs = 0;
  long long p = 0; // current value of P

  // Iterate through the string S
  for (int i = 0; i < N; i++) {
    // Update the value of P based on the current symbol
    if (S[i] == '>') {
      p++;
    } else if (S[i] == '<') {
      p--;
    }

    // Count the number of pairs (i, j) that lead to the same sequence A
    pairs += (p == 0); // Increment if P is 0 (same as the starting value)
  }

  // Print the total number of pairs
  printf("%lld\n", pairs);

  return 0;
}