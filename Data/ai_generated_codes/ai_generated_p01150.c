#include <stdio.h>
#include <math.h>

// Function to calculate the number of ways to seat the princes without quarrels
long long count_arrangements(int n) {
  // If the number of seats is less than 8, no arrangements are possible
  if (n < 8) {
    return 0;
  }

  // Calculate the number of arrangements
  long long arrangements = 1;
  for (int i = 0; i < 8; i++) {
    arrangements *= (n - i);
  }

  // Divide by 8 to account for rotations
  arrangements /= 8;

  // If the number of seats is even, divide by 2 to account for mirroring
  if (n % 2 == 0) {
    arrangements /= 2;
  }

  return arrangements;
}

int main() {
  int n;

  // Read the input
  while (scanf("%d", &n) != EOF && n != 0) {
    // Calculate and print the number of arrangements
    printf("%lld\n", count_arrangements(n));
  }

  return 0;
}