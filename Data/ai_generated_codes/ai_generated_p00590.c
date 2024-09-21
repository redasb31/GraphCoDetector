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
  int N, count;
  while (scanf("%d", &N) != EOF) {
    count = 0; // Initialize the count of prime pairs
    for (int i = 1; i <= N / 2; i++) {
      // Check if both i and N-i+1 are prime
      if (isPrime(i) && isPrime(N - i + 1)) {
        count++; // Increment the count if both numbers are prime
      }
    }
    printf("%d\n", count);
  }
  return 0;
}