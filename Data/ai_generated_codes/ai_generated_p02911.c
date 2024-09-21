#include <stdio.h>

int main() {
  // N: Number of players
  // K: Initial points
  // Q: Number of correct answers
  int N, K, Q;

  // Read input values
  scanf("%d %d %d", &N, &K, &Q);

  // Array to store the scores of each player
  int scores[N];

  // Initialize the scores of each player to K
  for (int i = 0; i < N; i++) {
    scores[i] = K;
  }

  // Read the player who answered each question correctly
  int A[Q];
  for (int i = 0; i < Q; i++) {
    scanf("%d", &A[i]);
  }

  // Process each correct answer
  for (int i = 0; i < Q; i++) {
    // Decrement the scores of all players except the player who answered correctly
    for (int j = 0; j < N; j++) {
      if (j != A[i] - 1) {
        scores[j]--;
      }
    }
  }

  // Print whether each player survived or not
  for (int i = 0; i < N; i++) {
    if (scores[i] > 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}