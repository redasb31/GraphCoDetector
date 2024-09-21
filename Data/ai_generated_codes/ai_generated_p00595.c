#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
  // Base case: If b is 0, then a is the GCD
  if (b == 0) {
    return a;
  }
  // Recursive call: Calculate the GCD of b and the remainder of a divided by b
  return gcd(b, a % b);
}

int main() {
  int a, b;
  // Loop through each pair of input numbers
  while (scanf("%d %d", &a, &b) != EOF) {
    // Calculate and print the GCD
    printf("%d\n", gcd(a, b));
  }
  return 0;
}