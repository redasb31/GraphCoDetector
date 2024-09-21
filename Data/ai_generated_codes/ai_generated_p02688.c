#include <stdio.h>

int main() {
  // N: Number of Snukes
  // K: Number of Snack types
  int N, K;
  scanf("%d %d", &N, &K);

  // Array to store which Snukes have which snacks
  int snacks[N + 1] = {0}; // Initialize all Snukes to have no snacks

  // Loop through each snack type
  for (int i = 1; i <= K; i++) {
    // d_i: Number of Snukes who have Snack i
    int d_i;
    scanf("%d", &d_i);

    // A_i, 1 ⋯A_i, d_i: Snukes who have Snack i
    for (int j = 1; j <= d_i; j++) {
      int A_i_j;
      scanf("%d", &A_i_j);
      // Mark the Snukes who have Snack i
      snacks[A_i_j] = 1;
    }
  }

  // Count the Snukes who have no snacks (victims)
  int victims = 0;
  for (int i = 1; i <= N; i++) {
    if (snacks[i] == 0) {
      victims++;
    }
  }

  // Print the number of victims
  printf("%d\n", victims);

  return 0;
}