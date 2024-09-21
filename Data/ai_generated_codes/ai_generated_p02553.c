#include <stdio.h>

int main() {
  long long a, b, c, d; // Use long long to handle large integers
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

  // Maximize x * y by considering the extreme values of x and y
  long long max_xy = b * d; // Product of the maximum values of x and y

  printf("%lld\n", max_xy); // Output the maximum possible value of x * y
  return 0;
}