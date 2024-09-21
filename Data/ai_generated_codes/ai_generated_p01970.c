#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to calculate the number of natural numbers that result in a given output
long long countNumbers(int *q, int N) {
  long long result = 1;
  int prevPrime = 0;
  for (int i = 0; i < N; i++) {
    if (!isPrime(q[i])) {
      return 0; // Not a valid output
    }
    if (q[i] == prevPrime) {
      result = (result * (q[i] + 1)) % MOD; // If the prime is repeated, multiply by (e + 1)
    } else {
      result = (result * q[i]) % MOD; // If the prime is not repeated, multiply by p
    }
    prevPrime = q[i];
  }
  return result;
}

int main() {
  int N;
  scanf("%d", &N);

  int *q = (int *)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    scanf("%d", &q[i]);
  }

  long long answer = countNumbers(q, N);
  printf("%lld\n", answer);

  free(q);
  return 0;
}