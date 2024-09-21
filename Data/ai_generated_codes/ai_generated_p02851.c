#include <stdio.h>

int main() {
  // N: Number of integers in the sequence
  // K: The divisor
  int N, K;
  scanf("%d %d", &N, &K);

  // A: Array to store the sequence of integers
  int A[200001];

  // Read the sequence of integers from input
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  // Initialize variables for counting subsequences
  long long count = 0; // Total number of valid subsequences
  long long sum = 0; // Sum of elements in the current subsequence
  long long length = 0; // Length of the current subsequence

  // Iterate through all possible subsequences
  for (int i = 0; i < N; i++) {
    // Reset the sum and length for each new subsequence
    sum = 0;
    length = 0;

    // Iterate through the subsequence starting from the current position
    for (int j = i; j < N; j++) {
      // Add the current element to the sum and increment the length
      sum += A[j];
      length++;

      // Check if the current subsequence satisfies the condition
      if ((sum % K) == length) {
        // Increment the count of valid subsequences
        count++;
      }
    }
  }

  // Print the total number of valid subsequences
  printf("%lld\n", count);

  return 0;
}