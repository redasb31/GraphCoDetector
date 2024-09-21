#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for sorting
int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  int n;
  scanf("%d", &n);

  // Read Mr. Past's card order
  int *past_cards = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &past_cards[i]);
  }

  // Read Ms. Future's card order
  int *future_cards = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &future_cards[i]);
  }

  // Sort both card orders in ascending order
  qsort(past_cards, n, sizeof(int), compare);
  qsort(future_cards, n, sizeof(int), compare);

  // Create an array to store Ms. Future's optimal card playing order
  int *optimal_order = malloc(n * sizeof(int));

  // Initialize the optimal order with the largest card from Ms. Future's hand
  optimal_order[0] = future_cards[n - 1];

  // Find the optimal playing order by matching cards with Mr. Past's order
  int past_index = 0;
  int future_index = n - 2; // Start from the second largest card

  for (int i = 1; i < n; i++) {
    // If Mr. Past's card is greater than Ms. Future's current card, move to the next card
    while (past_index < n && past_cards[past_index] > future_cards[future_index]) {
      past_index++;
    }

    // If Mr. Past's card is equal or smaller, use the current card from Ms. Future
    if (past_index < n) {
      optimal_order[i] = future_cards[future_index];
      past_index++;
      future_index--;
    } else {
      // If Mr. Past's cards are all smaller, use the remaining cards from Ms. Future in reverse order
      for (; future_index >= 0; future_index--) {
        optimal_order[i++] = future_cards[future_index];
      }
    }
  }

  // Print the optimal playing order
  for (int i = 0; i < n; i++) {
    printf("%d ", optimal_order[i]);
  }
  printf("\n");

  // Free allocated memory
  free(past_cards);
  free(future_cards);
  free(optimal_order);

  return 0;
}