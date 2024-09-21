#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the number of digits in a number
int countDigits(long long int num) {
  int count = 0;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return count;
}

// Function to find the minimum number of banknotes
long long int findMinBanknotes(char *N) {
  long long int banknotes = 0;
  int len = strlen(N);

  // Calculate the number of banknotes required for each digit
  for (int i = 0; i < len; i++) {
    // Find the digit at the current position
    int digit = N[i] - '0';

    // If the digit is non-zero, add the corresponding number of banknotes
    if (digit != 0) {
      banknotes += digit * pow(10, len - i - 1);
    }
  }

  // Return the total number of banknotes
  return banknotes;
}

int main() {
  char N[1000001];

  // Read the input value
  scanf("%s", N);

  // Calculate the minimum number of banknotes
  long long int minBanknotes = findMinBanknotes(N);

  // Print the result
  printf("%lld\n", minBanknotes);

  return 0;
}