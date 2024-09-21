#include <stdio.h>
#include <string.h>

#define MOD 1000000007

// Function to calculate the sum of digits of a number
int sum_of_digits(char *number) {
  int sum = 0;
  for (int i = 0; i < strlen(number); i++) {
    sum += number[i] - '0';
  }
  return sum;
}

// Function to count the numbers satisfying the condition
int count_numbers(char *k, int d) {
  int count = 0;
  // Iterate through all numbers from 1 to k
  for (int i = 1; i <= strlen(k); i++) {
    char number[10000];
    sprintf(number, "%d", i);
    // Check if the sum of digits is a multiple of d
    if (sum_of_digits(number) % d == 0) {
      count++;
    }
  }
  return count;
}

int main() {
  char k[10000];
  int d;

  // Read the input
  scanf("%s %d", k, &d);

  // Calculate the number of integers
  int result = count_numbers(k, d);

  // Print the result modulo 10^9 + 7
  printf("%d\n", result % MOD);

  return 0;
}