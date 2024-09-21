#include <stdio.h>

int main() {
  int N; // Number of heroes
  scanf("%d", &N);

  // Array to store the number of monsters attacking each town
  int A[N + 1]; 
  for (int i = 1; i <= N + 1; i++) {
    scanf("%d", &A[i]);
  }

  // Array to store the maximum number of monsters each hero can defeat
  int B[N];
  for (int i = 1; i <= N; i++) {
    scanf("%d", &B[i]);
  }

  // Initialize the total number of defeated monsters to 0
  int total_defeated = 0; 

  // Iterate through each town (except the last one)
  for (int i = 1; i <= N; i++) {
    // Calculate the maximum number of monsters the current hero can defeat in the current town
    int max_defeated_current_town = B[i] - A[i + 1];
    // If the hero can defeat some monsters in the current town
    if (max_defeated_current_town > 0) {
      // Update the total number of defeated monsters
      total_defeated += max_defeated_current_town;
      // Update the number of monsters attacking the current town
      A[i] -= max_defeated_current_town;
    }

    // Calculate the maximum number of monsters the current hero can defeat in the next town
    int max_defeated_next_town = B[i] - A[i];
    // If the hero can defeat some monsters in the next town
    if (max_defeated_next_town > 0) {
      // Update the total number of defeated monsters
      total_defeated += max_defeated_next_town;
      // Update the number of monsters attacking the next town
      A[i + 1] -= max_defeated_next_town;
    }
  }

  // Print the total number of defeated monsters
  printf("%d\n", total_defeated);

  return 0;
}