#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  long long X, K, D;
  
  // Read the input values
  scanf("%lld %lld %lld", &X, &K, &D);

  // Calculate the maximum possible displacement
  long long max_displacement = K * D;

  // Calculate the minimum possible absolute value of the destination coordinate
  long long min_abs_destination = abs(X - max_displacement);
  min_abs_destination = min(min_abs_destination, abs(X + max_displacement));

  // Print the result
  printf("%lld\n", min_abs_destination);
  
  return 0;
}