#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int N; // Degree of the polynomial
  scanf("%d", &N);

  // Array to store the coefficients of the polynomial
  int coeff[N + 1];
  for (int i = N; i >= 0; i--) {
    scanf("%d", &coeff[i]);
  }

  // Finding the prime factors of the leading coefficient
  int leadingCoeff = coeff[N];
  int foundPrime = 0; // Flag to check if any prime factor is found

  for (int i = 2; i <= sqrt(leadingCoeff); i++) {
    if (isPrime(i) && leadingCoeff % i == 0) {
      // If a prime factor is found, check if it divides all coefficients
      int dividesAll = 1;
      for (int j = 0; j <= N; j++) {
        if (coeff[j] % i != 0) {
          dividesAll = 0;
          break;
        }
      }
      // If the prime factor divides all coefficients, print it
      if (dividesAll) {
        printf("%d\n", i);
        foundPrime = 1;
      }
    }
  }

  // If no prime factor is found, print "There may be no integers that satisfy the condition."
  if (!foundPrime) {
    printf("There may be no integers that satisfy the condition.\n");
  }

  return 0;
}