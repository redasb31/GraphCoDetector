#include <stdio.h>
#include <stdbool.h>

// Function to check if Snuke can always win the game
bool canSnukeWin(int N, int K, int a[], int Q, int x[]) {
  // Initialize the remaining attempts for each box
  int remaining[N];
  for (int i = 0; i < N; i++) {
    remaining[i] = a[i];
  }

  // Check if Snuke can win the game
  for (int i = 0; i < Q; i++) {
    // Get the index of the box to be opened
    int boxIndex = x[i] - 1;

    // Check if the box has remaining attempts
    if (remaining[boxIndex] > 0) {
      // Decrease the remaining attempts
      remaining[boxIndex]--;

      // Check if the magician can still move the treasure
      if (K > 0) {
        // Find a box with remaining attempts
        int nextBoxIndex = -1;
        for (int j = 0; j < N; j++) {
          if (remaining[j] > 0 && j != boxIndex) {
            nextBoxIndex = j;
            break;
          }
        }

        // If a box with remaining attempts is found, move the treasure
        if (nextBoxIndex != -1) {
          K--;
        }
      }
    } else {
      // If the box has no remaining attempts, Snuke loses
      return false;
    }
  }

  // If Snuke has opened all the boxes with remaining attempts, he wins
  return true;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  // Check if Snuke can always win the game
  // If Snuke can win, output the sequence of boxes to open
  // Otherwise, output -1
  bool canWin = false;
  int Q = 0;
  int x[N];

  // Try all possible sequences of boxes to open
  for (int i = 0; i < N; i++) {
    // Initialize the sequence of boxes to open
    for (int j = 0; j < N; j++) {
      x[j] = 0;
    }

    // Set the first box to be opened
    x[0] = i + 1;

    // Iterate through all possible sequences
    Q = 1;
    while (Q < N && x[Q - 1] != 0) {
      // Find the next box to be opened
      int nextBox = 0;
      while (nextBox < N && x[Q - 1] == x[nextBox]) {
        nextBox++;
      }

      // If a new box is found, add it to the sequence
      if (nextBox < N) {
        x[Q] = nextBox + 1;
        Q++;
      } else {
        // If all boxes have been opened, check if Snuke can win
        if (canSnukeWin(N, K, a, Q, x)) {
          canWin = true;
          break;
        }
      }
    }

    // If Snuke can win, break the loop
    if (canWin) {
      break;
    }
  }

  // Output the result
  if (canWin) {
    printf("%d\n", Q);
    for (int i = 0; i < Q; i++) {
      printf("%d ", x[i]);
    }
  } else {
    printf("-1\n");
  }

  return 0;
}