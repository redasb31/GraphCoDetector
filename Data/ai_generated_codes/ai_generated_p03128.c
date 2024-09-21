#include <stdio.h>

// Matchsticks required for each digit
int matchsticks[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// Function to calculate the number of matchsticks required to form an integer
int calculate_matchsticks(int num) {
  int total_matchsticks = 0;
  while (num > 0) {
    total_matchsticks += matchsticks[num % 10];
    num /= 10;
  }
  return total_matchsticks;
}

int main() {
  int N, M; // Number of matchsticks and number of digits
  scanf("%d %d", &N, &M);

  int digits[10] = {0}; // Array to store the digits

  // Input the allowed digits
  for (int i = 0; i < M; i++) {
    int digit;
    scanf("%d", &digit);
    digits[digit] = 1;
  }

  // Find the largest integer using greedy approach
  int largest_integer = 0;
  for (int i = 9; i >= 1; i--) {
    // Check if the digit is allowed and if enough matchsticks are available
    if (digits[i] == 1 && calculate_matchsticks(largest_integer * 10 + i) <= N) {
      // Add the digit to the integer repeatedly as long as enough matchsticks are available
      while (calculate_matchsticks(largest_integer * 10 + i) <= N) {
        largest_integer = largest_integer * 10 + i;
      }
    }
  }

  // Print the largest integer
  printf("%d\n", largest_integer);

  return 0;
}