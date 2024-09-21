#include <stdio.h>
#include <math.h>

int main() {
  long long N; // Declare N as long long to handle large inputs
  scanf("%lld", &N); // Read N from the user

  long long sum = 0; // Initialize the sum of favorite numbers

  // Loop through potential favorite numbers
  for (long long m = 1; m * m <= N; m++) {
    // Check if the quotient and remainder are equal
    if (N / m == N % m) {
      sum += m; // Add the favorite number to the sum
      // If m^2 != N, then N/m is also a favorite number
      if (m * m != N) {
        sum += N / m;
      }
    }
  }

  printf("%lld\n", sum); // Print the sum of favorite numbers

  return 0;
}