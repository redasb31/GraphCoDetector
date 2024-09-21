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

// Function to find the nth prime number in an arithmetic sequence
int find_nth_prime(int a, int d, int n) {
  int count = 0;
  int num = a;
  while (count < n) {
    if (is_prime(num)) {
      count++;
    }
    num += d;
  }
  return num - d;
}

int main() {
  int a, d, n;
  // Input loop
  while (scanf("%d %d %d", &a, &d, &n) == 3 && (a != 0 || d != 0 || n != 0)) {
    // Find the nth prime number
    int nth_prime = find_nth_prime(a, d, n);
    // Print the result
    printf("%d\n", nth_prime);
  }
  return 0;
}