#include <stdio.h>

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  // Input variables
  int a, b, k;
  scanf("%d %d %d", &a, &b, &k);

  // Calculate the GCD
  int gcd_ab = gcd(a, b);

  // Find the k-th largest divisor
  int count = 0; // Counter for the number of divisors found
  int divisor; 
  for (divisor = gcd_ab; divisor >= 1; divisor--) { // Iterate from GCD to 1
    if (gcd_ab % divisor == 0) { // Check if the current number divides the GCD
      count++; 
      if (count == k) { // If we find the k-th divisor, break
        break;
      }
    }
  }

  // Output the k-th largest divisor
  printf("%d\n", divisor);
  return 0;
}