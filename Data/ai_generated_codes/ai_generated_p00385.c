#include <stdio.h>
#include <stdlib.h>

// Function to rotate the disc clockwise
void rotate_clockwise(int *current_position, int steps, int K) {
  *current_position = (*current_position + steps) % K;
  if (*current_position < 0) {
    *current_position += K;
  }
}

// Function to rotate the disc counterclockwise
void rotate_counterclockwise(int *current_position, int steps, int K) {
  *current_position = (*current_position - steps) % K;
  if (*current_position < 0) {
    *current_position += K;
  }
}

// Function to flip the disc
void flip_disc(int *current_position) {
  *current_position = -(*current_position);
}

int main() {
  int K, N, Q;
  scanf("%d %d %d", &K, &N, &Q);

  // Read the array of numbers on the cards
  int *cards = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &cards[i]);
  }

  // Initialize the current position of the disc
  int current_position = 1;

  // Process each command
  for (int i = 0; i < Q; i++) {
    int L, R;
    scanf("%d %d", &L, &R);

    // Swap the cards
    int temp = cards[L - 1];
    cards[L - 1] = cards[R - 1];
    cards[R - 1] = temp;

    // Simulate the device actions
    for (int j = 0; j < N; j++) {
      if (cards[j] > 0) {
        rotate_clockwise(&current_position, abs(cards[j]), K);
      } else if (cards[j] == 0) {
        flip_disc(&current_position);
      } else {
        rotate_counterclockwise(&current_position, abs(cards[j]), K);
      }
    }

    // Print the final position of the disc
    printf("%d\n", current_position);
  }

  // Free the allocated memory
  free(cards);

  return 0;
}