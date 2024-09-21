#include <stdio.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to calculate the number of divisors of a number
int divisors(int n) {
  int count = 0;
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      count += 2; // Count both i and n/i as divisors
    }
  }
  // If n is a perfect square, we counted its square root twice, so subtract 1
  if (sqrt(n) == (int)sqrt(n)) {
    count--;
  }
  return count;
}

int main() {
  int A, B;
  scanf("%d %d", &A, &B);

  // Calculate the GCD of A and B
  int gcd_AB = gcd(A, B);

  // The maximum number of coprime divisors is equal to the number of divisors of the GCD
  printf("%d\n", divisors(gcd_AB));

  return 0;
}