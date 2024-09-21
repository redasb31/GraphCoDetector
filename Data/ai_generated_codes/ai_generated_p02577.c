#include <stdio.h>
#include <string.h>

int main() {
  char N[200001]; // Character array to store the input string (up to 200,000 digits)
  scanf("%s", N); // Read the input string

  int sum = 0; // Variable to store the sum of digits
  int len = strlen(N); // Calculate the length of the string

  // Iterate through each digit in the string
  for (int i = 0; i < len; i++) {
    sum += N[i] - '0'; // Convert the character to an integer and add to the sum
  }

  // Check if the sum is divisible by 9
  if (sum % 9 == 0) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

  return 0;
}