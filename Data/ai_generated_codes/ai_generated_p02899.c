#include <stdio.h>
#include <stdlib.h>

int main() {
  // N: number of students
  int N;
  scanf("%d", &N);

  // A: array to store the number of students in the classroom when each student entered
  int *A = malloc(sizeof(int) * N);

  // Read the input array A
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Create an array to store the order of students entering the classroom
  int *order = malloc(sizeof(int) * N);

  // Initialize the order array with -1
  for (int i = 0; i < N; i++) {
    order[i] = -1;
  }

  // Iterate through each student
  for (int i = 0; i < N; i++) {
    // Find the position in the order array where the student should be placed
    int pos = A[i] - 1;

    // Place the student's number in the order array
    order[pos] = i + 1;
  }

  // Print the order of students entering the classroom
  for (int i = 0; i < N; i++) {
    printf("%d ", order[i]);
  }
  printf("\n");

  // Free the allocated memory
  free(A);
  free(order);

  return 0;
}