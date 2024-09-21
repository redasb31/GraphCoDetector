#include <stdio.h>

// Function to find the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
  // Find the greatest common divisor (GCD) using Euclid's algorithm
  int gcd = 1;
  for (int i = 1; i <= a && i <= b; ++i) {
    if (a % i == 0 && b % i == 0) {
      gcd = i;
    }
  }
  // Calculate the LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
  return (a * b) / gcd;
}

int main() {
  int A, B;

  // Input the number of guests in each case
  scanf("%d %d", &A, &B);

  // Calculate and print the minimum number of pieces required
  printf("%d\n", lcm(A, B));

  return 0;
}