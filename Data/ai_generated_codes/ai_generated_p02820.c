#include <stdio.h>
#include <string.h>

// Function to calculate the maximum score achievable
int maxScore(int N, int K, int R, int S, int P, char *T) {
  // Initialize the score to 0
  int score = 0;

  // Create an array to store the last K moves
  char lastKMoves[K];
  // Initialize the last K moves to empty
  memset(lastKMoves, 0, sizeof(lastKMoves));

  // Iterate over each round
  for (int i = 0; i < N; i++) {
    // Calculate the index of the move that needs to be checked
    int prevIndex = (i - K + N) % N; 

    // Check if the current move is the same as the previous move
    if (lastKMoves[prevIndex] == T[i]) {
      // If the moves are the same, find the best move based on the machine's move
      if (T[i] == 'r') {
        // If the machine plays rock, play paper for maximum score
        if (S > P) {
          score += S;
          lastKMoves[i % K] = 's';
        } else {
          score += P;
          lastKMoves[i % K] = 'p';
        }
      } else if (T[i] == 'p') {
        // If the machine plays paper, play scissors for maximum score
        if (R > S) {
          score += R;
          lastKMoves[i % K] = 'r';
        } else {
          score += S;
          lastKMoves[i % K] = 's';
        }
      } else {
        // If the machine plays scissors, play rock for maximum score
        if (P > R) {
          score += P;
          lastKMoves[i % K] = 'p';
        } else {
          score += R;
          lastKMoves[i % K] = 'r';
        }
      }
    } else {
      // If the moves are different, find the best move based on the machine's move
      if (T[i] == 'r') {
        // If the machine plays rock, play paper for maximum score
        score += P;
        lastKMoves[i % K] = 'p';
      } else if (T[i] == 'p') {
        // If the machine plays paper, play scissors for maximum score
        score += S;
        lastKMoves[i % K] = 's';
      } else {
        // If the machine plays scissors, play rock for maximum score
        score += R;
        lastKMoves[i % K] = 'r';
      }
    }
  }

  return score;
}

int main() {
  int N, K, R, S, P;
  char T[100000];

  scanf("%d %d", &N, &K);
  scanf("%d %d %d", &R, &S, &P);
  scanf("%s", T);

  // Calculate the maximum score
  int maxScoreEarned = maxScore(N, K, R, S, P, T);

  // Print the maximum score
  printf("%d\n", maxScoreEarned);

  return 0;
}