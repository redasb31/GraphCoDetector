#include <stdio.h>

int main() {
  // Declare variable for the input number N
  int N;

  // Read the input number N from standard input
  scanf("%d", &N);

  // Declare variable to store the sum of the FizzBuzz sequence
  long long sum = 0; // Use long long for larger sums

  // Iterate through the first N terms of the FizzBuzz sequence
  for (int i = 1; i <= N; i++) {
    // Check if i is divisible by both 3 and 5
    if (i % 3 == 0 && i % 5 == 0) {
      continue; // Skip to the next iteration if both divisible
    }
    // Check if i is divisible by 3
    else if (i % 3 == 0) {
      continue; // Skip to the next iteration if divisible by 3
    }
    // Check if i is divisible by 5
    else if (i % 5 == 0) {
      continue; // Skip to the next iteration if divisible by 5
    }
    // If none of the above conditions hold, add i to the sum
    else {
      sum += i;
    }
  }

  // Print the sum of the FizzBuzz sequence
  printf("%lld\n", sum);
  
  return 0;
}