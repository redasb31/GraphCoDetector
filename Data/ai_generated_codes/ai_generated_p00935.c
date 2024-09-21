#include <stdio.h>

int main() {
  // Input the number of digits
  int n;
  scanf("%d", &n);

  // Declare an array to store the digits
  int digits[1000];

  // Input the digits
  for (int i = 0; i < n; i++) {
    scanf("%d", &digits[i]);
  }

  // Create a boolean array to track the presence of digits
  bool present[1000] = {false};

  // Mark the presence of digits in the input sequence
  for (int i = 0; i < n; i++) {
    present[digits[i]] = true;
  }

  // Find the smallest missing non-negative integer
  int smallest_missing = 0;
  while (present[smallest_missing]) {
    smallest_missing++;
  }

  // Output the smallest missing non-negative integer
  printf("%d\n", smallest_missing);

  return 0;
}