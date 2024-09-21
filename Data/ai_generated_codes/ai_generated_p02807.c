#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

long long int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return (n * fact(n - 1)) % MOD;
}

int main() {
  int n;
  scanf("%d", &n);

  // Store the positions of the slimes
  long long int* positions = (long long int*) malloc(n * sizeof(long long int));
  for (int i = 0; i < n; i++) {
    scanf("%lld", &positions[i]);
  }

  // Calculate the total distance traveled
  long long int total_distance = 0;
  for (int i = 0; i < n - 1; i++) {
    // Calculate the expected distance traveled in the i-th operation
    long long int expected_distance = 0;
    for (int j = i + 1; j < n; j++) {
      expected_distance += (positions[j] - positions[j - 1]);
    }
    expected_distance /= (n - i);
    total_distance += expected_distance;
  }

  // Calculate the factorial of (N-1)
  long long int factorial = fact(n - 1);

  // Multiply the total distance by (N-1)! and take modulo (10^9+7)
  total_distance = (total_distance * factorial) % MOD;

  printf("%lld\n", total_distance);

  free(positions);
  return 0;
}