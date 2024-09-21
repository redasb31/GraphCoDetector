#include <stdio.h>

// Function to calculate the number of trailing zeros in f(n)
int countTrailingZeros(long long n) {
  // If n is less than 2, there are no trailing zeros
  if (n < 2) {
    return 0;
  }

  // Initialize the count of trailing zeros
  int count = 0;

  // Iterate through the numbers from n to 2, decrementing by 2
  for (long long i = n; i >= 2; i -= 2) {
    // Calculate the number of factors of 5 in i
    long long temp = i;
    while (temp % 5 == 0) {
      count++;
      temp /= 5;
    }
  }

  // Return the count of trailing zeros
  return count;
}

int main() {
  // Input the value of N
  long long N;
  scanf("%lld", &N);

  // Calculate and print the number of trailing zeros in f(N)
  printf("%lld\n", countTrailingZeros(N));

  return 0;
}