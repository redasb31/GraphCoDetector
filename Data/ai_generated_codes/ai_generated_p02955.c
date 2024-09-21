#include <stdio.h>
#include <stdlib.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// Function to find the maximum possible positive integer that divides every element of A after operations
int findMaxDivisor(int* A, int N, int K) {
  // Calculate the sum of all elements in A
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
  }

  // If the sum is divisible by N, then we can make all elements equal to sum / N
  if (sum % N == 0) {
    return sum / N;
  }

  // Calculate the maximum possible difference between any two elements
  int max_diff = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      max_diff = (max_diff > abs(A[i] - A[j])) ? max_diff : abs(A[i] - A[j]);
    }
  }

  // Calculate the maximum number of operations we can perform to make all elements congruent modulo max_diff
  int max_operations = (K + max_diff - 1) / max_diff;

  // Initialize the maximum divisor to 1
  int max_divisor = 1;

  // Iterate through all elements of A and update the maximum divisor
  for (int i = 0; i < N; i++) {
    // Apply the maximum number of operations to make all elements congruent modulo max_diff
    A[i] = (A[i] + max_operations * max_diff) % max_diff;

    // Update the maximum divisor using the GCD
    max_divisor = gcd(max_divisor, A[i]);
  }

  // Return the maximum divisor
  return max_divisor;
}

int main() {
  int N, K;
  // Read the number of elements and the number of operations
  scanf("%d %d", &N, &K);

  // Allocate memory for the array A
  int* A = (int*)malloc(N * sizeof(int));

  // Read the elements of the array A
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Calculate and print the maximum possible positive integer that divides every element of A after operations
  printf("%d\n", findMaxDivisor(A, N, K));

  // Free the allocated memory
  free(A);

  return 0;
}