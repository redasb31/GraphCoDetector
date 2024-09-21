#include <stdio.h>
#include <math.h>

int main() {
  // Declare variables for input
  long long A, B, N;

  // Read input values
  scanf("%lld %lld %lld", &A, &B, &N);

  // Calculate the maximum possible value
  long long max_value = 0;
  for (long long x = 0; x <= N; x++) {
    long long current_value = (long long)floor((double)A * x / B) - A * (long long)floor((double)x / B);
    max_value = (current_value > max_value) ? current_value : max_value;
  }

  // Print the maximum value
  printf("%lld\n", max_value);

  return 0;
}