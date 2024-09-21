#include <stdio.h>

// Function to simulate Hanafuda shuffling
int hanafuda_shuffle(int n, int r, int p[], int c[]) {
  // Create an array to represent the deck of cards
  int deck[n];

  // Initialize the deck with numbers from 1 to n
  for (int i = 0; i < n; i++) {
    deck[i] = i + 1;
  }

  // Perform the cutting operations
  for (int i = 0; i < r; i++) {
    // Extract the cards to be moved
    int temp[c[i]];
    for (int j = 0; j < c[i]; j++) {
      temp[j] = deck[p[i] - 1 + j];
    }

    // Shift the remaining cards down
    for (int j = p[i] - 1; j < n - c[i]; j++) {
      deck[j] = deck[j + c[i]];
    }

    // Put the extracted cards on top of the deck
    for (int j = 0; j < c[i]; j++) {
      deck[n - c[i] + j] = temp[j];
    }
  }

  // Return the number of the top card
  return deck[n - 1];
}

int main() {
  int n, r, p, c;

  // Read the input
  while (scanf("%d %d", &n, &r) != EOF && (n != 0 || r != 0)) {
    int p_array[r], c_array[r];
    for (int i = 0; i < r; i++) {
      scanf("%d %d", &p, &c);
      p_array[i] = p;
      c_array[i] = c;
    }

    // Print the result
    printf("%d\n", hanafuda_shuffle(n, r, p_array, c_array));
  }

  return 0;
}