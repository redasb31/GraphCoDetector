#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum possible score of the sequence A
int maxScore(int N, int M, int Q, int **quadruples) {
  // Create a 2D array to store the scores for each possible difference
  int scores[M][M];
  // Initialize all scores to 0
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      scores[i][j] = 0;
    }
  }
  // Iterate through each quadruple
  for (int i = 0; i < Q; i++) {
    // Get the quadruple values
    int a = quadruples[i][0];
    int b = quadruples[i][1];
    int c = quadruples[i][2];
    int d = quadruples[i][3];
    // Update the score for the corresponding difference
    scores[c][d] += d;
  }
  // Create a sequence A with all elements initialized to 1
  int *A = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    A[i] = 1;
  }
  // Calculate the initial score
  int score = 0;
  for (int i = 0; i < Q; i++) {
    // Get the quadruple values
    int a = quadruples[i][0];
    int b = quadruples[i][1];
    int c = quadruples[i][2];
    int d = quadruples[i][3];
    // If the difference matches, update the score
    if (A[b - 1] - A[a - 1] == c) {
      score += d;
    }
  }
  // Iterate through the sequence A
  for (int i = 0; i < N; i++) {
    // Iterate through the possible values of A[i]
    for (int j = A[i]; j <= M; j++) {
      // Calculate the new score for the current value of A[i]
      int newScore = score;
      for (int k = 0; k < Q; k++) {
        // Get the quadruple values
        int a = quadruples[k][0];
        int b = quadruples[k][1];
        int c = quadruples[k][2];
        int d = quadruples[k][3];
        // If the difference matches, update the score
        if (b - 1 == i && A[b - 1] - A[a - 1] == c) {
          newScore -= d;
        }
        // If the difference matches after changing A[i], update the score
        if (b - 1 == i && j - A[a - 1] == c) {
          newScore += d;
        }
      }
      // If the new score is greater than the current score, update the score and A[i]
      if (newScore > score) {
        score = newScore;
        A[i] = j;
      }
    }
  }
  // Free the memory allocated for the sequence A
  free(A);
  // Return the maximum possible score
  return score;
}

int main() {
  int N, M, Q;
  // Read the input values
  scanf("%d %d %d", &N, &M, &Q);
  // Create a 2D array to store the quadruples
  int **quadruples = (int **)malloc(sizeof(int *) * Q);
  for (int i = 0; i < Q; i++) {
    quadruples[i] = (int *)malloc(sizeof(int) * 4);
    scanf("%d %d %d %d", &quadruples[i][0], &quadruples[i][1], &quadruples[i][2], &quadruples[i][3]);
  }
  // Calculate and print the maximum possible score
  printf("%d\n", maxScore(N, M, Q, quadruples));
  // Free the memory allocated for the quadruples
  for (int i = 0; i < Q; i++) {
    free(quadruples[i]);
  }
  free(quadruples);
  return 0;
}