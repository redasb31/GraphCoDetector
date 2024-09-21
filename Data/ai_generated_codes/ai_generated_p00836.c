#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
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

// Function to count the number of representations of an integer as sum of consecutive primes
int countRepresentations(int num) {
  int count = 0;
  // Iterate through all possible starting primes
  for (int i = 2; i <= num; i++) {
    if (isPrime(i)) {
      int sum = i;
      int j = i + 1;
      // Iterate through consecutive primes to check if they sum to the given number
      while (sum < num) {
        if (isPrime(j)) {
          sum += j;
        }
        j++;
      }
      // If the sum equals the given number, increment the count
      if (sum == num) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int num;
  // Read input until a zero is encountered
  while (true) {
    scanf("%d", &num);
    if (num == 0) {
      break;
    }
    // Print the number of representations for the input number
    printf("%d\n", countRepresentations(num));
  }
  return 0;
}