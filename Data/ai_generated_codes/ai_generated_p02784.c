#include <stdio.h>
#include <stdbool.h>

int main() {
  // H: Monster's health
  // N: Number of special moves
  int H, N;
  scanf("%d %d", &H, &N);

  // A: Array to store the damage of each special move
  int A[N];

  // Read the damage values for each move
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize a boolean array to track whether a move has been used
  bool used[N];
  for (int i = 0; i < N; i++) {
    used[i] = false;
  }

  // Iterate through all possible combinations of moves
  for (int i = 0; i < (1 << N); i++) {
    // Calculate the total damage for the current combination
    int total_damage = 0;
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        total_damage += A[j];
        used[j] = true;
      }
    }

    // Check if the monster's health can be reduced to 0 or below
    if (total_damage >= H) {
      // Check if each move has been used at most once
      bool all_used_once = true;
      for (int j = 0; j < N; j++) {
        if (used[j] && (i >> j) & 1) {
          all_used_once = false;
          break;
        }
      }

      // If all moves have been used at most once, print Yes
      if (all_used_once) {
        printf("Yes\n");
        return 0;
      }
    }

    // Reset the used array for the next combination
    for (int j = 0; j < N; j++) {
      used[j] = false;
    }
  }

  // If no valid combination is found, print No
  printf("No\n");

  return 0;
}