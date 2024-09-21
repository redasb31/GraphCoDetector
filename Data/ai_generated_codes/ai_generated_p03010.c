#include <stdio.h>

// Function to generate a set of road lengths satisfying the conditions
void generate_road_lengths(int N) {
  // Initialize a 2D array to store road lengths
  int road_lengths[N][N];

  // Set diagonal elements to 0
  for (int i = 0; i < N; i++) {
    road_lengths[i][i] = 0;
  }

  // Generate unique lengths for off-diagonal elements
  int length = 1;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      road_lengths[i][j] = length;
      road_lengths[j][i] = length; // Ensure symmetry
      length++;
    }
  }

  // Print the road lengths in the required format
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", road_lengths[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int N;

  // Input the number of towns
  scanf("%d", &N);

  // Generate and print the road lengths
  generate_road_lengths(N);

  return 0;
}