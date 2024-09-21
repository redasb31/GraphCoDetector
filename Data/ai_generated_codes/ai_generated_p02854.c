#include <stdio.h>
#include <stdlib.h>

int main() {
  // Get the number of sections
  int N;
  scanf("%d", &N);

  // Allocate memory for the section lengths
  int *A = malloc(sizeof(int) * N);

  // Get the lengths of each section
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the total length of the bar
  long long total_length = 0;
  for (int i = 0; i < N; i++) {
    total_length += A[i];
  }

  // Calculate the target length for each half
  long long target_length = total_length / 2;

  // Calculate the difference between the current length of the left half and the target length
  long long left_diff = 0;
  for (int i = 0; i < N / 2; i++) {
    left_diff += A[i];
  }
  left_diff -= target_length;

  // Calculate the difference between the current length of the right half and the target length
  long long right_diff = 0;
  for (int i = N / 2; i < N; i++) {
    right_diff += A[i];
  }
  right_diff -= target_length;

  // Calculate the minimum cost
  int cost = abs(left_diff) + abs(right_diff);

  // Free the allocated memory
  free(A);

  // Print the minimum cost
  printf("%d\n", cost);

  return 0;
}