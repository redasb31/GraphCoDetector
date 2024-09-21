#include <stdio.h>

int main() {
  // Declare variables to store the number of rows and columns.
  long long int N, M;

  // Read the number of rows and columns from the standard input.
  scanf("%lld %lld", &N, &M);

  // Calculate the number of cards that will be flipped.
  // The cards in the corner are flipped four times, those on the edges are flipped three times, and those inside the rectangle are flipped twice.
  long long int flipped_cards = 4 * (N - 1) * (M - 1) + 3 * (2 * (N - 1) + 2 * (M - 1));

  // Calculate the number of cards that will face down.
  // The number of cards that face down is equal to the number of cards flipped minus the total number of cards.
  long long int cards_down = flipped_cards - N * M;

  // Print the number of cards that face down.
  printf("%lld\n", cards_down);

  return 0;
}