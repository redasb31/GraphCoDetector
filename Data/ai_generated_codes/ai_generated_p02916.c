#include <stdio.h>

int main() {
  // N: Number of dishes
  int N;
  scanf("%d", &N);

  // A: Array storing the order in which dishes were eaten
  int A[N];
  // B: Array storing satisfaction points gained from each dish
  int B[N];
  // C: Array storing additional satisfaction points gained from eating consecutive dishes
  int C[N - 1];

  // Input the order of dishes eaten
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Input satisfaction points gained from each dish
  for (int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
  }

  // Input additional satisfaction points gained from eating consecutive dishes
  for (int i = 0; i < N - 1; i++) {
    scanf("%d", &C[i]);
  }

  // Total satisfaction points gained
  int total_satisfaction = 0;

  // Iterate through the dishes
  for (int i = 0; i < N; i++) {
    // Calculate the index of the current dish in the A array
    int dish_index = A[i] - 1;

    // Add the satisfaction points gained from the current dish
    total_satisfaction += B[dish_index];

    // If it's not the last dish, add the bonus satisfaction points for eating the next consecutive dish
    if (i < N - 1) {
      total_satisfaction += C[i];
    }
  }

  // Print the total satisfaction points gained
  printf("%d\n", total_satisfaction);

  return 0;
}