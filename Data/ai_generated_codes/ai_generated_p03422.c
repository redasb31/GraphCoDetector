#include <stdio.h>
#include <math.h>

int main() {
  int n; // Number of piles
  scanf("%d", &n);

  int a[200], k[200]; // Arrays to store number of stones and K values for each pile

  // Read input for each pile
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &k[i]);
  }

  // Initialize nim-sum to 0
  int nim_sum = 0;

  // Calculate nim-sum for each pile
  for (int i = 0; i < n; i++) {
    // Find the largest power of K_i less than or equal to A_i
    int pow_k = 1;
    while (pow_k * k[i] <= a[i]) {
      pow_k *= k[i];
    }
    // Update nim-sum with the number of stones remaining after removing the largest power of K_i
    nim_sum ^= (a[i] - pow_k);
  }

  // Print the winner based on nim-sum
  if (nim_sum == 0) {
    printf("Aoki\n");
  } else {
    printf("Takahashi\n");
  }

  return 0;
}