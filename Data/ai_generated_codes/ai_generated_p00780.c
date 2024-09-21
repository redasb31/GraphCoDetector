#include <stdio.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
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

// Function to count the number of prime pairs for a given even number
int count_prime_pairs(int num) {
  int count = 0;
  for (int i = 2; i <= num / 2; i++) {
    if (is_prime(i) && is_prime(num - i)) {
      count++;
    }
  }
  return count;
}

int main() {
  int num;

  // Read input numbers until 0 is encountered
  while (1) {
    scanf("%d", &num);
    if (num == 0) {
      break;
    }

    // Print the count of prime pairs
    printf("%d\n", count_prime_pairs(num));
  }

  return 0;
}