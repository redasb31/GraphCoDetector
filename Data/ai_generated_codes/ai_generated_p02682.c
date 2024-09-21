#include <stdio.h>

int main() {
  // Declare variables for the number of cards of each type
  long long A, B, C;

  // Declare a variable for the number of cards to be chosen
  long long K;

  // Read the input from the user
  scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

  // Calculate the maximum possible sum
  long long max_sum = 0; // Initialize the maximum sum to 0

  // If the number of cards to be chosen is less than or equal to the number of cards with 1s,
  // then we can choose all the cards with 1s
  if (K <= A) {
    max_sum = K; // Set the maximum sum to the number of cards to be chosen
  } else {
    // If the number of cards to be chosen is greater than the number of cards with 1s,
    // then we choose all the cards with 1s and the remaining cards with 0s
    max_sum = A; // Set the maximum sum to the number of cards with 1s
    K -= A; // Update the number of cards to be chosen
    max_sum += K; // Add the remaining cards with 0s
  }

  // Print the maximum possible sum
  printf("%lld\n", max_sum);

  return 0;
}