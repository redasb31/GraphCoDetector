#include <stdio.h>
#include <stdlib.h>

int main() {
  // Get the number of cards
  int N;
  scanf("%d", &N);

  // Allocate memory for the card values
  int *cards = (int *)malloc(N * sizeof(int));

  // Read the card values
  for (int i = 0; i < N; i++) {
    scanf("%d", &cards[i]);
  }

  // Sort the cards in descending order
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (cards[i] < cards[j]) {
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
      }
    }
  }

  // Calculate Alice's score
  int alice_score = 0;
  for (int i = 0; i < N; i += 2) {
    alice_score += cards[i];
  }

  // Calculate Bob's score
  int bob_score = 0;
  for (int i = 1; i < N; i += 2) {
    bob_score += cards[i];
  }

  // Print the difference of their scores
  printf("%d\n", alice_score - bob_score);

  // Free the allocated memory
  free(cards);

  return 0;
}