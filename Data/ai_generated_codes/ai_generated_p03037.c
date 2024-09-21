#include <stdio.h>

int main() {
  // N: Number of ID cards
  // M: Number of gates
  int N, M;
  scanf("%d %d", &N, &M);

  // L: Array to store the lower bound of the ID cards allowed for each gate
  // R: Array to store the upper bound of the ID cards allowed for each gate
  int L[M], R[M];
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &L[i], &R[i]);
  }

  // Create an array to store the count of ID cards allowed for each gate
  int count[N + 1] = {0};
  for (int i = 0; i < M; i++) {
    // Increment the count for each ID card allowed for the current gate
    for (int j = L[i]; j <= R[i]; j++) {
      count[j]++;
    }
  }

  // Initialize the count of ID cards that allow us to pass all the gates
  int result = 0;
  // Iterate through all the ID cards
  for (int i = 1; i <= N; i++) {
    // If the count for the current ID card is equal to the number of gates, it allows us to pass all the gates
    if (count[i] == M) {
      result++;
    }
  }

  // Print the result
  printf("%d\n", result);

  return 0;
}