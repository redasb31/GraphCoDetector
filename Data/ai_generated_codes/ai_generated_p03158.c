#include <stdio.h>
#include <stdlib.h>

// Function to find the sum of integers taken by Takahashi
int find_takahashi_sum(int *cards, int n, int x) {
  int sum = 0;
  int *taken = (int *)calloc(n, sizeof(int)); // Array to track taken cards

  // Sort the cards in descending order
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (cards[i] < cards[j]) {
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    // If the card is already taken, skip
    if (taken[i]) {
      continue;
    }

    // Takahashi takes the largest remaining card
    sum += cards[i];
    taken[i] = 1;

    // Aoki takes the closest card to x
    int closest = i;
    for (int j = 0; j < n; j++) {
      // Skip already taken cards
      if (taken[j]) {
        continue;
      }

      if (abs(cards[j] - x) < abs(cards[closest] - x)) {
        closest = j;
      } else if (abs(cards[j] - x) == abs(cards[closest] - x) && cards[j] < cards[closest]) {
        closest = j;
      }
    }

    taken[closest] = 1;
  }

  free(taken);
  return sum;
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  int *cards = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &cards[i]);
  }

  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);

    int sum = find_takahashi_sum(cards, n, x);
    printf("%d\n", sum);
  }

  free(cards);
  return 0;
}