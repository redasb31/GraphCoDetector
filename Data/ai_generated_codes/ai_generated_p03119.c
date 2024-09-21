#include <stdio.h>
#include <stdbool.h>

// Function to check if Snuke can win the game
bool can_win(int N, int K, int *a) {
  // Check if the sum of the maximum number of times Snuke can open each box
  // is greater than or equal to the number of boxes plus the number of times the
  // magician can move the treasure
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
  }
  if (sum >= N + K) {
    return true;
  } else {
    return false;
  }
}

// Function to generate a possible winning move for Snuke
void generate_move(int N, int K, int *a) {
  // If Snuke cannot win, print -1
  if (!can_win(N, K, a)) {
    printf("-1\n");
    return;
  }

  // Otherwise, generate a possible winning move
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    // Print the box number for each opening
    printf("%d ", i + 1);
    // Decrease the number of times Snuke can open the box
    a[i]--;
  }
  printf("\n");
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  int a[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }

  generate_move(N, K, a);

  return 0;
}