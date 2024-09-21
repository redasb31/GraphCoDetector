#include <stdio.h>
#include <limits.h>

// Function to find the minimum magic points required to defeat the monster
int minMagicPoints(int H, int N, int A[], int B[]) {
  // Initialize the minimum magic points to a large value
  int minMagicPoints = INT_MAX;

  // Iterate over all possible combinations of spells
  for (int i = 0; i < (1 << N); i++) {
    int currentMagicPoints = 0; // Initialize the current magic points to 0
    int currentHealth = H; // Initialize the current health to the monster's health

    // Iterate over all spells
    for (int j = 0; j < N; j++) {
      // If the j-th spell is selected
      if (i & (1 << j)) {
        // Decrease the monster's health and update the magic points
        currentHealth -= A[j];
        currentMagicPoints += B[j];
      }
    }

    // If the monster's health is 0 or less, update the minimum magic points
    if (currentHealth <= 0) {
      minMagicPoints = (minMagicPoints < currentMagicPoints) ? minMagicPoints : currentMagicPoints;
    }
  }

  // Return the minimum magic points
  return minMagicPoints;
}

int main() {
  int H, N;
  scanf("%d %d", &H, &N);

  // Declare arrays to store the spell effects and costs
  int A[N], B[N];

  // Read the spell effects and costs
  for (int i = 0; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }

  // Find and print the minimum magic points
  int result = minMagicPoints(H, N, A, B);
  printf("%d\n", result);

  return 0;
}