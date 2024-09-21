#include <stdio.h>

int main() {
  // Declare variables to store the input values
  long long N, M;

  // Read the input values from the user
  scanf("%lld %lld", &N, &M);

  // Calculate the number of cards that will face down after all operations
  long long down_cards = (N - 2) * (M - 2);

  // Print the output
  printf("%lld\n", down_cards);

  return 0;
}