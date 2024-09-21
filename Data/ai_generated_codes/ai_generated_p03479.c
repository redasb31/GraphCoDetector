#include <stdio.h>
#include <math.h>

// Function to calculate the maximum length of the sequence
long long max_length(long long X, long long Y) {
  long long length = 1; // Initial length of the sequence
  long long current = X; // Current element in the sequence

  // Iterate until the current element exceeds Y
  while (current <= Y) {
    // Find the smallest multiple of current that is greater than Y
    long long next = current * 2; // Start with the next multiple
    while (next <= Y) {
      next *= 2; // Keep doubling until we exceed Y
    }
    next /= 2; // Backtrack to the last multiple within Y
    current = next; // Update the current element
    length++; // Increment the length of the sequence
  }

  return length; // Return the maximum length
}

int main() {
  long long X, Y; // Input values
  scanf("%lld %lld", &X, &Y); // Read input values

  long long result = max_length(X, Y); // Calculate the maximum length
  printf("%lld\n", result); // Print the result

  return 0; // End of the program
}