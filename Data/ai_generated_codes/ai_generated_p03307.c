#include <stdio.h>

int main() {
  // Declare variable to store the input integer N
  long long int N;

  // Read the input integer N from the standard input
  scanf("%lld", &N);

  // Check if N is already divisible by 2
  if (N % 2 == 0) {
    // If N is divisible by 2, N itself is the answer
    printf("%lld\n", N);
  } else {
    // If N is not divisible by 2, the minimum positive integer divisible by both 2 and N is N * 2
    printf("%lld\n", N * 2);
  }

  return 0;
}