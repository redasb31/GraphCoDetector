#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a Monday-Saturday number
bool isMondaySaturdayNumber(int num) {
  return (num % 7 == 1 || num % 7 == 6);
}

// Function to check if a number is a Monday-Saturday prime
bool isMondaySaturdayPrime(int num) {
  if (num <= 1 || !isMondaySaturdayNumber(num)) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0 && isMondaySaturdayNumber(i)) {
      return false;
    }
  }
  return true;
}

// Function to find and print Monday-Saturday prime factors of a number
void findMondaySaturdayPrimeFactors(int num) {
  printf("%d: ", num);
  bool printed[300000] = {false}; // Array to track printed factors

  // Find all Monday-Saturday prime factors
  for (int i = 2; i <= num; i++) {
    if (isMondaySaturdayPrime(i) && num % i == 0 && !printed[i]) {
      printf(" %d", i);
      printed[i] = true;
    }
  }

  printf("\n");
}

int main() {
  int num;
  // Read input until a '1' is encountered
  while (scanf("%d", &num) == 1 && num != 1) {
    if (isMondaySaturdayNumber(num)) {
      findMondaySaturdayPrimeFactors(num);
    } else {
      printf("%d: \n", num); // Handle non-Monday-Saturday numbers
    }
  }
  return 0;
}