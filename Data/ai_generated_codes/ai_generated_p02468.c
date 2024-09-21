#include <stdio.h>

// Function to calculate the modular exponentiation
long long int modulo_power(long long int m, long long int n) {
  // Modulo value
  long long int MOD = 1000000007;
  // Base case for n == 0
  if (n == 0) {
    return 1;
  }
  // Recursive call for n/2 and calculate the result based on even or odd n
  long long int temp = modulo_power(m, n / 2);
  if (n % 2 == 0) {
    return (temp * temp) % MOD;
  } else {
    return (((temp * temp) % MOD) * m) % MOD;
  }
}

int main() {
  // Declare variables to store input values
  long long int m, n;
  // Read input values from the user
  scanf("%lld %lld", &m, &n);
  // Calculate and print the result using modular exponentiation function
  printf("%lld\n", modulo_power(m, n));
  return 0;
}