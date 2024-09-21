#include <stdio.h>

int main() {
  // Get the length of the sequence
  int N;
  scanf("%d", &N);

  // Declare an array to store the sequence
  int A[N];

  // Read the sequence from input
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate the number of elements to choose
  int num_elements = N / 2;

  // Declare two variables to store the maximum sum considering the current and previous elements
  int max_sum_current = 0;
  int max_sum_previous = 0;

  // Iterate through the sequence
  for (int i = 0; i < N; i++) {
    // Calculate the maximum sum considering the current element
    int current_sum = max_sum_previous + A[i];
    // Update the maximum sum considering the current element
    max_sum_current = (current_sum > max_sum_current) ? current_sum : max_sum_current;

    // Update the maximum sum considering the previous element
    max_sum_previous = max_sum_current;
  }

  // Print the maximum possible sum
  printf("%d\n", max_sum_current);

  return 0;
}