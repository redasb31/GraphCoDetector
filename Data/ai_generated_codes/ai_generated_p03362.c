#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// Function to generate a sequence of prime numbers satisfying the given conditions
void generate_sequence(int N) {
  int primes[55] = {0}; // Array to store prime numbers up to 55555
  int count = 0; // Counter for prime numbers found

  // Generate prime numbers up to 55555
  for (int i = 2; i <= 55555; i++) {
    if (is_prime(i)) {
      primes[count++] = i;
    }
  }

  // Check if N is valid
  if (N < 5 || N > 55) {
    printf("Invalid input: N must be between 5 and 55\n");
    return;
  }

  // Print the sequence
  for (int i = 0; i < N; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");
}

int main() {
  int N;
  scanf("%d", &N);

  generate_sequence(N);

  return 0;
}