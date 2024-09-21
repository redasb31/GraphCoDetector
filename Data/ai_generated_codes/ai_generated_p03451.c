#include <stdio.h>

int main() {
  // N: the number of columns in the grid
  int N;
  // A: a 2xN array representing the number of candies in each square
  int A[2][100];
  // max_candies: the maximum number of candies that can be collected
  int max_candies;

  // Read the input
  scanf("%d", &N);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Calculate the maximum number of candies
  max_candies = 0;
  // Calculate the maximum candies by considering two possible paths:
  // 1. Move down first, then right
  // 2. Move right first, then down
  for (int i = 0; i < N; i++) {
    // Path 1: Move down first, then right
    max_candies = max(max_candies, A[0][i] + A[1][i] + sum_array(A[1], i + 1, N));
    // Path 2: Move right first, then down
    max_candies = max(max_candies, A[0][i] + A[1][i] + sum_array(A[0], i + 1, N));
  }

  // Print the output
  printf("%d\n", max_candies);

  return 0;
}

// Function to calculate the sum of elements in an array from index start to end
int sum_array(int array[], int start, int end) {
  int sum = 0;
  for (int i = start; i < end; i++) {
    sum += array[i];
  }
  return sum;
}

// Function to find the maximum of two integers
int max(int a, int b) {
  return (a > b) ? a : b;
}