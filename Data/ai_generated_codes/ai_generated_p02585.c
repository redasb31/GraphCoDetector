#include <stdio.h>
#include <limits.h>

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  // Array to store the permutation.
  int P[N];
  // Array to store the value on each square.
  int C[N];

  // Read the permutation.
  for (int i = 0; i < N; i++) {
    scanf("%d", &P[i]);
    // Adjust the index to be 0-based.
    P[i]--; 
  }

  // Read the value on each square.
  for (int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }

  // Initialize the maximum score to the minimum possible integer value.
  long long max_score = LLONG_MIN;

  // Iterate through all starting squares.
  for (int start = 0; start < N; start++) {
    // Initialize the current score.
    long long score = 0;
    // Initialize the current position to the starting square.
    int current_position = start;

    // Iterate for up to K moves.
    for (int move = 0; move <= K; move++) {
      // Add the value of the current square to the score.
      score += C[current_position];

      // Move to the next square based on the permutation.
      current_position = P[current_position];

      // Update the maximum score if the current score is greater.
      max_score = (score > max_score) ? score : max_score;
    }
  }

  // Print the maximum score.
  printf("%lld\n", max_score);

  return 0;
}