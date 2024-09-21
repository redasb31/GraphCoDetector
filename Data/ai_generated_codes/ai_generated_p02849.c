#include <stdio.h>

// Function to calculate the price of an integer
long long int price(long long int A, long long int B, long long int N) {
  // Calculate the number of digits in N
  int digits = 0;
  long long int temp = N;
  while (temp > 0) {
    digits++;
    temp /= 10;
  }
  // Calculate the price
  return A * N + B * digits;
}

int main() {
  // Declare variables to store input
  long long int A, B, X;

  // Read input
  scanf("%lld %lld %lld", &A, &B, &X);

  // Declare a variable to store the maximum integer that can be bought
  long long int max_integer = 0;

  // Iterate from 1 to 10^9 and find the maximum integer that can be bought
  for (long long int i = 1; i <= 1000000000; i++) {
    // If the price of the current integer is less than or equal to X
    if (price(A, B, i) <= X) {
      // Update the maximum integer
      max_integer = i;
    }
  }

  // Print the maximum integer
  printf("%lld\n", max_integer);

  return 0;
}