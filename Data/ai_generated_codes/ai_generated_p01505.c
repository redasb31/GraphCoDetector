#include <stdio.h>

int main() {
  int N, i, j, k, swaps, ball, target;
  int ball_array[5][15]; // Store ball positions
  int target_array[5][15] = { // Store target positions
    {1},
    {2, 3},
    {4, 5, 6},
    {7, 8, 9, 10},
    {11, 12, 13, 14, 15}
  };

  int case_num = 0; // Case counter

  while (1) {
    scanf("%d", &N); // Read number of rows
    if (N == 0) break; // Exit on N = 0

    case_num++; // Increment case number

    // Read ball arrangement
    for (i = 0; i < N; i++) {
      for (j = 0; j <= i; j++) {
        scanf("%d", &ball_array[i][j]);
      }
    }

    swaps = 0; // Initialize swap count

    // Iterate through rows and columns
    for (i = 0; i < N; i++) {
      for (j = 0; j <= i; j++) {
        ball = ball_array[i][j]; // Get current ball

        // Find the target position for the ball
        for (k = 0; k <= i; k++) {
          if (target_array[i][k] == ball) {
            target = k; // Store target column
            break;
          }
        }

        // Swap ball to target position
        while (j != target) {
          if (j < target) { // Move ball right
            ball_array[i][j] = ball_array[i][j + 1];
            ball_array[i][j + 1] = ball;
            j++;
          } else { // Move ball left
            ball_array[i][j] = ball_array[i][j - 1];
            ball_array[i][j - 1] = ball;
            j--;
          }
          swaps++; // Increment swap count
        }
      }
    }

    printf("Case %d: %d\n", case_num, swaps); // Print case number and swap count
  }

  return 0;
}