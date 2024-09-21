#include <stdio.h>

// Function to calculate the maximum number of biscuits after K operations
int max_biscuits(int K, int A, int B) {
  // If A is greater than or equal to B, then it's always better to exchange biscuits for yen
  if (A >= B) {
    return K + 1; // Initial biscuit + K hits
  }

  // Otherwise, we need to optimize the exchange strategy
  int max_biscuits = 1; // Initial biscuit
  int current_yen = 0; // Initial yen
  int current_biscuits = 1; // Initial biscuit

  // Loop through the operations
  for (int i = 0; i < K; i++) {
    // If we have enough biscuits to exchange, do it
    if (current_biscuits >= A) {
      current_yen += current_biscuits / A;
      current_biscuits %= A; // Remaining biscuits
    } else {
      // If not enough biscuits to exchange, hit the pocket
      current_biscuits++;
    }

    // If we have yen to exchange, do it
    if (current_yen > 0) {
      current_biscuits += current_yen * B;
      current_yen = 0;
    }

    // Update maximum biscuits
    max_biscuits = (max_biscuits > current_biscuits) ? max_biscuits : current_biscuits;
  }

  return max_biscuits;
}

int main() {
  int K, A, B;

  // Read input
  scanf("%d %d %d", &K, &A, &B);

  // Calculate and print the maximum number of biscuits
  printf("%d\n", max_biscuits(K, A, B));

  return 0;
}